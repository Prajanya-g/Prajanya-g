var loginStatus = true;
var isAdmin = false;
var currentUsername;
var currentFirstName;
var currentEmail;
var currentPassword;
var oldPassword;
var newPassword;
var confirmPassword;

var body = document.getElementById("body");
// admin check
function admin() { //function should run onload (is called by the get_list function, which also runs onload)
  var body = document.getElementById("body");
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) { //3. store response
      var json = JSON.parse(this.responseText);
      console.log(json, "admin status");
      admin = json[0].is_admin;
      if (admin == true) {
        body.style.display="block";
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
        console.log(userInfo,"userInfo");
        document.getElementById("firstName").value = userInfo[0].first_name;
        document.getElementById("username").value = userInfo[0].username; //4. hopefully this puts current user info in the input boxes in account page
        document.getElementById("email").value = userInfo[0].email;
      }
    };
    xhttp.open("GET", "/adminViewUser", true); //2. sends a request to the route /account
    xhttp.send();

    getEvents(); //also get events of the user
}

//buttons
var e = document.getElementById("edit");
var s = document.getElementById("submit");
var c = document.getElementById("cancel");

function showConfirmButton() { //shows confirm button if edit info button is clicked, vice versa. also show confirm password
  if (e.style.display === "none") {
    e.style.display = "block";
    s.style.display = "none";
    c.style.display = "none";
    document.getElementById("firstName").readOnly=true;
    document.getElementById("email").readOnly=true;
  }
  else {
    e.style.display = "none";
    s.style.display = "block";
    c.style.display = "block";
    document.getElementById("firstName").readOnly=false;
    document.getElementById("email").readOnly=false;
  }

}

function cancel() {
  // location.reload();
  get_list();
  showConfirmButton();
}

function send(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        }
      };

    xhttp.open("POST", "/changeInfoAdmin", true); //send change info request to database
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send(JSON.stringify({first_name: firstName, email: email}));

  e.style.display = "block";
  s.style.display = "none";
  c.style.display = "none";

}

function confirmMakeAdmin() {
  let text = "Are you sure you want to make this user Admin?\nThis action is irreversible.";
  if (confirm(text) == true) {
    makeAdmin();
  }
}

function confirmDeleteAcc() {
  let text = "Are you sure you want to permanently delete this account?\nThis action is irreversible.";
  if (confirm(text) == true) {
    deleteUser();
  }
}


//im making these functions with the assumption that isAdmin will update to true in admin() (see above)
function makeAdmin(){

  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      }
    };

  xhttp.open("POST", "/makeAdmin", true);
  xhttp.setRequestHeader("Content-type", "application/json");
  xhttp.send(JSON.stringify({is_admin: isAdmin}));

}

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

function logout(){
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
            // eventName.setAttribute('class', 'inline');
            eventName.innerHTML = eventList[i].event_name;
            newDiv.appendChild(eventName);

            var button = document.createElement("button");
            button.innerHTML = "VIEW EVENT";
            button.id = eventList[i].event_ID;
            button.setAttribute('class', 'submitButton');

            console.log(button.id, "button id on load");

            button.onclick = function(event) {
              viewAnEvent(this.id)
           }

            newDiv.appendChild(button);
            list.appendChild(newDiv);

        }
      }
    };

    xhttp.open("GET", "/getEventsAdmin", true);
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