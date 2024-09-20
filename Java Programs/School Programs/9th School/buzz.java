import java.util.*;
public class buzz
{
public static void main (String[]args)
{
    Scanner sc=new Scanner(System.in);
    int a;
    System.out.print("Enter a number: ");
    a = sc.nextInt();
    if(a % 7==0||a%10==7)
    {
        System.out.println("Its a buzz no");
    }
    else 
    {
        System.out.println("It is not buzz no");
    
    }
}
    
}