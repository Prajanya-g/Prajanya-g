var vueinst = new Vue({
    el: '#loginPage',
    data: {
        login401: false,
        signup403: false,
        invalid_username: false,
        invalid_first_name: false,
        invalid_email: false,
        invalid_password: false,
        user: {},
    },
    methods: {
        //login function
        log_in: function() {
            user = {
                username: document.getElementById('loginUsername').value,
                password: document.getElementById('loginPassword').value
            };

            let xhttp = new XMLHttpRequest();
            var vm = this;

            xhttp.onreadystatechange = function () {
                //if login successful, redirect to account page
                if (this.readyState == 4 && this.status == 200) {
                    alert("Login Successful");
                    window.location.replace("account.html");
                }
                //incorrect username or password
                else if (this.readyState == 4 && this.status == 401) {
                    vm.login401 = true;
                }
                //bad request
                else if (this.readyState == 4 && this.status == 400) {
                    alert("Unexpected Login Fail");
                }
            };
            xhttp.open("POST", "/login");
            xhttp.setRequestHeader("Content-type", "application/json");
            xhttp.send(JSON.stringify(user));
        },
        //check username format
        check_valid_username: function(){
            var input = document.getElementById("signUpUsername").value;
            var letters = /[a-zA-Z]/g;

            if ((input.length >= 5) && (letters.test(input.charAt(0)) == 1)){
                this.invalid_username = false;
            }
            else{
                this.invalid_username = true;
            }
        },
        //check first name to be not NULL
        check_valid_first_name: function(){
            var input = document.getElementById("signUpFirstName").value;
            if (input.length >= 1){
                this.invalid_first_name = false;
            }
            else{
                this.invalid_first_name = true;
            }
        },
        //check email format
        check_email: function(){
            var input = document.getElementById("signUpEmail").value;
            var emailformat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
            if(emailformat.test(input)){
                this.invalid_email = false;
            }
            else{
                this.invalid_email = true;
            }
        },
        //check password format
        check_valid_password: function(){
            var input = document.getElementById("signUpPassword").value;
            if ((input.length >= 6) && (input.length <= 256) && (/[0-9]/.test(input) == 1) && (/[a-zA-Z]/.test(input) == 1)){
                this.invalid_password = false;
            }
            else{
                this.invalid_password = true;
            }
        },
        //sign up function
        sign_up: function(){
            if ((this.invalid_username == false) && (this.invalid_password == false) && (this.invalid_email == false) && (this.invalid_first_name == false)){
                user = {
                    username: document.getElementById('signUpUsername').value,
                    firstname: document.getElementById('signUpFirstName').value,
                    email: document.getElementById('signUpEmail').value,
                    password: document.getElementById('signUpPassword').value
                };

                let xhttp = new XMLHttpRequest();
                var vm = this;

                xhttp.onreadystatechange = function () {
                    //if sign up successful, redirect to account page
                    if (this.readyState == 4 && this.status == 200) {
                        alert("Sign Up Successful");
                        window.location.replace("account.html");
                    }
                    //username already exists
                    else if (this.readyState == 4 && this.status == 403) {
                        vm.signup403 = true;
                    }
                    //user not appearing in the database
                    else if (this.readyState == 4 && this.status == 401) {
                        alert("Sign Up Fail");
                    }
                    //bad request
                    else if (this.readyState == 4 && this.status == 400) {
                        alert("Unexpected Sign Up Fail");
                    }
                };
                xhttp.open("POST", "/signup");
                xhttp.setRequestHeader("Content-type", "application/json");
                xhttp.send(JSON.stringify(user));
            }
    },
    }
});

//google sign in function
function onSignIn(googleUser) {
    var id_token = googleUser.getAuthResponse().id_token;
    let xhttp = new XMLHttpRequest();
    var vm = this;

    xhttp.onreadystatechange = function () {
        //sign in successful, redirect to account page
        if (this.readyState == 4 && this.status == 200) {
            alert("Login Successful");
            window.location.replace("account.html");
        }
        //user not appearing in the database
        else if (this.readyState == 4 && this.status == 401) {
            vm.login401 = true;
        }
        //bad request
        else if (this.readyState == 4 && this.status == 400) {
            alert("Unexpected Login Fail");
        }
    };
    xhttp.open("POST", "/login");
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send(JSON.stringify({token: id_token}));
  }