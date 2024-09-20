import java.util.*;
import School_Package.*;
public class menu
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        int menu;
        double n,s=0.0,i;
        menu=sc.nextInt();
        switch(menu)
        {
            case 1: 
            n=sc.nextInt();
            for (i=1.0;i<=n;i++)
            {
                s=s+(1/(4*i));
            }
            s=s+(1/(4*i));
            System.out.println(s);
            break;
            case 2:
            n=sc.nextInt();
            for (i=1.0;i<=n;i++)
            {
                s=s+(i/(factorial.fact(i)));
            }
            s=s+(i/(factorial.fact(i)));
            System.out.println(s);
            break;
            default:
            System.out.println("Not an option");
        }
    }
}