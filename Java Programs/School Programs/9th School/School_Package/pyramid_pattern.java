package School_Package;
public class pyramid_pattern
{
    public static int pattern(int s_value,int e_value,int input)
    {
        int i,j,p_value;
        for(i=s_value;i<=e_value;i++)
        {
            p_value=input;
            for(j=s_value;j<=i;j++)
            {
                System.out.print(Math.abs(p_value)+" ");
                p_value++;
            }
            System.out.println();
        }
        return 0;
    }
    public static int rpattern(int s_value,int e_value)
    {
        int z=0,i,j;
        for(i=s_value;i>=e_value;i--)
        {
            z=1;
            for(j=i;j>=e_value;j--)
            {
                System.out.print(z+" ");
                z++;
            }
            System.out.println();
        }
        return 0;
    }  
}