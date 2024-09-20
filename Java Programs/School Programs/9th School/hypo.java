import java.util.*;
public class hypo
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        double p,b,h;
        p=sc.nextDouble();
        b=sc.nextDouble();
        h=Math.sqrt(p*p+b*b);
        System.out.println(h);
    }
}