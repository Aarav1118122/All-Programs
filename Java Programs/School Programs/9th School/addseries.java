import java.util.*;
public class addseries
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        int n;
        double sum=0.0;
        System.out.println("Enter n");
        n=sc.nextInt();
        for(double i=2;i<=n;i++)
        {
            sum=sum+(1/i);
        }
        sum=sum+1;
        System.out.println(sum);
    }
}