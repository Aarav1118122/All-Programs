import java.util.*;
public class Calculator_complex
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        double n1=0,n2;
        char o;
        boolean t;
        System.out.println("Enter numbers");
        n1=sc.nextDouble();
        o=sc.next().charAt(0);
        do
        {
            if(o=='+')
            {
                n2=sc.nextDouble();
                n1=n1+n2;
                t=true;
            }
            else if(o=='*')
            {
                n2=sc.nextDouble();
                n1=n1*n2;
                t=true;
            }
            else if(o=='-')
            {
                n2=sc.nextDouble();
                n1=n1-n2;
                t=true;
            }
            else if(o=='/')
            {
                n2=sc.nextDouble();
                n1=n1/n2;
                t=true;
            }
            else if(o=='=')
            {
                t=false;
                break;
            }
            else
            {
                System.out.println("This is not an option");
                t=true;
            }
            o=sc.next().charAt(0);
        }
        while(t==true);
        System.out.println(n1);
    }
}