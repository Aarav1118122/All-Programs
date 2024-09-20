public class arrayDeleteNumber {
    public static void main(String[] args) {
        int array[] = { 30, 56, 34, 24, 54 };
        int array2[] = new int[4];
        int delete = 34;
        for (int i = 0; i < array.length; i++) {
            if (array[i] == delete) {
                int j = i;
                while (j < array.length - 1) {
                    array2[j] = array[j + 1];
                    j++;
                }
                break;
            } else
                array2[i] = array[i];
        }
        for (int i = 0; i < array2.length; i++) {
            System.out.println(array2[i]);
        }
    }
}
