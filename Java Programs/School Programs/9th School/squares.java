import java.util.*;
public class squares
{
    public static void main(String[]args)
    {
        Scanner sc = new Scanner(System.in);
        int a,b,n1,n2;
        System.out.println("Enter a number: ");
        a=sc.nextInt();
        System.out.println("Enter a number: ");
        b=sc.nextInt();
        n1=a*a;
        n2=b*b;
        System.out.println("squares of "+a+" and "+b+ " are "+n1+" and "+n2);
        n1=a*a*a;
        n2=b*b*b;
        System.out.println("cubes of "+a+" and "+b+ " are "+n1+" and "+n2);
    }
} 