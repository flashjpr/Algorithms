package mihai.arrays;
import java.util.Scanner;

public class ReverseArray {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Please insert the number of elements of the array:");
        int n = in.nextInt();
        int[] array = new int[n];

        System.out.println("Please insert the elements, space separated:");
        for (int i = 0; i < n; i++){
            array[i] = in.nextInt();
        }

        reverse(array);

        System.out.println("The reversed array is:");
        for(int a : array)
            System.out.print(a + " ");
    }

    public static void reverse (int[] array) {
        int temp, middle = array.length / 2;
        if (array == null || array.length <= 1) return;

        for (int i = 0; i <= middle; i++) {
            temp = array[i];
            array[i] = array[array.length - i -1];
            array[array.length - i -1] = temp;
        }
    }
}
