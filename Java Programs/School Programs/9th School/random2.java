import java.util.*;
public class random2
{
    public static double random (double i2,double n2)
    {
        while(n2<(i2-1)*10)
        {
            n2+=10;
        }
        return n2;
    }
    public static void main(String[]args)
    {
        double i,n,counter_i=1,counter_range=10;
        for(i=1;i<=5;i++)
        {
            if(i==counter_i)
            {
                n=Math.random()*100;
                n=(n-n%1)%counter_range;
                n=random(i,n);
                System.out.println(n);
            }
            counter_i++;
            counter_range+=10;
        }
    }
}