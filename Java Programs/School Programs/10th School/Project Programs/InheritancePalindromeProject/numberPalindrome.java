package InheritancePalindromeProject;

import java.util.*;

public class numberPalindrome extends stringPalindrome {
    public void numberPal() {
        int number;
        int unitDigit;
        int numTemp;
        int numReverse = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number");
        number = sc.nextInt();
        numTemp = number;
        while (numTemp > 0) {
            unitDigit = numTemp % 10;
            numReverse = numReverse * 10 + unitDigit;
            numTemp /= 10;
        }
        if (numReverse == number) {
            System.out.println("This string is a palindrome number");
        } else {
            System.out.println("This string is a not palindrome number");
        }
    }
}
