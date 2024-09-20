package AccountDetails;

public class Main {
    public static void main(String[] args) {
        accountDetails account = new accountDetails();
        account.setName("Aarav Gupta");
        account.setPhone(987654321);
        account.setAccount(5623);
        System.out.println("Your name is " + account.getName() + "\nYour Phone number is " + account.getPhone()
                + "\nYour account number is " + account.getAccount());
    }
}
