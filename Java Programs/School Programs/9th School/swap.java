import java.util.*;
public class swap
{
    public static void main(String[]args)
    {
        Scanner sc = new Scanner (System.in);
        int n1 , n2,n3;
        System.out.print("Enter a no: ");
        n1=sc.nextInt();
        System.out.print("Enter a no: ");
        n2=sc.nextInt();
        n3=n1;
        n1=n2;
        n2=n3;
        System.out.println("n1 = "+n1+" and n2 = "+n2);
    }
}