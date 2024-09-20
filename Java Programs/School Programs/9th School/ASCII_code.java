public class ASCII_code
{
    public static void main(String[]args)
    {
        char[] letters ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        int ASCII;
        for(int i=0;i<=25;i++)
        {
            ASCII=letters[i];
            System.out.println(letters[i]+"    "+ASCII);
        }
    }
}