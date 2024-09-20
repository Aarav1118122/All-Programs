import java.util.*;
public class menu_measurments 
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        char m=sc.next().charAt(0);
        int result;
        switch(m)
        {
            case '1':
            int r=sc.nextInt();
            result=(4/3)*(22/7)*r*r*r;
            System.out.println(result);
            break;
            case'2':
            r=sc.nextInt();
            int h=sc.nextInt();
            result=(22/7)*h*r*r;
            System.out.println(result);
            break;
            case'3':
            int l=sc.nextInt();
            int b=sc.nextInt();
            h=sc.nextInt();
            result=l*b*h;
            System.out.println(result);
            break;
            default:
            System.out.println("this is not an option");
        }
    }
}