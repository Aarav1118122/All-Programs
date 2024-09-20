import java.util.*;

public class incomeTax {
    String gender;
    int age;
    long TI;
    double incomeTax;

    public static void main(String[] args) {
        incomeTax person = new incomeTax();
        person.accept();
        person.calculate();
        person.display();
    }

    public void accept() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your gender");
        gender = sc.nextLine();
        System.out.println("Enter your age");
        age = sc.nextInt();
        if (age <= 65 && gender.equalsIgnoreCase("male")) {
            System.out.println("Enter your taxable income");
            TI = sc.nextLong();
        }
    }

    public void calculate() {
        if (age <= 65 && gender.equalsIgnoreCase("male")) {
            if (TI <= 160000) {
                incomeTax = 0;
            } else if (TI > 160000 && TI <= 500000) {
                incomeTax = (TI - 160000) * 0.1;
            } else if (TI > 500000 && TI <= 800000) {
                incomeTax = ((TI - 500000) * 0.2) + 34000;
            } else {
                incomeTax = ((TI - 800000) * 0.3) + 94000;
            }
        } else {
            System.out.println("Worng Category");
        }
    }

    public void display() {
        if (age <= 65 && gender.equalsIgnoreCase("male")) {
            System.out.println(
                    "Gender: " + gender + "\nAge: " + age + "\nTaxable Income: " + TI + "\nIncome Tax: " + incomeTax);
        }
    }
}
