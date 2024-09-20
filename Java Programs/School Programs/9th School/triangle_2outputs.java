import java.util.*;
public class triangle_2outputs
{
    public static void main (String[]arg)
    {
        Scanner sc =new Scanner(System.in);
        int n,i,j,k,p;
        System.out.println("Enter a number");
        n=sc.nextInt();
        for(i=1;i<=n;i++)
        {
            p=n-i+1;
            for(k=1;k<p;k++) 
            {         
                System.out.print(" ");
            }
            for(j=1;j<=i;j++) 
            {
                System.out.print(j+"");   
            }
            for(k=i-1;k>=1;k--)
            {
                System.out.print(k+"");
            }
            System.out.println();
        }
    }
}