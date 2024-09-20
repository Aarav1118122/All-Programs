CLS
INPUT "Enter first number"; Num1
INPUT "Enter second number"; Num2
INPUT "Enter third number"; Num3
IF Num1 > Num2 AND Num1 > Num3 THEN
    Nm = Num1
ELSEIF Num2 > Num3 THEN
    Nm = Num2
ELSE
    Nm = Num3
END IF
PRINT "Greatest Number is"; Nm
END
