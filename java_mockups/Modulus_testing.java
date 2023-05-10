public class Modulus_testing {
    public static void main(String[] args) {
        int dividend = -26;
        int divisor = 5;

        int modulus = modulus(dividend, divisor);
        System.out.println("Modulus: " + modulus);
        System.out.println("Remainder: " + (dividend % divisor));
    }

    public static int modulus(int dividend, int divisor) {
        if (divisor == 0) {
            throw new ArithmeticException("Cannot divide by zero");
        }

        int result = dividend % divisor;
        if (result < 0) {
            result += divisor;
        }

        return result;
    }

}
