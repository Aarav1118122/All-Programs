public class arrayLargest {
    public static void main(String[] args) {
        int array[] = { 5, 23, 5, 235, 7 };
        int largest = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] > largest) {
                largest = array[i];
            }
        }
        System.out.println("The largest number is " + largest);
    }
}
