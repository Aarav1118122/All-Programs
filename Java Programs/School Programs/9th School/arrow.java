import java.util.*;
import School_Package.*;
public class arrow
{
    public static void main (String[]arg)
    {
        Scanner sc =new Scanner(System.in);
        int n,i,j,k;
        System.out.println("Enter a number");
        n=sc.nextInt();
        pyramid_pattern.pattern(1,n,1);
        pyramid_pattern.rpattern(n-1,1);
    }
}