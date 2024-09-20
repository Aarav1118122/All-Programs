import java.util.*;
public class charclass
{
    public static void main()
    {
        Scanner sc = new Scanner(System.in);
        char ch;
        System.out.println("Enter a character");
        ch = sc.next().charAt(0);
        System.out.println((char)((int)ch + 10));
    }
}