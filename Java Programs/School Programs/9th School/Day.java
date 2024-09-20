import java.util.*;
public class Day
{
    public static void main(String[]args)
    {
           Scanner sc =new Scanner(System.in);
           int d;
           while(1==1)
          {
                System.out.println("Enter number: ");
                d=sc.nextInt();
                if(d==1)  
                {
                    System.out.println("Monday");
                }
                else if(d==2)
                {
                    System.out.println("Tuesday");
                }
                else if(d==3)
                {
                   System.out.println("Wednesday");
                }
                else if(d==4)
                {
                    System.out.println("Thursday");
                }
                else if(d==5)
                {
                    System.out.println("friday");
                }
                else if(d==6)
                {
                    System.out.println("saturday");
                }
                else if(d==7)
                {
                    System.out.println("sunday");
                }
                else
                {
                    System.out.println("Number invalid");
                }
           }
    }
}