public class triangle_area {
    double height, base, area;

    triangle_area(double hinput, double binput) {
        height = hinput;
        base = binput;
    }

    public static void main(String[] args) {
        triangle_area t1 = new triangle_area(3, 8);
        System.out.println(t1.height * t1.base * 0.5);
    }
}