var currentSelected = [];

function loading(){
  ishost();
  getEventDetails();
  displayMonths();
  displayDates();
  currentParticipants();
}

var finaliseButton = document.getElementById("hostButton");
function ishost(){
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) { //3. store response
      var json = JSON.parse(this.responseText);
      var host = json[0].is_host;
      if(host == true){
        finaliseButton.style.display = "block";
      }
      else{
        finaliseButton.style.display = "none";
      }
    }
  };
  xhttp.open("GET", "/isHost", true); //2. sends a request to the route /isAdmin
  xhttp.send();
}

function currentParticipants(){
    var participants={};
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        participants = JSON.parse(this.responseText);
    }
    };
    xhttp.open("GET", "/getParticipants", true);
    xhttp.send();
    if(participants.length === undefined){
    }
    else{
        displayParticipants(participants);
    }
}

var monthTable = document.getElementById("months");
function displayMonths(){
  var blank = document.createElement('th');
blank.innerHTML = "&nbsp;";
monthTable.appendChild(blank);
    var numberMonths = [];
    var monthsAndCount = {};
              var xhttp = new XMLHttpRequest();
              xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) { //3. store response


                  var temp = JSON.parse(this.responseText);
                  for(let i = 0; i < temp.length; i++){
                      numberMonths.push(temp[i].month);
                  }
                  numberMonths.forEach(function(i) { monthsAndCount[i] = (monthsAndCount[i]||0) + 1;});
                  const nameMonths = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
                  var num = Object.getOwnPropertyNames(monthsAndCount);
                  var final1 =[];
                  var final2 = [];
                  for(let i = 0; i < num.length; i++){
                      final1.push(nameMonths[num[i]-1]);
                  }
                  for(const key in monthsAndCount){
                      final2.push(monthsAndCount[key]);
                  }
                  for(let i = 0; i < final1.length; i++){
                    let newMonth = document.createElement('th');
                    newMonth.setAttribute("id", "month");
                    newMonth.innerHTML = final1[i];
                    newMonth.colSpan = final2[i];
                    monthTable.appendChild(newMonth);
                }
                }
              };
              xhttp.open("GET", "/getMonths", true); //2. sends a request to the route /isAdmin
              xhttp.send();
}

var dateTable = document.getElementById("dates");

function  displayDates(){
  var blank = document.createElement('th');
  blank.innerHTML = "&nbsp;";
  dateTable.appendChild(blank);
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) { //3. store response
      var temp = JSON.parse(this.responseText);
      var final3 = [];
      for(let i = 0; i < temp.length; i++){
          final3.push(temp[i].date);
      }
      for(let i = 0; i < final3.length; i++){
        let newDate = document.createElement('th');
        newDate.innerHTML = final3[i];
        console.log(final3[i]);
        dateTable.appendChild(newDate);
        currentSelected.push(false);
      }
      displayInsert(final3);
    }
  };
  xhttp.open("GET", "/getDates", true); //2. sends a request to the route /isAdmin
  xhttp.send();
}
var eventNameDisplay = document.getElementById("eventName");
function getEventDetails(){
  var xhttp = new XMLHttpRequest();
  var display;
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) { //3. store response
      var json = JSON.parse(this.responseText);
      eventNameDisplay.innerHTML = json[0].event_name;
    }
  };
  xhttp.open("GET", "/getEventName", true); //2. sends a request to the route /isAdmin
  xhttp.send();
}

var table = document.getElementById("table");

function displayParticipant(participants){
  var currentName = participants[0].member_name;
  var boolDates = [];
  var obj={};
  var newRow = document.createElement('tr');
  var newName= document.createElement('td');
  newName.innerHTML = currentName;
  cosole.log(currentName);
  newRow.appendChild(newName);
  for(let i = 0; i < participants.length; i++){
      if(participants[i].member_name == currentName){
          boolDates.push(participants[i].if_available);
          let newDate = document.createElement('td');
          newDate.innerHTML = participants[i].if_available;
          cosole.log(participants[i].if_available);
          newRow.appendChild(newDate);
      }
      else{
          table.appendChild(newRow);
          obj['name'] = currentName;
          currentName = participants[i].member_name;
          obj['selected'] = boolDates;
          boolDates =[];
          newRow = document.createElement('tr');
          newName= document.createElement('td');
          newName.innerHTML = currentName;
          console.log(currentName);
          newRow.appendChild(newName);
      }
  }
}

var newPerson = document.getElementById("you");
function displayInsert(date){
    var name = document.createElement('td');
    name.setAttribute("class", "nameInput");
    const input = document.createElement("input");
    input.setAttribute("type", "text");
    input.setAttribute("id", "inputName");
    input.setAttribute("class", "nameInput");
    input.setAttribute("value", "EnterName");
    name.appendChild(input);
    newPerson.appendChild(name);
    for(let i =0; i < date.length;i++){
      const button = document.createElement('td');
      button.setAttribute("class", "yourDates");
      const image = document.createElement('img');
      image.setAttribute("src", "/images/greenTick.png");
      image.setAttribute("id", "tick");
      image.setAttribute("class", "tick1");
      image.setAttribute("value",i);
      image.setAttribute("onclick", "changef(this.bvalue)");
      image.style.display="none";
      button.appendChild(image);
      const but = document.createElement('button');
      but.setAttribute("value",i);
      but.setAttribute("class","but")
      but.setAttribute("onclick", "changet(this.bvalue)");
      button.appendChild(but);
      newPerson.appendChild(button);
    }
}

function sendParticipant(){
    sendEmail();
}

var emailInput = document.getElementById("memberEmail").value;
var check1 = document.getElementById("available").value;
var check2 = document.getElementById("finalised").value;
function sendEmail(){
    for(let i = 0; i < currentDates.length; i++){
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              sendName();
            }
        };
        xhttp.open("POST", "/sendEmails", true);
        xhttp.setRequestHeader("Content-type", "application/json");
        var selected = emailInput;
        var input = check1;
        var input2 =check2;
        xhttp.send(JSON.stringify({email:selected,avail:input,fina: input2 }));
    }

}


function sendName(){
  var nameGot = document.getElementById("inputName").value;
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        sendDates();
      }
  };
  xhttp.open("POST", "/sendNames", true);
  xhttp.setRequestHeader("Content-type", "application/json");
  var selected = nameGot;
  xhttp.send(JSON.stringify({name:selected}));
}

var currentDates = document.getElementById('dates').cells.length;
function sendDates(){
      for(let i = 0; i < currentDates.length; i++){
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function() {
              if (this.readyState == 4 && this.status == 200) {
              }
          };
          xhttp.open("POST", "/sendSelected", true);
          xhttp.setRequestHeader("Content-type", "application/json");
          var selected = currentSelected[i];
          xhttp.send(JSON.stringify({ifDates:selected, id: i}));
      }
      currentSelected=[];
  }

function finalised(){
    getEmails();
}

function getEmails(){
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
  if (this.readyState == 4 && this.status == 200) {
      var emails = JSON.parse(this.responseText);
      sendEmails(emails);
  }
  };
  xhttp.open("GET", "/getEmails", true);
  xhttp.send();
}

function  sendEmails(){
  //??
}

// n onclick="dosomething(this.value)">
function changet(n){
  var newArray = [];
  const but = document.getElementsByClassName("but");
  but[n].style.display = "none";
  const img = document.getElementsByClassName("tick1");
  but[n].style.display = "block";
  for(let i = 0; i < this.currentSelected.length; i++){
      if(i == n){
          newArray.push(true);
      }
      else{
          newArray.push(this.currentSelected[i]);
      }
  }
  this.currentSelected= newArray;
}

function changef(n){
  var newArray = [];
  const but = document.getElementsByClassName("but");
  but[n].style.display = "block";
  const img = document.getElementsByClassName("tick1");
  img[n].style.display = "none";
  for(let i = 0; i < this.currentSelected.length; i++){
      if(i == n){
          newArray.push(false);
      }
      else{
          newArray.push(this.currentSelected[i]);
      }
  }
  this.currentSelected = newArray;
}