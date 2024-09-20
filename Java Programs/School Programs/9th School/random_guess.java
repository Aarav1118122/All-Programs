import java.util.*;
public class random_guess
{
    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        double randi;
        int g;
        randi=Math.random();
        while (randi%10>1)
        {
            randi*=10;
        }
        randi=randi-randi%1;
        System.out.println("Enter a guess");
        g=sc.nextInt();
        while(g==randi)
        {
            System.out.println("Enter a guess");
            g=sc.nextInt();
            if(g>randi)
            {
                System.out.println("Too high try again");
            }
            if(g>randi)
            {
                System.out.println("Too low try again");
            }
        }
    }
}