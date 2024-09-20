import java.util.*;

public class binaryDecimal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int binary, binaryTemp, i = 0;
        double decimal = 0;
        System.out.println("Enter a binary number");
        binary = sc.nextInt();
        binaryTemp = binary;
        while (binaryTemp > 0) {
            decimal = decimal + ((binaryTemp % 10) * Math.pow(2, i));
            binaryTemp /= 10;
            i++;
        }
        System.out.println("Decimal for " + binary + " is " + decimal);
    }
}
