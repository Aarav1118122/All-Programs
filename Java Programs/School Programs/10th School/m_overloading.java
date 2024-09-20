public class m_overloading {
    public static void main(String[] args) {
        sumSeries(5, 6.0);
        sumSeries();
    }

    public static void sumSeries(int n, double x) {
        double s = 0;
        for (double i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                s = s - (x / i);
            } else {
                s = s + (x / i);
            }
        }
        System.out.println(s);
    }

    public static void sumSeries() {
        int s = 0;
        for (int i = 1; i <= 20; i++) {
            s = s + factorial(i);
        }
        System.out.print(s);
    }

    public static int factorial(int no) {
        int fact = 1;
        if (no != 0) {
            do {
                fact = fact * no;
            } while (--no != 0);
        }
        return fact;
    }
}