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

  // admin check
function admin() { //function should run onload (is called by the get_list function, which also runs onload)
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) { //3. store response
        var json = JSON.parse(this.responseText);
        var isAdmin = json[0].is_admin;
        console.log(isAdmin);
        if(isAdmin == true){
          document.getElementById("navAdmin").style.display="block";
        }
        else{
          document.getElementById("navAdmin").style.display="none";
        }
      }
    };
    xhttp.open("GET", "/isAdmin", true); //2. sends a request to the route /isAdmin
    xhttp.send();
  }

  function getLoginStatus() { //function should run onload (is called by the get_list function, which also runs onload)
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) { //3. store response
        loginStatus = JSON.parse(this.responseText);
        buttons(loginStatus);
      }
    };
    xhttp.open("GET", "/isLoggedIn", true); //2. sends a request to the route /isAdmin
    xhttp.send();
  }

  function greeting() { //function should run onload (is called by the get_list function, which also runs onload)
    var currentUsername;
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) { //3. store response
        currentUsername = this.responseText;
      }
    };
    xhttp.open("GET", "/getUsername", true); //2. sends a request to the route /isAdmin
    xhttp.send();
    console.log(currentUsername);
    if(currentUsername != null){
      document.getElementById("greeting").innerHTML="Hi, " + currentUsername + "!";
    }
  }

  function buttons(loginstatus){
    if(loginstatus==false){
      document.getElementById("login").style.display="block";
      document.getElementById("loginPlan").style.display="block";
      document.getElementById("create").style.display="none";
      document.getElementById("createPlan").style.display="none";
      document.getElementById("navLogin").style.display="block";
      document.getElementById("navSignup").style.display="block";
      document.getElementById("navLogout").style.display="none";
      document.getElementById("navAccount").style.display="none";
      document.getElementById("navAdmin").style.display="none";
      document.getElementById("greeting").style.display="none";
    }
    else{
      admin();
      greeting();
      document.getElementById("login").style.display="none";
      document.getElementById("loginPlan").style.display="none";
      document.getElementById("create").style.display="block";
      document.getElementById("createPlan").style.display="block";
      document.getElementById("navLogin").style.display="none";
      document.getElementById("navSignup").style.display="none";
      document.getElementById("navAccount").style.display="block";
    }
  }
