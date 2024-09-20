import java.util.*;
public class menu2
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        int n,m,n2,c=1,d=1;
        m=sc.nextInt();
        n=sc.nextInt();
        switch(m)
        {
            case 1:
            n2=n*n;
            while(n>0)
            {
                n=n/10;
                c++;
            }
            for(int i=1;1<=c;i++)
            {
                d=d*10;
            }
            n2=n2%d;
            if(n2==n)
            {
                System.out.println("It is an automorphic");
            }
            else 
            {
                System.out.println("It is not an automorphic");
            }
            break;
            case 2:
            for(int i=2;i<n;i++)
            {
                if(n%i==0)
                {
                    System.out.println("It is not a prime");
                    c++;
                    break;
                }
                else
                {
                    c=0;
                }
            }
            if(c==0) System.out.println("It is a prime");
            break;
            default: System.out.println("It is not an option");
        }
    }
}