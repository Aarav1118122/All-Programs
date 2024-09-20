import java.util.*;
public class Practicals2
{
    public static void main (String[]args)
    {
        Scanner sc=new Scanner(System.in);
        int m,y;
        System.out.println("Enter month in number: ");
        m=sc.nextInt();
        System.out.println("Enter year in number: ");
        y=sc.nextInt();
        if (m==1||m==3||m==5||m==7||m==8||m==10|| m ==12)
        {
           System.out.println("31 days");
        }
        else if (m==4||m==6||m==9||m==11)
        {
           System.out.println("30 days");
        }
        else if (m==2)
        {
           System.out.println("29 days");
        }
        else 
        {
            System.out.println("ERROR");
        }
        if (y%4==0 && y%100!=0)
        {
            System.out.println("Leap year");
        }
        else 
        {
             System.out.println("not a leap year");
        }
    }
}