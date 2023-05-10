package rational_thinking;

import java.lang.reflect.Array;
import java.util.*;

public class ArrayInteger {
    private ArrayList<Integer> digits;
    private int sign;

    public ArrayInteger(String str_number) {
        sign = 1;
        if (str_number.charAt(0) == '-') {
            sign = -1;
            str_number = str_number.substring(1, str_number.length());
        }
        Integer[] nums = new Integer[str_number.length()];

        for (int i = 0; i < str_number.length(); i++) {
            nums[i] = Character.getNumericValue(str_number.charAt(str_number.length() - 1 - i));
        }
        digits = new ArrayList<Integer>(Arrays.asList(nums));
    }

    public boolean isLargerThan(ArrayInteger num2) {
        if (this.sign != num2.sign) { // one is positive and the other is negative
            return this.sign == 1; // returns true if the sign is positive and false otherwise (can only be
                                   // positive or negative)
        }

        // can assume that both have the same sign
        // compare lengths
        if (this.digits.size() != num2.digits.size()) {
            // imbalance of sizes
            // returns true if positive sign and more letters or negative sign and less
            // letters
            return ((sign == 1 && this.digits.size() > num2.digits.size())
                    || (sign == -1 && this.digits.size() < num2.digits.size()));
        }

        // can assume same sign and same # letters
        // loop through each from most to least significant figure
        // as soon as find an imbalance return
        // otherwise return false
        for (int i = this.digits.size() - 1; i >= 0; i--) {
            // most significant figure is at the end
            if (this.digits.get(i) != num2.digits.get(i)) {
                return ((sign == 1 && this.digits.get(i) > num2.digits.get(i))
                        || (sign == -1 && this.digits.get(i) < num2.digits.get(i))); // will return true if positive
                                                                                     // sign and number is greater, or
                                                                                     // negative sign and number is less
            }
        }
        // if has not returned true until here - they are equal and therefore it will
        // return false
        return false;
    }

    public boolean isEqualTo(ArrayInteger num2) {
        return this.toString().equals(num2.toString());
    }

    public static boolean isAbsoluteArrayLarger(ArrayList<Integer> a1, ArrayList<Integer> a2) {
        // if the sizes are different then it will return true if a1 is longer and false
        // if s1 is not longer
        if (a1.size() != a2.size()) {
            return (a1.size() > a2.size());
        }

        // can assume same sign and same # letters
        // loop through each from most to least significant figure
        // as soon as find an imbalance return
        // otherwise return false
        for (int i = a1.size() - 1; i >= 0; i--) {
            // most significant figure is at the end
            if (a1.get(i) != a2.get(i)) {
                return (a1.get(i) > a2.get(i));
            }
        }
        // if has not returned true until here - they are equal and therefore it will
        // return false
        return false;
    }

    public static ArrayInteger[] divideInternal(ArrayInteger numerator, ArrayInteger denominator) {
        ArrayInteger i = new ArrayInteger("0");
        ArrayInteger remainder = new ArrayInteger(numerator.toString());
        while (remainder.isLargerThan(new ArrayInteger("0"))) {
            remainder = ArrayInteger.subtract(remainder, denominator); // take the demon from the remainder
            // System.out.println("remainder: "+remainder.toString());
            if (remainder.isLargerThan(new ArrayInteger("0")) || remainder.isEqualTo(new ArrayInteger("0"))) {
                i = ArrayInteger.add(i, new ArrayInteger("1")); // keeping track of the number of times it is looping
            }

        }
        // remainder.sign = remainder.sign * remainder.sign; //this will ensure the
        // absolute value of the sign is taken so the remainder won't be negative
        if (!remainder.isEqualTo(new ArrayInteger("0"))) {
            remainder = ArrayInteger.add(remainder, denominator);
        }

        ArrayInteger[] divisor_and_remainder = { i, remainder };
        return divisor_and_remainder;
    }

    public static ArrayInteger divide(ArrayInteger numerator, ArrayInteger denominator) {
        int numeratorOriginalSign = numerator.sign;
        int denominatorOriginalSign = denominator.sign;

        // setting both num and denom to +ve and will switch back to normal at the end
        numerator.sign = 1;
        denominator.sign = 1;

        String answer = ""; // integer answer for division
        String currMod = String.valueOf(numerator.digits.get(numerator.digits.size() - 1));
        ArrayInteger currentNumerator;
        // loop while there still is a number in the array
        // starts from -2 since have already taken the last item
        for (int i = numerator.digits.size() - 2; i >= -1; i--) {
            currentNumerator = new ArrayInteger(currMod);
            ArrayInteger[] division = ArrayInteger.divideInternal(currentNumerator, denominator);
            // testing
            // System.out.println(Arrays.toString(division));

            // only adds if it is not trying to add a 0 to the start
            if (!(division[0].toString().equals("0") && answer.length() == 0)) {
                answer = answer + division[0];
            }

            currMod = division[1].toString();
            // currMod = String.valueOf(division[1]);
            // protects against trying to access outside bounds
            if (i >= 0) {
                currMod = currMod + String.valueOf(numerator.digits.get(i));
            }
        }

        // setting back num and denom to normal
        numerator.sign = numeratorOriginalSign;
        denominator.sign = denominatorOriginalSign;

        ArrayInteger result = new ArrayInteger(answer);
        result.sign = numerator.sign * denominator.sign;
        return result;

    }

    public static ArrayInteger modulus(ArrayInteger numerator, ArrayInteger denominator) {
        int numeratorOriginalSign = numerator.sign;
        int denominatorOriginalSign = denominator.sign;

        // setting both num and denom to +ve and will switch back to normal at the end
        numerator.sign = 1;
        denominator.sign = 1;

        String answer = ""; // integer answer for division
        String currMod = String.valueOf(numerator.digits.get(numerator.digits.size() - 1));
        ArrayInteger currentNumerator;
        // loop while there still is a number in the array
        // starts from -2 since have already taken the last item
        for (int i = numerator.digits.size() - 2; i >= -1; i--) {
            currentNumerator = new ArrayInteger(currMod);
            ArrayInteger[] division = ArrayInteger.divideInternal(currentNumerator, denominator);
            // testing
            // System.out.println(Arrays.toString(division));
            if (!(division[0].toString().equals("0") && answer.length() == 0)) {
                answer = answer + division[0];
            }

            currMod = division[1].toString();
            // currMod = String.valueOf(division[1]);
            // protects against trying to access outside bounds
            if (i >= 0) {
                currMod = currMod + String.valueOf(numerator.digits.get(i));
            }

            // testing
            // System.out.println(currMod);
        }

        // setting back num and denom to normal
        numerator.sign = numeratorOriginalSign;
        denominator.sign = denominatorOriginalSign;

        ArrayInteger result = new ArrayInteger(currMod);
        result.sign = numerator.sign * denominator.sign;
        return result;

    }

    public static ArrayInteger multiplicationInternal(ArrayInteger num, int multiplier, int numTens) {
        // This will just repeat addition for multiplier times
        // Due to the way that I am implementing multiplication, the highest multiplier
        // will be is 9 so I can put it into a for loop
        ArrayInteger answer = new ArrayInteger("0"); // not using num since it will change the original copy
        if (multiplier != 0) {
            for (int i = 0; i < multiplier; i++) {
                answer = ArrayInteger.add(answer, num); // add the number again and again tp build up the answer
            }

            for (int i = 0; i < numTens; i++) {
                answer.digits.add(0, 0); // pad with 0s depending on how many times it needs to be put to the power of
                                         // 10
            }
        }

        return answer;
    }

    public static ArrayInteger multiplication(ArrayInteger num, ArrayInteger multiplier) {
        int numOriginalSign = num.sign;
        int multiplierOriginalSign = multiplier.sign;

        // setting both to 1 to ensure normal multiplication - will switch back after
        num.sign = 1;
        multiplier.sign = 1;

        ArrayInteger result = new ArrayInteger("0"); // start the result as 0 and keep adding the results of multiplying
                                                     // each part

        // find the smaller number (larger or smaller)
        // if smaller > larger then call multiplication again passing it with parameters
        // swapped around
        if (multiplier.isLargerThan(num)) {
            return multiplication(multiplier, num);
        }

        for (int i = 0; i < multiplier.digits.size(); i++) {
            result = ArrayInteger.add(result, ArrayInteger.multiplicationInternal(num, multiplier.digits.get(i), i));
            // testing
            // System.out.println("multiplier: " + multiplier.digits.get(i) + " result of
            // multiplying: " + result);
        }

        num.sign = numOriginalSign;
        multiplier.sign = multiplierOriginalSign;

        result.sign = num.sign * multiplier.sign;
        return result;
    }

    public static ArrayInteger subtract(ArrayInteger curr, ArrayInteger subtractor) {
        int subSignOriginal = subtractor.sign;
        subtractor.sign = subtractor.sign * -1; // flip the sign of the number taking off
        ArrayInteger result = ArrayInteger.add(curr, subtractor);
        subtractor.sign = subSignOriginal;
        return result;
    }

    public static ArrayInteger add(ArrayInteger curr, ArrayInteger adder) { // make this private
        // Takes a copy of the current arraylists and will reset curr_num and num2 with
        // these after performing the addition
        // this is to prevent side effects and changing the value since it is passed by
        // reference and not value
        Integer[] currNumOriginal = new Integer[curr.digits.size()];
        Integer[] adderOriginal = new Integer[adder.digits.size()];
        currNumOriginal = curr.digits.toArray(currNumOriginal);
        adderOriginal = adder.digits.toArray(adderOriginal);
        int currSignOriginal = curr.sign;
        int adderSignOriginal = adder.sign;

        int outputSign = 0;

        // if the signs are different and the absolute value of b is greater than a
        // flip the signs, perform the equation and then set the instance's signs back
        if (curr.sign != adder.sign) {
            if ((curr.sign == -1 && isAbsoluteArrayLarger(curr.digits, adder.digits))
                    || (adder.sign == -1 && isAbsoluteArrayLarger(adder.digits, curr.digits))) {
                curr.sign = curr.sign * -1;
                adder.sign = adder.sign * -1;
                // need to make sure to flip the bit of the output
                outputSign = -1;

            } else {
                outputSign = 1;
            }
        } else {
            curr.sign = 1; // this treats double negatives as a normal addition and works out the signs at
                           // the end
            adder.sign = 1;
        }

        ArrayList<Integer> output = new ArrayList<Integer>();
        int carry = 0; // carry will be 0 or 1 and multiplied by (num1.sign * num2.sign)

        int i = 0;
        while ((curr.digits.size() > i && adder.digits.size() > i) || (curr.digits.size() > i && carry != 0)
                || (adder.digits.size() > i && carry != 0)) { // loops while both have column i

            int curr_i;
            int adder_i;
            try {
                curr_i = curr.digits.get(i);
            } catch (Exception e) {
                curr_i = 0;
            }

            try {
                adder_i = adder.digits.get(i);
            } catch (Exception e) {
                adder_i = 0;
            }

            int sum = ((curr.sign * curr_i) + (adder.sign * adder_i) + carry);
            int output_i = (sum + 10) % 10; // accounts for subtraction and addition
            output.add(output_i);

            carry = 0;
            if (sum < 0 || sum > 9) {
                carry = 1 * curr.sign * adder.sign; // +1 if both signs are +ve or -ve. -1 if one sign is negative
            }

            i++;
        }

        // while loop for each arraylist - if there is left over information then it
        // will just append it to the output list
        while (i < curr.digits.size()) {
            output.add(curr.digits.get(i));
            i++;
        }
        while (i < adder.digits.size()) {
            output.add(adder.digits.get(i));
            i++;
        }

        if (carry == 1) {
            output.add(carry);
        }

        // reset the values of the array integers to oringals saved at the start of the
        // method
        curr.digits = new ArrayList<Integer>(Arrays.asList(currNumOriginal));
        adder.digits = new ArrayList<Integer>(Arrays.asList(adderOriginal));
        curr.sign = currSignOriginal;
        adder.sign = adderSignOriginal;

        if (outputSign == 0) {
            outputSign = (curr.sign + adder.sign) / 2;
        }

        if (output.get(output.size() - 1) == 0 && output.size() > 1) {
            output.remove(output.size() - 1);
        }

        ArrayInteger outputInt;
        if (outputSign == 1) {
            outputInt = new ArrayInteger(intArrayListToStringFlipped(output));
        } else {
            outputInt = new ArrayInteger("-" + intArrayListToStringFlipped(output));
        }

        return outputInt;
    }

    private static String intArrayListToStringFlipped(ArrayList<Integer> arr) {
        StringBuilder str = new StringBuilder();
        for (int i = arr.size() - 1; i >= 0; i--) {
            str.append(arr.get(i));
        }
        return str.toString();
    }

    public String printDebug() {
        return digits.toString();
    }

    public String toString() {
        StringBuilder returnString = new StringBuilder();
        if (sign == -1) {
            returnString.append("-");
        }
        for (int i = digits.size() - 1; i >= 0; i--) {
            returnString.append(String.valueOf(digits.get(i)));
        }
        return returnString.toString();
    }
}
