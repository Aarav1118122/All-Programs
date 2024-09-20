public class arrayDeleteIndex {
    public static void main(String[] args) {
        int array[] = { 30, 56, 34, 24, 54 };
        int index = 3;
        array[3] = 0;
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }
}
