import java.util.*;

public class arraySumSquare {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int array1[] = new int[5];
        int array2[] = new int[5];
        int a1square = 0, a2square = 0;
        System.out.println("Enter array 1");
        for (int i = 0; i < array1.length; i++) {
            array1[i] = sc.nextInt();
            a1square += Math.pow(array1[i], 2);
        }
        System.out.println("Enter array 2");
        for (int i = 0; i < array2.length; i++) {
            array2[i] = sc.nextInt();
            a2square += Math.pow(array2[i], 2);
        }
        if (a1square > a2square) {
            for (int i = 0; i < array1.length; i++) {
                System.out.println(array1[i]);
            }
        } else if (a1square < a2square) {
            for (int i = 0; i < array2.length; i++) {
                System.out.println(array2[i]);
            }
        } else {
            System.out.println("Both are equal");
        }
    }
}
