import java.util.*;
public class charclass2
{
    public static void main()
    {
        Scanner sc = new Scanner(System.in);
        char ch;
        System.out.println("Enter a character");
        ch = sc.next().charAt(0);
        for(int i = 1;i <= 5;i++)
        {
           System.out.println(++ch);
        }
    }
}