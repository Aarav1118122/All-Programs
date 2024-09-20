import java.util.*;
public class average_marks
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner (System.in);
        double p,c,b,a;
        p=sc.nextDouble();
        c=sc.nextDouble();
        b=sc.nextDouble();
        a=(p+b+c)/3;
        System.out.println(a);
        System.out.println(Math.round(a));        
    }
}