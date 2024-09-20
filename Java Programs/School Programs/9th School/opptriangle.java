import java.util.*;
public class opptriangle
{
    public static void main (String[]arg)
    {
        Scanner sc =new Scanner(System.in);
        int n,i,j,k;
        System.out.println("Enter a number");
        n=sc.nextInt();
        for(i=n;i>=1;i--)
        {
            k=n;
            for(j=i;j>=1;j--)
            {
                System.out.print(j+" ");
                k--;
            }
            System.out.println();
        }
    }
}