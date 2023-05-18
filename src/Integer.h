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
	 * @brief This class represents an integer number
	 */
	class Integer
	{

	public:
		/**
		 * @brief Default constructor
		 */
		Integer(); // Integer i;

		/**
		 * @brief Copy constructor
		 * @param i Integer to copy
		 */
		Integer(const Integer &i); // Integer j(i);

		/**
		 * @brief Constructor from string
		 * @param s String to convert
		 */
		Integer(const std::string &s); // Integer k("123");

		/**
		 * @brief Constructs an Integer from sign and digits
		 * @param sign The sign of the integer
		 * @param digits The digits of the integer
		 */
		Integer(const int_fast8_t sign, const std::vector<int_fast8_t> digits); //

		/**
		 * @brief Destructor
		 */
		~Integer();

		/**
		 * @brief Assignment operator
		 * @param i Integer to assign
		 */
		Integer &operator=(const Integer &i); // j = i;

		// Unary operators
		Integer operator-() const; ///< Negation operator
		Integer operator+() const; ///< Unary plus operator

		// Arithmetic assignment operators
		Integer &operator+=(const Integer &i); ///< Addition assignment operator
		Integer &operator-=(const Integer &i); ///< Subtraction assignment operator
		Integer &operator*=(const Integer &i); ///< Multiplication assignment operator
		Integer &operator/=(const Integer &i); ///< Division assignment operator
		Integer &operator%=(const Integer &i); ///< Modulus assignment operator

		// lhs < rhs -- a 'friend' means operator isn't a member, but can access the private parts of the class.
		// You may need to make some other functions friends, but do so sparingly.

		// Sparingly....
		// We can either do this or do a more java esque getter for the internal vector
		friend bool operator>(const Integer &lhs, const Integer &rhs);	///< Greater than operator
		friend bool operator==(const Integer &lhs, const Integer &rhs); ///< Equality operator

		friend Integer operator*(const Integer &lhs, const Integer &rhs); ///< Multiplication operator
		friend Integer operator/(const Integer &lhs, const Integer &rhs); ///< Division operator
		friend Integer operator%(const Integer &lhs, const Integer &rhs); ///< Modulus operator

		friend std::ostream &operator<<(std::ostream &os, const Integer &i); ///< Stream insertion operator
		friend std::istream &operator>>(std::istream &is, Integer &i);		 ///< Stream extraction operator

		friend Integer gcd(const Integer &a, const Integer &b); ///< Computes greatest common divisor

		friend bool absGreaterThan(const Integer &lhs, const Integer &rhs); ///< Absolute comparison operator
		friend bool absGreaterThan(const std::vector<int_fast8_t> &lhs, const std::vector<int_fast8_t> &rhs);

		/**
		 * @brief Returns the digits of the integer
		 * @return The digits of the integer
		 */
		std::vector<int_fast8_t> getDigits() const;

		/**
		 * @brief Returns the sign of the integer
		 * @return The sign of the integer
		 */
		int_fast8_t getSign() const;

	private:
		int_fast8_t sign; ///< The sign of the integer, 1 for positive, -1 for negative

		std::vector<int_fast8_t> digits; ///< Digits representing a column, in powers of 10, in reverse order

		/**
		 * @brief Internal function for division
		 *
		 * This function is used internally by the Integer class for its division operations.
		 *
		 * @param numerator The Integer to be divided.
		 * @param denominator The Integer by which the numerator is divided.
		 * @return A vector of the quotient and remainder.
		 */
		static std::vector<Integer> divideInternal(const Integer &numerator, const Integer &denominator);
		/**
		 * @brief Function for division
		 *
		 * This function wraps the internal divide function, providing a public API for division.
		 *
		 * @param numerator The Integer to be divided.
		 * @param denominator The Integer by which the numerator is divided.
		 * @return A vector of the quotient and remainder.
		 */
		static std::vector<Integer> divide(const Integer &numerator, const Integer &denominator);

		/**
		 * @brief Internal function for multiplication
		 *
		 * This function is used internally by the Integer class for its multiplication operations.
		 *
		 * @param num The Integer to be multiplied.
		 * @param multiplier The factor by which the Integer is multiplied.
		 * @param numTens The number of trailing zeros in the result.
		 * @return The product of the multiplication operation.
		 */
		static Integer multiplicationInternal(const Integer &num, int_fast8_t multiplier, size_t numTens);
	};

	bool operator<(const Integer &lhs, const Integer &rhs);	 ///< Less than operator
	bool operator<=(const Integer &lhs, const Integer &rhs); ///< Less than or equal operator
	bool operator>=(const Integer &lhs, const Integer &rhs); ///< Greater than or equal operator
	bool operator!=(const Integer &lhs, const Integer &rhs); ///< Inequality operator

	// Binary operators
	Integer operator+(const Integer &lhs, const Integer &rhs); ///< Addition operator
	Integer operator-(const Integer &lhs, const Integer &rhs); ///< Subtraction operator
}

#endif
