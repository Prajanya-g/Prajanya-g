var express = require('express');
var router = express.Router();
const {OAuth2Client} = require('google-auth-library');
const client = new OAuth2Client('446213487514-n1bj3kj00h4jmtttaijih8ni5u5oadme.apps.googleusercontent.com');
const argon2 = require('argon2');
/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

//global variables
var loginStatus = false;
var loggedInUser = "";
var CUser;
var currentEvent;
var isadmin = false;
var currentHostId;
var notification;
var memberId;
var dateIDS = [];
var adminSearchedUser;

//LOGIN
router.post('/login', function(req, res, next) {
  //check for valid information in the request body
  if ('username' in req.body && 'password' in req.body) {
    //set up database connection
    req.pool.getConnection(function(error,connection){
      if (error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      //select the user that matches the username
      let query = "SELECT user_ID, username, user_password, is_admin FROM Users WHERE username = ?;";
      connection.query(query, [req.body.username], async function(error, rows, fields){
        connection.release();
        if (error) {
          console.log(error);
          res.sendStatus(500);
          return;
        }
        //if user exists
        if(rows.length > 0){
          //verify hashed password
          try {
            //if successful, start session and set all global variables
            if (await argon2.verify(rows[0].user_password, req.body.password)) {
              console.log('login successful');
              delete rows[0].user_password;
              req.session.user = rows[0];
              loginStatus = true;
              loggedInUser = rows[0].user_ID;
              isadmin = rows[0].is_admin;
              res.sendStatus(200);
            }
            //if password does not match
            else{
              console.log('bad password');
              res.sendStatus(401);
            }
            //verification error
          } catch (error) {
            console.log('bad verify');
            res.sendStatus(401);
          }
        }
        //if user does not exist
        else {
          console.log('bad user');
          res.sendStatus(401);
        }
      });
    });
  }
  //if google sign in
  else if ('token' in req.body) {
    let googleID = null;
    let firstname = null;
    let email = null;

    async function verify() {
      const ticket = await client.verifyIdToken({
          idToken: req.body.token,
          audience: '446213487514-n1bj3kj00h4jmtttaijih8ni5u5oadme.apps.googleusercontent.com',
      });
      const payload = ticket.getPayload();
      //get all information needed
      googleID = payload['sub'];
      firstname = payload['given_name'];
      email = payload['email'];

    }
    verify().then(function(){
        req.pool.getConnection(function(error,connection){
        if (error){
          console.log(error);
          res.sendStatus(500);
          return;
        }

        //select the user that matches the google id
        let query = "SELECT user_ID, first_name, is_admin FROM Users WHERE google_ID = ?;";
        connection.query(query, [googleID], async function(error, rows, fields){
          if (error) {
            console.log(error);
            res.sendStatus(500);
            return;
          }
          //if user already exists in the database, login
          if(rows.length > 0){
            console.log("Google User "+rows[0].first_name+" logged in");
            req.session.user = rows[0];
            loginStatus = true;
            loggedInUser = rows[0].user_ID;
            isadmin = rows[0].is_admin;
            res.sendStatus(200);
          }
          //if google user does not exist in database
          else{
            //insert google sign up information to users table
            let query = "INSERT INTO Users (google_ID, first_name, email, is_admin) VALUES (?,?,?,false);";
            connection.query(query, [googleID, firstname, email], function(error, rows, fields){
              if (error) {
                console.log(error);
                res.sendStatus(500);
                return;
              }
              //check if the user is in the database
              //select the user that matches the google id
              let query = "SELECT user_ID, first_name, is_admin FROM Users WHERE google_ID = ?;";
              connection.query(query, [googleID], function(error, rows, fields){
                connection.release();
                if (error) {
                  console.log(error);
                  res.sendStatus(500);
                  return;
                }
                //google user successfully signed up
                if(rows.length > 0){
                  console.log("Google User "+rows[0].first_name+" created");
                  req.session.user = rows[0];
                  loginStatus = true;
                  loggedInUser = rows[0].user_ID;
                  isadmin = rows[0].is_admin;
                  res.sendStatus(200);
                }
                //google user does not appear in database
                else {
                  console.log('bad signup');
                  res.sendStatus(401);
                }
              });
            });
          }
        });
        });
      })
    }
    //not enough required information in the request body
    else {
      console.log('bad request');
      res.sendStatus(400);
      }
});

//SIGN UP
router.post('/signup', function(req, res, next) {

  if ('username' in req.body && 'firstname' in req.body && 'email' in req.body && 'password' in req.body) {
    //establish connection with database
    req.pool.getConnection(function(error,connection){
      if (error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      //check if user already exists
      //select the user that matches the username
      let query = "SELECT username FROM Users WHERE username = ?;";
      connection.query(query, [req.body.username], async function(error, rows, fields){
        if (error) {
          console.log(error);
          res.sendStatus(500);
          return;
        }
        //user already exists
        if(rows.length > 0){
          console.log('user exists');
          res.sendStatus(403);
        }
        //user does not exists
        else{
          let hash = null;
          try {
            hash = await argon2.hash(req.body.password);
          } catch (error) {
            console.log(error);
            res.sendStatus(500);
            return;
          }
          //insert sign up information to users table
          let query = "INSERT INTO Users (username, first_name, email, user_password, is_admin) VALUES (?,?,?,?,false);";
          connection.query(query, [req.body.username, req.body.firstname, req.body.email, hash], function(error, rows, fields){
            if (error) {
              console.log(error);
              res.sendStatus(500);
              return;
            }
            //check if the user is in the database
            //select the user that matches the username
            let query = "SELECT user_ID, username, is_admin FROM Users WHERE username = ?;";
            connection.query(query, [req.body.username], function(error, rows, fields){
              connection.release();
              if (error) {
                console.log(error);
                res.sendStatus(500);
                return;
              }
              //user sign up successful
              if(rows.length > 0){
                console.log("User "+req.body.username+" created");
                req.session.user = rows[0];
                loginStatus = true;
                loggedInUser = rows[0].user_ID;
                isadmin = rows[0].is_admin;
                res.sendStatus(200);
              }
              //user not appearing in the database
              else {
                console.log('bad signup');
                res.sendStatus(401);
              }
            });
          });
        }
      });
    });
  }
  //sign up information not correct
  else {
    console.log('bad request');
    res.sendStatus(400);
  }
});

//LOGOUT
router.post('/logout', function(req, res, next) {
  //delete session
  if('user' in req.session){
    loginStatus = false;
    delete req.session.user;
  }
  res.send();
});

router.post('/usernameSearched', function(req, res, next) { //the user admin clicks to view
  adminSearchedUser=req.body.username;
  res.end();
});

router.get('/account', function(req, res, next) { //account route
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT username, first_name, email, user_password FROM Users WHERE user_ID = ?;"; //select username email password from logged in user
    connection.query(query, [loggedInUser], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.json(rows);
    });
  });
});

router.get('/loggedIn', function(req, res, next) { //event details
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT username, first_name, email FROM Users WHERE user_ID = ?;"; //select logged in user's first name and email
    connection.query(query, [loggedInUser], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }

      res.json(rows);
    });
  });
});

router.post('/changeInfo', function(req, res, next) { //account route: send updated user info to database
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "UPDATE Users SET first_name = ?, email = ? WHERE user_ID = ?;";
    connection.query(query, [req.body.first_name, req.body.email, loggedInUser], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.end();
    });
  });
});


router.post('/changeInfoAdmin', function(req, res, next) { //account route: send updated user info to database
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "UPDATE Users SET first_name = ?, email = ? WHERE user_ID = ?;";
    connection.query(query, [req.body.first_name, req.body.email, adminSearchedUser], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.end();
    });
  });
});

router.post('/changePswd', function(req, res, next) { //help
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    //CHECK IF PASSWORD MATCHES --->
    //Checking old password
    let query = "SELECT user_password FROM Users WHERE user_id = ?;";
      connection.query(query, [loggedInUser], async function(error, rows, fields){
        if (error) {
          console.log(error);
          res.sendStatus(500);
          return;
        }
        try {
          if (await argon2.verify(rows[0].user_password, req.body.oldPassword)) {
            console.log('old password matches');
            delete rows[0].user_password;
            //Update new password
            let hash = null;
            try {
              hash = await argon2.hash(req.body.newPassword);
            } catch (error) {
              console.log(error);
              res.sendStatus(500);
              return;
            }
          let query = "UPDATE Users SET user_password = ? WHERE user_ID = ?;";
          connection.query(query, [hash, loggedInUser], function(error, rows, fields) {
          connection.release();
            if(error){
              console.log(error);
              res.sendStatus(500);
              return;
            }
            res.sendStatus(200);
          });
          } else {
            console.log('bad old password');
            res.sendStatus(401);
          }
        } catch (error) {
          console.log('bad verify');
          res.sendStatus(401);
        }
      });
  });
});



router.get('/searchUsers', function(req, res, next) { //admin search route
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT username FROM Users WHERE username LIKE '%?%';"; //NOT COMPLETE: need containing "search word"
    connection.query(query, [req.body], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      if(rows.length>0){
        console.log(rows, "ah");
        res.json(rows); //return username of user
      }
      else{
        res.sendStatus(401);
      }

    });
  });
});


router.get('/adminViewUser', function(req, res, next) { //account route
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT username, first_name, email FROM Users WHERE username = ?;"; //select username email password from searched user
    console.log(adminSearchedUser,"admin searched user");
    connection.query(query, [adminSearchedUser], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.json(rows);
    });
  });
});



// router.get('/searchEvents', function(req, res, next) { //admin search route
//   req.pool.getConnection(function(error,connection){
//     if(error){
//       console.log(error);
//       res.sendStatus(500);
//       return;
//     }

//     //query needs to be: events.event_name, Users.username inner join ...
//     let query = "SELECT events.event_name, Users.username"; //NOT COMPLETE: need containing "search word"
//     connection.query(query, function(error, rows, fields) {
//       connection.release();
//       if(error){
//         console.log(error);
//         res.sendStatus(500);
//         return;
//       }
//       res.json(rows); //return event name and username of event creator
//     });
//   });
// });

router.get('/isAdmin', function(req, res, next) { //check whether user is admin or not (to display admin buttons)
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }
    let query = "SELECT is_admin FROM Users WHERE user_ID = ?;"; //search the user that is currently logged in
    connection.query(query, [loggedInUser], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      console.log(rows);
      res.json(rows); //return username, first name of user
    });
  });
});


router.post('/makeAdmin', function(req, res, next) { //account info route for admins
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "UPDATE Users SET is_admin = TRUE WHERE user_ID = ?;";
    connection.query(query, [req.body.is_admin, loggedInUser], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.end();
    });
  });
});

router.get('/getEvents', function(req, res, next) { //account.html: getting a list of all events created by user
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT Events.event_ID, Events.event_name FROM Events INNER JOIN Hosts ON Events.event_ID = Hosts.event_ID WHERE Hosts.user_ID = ?;";
    console.log(loggedInUser, "sometext");
    connection.query(query, [loggedInUser], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      console.log(rows);
      res.json(rows);
    });
  });
});


router.get('/getEventsAdmin', function(req, res, next) { //account.html: getting a list of all events created by user
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT Events.event_ID, Events.event_name FROM Events INNER JOIN Hosts ON Events.event_ID = Hosts.event_ID WHERE Hosts.user_ID = ?;";
    console.log(loggedInUser, "sometext admin");
    connection.query(query, [adminSearchedUser], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      console.log(rows);
      res.json(rows);
    });
  });
});

router.get('/isLoggedIn', function(req, res, next) {
  console.log(loginStatus);
  res.send(loginStatus);
});

router.get('/getUsername', function(req, res, next) {
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT username FROM Users WHERE user_id = ?;";
    connection.query(query, [loggedInUser], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.send(rows[0].username);
    });
  });
});

// router.get('/viewEvent', function(req, res, next) { //account.html: getting one specific event
//   req.pool.getConnection(function(error,connection){
//     if(error){
//       console.log(error);
//       res.sendStatus(500);
//       return;
//     }

//     let query = "SELECT Event_member_list.member_name, Member_available_dates.if_available FROM Event_member_list RIGHT JOIN Member_available_dates ON Event_member_list.member_ID = Member_available_dates.member_ID WHERE Event_member_list.event_ID = ?;";
//     connection.query(query, req.body.eventID, function(error, rows, fields) {
//       connection.release();
//       if(error){
//         console.log(error);
//         res.sendStatus(500);
//         return;
//       }

//       currentEvent=rows.insertId;
//       res.json(rows);
//     });
//   });
// });

router.post('/deleteUser', function(req, res, next) {  //account info route for admins
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "delete the user lmao"; //deleteeee the userrrrrrrrr
    //add to req body if need (next line)
    connection.query(query, [req.body.username], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.end();
    });
  });
});

router.post('/eventName', function(req, res, next) {
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }
    var name = req.body.eventname;
    var query = "INSERT INTO Events (event_name) VALUES (?);";
    connection.query(query,[name], function(err, rows, fields) {
      connection.release();
      if (err) {
        console.log(err);
        res.sendStatus(500);
        return;
      }
      currentEvent=rows.insertId; //Need to check if this is correct
      res.end();
    });
});
});

  router.post('/eventDates', function(req, res, next) {
    req.pool.getConnection(function(err,connection) {
      if (err) {
        res.sendStatus(500);
        return;
      }
      var recievedDates = req.body.date;
        var query = "INSERT INTO Dates (selected_date, event_ID) VALUES (?, ?);";
          connection.query(query,[recievedDates, currentEvent], function(err, rows, fields) {
          connection.release();
          if (err) {
            console.log(err);
            res.sendStatus(500);
            return;
          }
          res.end();
        });
  });
  });



// router.get('/hideYou', function(req, res, next) { //event details route that hides the You row if logged in user is the event creator
//   req.pool.getConnection(function(error,connection){
//     if(error){
//       console.log(error);
//       res.sendStatus(500);
//       return;
//     }

//     let query = ""; //check if logged in user is the event creator
//     connection.query(query, function(error, rows, fields) {
//       connection.release();
//       if(error){
//         console.log(error);
//         res.sendStatus(500);
//         return;
//       }
//       res.json(rows);
//     });
//   });
// });

router.get('/getParticipants', function(req, res, next) { //event details route
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    let query = "SELECT Event_member_list.member_name, Member_available_dates.if_available FROM Event_member_list RIGHT JOIN Member_available_dates ON Event_member_list.member_ID = Member_available_dates.member_ID WHERE Event_member_list.event_ID = ?;";
    connection.query(query,[currentEvent], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      console.log(rows, "current event id");
      // currentEvent=rows.insertId;
      res.json(rows);
    });
  });
});

router.post('/sendDates', function(req, res, next) { //event details route
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }

    //query needs to be insert into dates selected_date... users first_name
    //how do dates & username connect??
    let query = "";
    connection.query(query, [req.body.first_name, req.body.selected_dates], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.end();
    });
  });
});

router.get('/linkToUser', function(req, res, next) { //event details route
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }
    //query needs to be Users.first name and Dates.selected dates
    let query = "INSERT INTO Hosts (user_ID, event_ID) VALUES (?,?);";
    connection.query(query,[loggedInUser,currentEvent], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.send("link successful");
    });
  });
});

router.get('/getEventName', function(req, res, next) { //event details route
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }
    //query needs to be Users.first name and Dates.selected dates
    let query = "SELECT Events.event_name FROM Events WHERE Events.event_ID = ?;";
    connection.query(query,[currentEvent], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      console.log(rows);
      res.json(rows);
    });
  });
});

router.get('/isHost', function(req, res, next) { //event details route
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }
    //query needs to be Users.first name and Dates.selected dates
    let query = "SELECT EXISTS(SELECT host_ID FROM Hosts WHERE event_ID = ? AND user_ID = ?);";
    connection.query(query,[currentEvent,loggedInUser], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.json(rows);
    });
  });
});

router.get('/getMonths', function(req, res, next) { //event details route
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }
    //query needs to be Users.first name and Dates.selected dates
    let query = "SELECT MONTH(selected_date) AS month FROM Dates WHERE event_ID = ?;";
    connection.query(query,[currentEvent], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      console.log(rows);
      res.json(rows);
    });
  });
});

router.get('/getDates', function(req, res, next) { //event details route
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }
    //query needs to be Users.first name and Dates.selected dates
    let query = "SELECT DAY(selected_date) AS date, date_ID FROM Dates WHERE event_ID = ?;";
    connection.query(query,[currentEvent], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      for(let i = 0; i < rows.length; i++){
        dateIDS.push(rows[i].date_ID);
      }
      res.json(rows);
    });
  });
});

router.post('/sendEmails', function(req, res, next) {
  req.pool.getConnection(function(err,connection) {
    if (err) {
      res.sendStatus(500);
      return;
    }
    var recievedEmail = req.body.email;
    var available = req.body.avail;
    var final = req.body.fina
      var query = "INSERT INTO Notifications (email,availability_confirmation,if_finalised) VALUES (?,?,?);";
        connection.query(query,[recievedDates, currentEvent], function(err, rows, fields) {
        connection.release();
        if (err) {
          console.log(err);
          res.sendStatus(500);
          return;
        }
        notification = rows.insertId;
        res.end();
      });
});
});

router.post('/sendNames', function(req, res, next) {
  req.pool.getConnection(function(err,connection) {
    if (err) {
      res.sendStatus(500);
      return;
    }
    var recievedName = req.body.name;
      var query = "INSERT INTO Event_member_list (member_name,event_id,notification_ID) VALUES (?,?,?);";
        connection.query(query,[recievedName, currentEvent, notification], function(err, rows, fields) {
        connection.release();
        if (err) {
          console.log(err);
          res.sendStatus(500);
          return;
        }
        memberId = rows.insertId;
        res.end();
      });
});
});

router.post('/sendSelected', function(req, res, next) {
  req.pool.getConnection(function(err,connection) {
    if (err) {
      res.sendStatus(500);
      return;
    }
    var recievedData = req.body.ifDates;
    var num = req.body.id;
      var query = "INSERT INTO Member_available_dates (member_ID,date_id,if_available) VALUES (?,?,?);";
        connection.query(query,[memberId,dateIDS[num],recievedData], function(err, rows, fields) {
        connection.release();
        if (err) {
          console.log(err);
          res.sendStatus(500);
          return;
        }
        res.end();
      });
});
});

router.get('/getEmails', function(req, res, next) { //event details route
  req.pool.getConnection(function(error,connection){
    if(error){
      console.log(error);
      res.sendStatus(500);
      return;
    }
    //query needs to be Users.first name and Dates.selected dates
    let query = "SELECT Notifications.email FROM Notifications INNER JOIN Event_member_list ON Notifications.notification_ID = Event_member_list.notification_ID WHERE event_ID = ?;";
    connection.query(query,[currentEvent], function(error, rows, fields) {
      connection.release();
      if(error){
        console.log(error);
        res.sendStatus(500);
        return;
      }
      res.json(rows);
    });
  });
});

router.post('/eventID', function(req, res, next) { //assign current event to the one user clicks on
    currentEvent=req.body.eventID;
    console.log(currentEvent,"currentEvent");
    res.end();
});

module.exports = router;