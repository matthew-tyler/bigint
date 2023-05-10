import java.util.*;

public class array_padding {
    public static void main(String[] args) {
        Integer[] nums = { 5, 2 };
        ArrayList<Integer> arr = new ArrayList<Integer>(Arrays.asList(nums));

        System.out.println(arr);

        // arr.add(0, 0);
        int n = 5;
        for (int i = 0; i < n; i++) {
            arr.add(0, 0);
        }

        System.out.println(arr);
    }

}
