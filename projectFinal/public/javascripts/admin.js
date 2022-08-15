var admin = false;

function isAdmin() { //function should run onload (is called by the get_list function, which also runs onload)
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

// function admin() { //function should run onload (is called by the get_list function, which also runs onload)
//   var xhttp = new XMLHttpRequest();
//   xhttp.onreadystatechange = function() {
//     if (this.readyState == 4 && this.status == 200) { //3. store response
//       var json = JSON.parse(this.responseText);
//       var isAdmin = json[0].is_admin;
//       if(isAdmin == true){
//           document.getElementById("navAdmin").style.display="block";
//       }
//     }
//   };
//   xhttp.open("GET", "/isAdmin", true); //2. sends a request to the route /isAdmin
//   xhttp.send();
// }

// var userArray = [];
// var searchBar = document.getElementById("userNameSearch").value;
// function searchUsers(){ //dynamically makes a new row for every search result found.

//   let xhttp = new XMLHttpRequest();

//   xhttp.onreadystatechange = function () {
//       if (this.readyState == 4 && this.status == 200) {
//         userArray = JSON.parse(this.responseText);
//           for (var i = 0; i < userArray.length; i++) {
//               var list = document.getElementById("userAccounts");
//               var newRow = document.createElement("tr");
//               var userArray_username = document.createElement("td");
//               userArray_username.setAttribute("id", "username");
//               var button = document.createElement("button");
//               button.innerHTML = "VIEW";
//               userArray_username.innerHTML = userArray[i].username;
//               newRow.appendChild(userArray_username);
//               var userArray_first_name = document.createElement("td");
//               userArray_first_name.setAttribute("id", "firstName");
//               userArray_first_name.innerHTML = userArray[i].first_name;
//               newRow.appendChild(userArray_first_name);
//               list.appendChild(newRow);
//               newRow.appendChild(button);
//               //TO EDIT: admin should not be able to edit or view user password
//               button.onclick = getUser();
//           }
//       }
//       //user does not exist
//       else if (this.readyState == 4 && this.status == 401) {

//       }
//   };
//   xhttp.open("POST", "/searchUser");
//   xhttp.setRequestHeader("Content-type", "application/json");
//   xhttp.send(searchBar);
// }


    // xhttp.open("GET", "/searchUsers", true);
    // xhttp.send();

// }



var userList = [];
function getUsers(){
    document.getElementById("users").innerHTML = ""; //clear out previous search results first
    var searchBar = document.getElementById("userNameSearch").value;
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        userList = JSON.parse(this.responseText);
        console.log(userList);
        for (var i = 0; i < userList.length; i++) {
            var list = document.getElementById("users");
            var newDiv = document.createElement("div");
            newDiv.setAttribute('class', 'eventBox');
            var username = document.createElement("h2");
            username.setAttribute('class', 'boxHeading');
            username.innerHTML = userList[i].username;
            newDiv.appendChild(username);

            var button = document.createElement("button");
            button.innerHTML = "VIEW USER";
            button.id = userList[i].username;
            button.setAttribute('class', 'submitButton');

            console.log(button.id, "username");


            button.onclick = function(user) {
              viewAUser(this.id)
           }

            newDiv.appendChild(button);
            list.appendChild(newDiv);

        }
      }
    };

    xhttp.open("GET", "/searchUsers", true);
    xhttp.send(searchBar);

}

function viewAUser(username) { // view specific event
  console.log(username, "view user"); //correct name

  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      window.location.replace("adminViewUser.html?username="+username);
    }
  };

  xhttp.open("POST", "/usernameSearched", true);
  xhttp.send();

}

// function getUser(){ //1. the function loads as soon as user redirects to /account.html

//   var xhttp = new XMLHttpRequest();
//   xhttp.onreadystatechange = function() {
//     if (this.readyState == 4 && this.status == 200) { //3. take response and store in array
//       window.location.replace("adminViewUser.html");
//     }
//   };
//   xhttp.open("GET", "/adminViewUser", true); //2. sends a request to the route /account
//   xhttp.send();
// }