package School_Package;
public class triangle_pattern
{
    public static int pattern(int input,int loop1,int loop2)
    {
        int i,n,a,j;
        for(i=loop1;i<=input;i++)
        {
            n=input-i+1;
            for(j=1;j<n;j++)
            {         
                System.out.print(" ");
            }
            for(j=loop2;j<=i;j++)
            {           
                System.out.print(j+" ");
            }
            System.out.println();
        }
        return 0;
    }
}