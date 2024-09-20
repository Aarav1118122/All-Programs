import java.util.*;
public class removevowels
{
    public static void main()
    {
        Scanner sc = new Scanner(System.in);
        String word;
        int vowels = 0;
        System.out.println("Enter a String");
        word = sc.nextLine();
        for(int i = 0; i <= word.length()-1;i++)
        {
            if(word.charAt(i) == 'a')
            {vowels++;}
            else if(word.charAt(i) == 'e')
            {vowels++;}
            else if(word.charAt(i) == 'i')
            {vowels++;}
            else if(word.charAt(i) == 'o')
            {vowels++;}
            else if(word.charAt(i) == 'u')
            {vowels++;}
            else
            {
                
                System.out.print(word.charAt(i));
            }
        }
        System.out.println();
        System.out.println("no of vowels = "+vowels);
    }
}