import java.util.*;
public class floorandceil
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        double a;
        while(1==1)
        {
            a=sc.nextDouble();
            System.out.println(Math.round(a));
            a=sc.nextDouble();
            System.out.println(Math.ceil(a));
            a=sc.nextDouble();
            System.out.println(Math.floor(a));
        }
    }
}