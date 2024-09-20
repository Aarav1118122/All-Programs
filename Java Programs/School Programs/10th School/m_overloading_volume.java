public class m_overloading_volume
{
    public static void main(String[]args)
    {
        volume(2.0);
        volume(2.0,1.0);
        volume(3.0,2.0,1.0);
    } 
    public static void volume(double r)
    {
        double v;
        v=1.33*3.14*Math.pow(r,3);
        System.out.println(v);
    }
    public static void volume(double r,double h)
    {
        double v;
        v=3.14*Math.pow(r,2)*h;
        System.out.println(v);
    }
    public static void volume(double l,double b,double h)
    {
        double v;
        v=l*b*h;
        System.out.println(v);
    }
}