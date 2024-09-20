public class m_overloading2 {
    public static void main(String[] args) {
        System.out.println(area(3.0, 3.0, 3.0));
        System.out.println(area(5, 6, 8));
        System.out.println(area(5, 9));
    }

    public static double area(double a, double b, double c) {
        double area, s;
        s = (a + b + c) / 2.0;
        area = Math.sqrt(s * (s - a) * (s - b) * (s - c));
        return area;
    }

    public static int area(int a, int b, int height) {
        int area;
        area = (height * (a + b)) / 2;
        return area;
    }

    public static double area(double diagonal1, double diagonal2) {
        double area;
        area = (diagonal1 * diagonal2) / 2;
        return area;
    }
}