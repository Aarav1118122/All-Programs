import java.util.*;
public class floorandceil2
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        double a;
        a=sc.nextDouble();
        System.out.println(Math.floor(a));
        System.out.println(Math.ceil(a));
        System.out.println(Math.ceil(a)-Math.floor(a));
    }
}