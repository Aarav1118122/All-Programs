import java.util.*;
public class even_odd_sum
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        int size,no,osum=0,esum=0;
        System.out.println("Enter the number of numbers");
        size=sc.nextInt();
        System.out.println("Enter the numbers");
        for(int i=0;i<=size-1;i++)
        {
            no=sc.nextInt();
            if (no%2==0)
            {
                esum=esum+no;
            }
            else
            {
                osum=osum+no;
            }
        }
        System.out.println("Sum of even = "+esum);
        System.out.println("Sum of odd = "+osum);
    }
}
