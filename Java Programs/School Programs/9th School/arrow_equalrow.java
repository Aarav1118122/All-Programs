import java.util.*;
public class arrow_equalrow
{
    public static void main (String[]arg)
    {
        Scanner sc =new Scanner(System.in);
        int n,i,j,k,l;
        System.out.println("Enter a number");
        n=sc.nextInt();
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                System.out.print(i+" ");   
            }
            System.out.println();
        }
        for(l=n-1;l>=1;l--)
        {
            for(j=1;j<=l;j++)
            {
                System.out.print(l+" ");   
            }
            System.out.println();
        }
    }
}