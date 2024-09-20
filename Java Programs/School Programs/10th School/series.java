public class series {
    public static void main(String[] args) {
        Series(5.0);
        Series(10.0, 2.0);
    }

    public static void Series(double n) {
        double sum = 0;
        for (double i = 1; i <= n; i++) {
            sum = sum + (1 / i);
        }
        System.out.println(sum);
    }

    public static void Series(double n, double a) {
        double sum = 0;
        double j = 1;
        for (int i = 1; i <= n; i++) {
            sum = sum + (j / (Math.pow(a, j + 1)));
            j += 3;
        }
        System.out.println(sum);
    }
}