import java.util.*;
public class marks
{
    public static void main(String args[])
    {
        int m,p;
        Scanner sc= new Scanner(System.in);
        System.out.println("enter passing marks and your marks");
        p=sc.nextInt();
        m=sc.nextInt();
        if(m>p)
        {
           System.out.println("passed");
        }
        else
        {
            System.out.println("failed");
        }
}
}