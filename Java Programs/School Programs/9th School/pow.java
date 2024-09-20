import java.util.*;
public class pow
{
    public static void main(String[]args)
    {
        Scanner sc= new Scanner(System.in);
        int a,b,c;
        a=sc.nextInt();
        b=sc.nextInt();
        c=a;
        for(int i=1;i<b;i++)
        {
            c=c*a;
        }
        System.out.println(c);
    }
}