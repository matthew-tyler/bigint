import java.math.BigInteger;

public class Rational_Wrapper {
    private BigInteger numerator;
    private BigInteger denimonator;

    // constructor which takes a whole int
    public Rational_Wrapper(BigInteger integer) {
        numerator = integer;
        denimonator = new BigInteger("1");
    }

    // consetructor which takes in a rational number with numerator and denominator
    public Rational_Wrapper(BigInteger n, BigInteger d) {
        // testing
        System.out.println("Standardised: " + n + "/" + d);

        // check that denominator doesn't equal 0

        if (d.equals(new BigInteger("0"))) {
            throw new ArithmeticException("Cannot have 0 as a deniminator");
        } else {
            numerator = n;
            denimonator = d;
        }

        standardizeSigns();

    }

    public Rational_Wrapper(BigInteger w, BigInteger n, BigInteger d) {

        if (d.equals(new BigInteger("0"))) {
            throw new ArithmeticException("Cannot have 0 as a deniminator");
        } else {
            numerator = n;
            denimonator = d;
        }

        numerator = w.multiply(d).add(n); // w.n/d multiply numerator by the denominator and then add it to the current
                                          // numerator
        denimonator = d;

        standardizeSigns();
    }

    public boolean isLessThan(Rational_Wrapper comparitor) {
        BigInteger balanced_curr_numerator = numerator.multiply(comparitor.denimonator);
        BigInteger balanced_comp_numerator = comparitor.numerator.multiply(denimonator);
        return balanced_curr_numerator.compareTo(balanced_comp_numerator) == -1; // returns true if the balanced
                                                                                 // numerator of the current is greater
                                                                                 // than the second
    }

    public boolean isGreaterThan(Rational_Wrapper comparitor) {
        BigInteger balanced_curr_numerator = numerator.multiply(comparitor.denimonator);
        BigInteger balanced_comp_numerator = comparitor.numerator.multiply(denimonator);
        return balanced_curr_numerator.compareTo(balanced_comp_numerator) == 1; // returns true if the balanced
                                                                                // numerator of the current is less than
                                                                                // the second
    }

    public boolean equals(Rational_Wrapper comparitor) {
        BigInteger balanced_curr_numerator = numerator.multiply(comparitor.denimonator);
        BigInteger balanced_comp_numerator = comparitor.numerator.multiply(denimonator);
        return balanced_curr_numerator.compareTo(balanced_comp_numerator) == 0; // returns true if the balanced
                                                                                // numerator of the current is equal to
                                                                                // the second
    }

    public static Rational_Wrapper multiply(Rational_Wrapper num1, Rational_Wrapper num2) {
        BigInteger new_numerator = num1.numerator.multiply(num2.numerator);
        BigInteger new_denominator = num1.denimonator.multiply(num2.denimonator);
        // standardizeSigns(new_numerator, new_denominator);
        Rational_Wrapper result = new Rational_Wrapper(new_numerator, new_denominator);
        return result;
    }

    public static Rational_Wrapper divide(Rational_Wrapper numerator, Rational_Wrapper denimonator) {
        BigInteger new_numerator = numerator.numerator.multiply(denimonator.denimonator);
        BigInteger new_denominator = numerator.denimonator.multiply(denimonator.numerator);
        // standardizeSigns(new_numerator, new_denominator);
        Rational_Wrapper result = new Rational_Wrapper(new_numerator, new_denominator);
        return result;
    }

    public static Rational_Wrapper add(Rational_Wrapper num1, Rational_Wrapper num2) {
        BigInteger new_numerator = (num1.numerator.multiply(num2.denimonator))
                .add(num2.numerator.multiply(num1.denimonator));
        BigInteger new_denominator = num1.denimonator.multiply(num2.denimonator);
        // standardizeSigns(new_numerator, new_denominator);
        Rational_Wrapper result = new Rational_Wrapper(new_numerator, new_denominator);
        // testing
        // System.out.println("Addition: New numerator: " + new_numerator + " New
        // denominator: " + new_denominator);
        return result;
    }

    public static Rational_Wrapper subtract(Rational_Wrapper num1, Rational_Wrapper num2) {
        BigInteger new_numerator = (num1.numerator.multiply(num2.denimonator))
                .subtract(num2.numerator.multiply(num1.denimonator));
        BigInteger new_denominator = num1.denimonator.multiply(num2.denimonator);
        // standardizeSigns(new_numerator, new_denominator);
        Rational_Wrapper result = new Rational_Wrapper(new_numerator, new_denominator);
        // testing
        // System.out.println("Addition: New numerator: " + new_numerator + " New
        // denominator: " + new_denominator);
        return result;
    }

    public void standardizeSigns() { // accesses data fields
        // isn't needed as it will change the value of the
        // original
        int n_sign = 1;
        int d_sign = 1;
        if (numerator.compareTo(new BigInteger("0")) == -1) {
            // smaller than 0
            n_sign = -1;
        }
        if (denimonator.compareTo(new BigInteger("0")) == -1) {
            // smaller than 0
            d_sign = -1;
        }

        if (n_sign != d_sign) {
            // imbalance
            // make the numerator negative and the denominator positive - this might cause
            // problems with 0 if it has a unique sign
            numerator = numerator.multiply(new BigInteger(String.valueOf(n_sign))).multiply(new BigInteger("-1"));
            denimonator = denimonator.multiply(new BigInteger(String.valueOf(d_sign)));
        } else {
            // if they have the same sign then the whole thing should be +ve
            numerator = numerator.multiply(new BigInteger(String.valueOf(n_sign)));
            denimonator = denimonator.multiply(new BigInteger(String.valueOf(d_sign)));
        }

        // testing
        // System.out.println("Standardised: " + n + "/" + d);
    }

    public String toString() {
        if (numerator.remainder(denimonator).equals(new BigInteger("0"))) {
            return (numerator.divide(denimonator)).toString();
        } else if (numerator.abs().compareTo(denimonator.abs()) == -1) {
            // denominator is larger than numerator
            // therefore number is between 0-1
            return numerator.toString() + "/" + denimonator.toString();
        } else {
            // fractional number > 1
            return numerator.divide(denimonator) + "." + numerator.remainder(denimonator).abs() + "/" + denimonator;
        }
    }

}
