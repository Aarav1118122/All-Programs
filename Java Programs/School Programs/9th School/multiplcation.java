import java.util.*;
public class multiplcation
{
    public static void main(String[]args)
    {
        Scanner sc = new Scanner(System.in);
        int a,b;
        System.out.println("Enter a no: ");
        a=sc.nextInt();
        for (int i=0;i<=10;i++)
        {
            b=a*i;
            System.out.println(b);
        }
    }
}
