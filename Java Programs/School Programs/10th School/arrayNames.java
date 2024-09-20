import java.util.*;

public class arrayNames {
    public static void main(String[] args) {
        int i;
        String name[] = { "Aarav", "Gopal", "Atharv", "Sparsh", "Abheer" };
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the index");
        i = sc.nextInt();
        System.out.println("The name at index " + i + " is " + name[i]);
    }
}