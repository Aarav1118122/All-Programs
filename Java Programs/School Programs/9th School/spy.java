import java.util.*;
public class spy 
{
    public static void main (String[]args)
    {
        Scanner sc=new Scanner (System.in);
        int n,sum=0,prod=1,n2,n3;
        System.out.println("Ënter a number");
        n=sc.nextInt();
        n2=n;
        while (n2>0)
        {
            n3=n2%10;
            sum=sum+n3;
            prod=prod*n3;
            n2=n2/10;
        }
        if (prod==sum)
        { 
            System.out.println("It is a spy number");
        }
        else
        {
            System.out.println("It is not a spy number");
        }
    }
}