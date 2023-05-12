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
        // check that denominator doesn't equal 0

        if (d.equals(new BigInteger("0"))) {
            throw new ArithmeticException("Cannot have 0 as a deniminator");
        } else {
            numerator = n;
            denimonator = d;
        }
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
    }

    public String toString() {
        if (numerator.mod(denimonator).equals(new BigInteger("0"))) {
            return (numerator.divide(denimonator)).toString();
        } else if (numerator.compareTo(denimonator) == -1) {
            // denominator is larger than numerator
            // therefore number is between 0-1
            return numerator.toString() + "/" + denimonator.toString();
        } else {
            // fractional number > 1
            return numerator.divide(denimonator) + "." + numerator.mod(denimonator) + "/" + denimonator;
        }
    }

}
