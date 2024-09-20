import java.util.*;

public class stringUptoLo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String word;
        System.out.println("Enter a word");
        word = sc.nextLine();
        for (int i = 0; i < word.length(); i++) {
            word = word.toLowerCase();
            char ch = word.charAt(i);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                word = word.replace(ch, (char) ((int) ch + 1));
            }
        }
        System.out.println(word);
    }
}
