import java.util.*;
public class stringindex
{
    public static void main()
    {
        Scanner sc = new Scanner(System.in);
        String word;
        word = sc.next();
        System.out.println(word.charAt(2));
        System.out.println(word.endsWith("a"));
        System.out.println(word.startsWith("a"));
    }
}