REM MY FIRST PROGRAM
10 DIM CH AS STRING, YRNM AS STRING, TRAG AS INTEGER, LT AS STRING
20 CLS
30 INPUT "Please enter your name: ", YRNM
40 INPUT "Please enter your age: ", TRAG
50 PRINT "Your name is " + YRNM + " and your age is" + STR$(TRAG) + " years."
60 INPUT "Do you want to print again (Y/N): ", CH
70 IF CH = "Y" OR CH = "y" THEN GOTO 20
80 PRINT "Thank you";
90 END


