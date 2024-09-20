import java.util.*;
public class charmenu
{
    public static void main()
    {
        Scanner sc = new Scanner(System.in);
        int m;
        m = sc.nextInt();
        switch(m)
        {
            case 1:
            for(int i = (int)'Z'; i >= (int)'A';i--)
            {
                System.out.println((char)i);
            }
            break;
            case 2:
            for(int i = (int)'a'; i <= (int)'z';i++)
            {
                System.out.println((char)i);
            }
            break;
            default:
            System.out.println("Not an option");
        }
    }
}