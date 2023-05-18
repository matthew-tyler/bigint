import java.math.BigInteger;

public class Rational_POC {
    public static void main(String[] args) {
        // BigInteger num1 = new BigInteger("5");
        // BigInteger num2 = new BigInteger("2");
        // BigInteger num3 = new BigInteger("4");
        // BigInteger num4 = new BigInteger("0");
        // Rational_Wrapper real1 = new Rational_Wrapper(num1, num2);
        // Rational_Wrapper real2 = new Rational_Wrapper(num1);
        // Rational_Wrapper real3 = new Rational_Wrapper(num1, num2, num3);
        // Rational_Wrapper real4 = new Rational_Wrapper(num3, num2);
        // Rational_Wrapper real5 = new Rational_Wrapper(num2, num1);
        // Rational_Wrapper real6 = new Rational_Wrapper(num4);
        // // Rational_Wrapper real7 = new Rational_Wrapper(num1, num4); //throws
        // exception
        // Rational_Wrapper real8 = new Rational_Wrapper(num4, num1, num2);
        // Rational_Wrapper real9 = new Rational_Wrapper(num1, num4, num2);
        // // Rational_Wrapper real10 = new Rational_Wrapper(num1, num2, num4); //
        // throws
        // Rational_Wrapper real11 = new Rational_Wrapper(num4, num1);
        // // exception

        // // Testing printing out numbers

        // System.out.println(real1);
        // System.out.println(real2);
        // System.out.println(real3);
        // System.out.println(real4);
        // System.out.println(real5);
        // System.out.println(real6);
        // // // System.out.println(real7);
        // System.out.println(real8);
        // System.out.println(real9);
        // // // System.out.println(real10);
        // System.out.println(real11);

        // // testing comparison
        // System.out.println(real2.isGreaterThan(real9));
        // System.out.println(real2.isLessThan(real9)); //
        // System.out.println(real2.equals(real9)); //

        // testing addition

        // 630785471 // 642281
        //  983.40964304277847/405554047982312, should be 983.65529/642281
        Rational_Wrapper real1 = new Rational_Wrapper(new BigInteger("630785471"), new BigInteger("642281"));
        Rational_Wrapper real2 = new Rational_Wrapper(new BigInteger("630785471"),
                ((new BigInteger("630785471")).add(new BigInteger("642281"))));

        // printing out the numbers
        System.out.println("Number 1: " + real1);
        System.out.println("Number 2: " + real2);

        // addition
        System.out.println(Rational_Wrapper.add(real1, real2));
        // subtraction
        System.out.println(Rational_Wrapper.subtract(real1, real2));
        // multiplication
        System.out.println(Rational_Wrapper.multiply(real1, real2));
        // division
        System.out.println(Rational_Wrapper.divide(real1, real2));

    }
}