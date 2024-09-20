import java.util.*;
public class sqrtncbrt
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        double a,b;
        double c;
        a=sc.nextDouble();
        b=sc.nextDouble();
        c=a;
        while(c*c!=a)
        {
            c=c-0.01;
        }
        System.out.println(c);
        System.out.println(Math.sqrt(a));
        System.out.println(Math.cbrt(b));
    }
}