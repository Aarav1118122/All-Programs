public class arrayTwoDimensional {
    public static void main(String[] args) {
        String array[][] = { { "Aarav", "Atharv", "Gopal", "Sparsh", "Abheer" }, { "80", "85", "82", "86", "90" } };
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.println(array[i][j] + " " + array[i + 1][j]);
            }
        }
    }
}
