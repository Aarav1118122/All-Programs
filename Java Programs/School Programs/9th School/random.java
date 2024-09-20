import java.util.*;
public class random
{
    public static void main(String[]args)
    {
        Scanner sc= new Scanner(System.in);
        double a,b,c,d;
        /*for(int i=1;i<=5;i++)
        {
            a=(Math.random()*100);
            b=a-a%1;
            System.out.println(b);
            a=(Math.random()*10);
            b=a%a-1;
            System.out.println(b);
        }*/
        a=sc.nextInt();
        for(int i=1;i<=10;i++)
        {
            b=(Math.random()*10);
            c=(b-b%1);
            d=c%(a+1);
            System.out.println(d);
        }
    }
}
