import java.util.*;
import School_Package.*;
public class pyramid3
{
    public static void main (String[]arg)
    {
        Scanner sc =new Scanner(System.in);
        int n,i,j;
        System.out.println("Enter a number");
        n=sc.nextInt();
        pyramid_pattern.pattern(1,n,-n);
    }
}   