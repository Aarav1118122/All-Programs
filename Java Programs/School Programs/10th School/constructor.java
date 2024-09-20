public class constructor
{
    int x,y,z;
    public constructor()
    {
        x = 5;
        y = 6;
        z = 7;
    }
    public static void main(String[]args)
    {
        constructor obj = new constructor();
        System.out.print(obj.x+" "+obj.y+" "+obj.z);
    }
}