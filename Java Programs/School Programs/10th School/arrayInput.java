import java.util.*;

public class arrayInput {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int array[] = new int[5];
        int sum = 0;
        for (int i = 0; i < array.length; i++) {
            array[i] = sc.nextInt();
            sum = sum + array[i];
        }
        System.out.println("The sum of the array is " + sum);
    }
}
