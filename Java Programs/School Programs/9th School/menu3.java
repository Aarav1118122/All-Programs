import java.util.*;
public class menu3
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        int m,n,n2,gcd=0,i;
        System.out.println("Enter option");
        m=sc.nextInt();
        switch(m)
        {
            case 1:
            System.out.println("Enter number");
            n=sc.nextInt();
            if(n%10==7||n%7==0)
            {
                System.out.println("Ït is a buzz number");
            }
            else
            {
                System.out.println("Ït is not a buzz number");
            }
            break;
            case 2:
            System.out.println("Enter numbers");
            n=sc.nextInt();
            n2=sc.nextInt();
            for(i=1;i<=Math.max(n,n2);i++)
            {
                if(n%i==0 && n2%i==0)
                {
                    gcd=i;
                }
            }
            System.out.println("G.C.D= "+gcd);
            break;
            default: System.out.println("Not an option");
            break;
        }
    }
}