-- MySQL dump 10.13  Distrib 8.0.29, for Linux (x86_64)
--
-- Host: 127.0.0.1    Database: Ease
-- ------------------------------------------------------
-- Server version	8.0.29-0ubuntu0.20.04.3

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `Ease`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `Ease` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;

USE `Ease`;

--
-- Table structure for table `Dates`
--

DROP TABLE IF EXISTS `Dates`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Dates` (
  `date_ID` int unsigned NOT NULL AUTO_INCREMENT,
  `selected_date` date NOT NULL,
  `event_ID` int unsigned NOT NULL,
  PRIMARY KEY (`date_ID`),
  KEY `event_ID` (`event_ID`),
  CONSTRAINT `Dates_ibfk_1` FOREIGN KEY (`event_ID`) REFERENCES `Events` (`event_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=187 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Dates`
--

LOCK TABLES `Dates` WRITE;
/*!40000 ALTER TABLE `Dates` DISABLE KEYS */;
INSERT INTO `Dates` VALUES (1,'2022-06-16',26),(2,'2022-06-17',26),(3,'2022-06-08',31),(4,'2022-06-09',31),(5,'2022-06-02',31),(6,'2022-06-09',31),(7,'2022-06-09',33),(8,'2022-06-24',33),(9,'2022-06-09',36),(10,'2022-06-10',36),(11,'2022-06-17',36),(12,'2022-06-09',38),(13,'2022-06-09',38),(14,'2022-06-16',42),(15,'2022-06-09',33),(16,'2022-06-10',33),(17,'2022-06-17',33),(18,'2022-06-09',31),(19,'2022-06-08',31),(20,'2022-06-09',31),(21,'2022-06-10',31),(22,'2022-06-16',31),(23,'2022-06-17',31),(24,'2022-06-02',58),(25,'2022-06-09',58),(26,'2022-07-07',59),(27,'2022-07-07',59),(28,'2022-07-08',59),(29,'2022-07-08',59),(30,'2022-07-07',60),(31,'2022-07-08',60),(32,'2022-07-14',60),(33,'2022-07-07',61),(34,'2022-07-08',61),(35,'2022-06-14',62),(36,'2022-06-15',62),(37,'2022-06-14',62),(38,'2022-06-15',62),(39,'2022-06-16',62),(40,'2022-06-16',62),(41,'2022-06-14',63),(42,'2022-06-15',63),(43,'2022-06-21',64),(44,'2022-06-15',64),(45,'2022-06-15',65),(46,'2022-06-16',65),(47,'2022-06-15',66),(48,'2022-06-16',66),(49,'2022-06-02',67),(50,'2022-06-09',67),(51,'2022-06-08',68),(52,'2022-06-15',68),(53,'2022-06-22',68),(54,'2022-06-01',69),(55,'2022-06-09',69),(56,'2022-06-10',71),(57,'2022-06-17',71),(58,'2022-06-03',72),(59,'2022-06-10',72),(60,'2022-06-09',73),(61,'2022-06-10',73),(62,'2022-06-01',74),(63,'2022-06-16',74),(64,'2022-06-03',75),(65,'2022-06-09',75),(66,'2022-06-09',76),(67,'2022-06-10',76),(68,'2022-06-09',77),(69,'2022-06-10',77),(70,'2022-06-08',78),(71,'2022-06-09',78),(72,'2022-06-10',78),(73,'2022-06-09',79),(74,'2022-06-10',79),(75,'2022-06-11',79),(76,'2022-06-14',80),(77,'2022-06-23',80),(78,'2022-06-22',80),(79,'2022-06-24',80),(80,'2022-06-11',81),(81,'2022-06-13',81),(82,'2022-06-12',81),(83,'2022-06-21',82),(84,'2022-06-03',82),(85,'2022-05-18',83),(86,'2022-05-30',83),(87,'2022-05-20',83),(88,'2022-07-03',84),(89,'2022-07-20',84),(90,'2022-06-20',85),(91,'2022-07-08',85),(92,'2022-06-08',86),(93,'2022-06-09',86),(94,'2022-06-02',87),(95,'2022-06-03',87),(96,'2022-06-07',88),(97,'2022-06-15',88),(98,'2022-06-08',88),(99,'2022-06-01',90),(100,'2022-06-14',90),(101,'2022-06-10',90),(102,'2022-07-08',90),(103,'2022-06-08',91),(104,'2022-06-10',91),(105,'2022-07-15',91),(106,'2022-08-12',91),(107,'2022-08-13',92),(108,'2022-06-14',92),(109,'2022-06-09',93),(110,'2022-06-02',93),(111,'2022-08-20',93),(112,'2022-07-08',93),(113,'2022-08-13',93),(114,'2022-07-16',93),(115,'2022-06-08',94),(116,'2022-06-09',94),(117,'2022-06-08',95),(118,'2022-06-09',95),(119,'2022-06-01',96),(120,'2022-06-22',96),(121,'2022-06-08',97),(122,'2022-06-09',97),(123,'2022-06-21',98),(124,'2022-06-22',98),(125,'2022-07-08',98),(126,'2022-07-01',98),(127,'2022-06-01',99),(128,'2022-07-01',99),(129,'2022-06-01',100),(130,'2022-06-02',100),(131,'2022-06-23',101),(132,'2022-06-30',101),(133,'2022-06-03',103),(134,'2022-08-13',104),(135,'2022-06-16',104),(136,'2022-07-15',104),(137,'2022-08-20',104),(138,'2022-06-08',105),(139,'2022-06-22',105),(140,'2022-06-16',106),(141,'2022-06-17',106),(142,'2022-07-08',106),(143,'2022-07-15',106),(144,'2022-06-10',107),(145,'2022-07-08',107),(146,'2022-06-14',108),(147,'2022-06-16',108),(148,'2022-06-17',108),(149,'2022-07-15',108),(150,'2022-08-12',108),(151,'2022-08-13',108),(152,'2022-06-03',110),(153,'2022-06-09',111),(154,'2022-06-24',111),(155,'2022-06-16',111),(156,'2022-06-01',112),(157,'2022-06-02',112),(158,'2022-06-17',113),(159,'2022-07-08',113),(160,'2022-08-19',113),(161,'2022-06-23',114),(162,'2022-06-29',114),(163,'2022-08-18',114),(164,'2022-08-25',114),(165,'2022-07-14',114),(166,'2022-07-20',114),(167,'2022-06-18',115),(168,'2022-08-27',115),(169,'2022-08-20',115),(170,'2022-08-26',115),(171,'2022-08-19',115),(172,'2022-06-24',115),(173,'2022-06-30',115),(174,'2022-08-13',115),(175,'2022-07-16',115),(176,'2022-07-15',115),(177,'2022-08-12',115),(178,'2022-06-17',116),(179,'2022-06-23',116),(180,'2022-06-24',116),(181,'2022-07-22',116),(182,'2022-07-23',116),(183,'2022-06-16',117),(184,'2022-07-14',117),(185,'2022-06-17',117),(186,'2022-07-15',117);
/*!40000 ALTER TABLE `Dates` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Event_member_list`
--

DROP TABLE IF EXISTS `Event_member_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Event_member_list` (
  `member_ID` int unsigned NOT NULL AUTO_INCREMENT,
  `member_name` varchar(63) NOT NULL,
  `event_ID` int unsigned NOT NULL,
  `notification_ID` int unsigned NOT NULL,
  PRIMARY KEY (`member_ID`),
  KEY `event_ID` (`event_ID`),
  KEY `notification_ID` (`notification_ID`),
  CONSTRAINT `Event_member_list_ibfk_1` FOREIGN KEY (`event_ID`) REFERENCES `Events` (`event_ID`),
  CONSTRAINT `Event_member_list_ibfk_2` FOREIGN KEY (`notification_ID`) REFERENCES `Notifications` (`notification_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Event_member_list`
--

LOCK TABLES `Event_member_list` WRITE;
/*!40000 ALTER TABLE `Event_member_list` DISABLE KEYS */;
INSERT INTO `Event_member_list` VALUES (1,'sarthak',77,1);
/*!40000 ALTER TABLE `Event_member_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Events`
--

DROP TABLE IF EXISTS `Events`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Events` (
  `event_ID` int unsigned NOT NULL AUTO_INCREMENT,
  `event_name` varchar(63) NOT NULL,
  `finalised_date` date DEFAULT NULL,
  `is_finalised` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`event_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=118 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Events`
--

LOCK TABLES `Events` WRITE;
/*!40000 ALTER TABLE `Events` DISABLE KEYS */;
INSERT INTO `Events` VALUES (1,'',NULL,0),(2,'',NULL,0),(3,'',NULL,0),(4,'',NULL,0),(5,'first',NULL,0),(6,'first event',NULL,0),(7,'first event',NULL,0),(8,'first event',NULL,0),(9,'first event ',NULL,0),(10,'first',NULL,0),(11,'first',NULL,0),(12,'sad',NULL,0),(13,'sofa',NULL,0),(14,'smf',NULL,0),(15,'smf',NULL,0),(16,'fads',NULL,0),(17,'aside',NULL,0),(18,'fed',NULL,0),(19,'sofa',NULL,0),(20,'afs',NULL,0),(21,'smf',NULL,0),(22,'sfa',NULL,0),(23,'fads',NULL,0),(24,'afsd',NULL,0),(25,'staff',NULL,0),(26,'dfs',NULL,0),(27,'fdsa',NULL,0),(28,'soda',NULL,0),(29,'job',NULL,0),(30,'fds',NULL,0),(31,'fds',NULL,0),(32,'finally',NULL,0),(33,'ask',NULL,0),(34,'fas',NULL,0),(35,'daft',NULL,0),(36,'sofa',NULL,0),(37,'aside',NULL,0),(38,'aside',NULL,0),(39,'aside',NULL,0),(40,'aside',NULL,0),(41,'asdf',NULL,0),(42,'sofa',NULL,0),(43,'sofa',NULL,0),(44,'said',NULL,0),(45,'adds',NULL,0),(46,'fads',NULL,0),(47,'soda',NULL,0),(48,'soda',NULL,0),(49,'soda',NULL,0),(50,'sofa',NULL,0),(51,'saf',NULL,0),(52,'sad',NULL,0),(53,'sfa',NULL,0),(54,'fdsa',NULL,0),(55,'soda',NULL,0),(56,'fads',NULL,0),(57,'dfsjk',NULL,0),(58,'fsadljk',NULL,0),(59,'final',NULL,0),(60,'final',NULL,0),(61,'final',NULL,0),(62,'first event finally',NULL,0),(63,'fdsa',NULL,0),(64,'fads',NULL,0),(65,'sofa',NULL,0),(66,'daft',NULL,0),(67,'test',NULL,0),(68,'',NULL,0),(69,'',NULL,0),(70,'',NULL,0),(71,'asdf',NULL,0),(72,'final',NULL,0),(73,'sad',NULL,0),(74,'test',NULL,0),(75,'party',NULL,0),(76,'fads',NULL,0),(77,'dosa',NULL,0),(78,'party tonight',NULL,0),(79,'plz',NULL,0),(80,'sofa',NULL,0),(81,'Just Chilling',NULL,0),(82,'hhh',NULL,0),(83,'df',NULL,0),(84,'asd',NULL,0),(85,'test!',NULL,0),(86,'sofa',NULL,0),(87,'dfsa',NULL,0),(88,'dfsa',NULL,0),(89,'dsfa',NULL,0),(90,'fsdaaf',NULL,0),(91,'soda',NULL,0),(92,'sad',NULL,0),(93,'dfsa',NULL,0),(94,'sofa',NULL,0),(95,'sfa',NULL,0),(96,'',NULL,0),(97,'dvcsdg',NULL,0),(98,'dfsa',NULL,0),(99,'fock',NULL,0),(100,'aside',NULL,0),(101,'sofa',NULL,0),(102,'hjello ',NULL,0),(103,'hjello ',NULL,0),(104,'Event 007',NULL,0),(105,'admin\'s first event uwu',NULL,0),(106,'Event 007',NULL,0),(107,'Event 007',NULL,0),(108,'Event 007',NULL,0),(109,'Event 007',NULL,0),(110,'Event 007',NULL,0),(111,'Event 007',NULL,0),(112,'Event 007',NULL,0),(113,'Event 007',NULL,0),(114,'Event 007',NULL,0),(115,'Event 007',NULL,0),(116,'Event 007',NULL,0),(117,'Event 007',NULL,0);
/*!40000 ALTER TABLE `Events` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Hosts`
--

DROP TABLE IF EXISTS `Hosts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Hosts` (
  `host_ID` int unsigned NOT NULL AUTO_INCREMENT,
  `user_ID` int unsigned NOT NULL,
  `event_ID` int unsigned NOT NULL,
  PRIMARY KEY (`host_ID`),
  KEY `user_ID` (`user_ID`),
  KEY `event_ID` (`event_ID`),
  CONSTRAINT `Hosts_ibfk_1` FOREIGN KEY (`user_ID`) REFERENCES `Users` (`user_ID`),
  CONSTRAINT `Hosts_ibfk_2` FOREIGN KEY (`event_ID`) REFERENCES `Events` (`event_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=47 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Hosts`
--

LOCK TABLES `Hosts` WRITE;
/*!40000 ALTER TABLE `Hosts` DISABLE KEYS */;
INSERT INTO `Hosts` VALUES (1,1,73),(2,1,74),(3,15,75),(4,14,76),(5,15,77),(6,15,78),(7,15,79),(8,15,80),(9,6,81),(10,16,82),(11,16,83),(12,16,84),(17,16,85),(18,15,86),(19,15,87),(20,15,88),(21,15,90),(22,15,91),(23,15,92),(24,15,93),(25,15,94),(26,15,95),(27,15,96),(28,15,97),(29,15,98),(30,15,99),(31,15,100),(32,15,101),(33,16,103),(34,15,104),(35,20,105),(36,20,106),(37,20,107),(38,15,108),(39,15,110),(40,20,111),(41,20,112),(42,20,113),(43,20,114),(44,20,115),(45,20,116),(46,15,117);
/*!40000 ALTER TABLE `Hosts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Member_available_dates`
--

DROP TABLE IF EXISTS `Member_available_dates`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Member_available_dates` (
  `member_ID` int unsigned NOT NULL,
  `date_ID` int unsigned NOT NULL,
  `if_available` tinyint(1) NOT NULL DEFAULT '0',
  KEY `member_ID` (`member_ID`),
  KEY `date_ID` (`date_ID`),
  CONSTRAINT `Member_available_dates_ibfk_1` FOREIGN KEY (`member_ID`) REFERENCES `Event_member_list` (`member_ID`),
  CONSTRAINT `Member_available_dates_ibfk_2` FOREIGN KEY (`date_ID`) REFERENCES `Dates` (`date_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Member_available_dates`
--

LOCK TABLES `Member_available_dates` WRITE;
/*!40000 ALTER TABLE `Member_available_dates` DISABLE KEYS */;
INSERT INTO `Member_available_dates` VALUES (1,68,1),(1,69,1);
/*!40000 ALTER TABLE `Member_available_dates` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Notifications`
--

DROP TABLE IF EXISTS `Notifications`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Notifications` (
  `notification_ID` int unsigned NOT NULL AUTO_INCREMENT,
  `email` varchar(63) DEFAULT NULL,
  `availability_confirmation` tinyint(1) NOT NULL DEFAULT '0',
  `if_finalised` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`notification_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Notifications`
--

LOCK TABLES `Notifications` WRITE;
/*!40000 ALTER TABLE `Notifications` DISABLE KEYS */;
INSERT INTO `Notifications` VALUES (1,'prajanya.2001@gmail.com',1,1),(2,'prajanya.2001@gmail.com',1,1);
/*!40000 ALTER TABLE `Notifications` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Users`
--

DROP TABLE IF EXISTS `Users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Users` (
  `user_ID` int unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(63) DEFAULT NULL,
  `first_name` varchar(63) NOT NULL,
  `email` varchar(63) NOT NULL,
  `user_password` varchar(200) DEFAULT NULL,
  `is_admin` tinyint(1) NOT NULL DEFAULT '0',
  `google_ID` varchar(63) DEFAULT NULL,
  PRIMARY KEY (`user_ID`),
  UNIQUE KEY `username` (`username`),
  UNIQUE KEY `google_ID` (`google_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Users`
--

LOCK TABLES `Users` WRITE;
/*!40000 ALTER TABLE `Users` DISABLE KEYS */;
INSERT INTO `Users` VALUES (1,'admin1','admin','a1826488@adelaide.edu.au','$argon2i$v=19$m=4096,t=3,p=1$F10Aap60eWX82X57AtTOzQ$2rdto2+hcbsY/7jHkfLHZDEzGboovLK0tFEPBiy7OKU',1,NULL),(6,NULL,'Catherine','huocatherinejiaying@gmail.com',NULL,0,'103634247531005622623'),(7,'randomUser1','randomUser1','a1826488@gmail.com','$argon2i$v=19$m=4096,t=3,p=1$p48OcK4c4absfTdM8eqKLg$wElSdrEKkUtQyWhVb+dMN2J4kS5/FQ8HVgp1k+6dPz8',0,NULL),(8,'hello','first','a@gmail.com','$argon2i$v=19$m=4096,t=3,p=1$FGqr41S3UZayx2vfvok2Hg$VcOhf75xQuscXXCa1BrbwK5zL7yhpn2dGprtEkHDDYI',0,NULL),(9,'crying','tears','a@gmail.com','$argon2i$v=19$m=4096,t=3,p=1$8OT+XMtYZS3KS6yBS0fyLQ$mQGCzSe+ZA7drv3yT1yENZGUUDvgR8yaQ/Lld/zArbU',0,NULL),(10,'random2','a','a1826488@adelaide.edu.au','$argon2i$v=19$m=4096,t=3,p=1$AnUI/Fd8/n0/tldZnSKDzw$HhPp+CM4n74bOuLq2n7rO8nC+cMU0rVtdy485dIN2yU',0,NULL),(11,'Helppp','me','icantanymore@gmail.com','$argon2i$v=19$m=4096,t=3,p=1$2ddgl5fvsJBic5IMfhKj6Q$A3U5nAHFZiUnyDedUo2R+Xd4wi1AGQSgzdG32z8Be/c',0,NULL),(12,'random3','abc','abc@email.com','$argon2i$v=19$m=4096,t=3,p=1$Q2GB6Elwz2L3duuL3FW2lg$gMFBN5zqpWPlkvc/mDnn419QwVlsFJ9/9W2PQCYPlbc',0,NULL),(13,'random4','abc','abc@email.com','$argon2i$v=19$m=4096,t=3,p=1$O0JXF8tSfLIm+2QkW8bONw$xDx7zy9TU4CTguB5aCrayp1SZcmynzAyb0ViMYbVVAY',0,NULL),(14,'random5','random5','random5@email.com','$argon2i$v=19$m=4096,t=3,p=1$GDrdW9kXvM8AX7+lNwkIfg$eeJnz1Z36MFmZtGNOj++HKFDfy8dRwoxWJ/nepjwKIY',0,NULL),(15,'shreya','shreyaxdczxc','shreya@gmail.com','$argon2i$v=19$m=4096,t=3,p=1$Gr70x2rek9N71eQqvRQB+w$eQQ5ZujXRzYRLylUrHwWb1OxUknJM6iJ+cQf4eAu5+s',0,NULL),(16,'hello1','ashdasd','hello@gmail.com','$argon2i$v=19$m=4096,t=3,p=1$Js08lq4rkFXKlpXEfL5kYQ$Yx14W7OAVnRbexFDvBidycJHrhtiKZqdb3oM/qGLGwo',0,NULL),(19,'Testing1','test','test@gmail.com','$argon2i$v=19$m=4096,t=3,p=1$o5XxgBrErDk6zT60Mxs/2w$OhBMb542ZNCuJNkySbiB78p8zCV8K3pR4OqhX3C6+Pw',0,NULL),(20,'Testing2','test','test@email.com','$argon2i$v=19$m=4096,t=3,p=1$Xv4B9O+XLnZqsNy+mLgEDA$gDLMzYAY07YbYeTAlVA3NxlU5ML0dHurQMpySzRib7c',1,NULL);
/*!40000 ALTER TABLE `Users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-06-10 14:03:42
