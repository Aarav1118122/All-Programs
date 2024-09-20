import java.util.*;
public class pronic
{
    public static void main(String[]args)
    {
        Scanner sc = new Scanner(System.in);
        int p;
        p = sc.nextInt();
        for(int i = 1;i <= p;i++)
        {
            if(p == i*(i+1))
            {
                System.out.println("it is a pronic number");
            }
            else
            {
                System.out.println("it is not a pronic number");
            }
        }
    }
}