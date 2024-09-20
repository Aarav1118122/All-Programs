import java.util.*;

public class arrayBinaryNames {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String names[] = new String[5];
        String target;
        System.out.println("Enter five names");
        for (int i = 0; i < names.length; i++) {
            names[i] = sc.nextLine();
        }
        System.out.println("Enter the name you wanna find");
        target = sc.nextLine();
        for (int i = 0; i < names.length - 1; i++) {
            for (int k = 0; k <= i; k++) {
                for (int j = 0; j < names[k].length(); j++) {
                    if ((int) names[k].charAt(j) < (int) names[k + 1].charAt(j)) {
                        break;
                    } else if ((int) names[k].charAt(j) > (int) names[k + 1].charAt(j)) {
                        String swap = names[k];
                        names[k] = names[k + 1];
                        names[k + 1] = swap;
                    } else {
                        continue;
                    }
                }
            }
        }
        for (String name : names) {
            System.out.println(name);
        }
    }
}
