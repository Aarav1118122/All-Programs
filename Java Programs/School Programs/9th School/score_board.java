import java.util.*;
public class score_board
{
    public static void main(String[]args)
    {
        Scanner sc= new Scanner(System.in);
        int runs=0,runs2,wicket=0,balls=0;
        String ball;
        do
        {
            System.out.println("Runs/Out/Wide/No Ball");
            ball=sc.next();
            switch(ball)
            {
                case "run":
                System.out.println("How many runs?");
                runs2=sc.nextInt();
                runs=runs+runs2;
                balls++;
                break;
                case "out":
                wicket++;
                balls++;
                break;
                case "wide":
                runs++;
                break;
                case "No Ball":
                runs++;
                break;
            }
            System.out.println(runs+" runs in "+balls+" balls.");
        }
        while(wicket<=2);
    }
}