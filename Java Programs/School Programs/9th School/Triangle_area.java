import java.util.*;
public class Triangle_area
{
    public static void main(String[]args)
    {
        Scanner sc = new Scanner(System.in);
        double h,b,a;
        System.out.print("Enter height: ");
        h=sc.nextDouble();
        System.out.print("Enter base: ");
        b=sc.nextDouble();
        a=0.5*h*b;
        System.out.println("Area of triangle of height "+h+" and base "+b+" is "+a);
    }
}