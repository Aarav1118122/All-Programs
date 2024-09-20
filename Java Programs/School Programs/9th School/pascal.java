import java.util.*;
public class pascal
{
    public static void main (String[]args)
    {
        Scanner sc =new Scanner (System.in);
        int a=1,n,i,j,k,l,c,d;
        for(i=1;i<=5;i++)
        {
            a=1;
            n=5-i+1;
            for(int b=1;b<=i-1;b++)
            {
                a=a*11;
            }
            for(k=1;k<n;k++)
            {         
                System.out.print(" ");
            }
            d=a;
            while(d>0)
            {
                c=d%10;
                System.out.print(c+" ");
                d=d/10;
            }
            System.out.println();
        }
    }
}