import java.util.*;
public class armstrong2
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        double sum,i2;
        for(int i=1;i<=500;i++)
        {
            sum=0;
            while(i>0)
            {
                i2=i%10;
                sum=sum+Math.pow(i2,3);
                i/=10;
            }
            if(i==sum)
            {
                System.out.println(i);
            }
        }
    }
}
