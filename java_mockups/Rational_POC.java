import java.math.BigInteger;

public class Rational_POC {
    public static void main(String[] args) {
        BigInteger num1 = new BigInteger("5");
        BigInteger num2 = new BigInteger("2");
        BigInteger num3 = new BigInteger("4");
        BigInteger num4 = new BigInteger("0");
        Rational_Wrapper real1 = new Rational_Wrapper(num1, num2);
        Rational_Wrapper real2 = new Rational_Wrapper(num1);
        Rational_Wrapper real3 = new Rational_Wrapper(num1, num2, num3);
        Rational_Wrapper real4 = new Rational_Wrapper(num3, num2);
        Rational_Wrapper real5 = new Rational_Wrapper(num2, num1);
        Rational_Wrapper real6 = new Rational_Wrapper(num4);
        // Rational_Wrapper real7 = new Rational_Wrapper(num1, num4); //throws exception
        Rational_Wrapper real8 = new Rational_Wrapper(num4, num1, num2);
        Rational_Wrapper real9 = new Rational_Wrapper(num1, num4, num2);
        // Rational_Wrapper real10 = new Rational_Wrapper(num1, num2, num4); // throws
        // exception
        Rational_Wrapper real11 = new Rational_Wrapper(num4, num1);
        System.out.println(real1);
        System.out.println(real2);
        System.out.println(real3);
        System.out.println(real4);
        System.out.println(real5);
        System.out.println(real6);
        // System.out.println(real7);
        System.out.println(real8);
        System.out.println(real9);
        // System.out.println(real10);
        System.out.println(real11);
    }
}