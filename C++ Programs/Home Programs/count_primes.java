import java.lang.*;
public class count_primes {
    public static void main(String[]args) {
        int count = 0;
        double sq;
        boolean prime = true;
        for (int i = 1; i <= 10000000; i += 2)
        {
            sq = Math.sqrt(i);
            prime = true;
            for (int factor = 3; factor <= sq; factor += 2)
            {
                if (i % factor == 0)
                {
                    prime = false;
                    break;
                }
            }
            if (prime)
                count++;
        }
        System.out.println("No of primes are - " + count);

    }
}