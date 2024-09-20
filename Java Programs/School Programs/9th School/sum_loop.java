import java.util.*;
public class sum_loop
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        int n1,n2;
        boolean o;
        do
        {
            System.out.println("Enter 2 numbers");
            n1=sc.nextInt();
            n2=sc.nextInt();
            System.out.println(n1+n2);
            System.out.println("Do you want to continue? true or false");
            o=sc.nextBoolean();
        }
        while(o==true);
    }
}
