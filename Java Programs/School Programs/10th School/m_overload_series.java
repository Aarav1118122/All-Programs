public class m_overload_series
{
    public static void main(String[]args)
    {
        series(2.0);
        series(3.0,1.0);
    }
    public static void series(double n)
    {
        double sum = 0;
        for(double i = 1;i <= n;i++)
        {
            sum = sum + (1/i);
        }
        System.out.println(sum);
    }
    public static void series(double n,double a)
    {
        double sum = 0;
        double j = 1;
        for(double i = 1;i <= n;i++)
        {
            sum = sum + (j/Math.pow(a,j+1));
            j+=3;
        }
        System.out.println(sum);
    }
}