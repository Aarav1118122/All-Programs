package School_Package;
public class factorial
{   
    public static double fact(double x)
    {
        double y=1;
        if (x!=0)
        {
            do
            {
                y=y*x;
            }
            while (--x!=0);
        }
        return y;
    }
}   