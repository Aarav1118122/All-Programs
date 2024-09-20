import java.util.*;

public class arrayMaxMin {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int array[] = new int[20];
        int max = 0, min = 0, maxIn = 0, minIn = 0;
        System.out.println("Enter 20 numbers");
        for (int i = 0; i < 20; i++) {
            array[i] = sc.nextInt();
        }
        for (int i = 0; i < 20; i++) {
            if (array[i] > max) {
                max = array[i];
                maxIn = i;
            }
            if (array[i] < min) {
                min = array[i];
                minIn = i;
            }
        }
        System.out.println("Max number is " + max + " on index " + maxIn);
        System.out.println("Min number is " + min + " on index " + minIn);
    }
}
