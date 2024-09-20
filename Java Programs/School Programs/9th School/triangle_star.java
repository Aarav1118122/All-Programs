import java.util.*;
public class triangle_star
{
    public static void main(String[]args)
    {
        int a,b,c=0,d;
        for(a=1;a<=5;a++)
        {
            d=2*c+1;
            for(b=1;b<=d;b++)
            {
                System.out.print("* ");
            }
            c++;
            System.out.println();
        }
    }
}