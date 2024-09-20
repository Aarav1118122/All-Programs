import java.util.*;
import School_Package.*;
public class triangle
{
    public static void main (String[]args)
    {
        Scanner sc =new Scanner (System.in);
        int a,n,i,j,l;
        System.out.println("Enter a number");
        a=sc.nextInt();
        triangle_pattern.pattern(a,1,1);
        /*for(i=a-1;i>=1;i--)
        {
            n=a-i+1;
            l=1;
            for(k=n;k>1;k--)
            {         
                System.out.print(" ");
            }
            for(j=i;j>=1;j--)
            {           
                System.out.print(l+" ");
                l++;
            }
            System.out.println();
        }*/
        //only for rhombus
    }
}