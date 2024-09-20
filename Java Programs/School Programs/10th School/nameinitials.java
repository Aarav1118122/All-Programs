import java.util.*;
public class nameinitials
{
    public static void main()
    {
        Scanner sc = new Scanner(System.in);
        String name;
        char i1,i2 = ' ';
        System.out.println("Enter your name");
        name = sc.nextLine();
        name = name.toUpperCase();
        i1 = name.charAt(0);
        for(int i = 0; i <= name.length();i++)
        {
            if(name.charAt(i) == ' ')
            {
                i2 = name.charAt(i+1);
                break;
            }
        }
        System.out.println("Initials are "+i1+" and "+i2);
    }
}