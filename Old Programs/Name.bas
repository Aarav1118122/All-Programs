10 DIM Ch AS STRING, YrNm AS STRING
20 CLS
25 INPUT "Please Enter Your Name: ", YrNm
30 PRINT "Your Name is: ", YrNm
40 INPUT "Do you want to Print more Names (Y/N)?", Ch
45 IF Ch = "Y" OR Ch = "y" THEN GOTO 20
50 PRINT "Good Bye"
60 END

