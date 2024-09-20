public class pyramid_floyd
{
    public static void main (String[]arg)
    {
        int n=1,i,j;
        for(i=1;i<=5;i++)
        {
            for(j=1;j<=i;j++)
            {
                System.out.print(n+" "); 
                n++;
            }
            System.out.println();
        }
    }
}