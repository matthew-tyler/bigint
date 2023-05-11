package rational_thinking;

import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class ArrayAdditionPOC {
    public static void main(String[] args) {
        // ArrayList<Integer> num1 = new ArrayList<Integer>(Arrays.asList(3,2,9));
        // ArrayList<Integer> num2 = new ArrayList<Integer>(Arrays.asList(8,9));

        // System.out.println(num1);
        // System.out.println(num2);

        // int carry = 0;
        // int sum = num1.get(0) + num2.get(0) + carry;
        // int curr_col_result = sum % 10;
        // if(sum>9){
        // carry = 1;
        // }
        // System.out.println(sum);
        // System.out.println(curr_col_result);
        // System.out.println(carry);

        ArrayInteger num1 = new ArrayInteger("-567670898797986721");
        ArrayInteger num2 = new ArrayInteger("4098765545343543544");
        BigInteger num1BigInt = new BigInteger(num1.toString());
        BigInteger num2BigInt = new BigInteger(num2.toString());

        System.out.println("Division");
        ArrayInteger divided = ArrayInteger.divide(num1, num2);
        System.out.println("My Answer: \n" + divided);

        System.out.println("BigInt Answer: \n" + num1BigInt.divide(num2BigInt));

        System.out.println("Modulus");
        ArrayInteger mod = ArrayInteger.modulus(num1, num2);
        System.out.println("My Answer: \n" + mod);

        System.out.println("BigInt Answer: \n" + num1BigInt.remainder(num2BigInt));

        System.out.println("Multiplication");
        ArrayInteger multiplied = ArrayInteger.multiplication(num1, num2);
        System.out.println("My Answer: \n" + multiplied);

        System.out.println("BigInt Answer: \n" + num1BigInt.multiply(num2BigInt));
    }
}
