--Create in this order (top --> bottom) for it to work so tables can link properly
--//mysql --host=127.0.0.1

--WRITTEN BY EL THE ENIGMATIC


--THESE ARE THE CURRENT COMMANDS BEFORE THE LINE
----------------------------------------------------------------
--⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
--⠄⠄⠄⠄⠄⠄⠄⣀⣀⣐⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
--⠄⠄⢠⠄⣠⣶⣿⣿⣿⠿⠿⣛⣂⣀⣀⡒⠶⣶⣤⣤⣬⣀⡀⠄⢀⠄⠄⠄⠄⠄⠄⠄
--⠄⠄⢀⣾⣿⣿⣿⡟⢡⢾⣿⣿⣿⣿⣿⣿⣶⣌⠻⣿⣿⣿⣿⣷⣦⣄⡀⠄⠄⠄⠄⠄
--⠄⠄⣈⣉⡛⣿⣿⣿⡌⢇⢻⣿⣿⣿⣿⣿⠿⠛⣡⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⠄⠄⠄
--⠄⠺⠟⣉⣴⡿⠛⣩⣾⣎⠳⠿⠛⣋⣩⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠄⠄
--⠄⠄⠄⠘⢋⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠄
--⠄⠄⢀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠄
--⠄⠄⠄⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⣀
--⠄⠄⠄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠘⠛
--⠄⠄⠄⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠋⣀⣀⣠⣤
--⠄⠄⣀⣀⡙⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢛⣩⠤⠾⠄⠛⠋⠉⢉
--⠄⠺⠿⠛⠛⠃⠄⠉⠙⠛⠛⠻⠿⠿⠿⠟⠛⠛⠛⠉⠁⠄⠄⣀⣀⣠⣤⣠⣴⣶⣼⣿
----------------------------------------------------------------
--NEW SQL COMMANDS for UPDATED SCHEMA

CREATE TABLE Users (
    user_ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    username varchar(63) UNIQUE,
    first_name varchar(63) NOT NULL,
    email varchar(63) NOT NULL,
    user_password varchar(200),
    is_admin BOOLEAN NOT NULL DEFAULT FALSE,
    google_ID varchar(63) UNIQUE,
    PRIMARY KEY (user_ID)
);

CREATE TABLE Events(
    event_ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    event_name varchar(63) NOT NULL,
    finalised_date DATE DEFAULT NULL,
    is_finalised BOOLEAN NOT NULL DEFAULT FALSE,
    PRIMARY KEY (event_ID)
);

CREATE TABLE Dates(
    date_ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    selected_date DATE NOT NULL,
    event_ID INT UNSIGNED NOT NULL,
    PRIMARY KEY (date_ID),
    FOREIGN KEY (event_ID) REFERENCES Events(event_ID)
);

CREATE TABLE Notifications(
    notification_ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    email varchar(63),
    availability_confirmation BOOLEAN NOT NULL DEFAULT FALSE,
    if_finalised BOOLEAN NOT NULL DEFAULT FALSE,
    PRIMARY KEY (notification_ID)
);

CREATE TABLE Hosts(
    host_ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    user_ID INT UNSIGNED NOT NULL,
    event_ID INT UNSIGNED NOT NULL,
    PRIMARY KEY (host_ID),
    FOREIGN KEY (user_ID) REFERENCES Users(user_ID),
    FOREIGN KEY (event_ID) REFERENCES Events(event_ID)
);

CREATE TABLE Event_member_list(
    member_ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    member_name varchar(63) NOT NULL,
    event_ID INT UNSIGNED NOT NULL,
    notification_ID INT UNSIGNED NOT NULL,
    PRIMARY KEY (member_ID),
    FOREIGN KEY (event_ID) REFERENCES Events(event_ID),
    FOREIGN KEY (notification_ID) REFERENCES Notifications(notification_ID)
);

CREATE TABLE Member_available_dates(
    member_ID INT UNSIGNED NOT NULL,
    date_ID INT UNSIGNED NOT NULL,
    if_available BOOLEAN NOT NULL DEFAULT FALSE,
    FOREIGN KEY (member_ID) REFERENCES Event_member_list(member_ID),
    FOREIGN KEY (date_ID) REFERENCES Dates(date_ID)
);

--QUERIES FOR SISI THE SINISTER

--/account
--username, first name, email, password
SELECT username, first_name, email, user_password FROM Users WHERE user_ID = ?;


--/changeInfo
UPDATE Users SET first_name = ?, email = ? WHERE user_ID = ?;


--/changePassword
    --get old password
SELECT user_password FROM Users WHERE user_ID = ?;
    --update
UPDATE Users SET user_password = ? WHERE user_ID = ?;


--/isAdminCheck
SELECT is_admin FROM Users WHERE user_ID = ?;


--/makeAdmin
UPDATE Users SET is_admin = TRUE WHERE user_ID = ?;
    --/adminNoMore
    UPDATE Users SET is_admin = FALSE WHERE user_ID = ?;


--/deleteUser (THIS IS LOW PRIORITY, WILL DO LATER)
--Need to delete records from each table starting futherest from Users up to User deletion
--Will need 7 different delete commands


--/searchUsers
SELECT username, first_name, email, user_password FROM Users WHERE username = ?;


--/createEvent
    --/Makes the event
    INSERT INTO Events (event_name) VALUES (?);
    --/Save dates (must be ran in a loop?)
    INSERT INTO Dates (selected_date, event_ID) VALUES (?, ?);
    --Creates the link between user hosts and their events
    INSERT INTO Hosts (user_ID, event_ID) VALUES (?,?);

--/eventDisplayPage (for displaying a users hosted events)
SELECT Events.event_ID, Events.event_name FROM Events RIGHT JOIN Hosts WHERE (Events.event_ID = Hosts.event_ID AND Hosts.user_ID = ?);

--/sendDates (for when a user responds with their available dates)
    INSERT INTO Notifications (email, availability_confirmation, event_finalised) VALUES (?,?,?);
    --Needs to get the notification ID (above) generated from this to use in the below query
    INSERT INTO Event_member_list (member_name, event_ID, notification_ID) VALUES (?,?,?);
    --Needs to get the above member ID to add to below query
    INSERT INTO Member_available_dates (member_ID, date_ID, if_available) VALUES (?,?,?);
        --For each date that is selected you need to get the date ID below
        SELECT date_ID FROM Dates WHERE (selected_date = ? AND event_ID = ?);

--/getParticipants
SELECT Event_member_list.member_name, Member_available_dates.if_available FROM Event_member_list RIGHT JOIN Member_available_dates ON Event_member_list.member_ID = Member_available_dates.member_ID WHERE Event_member_list.event_ID = ?;

--/eventIsFinalised
UPDATE Users SET is_admin = FALSE WHERE user_ID = ?;
--First ? = final confirmed date, Second ? = current event ID
UPDATE Events SET finalised_date = ?, is_finalised = TRUE WHERE event_ID = ?;

--/getEmailsToSend
SELECT Notifications.email, Notifications.availability_confirmation, Notifications.event_finalised, Event_member_list.member_name FROM Notifications LEFT JOIN Event_member_list ON (Notifications.notification_ID = Event_member_list.notification_ID AND Event_member_list.event_ID = ?);


--QUERIES FOR CATH THE CONQUEROR

--/checkLogin
SELECT username, user_password FROM Users WHERE username = ?;
    --if login was succsessful return user_ID
    SELECT user_ID FROM Users WHERE username = ?;

--/signUp
INSERT INTO Users (username, first_name, email, user_password) VALUES (?,?,?,?);
    --check if a user name exists
    --will return username if it exists in the database
    --else returns nothing
        SELECT username FROM Users WHERE username = ?;

--QUERIES FOR PG THE PHILANTHROPIC
--Such a philanthrpist needs nothing and asks for less