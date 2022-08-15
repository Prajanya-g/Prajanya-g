var loginStatus = true;
var isAdmin = false;
var currentUsername;
var currentFirstName;
var currentEmail;
var currentPassword;
var oldPassword;
var newPassword;
var confirmPassword;

function admin() { //function should run onload (is called by the get_list function, which also runs onload)
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) { //3. store response
      var json = JSON.parse(this.responseText);
      var isAdmin = json[0].is_admin;
      if(isAdmin == true){
          document.getElementById("navAdmin").style.display="block";
      }
    }
  };
  xhttp.open("GET", "/isAdmin", true); //2. sends a request to the route /isAdmin
  xhttp.send();
}

var userInfo = [];

function get_list(){ //1. the function loads as soon as user redirects to /account.html
    admin(); //also run admin check function on pageload
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) { //3. take response and store in array
        var userInfo = JSON.parse(this.responseText);
        document.getElementById("firstName").value = userInfo[0].first_name;
        document.getElementById("username").value = userInfo[0].username; //4. hopefully this puts current user info in the input boxes in account page
        document.getElementById("email").value = userInfo[0].email;
        document.getElementById("password").value = userInfo[0].password;

        // currentFirstName=document.getElementById("firstName").value;
        // currentUsername=document.getElementById("username").value;
        // currentEmail=document.getElementById("email").value;
        // currentPassword= document.getElementById("password").value;
      }
    };
    xhttp.open("GET", "/account", true); //2. sends a request to the route /account
    xhttp.send();

    getEvents(); //also get events of the user
}

//buttons
var e = document.getElementById("edit");
var s = document.getElementById("submit");
var c = document.getElementById("cancel");
var pb = document.getElementById("pswdChange");

//divs
var p = document.getElementById("normalPassword");
var pc = document.getElementById("changePassword");

function showConfirmButton() { //shows confirm button if edit info button is clicked, vice versa. also show confirm password
  if (e.style.display === "none") {
    e.style.display = "block";
    pb.style.display = "block";
    s.style.display = "none";
    c.style.display = "none";
    p.style.display = "block";
    pc.style.display = "none";
    document.getElementById("firstName").readOnly=true;
    document.getElementById("email").readOnly=true;
  }
  else {
    e.style.display = "none";
    pb.style.display = "none";
    s.style.display = "block";
    c.style.display = "block";
    document.getElementById("firstName").readOnly=false;
    document.getElementById("email").readOnly=false;
  }

}

function pswd() {
  document.getElementById("oldPassword").value="";
  document.getElementById("newPassword").value="";
  document.getElementById("confirmPassword").value="";
  pc.style.display = "block";
  pb.style.display = "none";
  p.style.display = "none";
  showConfirmButton();
}


function cancel() {
  // location.reload();
  get_list();
  showConfirmButton();
}

function sendInfo() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      alert("User info successfully updated!");
      }
    };

  xhttp.open("POST", "/changeInfo", true); //send change info request to database
  xhttp.setRequestHeader("Content-type", "application/json");
  xhttp.send(JSON.stringify({first_name: document.getElementById("firstName").value, email: document.getElementById("email").value}));

}

function send(){
  if(pc.style.display == "none") { //if changing user info (not password)
    if(document.getElementById("firstName").value.length == 0) {
      alert("First name can't be blank!");
      get_list();
    }
    else {
        var input = document.getElementById("email").value;
        var emailformat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
        if(input.match(emailformat)){
          sendInfo();
        }
        else{
            alert("Please enter email in the correct format!");
            get_list();
        }
    }
  }
  else { //if changing password
    var newPassword = document.getElementById("newPassword").value;
    if ((newPassword.length >= 6) && (newPassword.length <= 256) && (/[0-9]/.test(newPassword) == 1) && (/[a-zA-Z]/.test(newPassword) == 1)){
      confirmPassword = document.getElementById("confirmPassword").value;
      if (newPassword === confirmPassword){
        oldPassword = document.getElementById("oldPassword").value;
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              alert("Password successfully updated!");
              }
            else if(this.readyState == 4 && this.status == 401){
              alert("Incorrect old password!");
            }
          };

        xhttp.open("POST", "/changePswd", true); //send change info request to database
        xhttp.setRequestHeader("Content-type", "application/json");
        xhttp.send(JSON.stringify({oldPassword: oldPassword, newPassword: newPassword}));
      }
      else{
        alert("Please correctly confirm your new password!");
      }
    }
    else{
      alert("Your new password does not meet the requirements! Please try again. Reminder: Passwords are required to be 6 to 256 characters long and have to include at least one letter and one number.");
    }
  }

  e.style.display = "block";
  s.style.display = "none";
  c.style.display = "none";
  p.style.display = "block";
  pc.style.display = "none";
  pb.style.display = "block";
}

// function confirmMakeAdmin() {
//   let text = "Are you sure you want to make this user Admin?\nThis action is irreversible.";
//   if (confirm(text) == true) {
//     makeAdmin();
//   }
// }

// function confirmDeleteAcc() {
//   let text = "Are you sure you want to permanently delete this account?\nThis action is irreversible.";
//   if (confirm(text) == true) {
//     deleteUser();
//   }
// }


// //im making these functions with the assumption that isAdmin will update to true in admin() (see above)
// function makeAdmin(){

//   var xhttp = new XMLHttpRequest();
//   xhttp.onreadystatechange = function() {
//     if (this.readyState == 4 && this.status == 200) {
//       }
//     };

//   xhttp.open("POST", "/makeAdmin", true);
//   xhttp.setRequestHeader("Content-type", "application/json");
//   xhttp.send(JSON.stringify({is_admin: isAdmin}));

// }

// function deleteUser(){

//   var xhttp = new XMLHttpRequest();
//   xhttp.onreadystatechange = function() {
//     if (this.readyState == 4 && this.status == 200) {
//       }
//     };

//   xhttp.open("POST", "/deleteUser", true);
//   xhttp.setRequestHeader("Content-type", "application/json");
//   xhttp.send();

// }

function togglePassword() {
  var x = document.getElementById("changePassword");
  if (x.style.display === "none") {
    x.style.display = "block";
  } else {
    x.style.display = "none";
  }
}


// function hidePassword() { //if admin, hide user password
//   if(isAdmin==true) {
//     password.style.visibility="hidden";
//   }
// }
//log out function
function log_out(){
  //try google log out if it is a google sign in account
  try{
      var auth2 = gapi.auth2.getAuthInstance();
      auth2.signOut().then(function () {
      loginStatus = false;
      alert("Logout Successful");
      console.log('User signed out of Google.');
  });
  }
  catch(error){
  };
  //send log out request if it is a normal account, redirect to home page if successful
  let xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function () {
      if (this.readyState == 4 && this.status == 200) {
          alert("Logout Successful");
          loginStatus = false;
          window.location.replace("index.html");
      }
  };
  xhttp.open("POST", "/logout");
  xhttp.send();
}

var eventList = [];
function getEvents(){ //executes onload with get_list(),

    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        eventList = JSON.parse(this.responseText);
        console.log(eventList);
        for (var i = 0; i < eventList.length; i++) {
            var list = document.getElementById("events");
            var newDiv = document.createElement("div");
            newDiv.setAttribute('class', 'eventBox');
            var eventName = document.createElement("h2");
            eventName.setAttribute('class', 'boxHeading');
            eventName.innerHTML = eventList[i].event_name;
            newDiv.appendChild(eventName);

            var button = document.createElement("button");
            button.innerHTML = "VIEW EVENT";
            button.id = eventList[i].event_ID;
            button.setAttribute('class', 'submitButton');

            // button.setAttribute('value', i);
            // var buttonValue = document.getElementById("button").value;
            // var buttonValue = button.clicked.value;

            // var eventID = eventList[i].event_ID;
            // console.log(eventID, "page load");

            console.log(button.id, "button id on load");

            // button.onclick=()=>{
            //   // document.getElementById("button");
            //   // console.log(this.id, "button id");
            //   viewAnEvent(this.id);

            // };

            button.onclick = function(event) {
              viewAnEvent(this.id)
           }

            // button.onclick = viewAnEvent(this.id);

            newDiv.appendChild(button);
            list.appendChild(newDiv);

        }
      }
    };

    xhttp.open("GET", "/getEvents", true);
    xhttp.send();

}

function viewAnEvent(eventID) { // view specific event
  console.log(eventID, "view event");

  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      window.location.replace("eventDetails.html?event_ID="+eventID);
    }
  };

  xhttp.open("POST", "/eventID", true);
  xhttp.send();

}


console.log(currentUsername);
console.log(currentFirstName);
console.log(currentEmail);
console.log(currentPassword);
console.log(isAdmin);