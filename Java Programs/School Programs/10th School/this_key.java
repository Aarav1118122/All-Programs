public class this_key
{
    int s,area;
    public this_key(int s)
    {
        this.s = s;
        area = this.s*this.s;
    }
    public static void main(String[]args)
    {
        this_key tk = new this_key(5);
        System.out.println(tk.area);
    }
}