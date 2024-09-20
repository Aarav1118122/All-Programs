package InheritancePalindromeProject;

import java.util.*;

public class stringPalindrome {

    public void stringPal() {
        String word;
        String reverseWord = "";
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string");
        word = sc.nextLine();
        for (int i = word.length() - 1; i >= 0; i--) {
            reverseWord += word.charAt(i);
        }
        if (reverseWord.equalsIgnoreCase(word)) {
            System.out.println("This number is a palindrome string");

        } else {
            System.out.println("This number is not a palindrome string");
        }

    }
}