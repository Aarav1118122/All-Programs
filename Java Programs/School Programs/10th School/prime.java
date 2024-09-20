import java.util.*;

public class prime {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number, counter = 0;
        System.out.println("Enter a number");
        number = sc.nextInt();
        for (int i = 1; i < number; i++) {
            if (number % i != 0)
                continue;
            else
                counter++;

        }
        if (number != 1) {
            if (counter > 1) {
                System.out.println("The number is a composite");
            } else {
                System.out.println("The number is a prime");
            }
        } else
            System.out.println("Neither prime nor composite");
    }
}
