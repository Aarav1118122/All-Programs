public class constradd
{
    int a,b,sum;
    public constradd(int a , int b)
    {
        this.a = a;
        this.b = b;
    }
    public static void main()
    {
        constradd ca = new constradd(5,6);
        ca.sum = ca.a+ca.b;
        System.out.print(ca.sum);
    }
}