import java.util.*;

public class arrayTwoDimIndex {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int array[][] = { { 01, 02, 03, 04, 05 }, { 10, 11, 12, 13, 14 } };
        int indexX, indexY;
        System.out.println("Enter the index you want to see");
        indexX = sc.nextInt();
        indexY = sc.nextInt();
        if (indexX <= 1 && indexY <= 4) {
            System.out.println(array[indexX][indexY]);
        } else {
            System.out.println("The index is not valid");
        }
    }
}
