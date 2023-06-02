#pragma once

// Most compilers understand the once pragma, but just in case...
#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include <stdint.h>

namespace cosc326
{
	/**
	 * @class Integer
	 * @brief This class represents an integer number of an arbitrary precision
	 */
	class Integer
	{

	public:
		/**
		 * @brief Default constructor
		 * This constructor initializes an Integer with a value of 0.
		 */
		Integer(); // Integer i;

		/**
		 * Copy Constructor for Integer class.
		 * This constructor creates a new Integer object by copying the contents of an existing Integer object.
		 * @param i - The Integer object to be copied.
		 */
		Integer(const Integer &i); // Integer j(i);

		/**
		 * String constructor for Integer class.
		 * This constructor creates an Integer object from a string. The string should represent a valid integer.
		 * The string can include a sign at the beginning ('-' for negative, '+' for positive), followed by digits.
		 * @param s - The string representing the integer value.
		 */
		Integer(const std::string &s); // Integer k("123");

		/**
		 * Parameterized constructor for Integer class.
		 * This constructor creates an Integer object from a sign and a vector of digits.
		 * @param sign - The sign of the integer (-1 for negative, 1 for positive).
		 * @param digits - The digits of the integer, from least significant to most significant.
		 */
		Integer(const int_fast8_t sign, const std::vector<int_fast8_t> digits); //

		/**
		 * Destructor for the Integer class.
		 * This destructor is called when an Integer object goes out of scope or is deleted.
		 * It frees up any resources the Integer object may have been using.
		 */
		~Integer();

		/**
		 * Overloaded assignment operator for the Integer class.
		 * It sets the value of the left-hand-side object to the value of the right-hand-side object.
		 * @param i - The Integer object to assign from.
		 * @return - Returns a reference to the current object.
		 */
		Integer &operator=(const Integer &i); // j = i;

		/**
		 * Unary negation operator overload for Integer class.
		 * This operator returns a new Integer that is the negative of the current Integer.
		 * @return - A new Integer with the same digits as the current Integer, but with its sign flipped.
		 */
		Integer operator-() const; ///< Negation operator

		/**
		 * Unary plus operator overload for Integer class.
		 * This operator returns a copy of the current Integer.
		 * @return - A new Integer with the same digits and sign as the current Integer.
		 */
		Integer operator+() const; ///< Unary plus operator

		/**
		 * Overloaded addition assignment operator for Integer class.
		 * It adds the right-hand-side Integer to the current object and assigns the result to the current object.
		 * @param i - The Integer to add.
		 * @return - Returns a reference to the current object.
		 */
		Integer &operator+=(const Integer &i); ///< Addition assignment operator

		/**
		 * Overloaded subtraction assignment operator for Integer class.
		 * It subtracts the right-hand-side Integer from the current object and assigns the result to the current object.
		 * @param i - The Integer to subtract.
		 * @return - Returns a reference to the current object.
		 */
		Integer &operator-=(const Integer &i); ///< Subtraction assignment operator

		/**
		 * Overloaded multiplication assignment operator for Integer class.
		 * It multiplies the current object with the right-hand-side Integer and assigns the result to the current object.
		 * @param i - The Integer to multiply with.
		 * @return - Returns a reference to the current object.
		 */
		Integer &operator*=(const Integer &i); ///< Multiplication assignment operator

		/**
		 * Overloaded division assignment operator for Integer class.
		 * It divides the current object by the right-hand-side Integer and assigns the quotient to the current object.
		 * @param i - The Integer to divide by.
		 * @return - Returns a reference to the current object.
		 */
		Integer &operator/=(const Integer &i); ///< Division assignment operator

		/**
		 * Overloaded modulus assignment operator for Integer class.
		 * It divides the current object by the right-hand-side Integer and assigns the remainder to the current object.
		 * @param i - The Integer to divide by.
		 * @return - Returns a reference to the current object.
		 */
		Integer &operator%=(const Integer &i); ///< Modulus assignment operator

		// lhs < rhs -- a 'friend' means operator isn't a member, but can access the private parts of the class.
		// You may need to make some other functions friends, but do so sparingly.

		// Sparingly....
		// We can either do this or do a more java esque getter for the internal vector

		/**
		 * Overloaded greater-than operator for Integer class.
		 * @param lhs - The first Integer to compare.
		 * @param rhs - The second Integer to compare.
		 * @return - Returns true if lhs is greater than rhs, false otherwise.
		 */
		friend bool operator>(const Integer &lhs, const Integer &rhs); ///< Greater than operator

		/**
		 * Overloaded equality operator for Integer class.
		 * @param lhs - The first Integer to compare.
		 * @param rhs - The second Integer to compare.
		 * @return - Returns true if lhs is equal to rhs, false otherwise.
		 */

		friend bool operator==(const Integer &lhs, const Integer &rhs); ///< Equality operator

		/**
		 * Overloaded multiplication operator for Integer class.
		 * @param lhs - The first Integer to multiply.
		 * @param rhs - The second Integer to multiply.
		 * @return - Returns the product of lhs and rhs.
		 */
		friend Integer operator*(const Integer &lhs, const Integer &rhs); ///< Multiplication operator

		/**
		 * Overloaded division operator for Integer class.
		 * @param lhs - The dividend Integer.
		 * @param rhs - The divisor Integer.
		 * @return - Returns the quotient of lhs divided by rhs.
		 */
		friend Integer operator/(const Integer &lhs, const Integer &rhs); ///< Division operator

		/**
		 * Overloaded modulus operator for Integer class.
		 * @param lhs - The dividend Integer.
		 * @param rhs - The divisor Integer.
		 * @return - Returns the remainder of lhs divided by rhs.
		 */
		friend Integer operator%(const Integer &lhs, const Integer &rhs); ///< Modulus operator

		/**
		 * Overloaded stream insertion operator for Integer class.
		 * @param os - The output stream.
		 * @param i - The Integer to output.
		 * @return - Returns the output stream.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Integer &i); ///< Stream insertion operator

		/**
		 * Overloaded stream extraction operator for Integer class.
		 * @param is - The input stream.
		 * @param i - The Integer to input.
		 * @return - Returns the input stream.
		 */
		friend std::istream &operator>>(std::istream &is, Integer &i); ///< Stream extraction operator

		/**
		 * Function to compare the absolute values of two Integers.
		 * @param lhs - The first Integer to compare.
		 * @param rhs - The second Integer to compare.
		 * @return - Returns true if the absolute value of lhs is greater than that of rhs, false otherwise.
		 */
		friend bool abs_greater_than(const Integer &lhs, const Integer &rhs); ///< Absolute comparison operator

		/**
		 * Function to compare two vectors' absolute values.
		 * @param lhs - The first vector to compare.
		 * @param rhs - The second vector to compare.
		 * @return - Returns true if the absolute value of lhs is greater than that of rhs, false otherwise.
		 */
		friend bool abs_greater_than(const std::vector<int_fast8_t> &lhs, const std::vector<int_fast8_t> &rhs);

		/**
		 * Member function to retrieve the digits of the Integer object in vector format.
		 * @return - Returns a vector of digits representing the integer, in reverse order.
		 */
		std::vector<int_fast8_t> get_digits() const;

		/**
		 * Member function to retrieve the sign of the Integer object.
		 * @return - Returns the sign of the integer. 1 for positive, -1 for negative.
		 */
		int_fast8_t get_sign() const;

	private:
		int_fast8_t sign; ///< The sign of the integer, 1 for positive, -1 for negative

		std::vector<int_fast8_t> digits; ///< Digits representing a column, in powers of 10, in reverse order

		/**
		 * Static function for division. It's used internally by the Integer class for its division operations.
		 * @param numerator - The Integer to be divided.
		 * @param denominator - The Integer by which the numerator is divided.
		 * @return - Returns a vector of the quotient and remainder.
		 */
		static std::vector<Integer> divide_internal(const Integer &numerator, const Integer &denominator);
		/**
		 * Static function for division, which wraps the internal divide function, providing a public API for division.
		 * @param numerator - The Integer to be divided.
		 * @param denominator - The Integer by which the numerator is divided.
		 * @return - Returns a vector of the quotient and remainder.
		 */

		static std::vector<Integer> divide(const Integer &numerator, const Integer &denominator);

		/**
		 * Static function for multiplication, used internally by the Integer class for its multiplication operations.
		 * @param multiplicand - The Integer to be multiplied.
		 * @param multiplier - The factor by which the Integer is multiplied.
		 * @param num_tens - The number of trailing zeros in the result.
		 * @return - Returns the product of the multiplication operation.
		 */
		static Integer multiplication_internal(const Integer &multiplicand, int_fast8_t multiplier, size_t num_tens);
	};

	/**
	 * Function to compute the greatest common divisor (gcd) of two Integers.
	 * @param a - The first Integer.
	 * @param b - The second Integer.
	 * @return - Returns the gcd of a and b.
	 */
	Integer gcd(const Integer &a, const Integer &b); ///< Computes greatest common divisor

	/**
	 * Overloaded less than operator for Integer class.
	 * @param lhs - The first Integer to compare.
	 * @param rhs - The second Integer to compare.
	 * @return - Returns true if lhs is less than rhs, false otherwise.
	 */
	bool operator<(const Integer &lhs, const Integer &rhs); ///< Less than operator

	/**
	 * Overloaded less than or equal to operator for Integer class.
	 * @param lhs - The first Integer to compare.
	 * @param rhs - The second Integer to compare.
	 * @return - Returns true if lhs is less than or equal to rhs, false otherwise.
	 */
	bool operator<=(const Integer &lhs, const Integer &rhs); ///< Less than or equal operator

	/**
	 * Overloaded greater than or equal to operator for Integer class.
	 * @param lhs - The first Integer to compare.
	 * @param rhs - The second Integer to compare.
	 * @return - Returns true if lhs is greater than or equal to rhs, false otherwise.
	 */
	bool operator>=(const Integer &lhs, const Integer &rhs); ///< Greater than or equal operator

	/**
	 * Overloaded inequality operator for Integer class.
	 * @param lhs - The first Integer to compare.
	 * @param rhs - The second Integer to compare.
	 * @return - Returns true if lhs is not equal to rhs, false otherwise.
	 */
	bool operator!=(const Integer &lhs, const Integer &rhs); ///< Inequality operator

	/**
	 * Overloaded addition operator for Integer class.
	 * @param lhs - The first Integer to add.
	 * @param rhs - The second Integer to add.
	 * @return - Returns the sum of lhs and rhs.
	 */
	Integer operator+(const Integer &lhs, const Integer &rhs); ///< Addition operator

	/**
	 * Overloaded subtraction operator for the Integer class.
	 * @param lhs - The Integer from which rhs will be subtracted.
	 * @param rhs - The Integer to subtract from lhs.
	 * @return - Returns a new Integer object that is the result of lhs minus rhs.
	 */
	Integer operator-(const Integer &lhs, const Integer &rhs); ///< Subtraction operator
}

#endif
