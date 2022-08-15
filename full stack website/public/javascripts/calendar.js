mobiscroll.setOptions({
    theme: 'ios',
    themeVariant: 'light'
});

var selectedDates = mobiscroll.datepicker('#demo-multi-day', {
    controls: ['calendar'],
    display: 'inline',
    selectMultiple: true,
    onChange: function (event, inst) {
        updateValue('returnVal', inst);
    }
});

var dates;
const months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

//var finalMonths = [];
//var finalDates = [];

function updateValue(id, inst) {
setTimeout(function() {
if (id == 'returnMoment') {
    document.getElementById(id).innerHTML = inst.getVal().format();
} else {
    dates= inst.getVal();
    let text = "";
    for (let i = 0; i < dates.length; i++) {
        dates.sort((a,b)=> a-b);
        text += "<div>" + "<p>" +dates[i].getFullYear()+'/'+(dates[i].getMonth()+1)+'/'+dates[i].getDate();+ "</p>" + "</div>";
        //finalMonths[i] = months[dates[i].getMonth()];
        //finalDates[i] = dates[i].getDate();
        dates[i] = dates[i].getFullYear() + '-' +
        ('00' + (dates[i].getMonth()+1)).slice(-2) + '-' +
        ('00' + dates[i].getDate()).slice(-2) + ' ' +
        ('00' + dates[i].getHours()).slice(-2) + ':' +
        ('00' + dates[i].getMinutes()).slice(-2) + ':' +
        ('00' + dates[i].getSeconds()).slice(-2);
    }
    document.getElementById(id).innerHTML = text;
    //var monthsAndCount = {};
    //finalMonths.forEach(function(i) { monthsAndCount[i] = (monthsAndCount[i]||0) + 1;});
    //console.log(monthsAndCount);
}
});
}

var sendDateRes;
var sendNameRes;

function sendEventDates(i){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        }
    };
    xhttp.open("POST", "/eventDates", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    var selected = dates[i]
    xhttp.send(JSON.stringify({date:selected}));
}

function sendEventName(){
    var name = document.getElementById("eventName").value;
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            for (let i = 0; i < dates.length; i++) {
                sendEventDates(i);
            }
            linkToUser();
            create();
        }
    };
    xhttp.open("POST", "/eventName", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send(JSON.stringify({eventname:name}));
}

function create(){
    alert("Event Created Successful");
    window.location.replace("eventDetails.html");
}

function linkToUser(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) { //3. store response
        console.log(this.responseText);
      }
    };
    xhttp.open("GET", "/linkToUser", true); //2. sends a request to the route /isAdmin
    xhttp.send();
}

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