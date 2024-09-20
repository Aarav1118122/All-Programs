import java.util.*;
public class menu4
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        int n,x,m,r,a=1,b=2;
        m=sc.nextInt();
        switch(m)
        {
            case 1:
            n=sc.nextInt();
            x=sc.nextInt();
            r=x;
            
            case 2:
            n=sc.nextInt();
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=i;j++)
                {
                    System.out.print("1");
                }
                System.out.print(" ");
            }   
            default:
            System.out.println("this is not an option");
        }
    }
}