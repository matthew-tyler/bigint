package rational_thinking;

import java.lang.reflect.Array;
import java.util.*;

public class ArrayAdditionPOC{
    public static void main(String[] args) {
        // ArrayList<Integer> num1 = new ArrayList<Integer>(Arrays.asList(3,2,9));
        // ArrayList<Integer> num2 = new ArrayList<Integer>(Arrays.asList(8,9));

        // System.out.println(num1);
        // System.out.println(num2);

        // int carry = 0;
        // int sum = num1.get(0) + num2.get(0) + carry;
        // int curr_col_result = sum % 10;
        // if(sum>9){
        //     carry = 1;
        // }
        // System.out.println(sum);
        // System.out.println(curr_col_result);
        // System.out.println(carry);

        ArrayInteger num1 = new ArrayInteger("3045689708989768958465634498976854323456789765432134568790");
        ArrayInteger num2 = new ArrayInteger("5");
        // System.out.println(num1);
        // System.out.println(num2);

        // ArrayInteger sum  = ArrayInteger.add(num1, num2);
        // System.out.println(sum);

        // System.out.println(ArrayInteger.subtract(num1, num2));

        // division practise
        // int[] divisor_and_remainder = ArrayInteger.divideInternal(num1, num2);
        // System.out.println(Arrays.toString(divisor_and_remainder));

        ArrayInteger divided = ArrayInteger.divide(num1, num2);
        System.out.println(divided);

        ArrayInteger mod = ArrayInteger.modulus(num1, num2);
        System.out.println(mod);


        // System.out.println(num1.isLargerThan(num2));

        //System.out.println(ArrayInteger.isAbsoluteArrayLarger(num1.digits, num2.digits));
        // num1.add(num2);
    }
}
