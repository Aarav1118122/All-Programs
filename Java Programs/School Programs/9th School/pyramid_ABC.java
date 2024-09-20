import java.util.*;
public class pyramid_ABC
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        n=n+65;
        for(char i=65;i<=n;i++)
        {
            for(char j=65;j<=i;j++)
            {
                System.out.print(j);
            }
            System.out.println();
        }
    } 
}