import java.util.*;

public class arraySalary {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Scanner ob = new Scanner(System.in);
        int salary[] = new int[20];
        String name[] = new String[20];
        System.out.println("Enter the names and salaries");
        for (int i = 0; i < 20; i++) {
            name[i] = ob.nextLine();
            salary[i] = sc.nextInt();
        }
        System.out.println("Salary above 70000");
        for (int i = 0; i < 20; i++) {
            if (salary[i] >= 70000) {
                System.out.println(salary[i] + "\t" + name[i]);
            }
        }
    }
}
