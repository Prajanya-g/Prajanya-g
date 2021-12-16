library(ggplot2)
library(dplyr)

# read the data
ks2018 <- read.csv("~/Documents/grand /ks-projects-201801.csv")




# getting the years from the dates 
ks2018$dates.launch <- as.POSIXct(ks2018$launched,format = "%Y-%m-%d %H:%M:%S")
ks2018$dates.launch <- format(ks2018$dates.launch, format = "%Y")
stateyear <-  data.frame(table(ks2018$dates.launch,ks2018$state))
stateyear <-  subset(stateyear, stateyear$Var2 != "live") 
stateyear <-  subset(stateyear, stateyear$Var2 != "undefined") 
stateyear <-  subset(stateyear, stateyear$Var2 != "suspended") 
stateyear <-  subset(stateyear, stateyear$Var2 != "canceled") 
stateyear <- setNames(stateyear,c("Var1","Legend","Freq"))
totalprojectsyear <- data.frame(table(ks2018$dates.launch))
totalprojectsyear <- data.frame(totalprojectsyear$Var1,c(rep("total",11)),totalprojectsyear$Freq)
totalprojectsyear <- setNames(totalprojectsyear,c("Var1","Legend","Freq"))
stateyear<-rbind(stateyear,totalprojectsyear)
stateyear <-  subset(stateyear, stateyear$Var1 != 1970) 
stateyear <-  subset(stateyear, stateyear$Var1 != 2018) 
# Ploting the line graph for success and fail each year
ggplot(stateyear, aes(x=Var1, y=Freq , group=Legend, color=Legend))+geom_line()+
  xlab("years")+ylab("Total projects")





# forming a data frame of the main category
main_category <- data.frame(table(ks2018$main_category))
# plotting the data for the total projects in each category
ggplot(main_category,aes(x=Var1,y=Freq)) +
geom_bar(stat="identity",fill="cadetblue2") +
coord_flip()+
ylab("total projects") + xlab("category")+
  geom_text(aes(x = Var1,   y = Freq+30, label = Freq))+
  geom_hline(aes(yintercept=mean(Freq)),color="gray70", size=0.5, linetype="dashed")+
  geom_text(aes(x="Theater", label=paste0("Mean ",floor(mean(Freq))), y=29000),size = 3)






#dividing categories based on succcesss and failure
status_categories <-  data.frame(table(ks2018$main_category,ks2018$state))
#removing all the other status from the data frame 
status_categories <-  subset(status_categories, status_categories$Var2 != "live") 
status_categories <-  subset(status_categories, status_categories$Var2 != "undefined") 
status_categories <-  subset(status_categories, status_categories$Var2 != "suspended") 
status_categories <-  subset(status_categories, status_categories$Var2 != "canceled") 
# creating two different categories for success and failure 
categories_fail <- subset(status_categories, status_categories$Var2 != "successful") 
categories_pass <- subset(status_categories, status_categories$Var2 != "failed")
#performing calculationsan renaming the columns
categories_pass <- data.frame(categories_pass,main_category$Freq)
categories_pass$success_percentage <- ((categories_pass$Freq / categories_pass$main_category.Freq)*100) 
categories_fail <- data.frame(categories_fail,main_category$Freq)
categories_fail$fail_percentage <- ((categories_fail$Freq / categories_fail$main_category.Freq)*100) 
names(categories_fail)[5] <- 'percentage'
names(categories_pass)[5] <- 'percentage'
# creating a data with both percentages and the categories 
pass_fail <- data.frame(categories_fail$Var1,categories_fail$percentage,categories_pass$percentage)
pass_fail <- setNames(test,c("Var1","fail","success"))
#plotting the graph for fail success
ggplot(pass_fail, aes(x=fail, y=success)) +
  geom_point() + # Show dots
  geom_label(
    label=pass_fail$Var1, 
    nudge_x = 0.25, nudge_y = 0.25, 
    check_overlap = T
  )+xlab("percentage of projects failed")+ylab("percentage of projects successful")






# getting the sum of backer in different categories 
backers <- data.frame(aggregate(ks2018$backers, by=list(categories=ks2018$main_category), FUN=sum))
backers <- setNames(backers,c("categories","backers"))
# getting total investments
investment <- data.frame(aggregate(ks2018$usd.pledged, by=list(categories=ks2018$main_category), FUN=sum))
avgfb <- data.frame(backers$categories)
# calculating average
avgfb$average <- (investment$x/backers$backers)
avgfb <- setNames(avgfb,c("Var1","average"))
#converting to two decimals 
avgfb$twodec <- format(round(avgfb$average, 2), nsmall = 2)
# plotting the graph for avg investment per backer in each category                 
ggplot(avgfb,aes(x=Var1,y=average)) +
  geom_bar(stat="identity",fill="coral") +
  ylab("average funds invested by a backer") + xlab("categories")+
  geom_text(aes(x = Var1,   y = average+1.5, label = twodec))+
  geom_hline(aes(yintercept=mean(average)),color="gray70", size=0.5, linetype="dashed")+
  geom_text(aes(x="Art", label=paste0("Mean: ",floor(mean(average))), y=66),size = 3)

                
                
                

                
                
successyear <- subset(stateyear, stateyear$Var2 != "failed")
successyear <-  subset(successyear, successyear$Var1 != 1970) 
successyear <-  subset(successyear, successyear$Var1 != 2018) 

catyearsuccess<- data.frame(table(ks2018$dates.launch,ks2018$main_category,ks2018$state))
catyearsuccess <-  subset(catyearsuccess, catyearsuccess$Var3 != "live") 
catyearsuccess <-  subset(catyearsuccess, catyearsuccess$Var3 != "undefined") 
catyearsuccess <-  subset(catyearsuccess, catyearsuccess$Var3 != "suspended") 
catyearsuccess <-  subset(catyearsuccess, catyearsuccess$Var3 != "canceled") 
catyearsuccess <-  subset(catyearsuccess, catyearsuccess$Var3 != "failed")
catyearsuccess <-  subset(catyearsuccess, catyearsuccess$Var1 != 1970) 
catyearsuccess <-  subset(catyearsuccess, catyearsuccess$Var1 != 2018) 
catyearsuccess$sum <- c(rep(successyear$Freq,3))
catyearsuccess$percentage <- (catyearsuccess$Freq/catyearsuccess$sum)*100
catyearsuccess<-setNames(catyearsuccess,c("Var1","categories","Var3","Freq","sum","percentage"))
#The portion of a category in successful projects each year
ggplot(catyearsuccess, aes(fill=categories, y=percentage, x=Var1)) + 
  geom_bar(position="fill", stat="identity",color = "black")+xlab("Years")+ylab("% total number of records")+
  scale_fill_manual(values = c("aliceblue","brown1","burlywood1","cadetblue1","chocolate","coral","cyan4","darkgreen","darkgrey","blue4","darkolivegreen2","darkslategray3","deeppink","deepskyblue","darkred"))

