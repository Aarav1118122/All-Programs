import java.util.*;
public class Practicals3
{
    public static void main (String[]args)
    {
        Scanner sc=new Scanner(System.in);
        int n,ans=0,n2=0,n3;
        System.out.println("Enter a number: ");
        n=sc.nextInt();
        n3=n;
        while(n>0)
        {
            n2=n%10;
            ans=(ans*10)+n2;
            n=n/10;
        }
        if(ans==n3)
        {
            System.out.println("It is a palindrome number");
        }
        else
        {
            System.out.println("It is not a palindrome number");
        }
    }
}