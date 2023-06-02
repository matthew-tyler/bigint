#pragma once

// Most compilers understand the once pragma, but just in case...
#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>
#include <string>
#include "Integer.h"

namespace cosc326
{
	/**
	 * @class Rational
	 * @brief This class represents a rational number, which is a ratio of two integers.
	 */
	class Rational
	{

	public:
		/**
		 * @brief Default constructor. Constructs a Rational object with a default value.
		 */
		Rational();
		/**
		 * @brief Constructs a Rational object from a string representation of a rational number.
		 * @param str String representing the rational number.
		 */
		Rational(const std::string &str);
		/**
		 * @brief Copy constructor. Constructs a new Rational object as a copy of an existing one.
		 * @param r The Rational object to be copied.
		 */
		Rational(const Rational &r);
		/**
		 * @brief Constructs a Rational object from an Integer, with the denominator defaulted to 1.
		 * @param a The Integer to be used as the numerator.
		 */
		Rational(const Integer &a);

		/**
		 * @brief Constructs a Rational object from two Integer objects.
		 * @param a The Integer to be used as the numerator.
		 * @param b The Integer to be used as the denominator.
		 */
		Rational(const Integer &a, const Integer &b);
		/**
		 * @brief Constructs a Rational object from three Integer objects. The first Integer is treated as a whole number,
		 * the second as the numerator of the fractional part, and the third as the denominator of the fractional part.
		 * @param a The whole number part.
		 * @param b The numerator of the fractional part.
		 * @param c The denominator of the fractional part.
		 */
		Rational(const Integer &a, const Integer &b, const Integer &c); // a + b/c
		/**
		 * @brief Destructor for the Rational object.
		 */
		~Rational();
		/**
		 * @brief Assignment operator.
		 * @param r The Rational to assign.
		 * @return Reference to the Rational object after assignment.
		 */
		Rational &operator=(const Rational &r); // q = r;

		/**
		 * @brief Unary negation operator.
		 * @return A new Rational object that is the negation of the original.
		 */
		Rational operator-() const; ///< Negation operator

		/**
		 * @brief Unary plus operator.
		 * @return A new Rational object that is a copy of the original.
		 */
		Rational operator+() const; ///< Unary plus operator

		/**
		 * @brief Addition assignment operator. Adds a Rational to the current object.
		 * @param r The Rational to add.
		 * @return Reference to the Rational object after addition.
		 */
		Rational &operator+=(const Rational &r); ///< Addition assignment operator

		/**
		 * @brief Subtraction assignment operator. Subtracts a Rational from the current object.
		 * @param r The Rational to subtract.
		 * @return Reference to the Rational object after subtraction.
		 */
		Rational &operator-=(const Rational &r); ///< Subtraction assignment operator

		/**
		 * @brief Multiplication assignment operator. Multiplies the current object by a Rational.
		 * @param r The Rational to multiply.
		 * @return Reference to the Rational object after multiplication.
		 */
		Rational &operator*=(const Rational &r); ///< Multiplication assignment operator

		/**
		 * @brief Division assignment operator. Divides the current object by a Rational.
		 * @param r The Rational to divide.
		 * @return Reference to the Rational object after division.
		 */
		Rational &operator/=(const Rational &r); ///< Division assignment operator

		/**
		 * @brief Checks if the left-hand side Rational is less than the right-hand side Rational.
		 * @param lhs The left-hand side Rational.
		 * @param rhs The right-hand side Rational.
		 * @return True if lhs is less than rhs, false otherwise.
		 */
		friend bool operator<(const Rational &lhs, const Rational &rhs); ///< Less than operator

		/**
		 * @brief Gets the numerator of the Rational
		 * @return The numerator
		 */
		Integer get_numerator() const;

		/**
		 * @brief Gets the denominator of the Rational
		 * @return The denominator
		 */
		Integer get_denominator() const;

	private:
		Integer numerator;	 ///< The numerator of the Rational
		Integer denominator; ///< The denominator of the Rational

		/**
		 * @brief Standardizes the signs of the numerator and denominator
		 */
		void standardize_signs();
	};

	/**
	 * @brief Binary addition operator. Adds two Rationals together.
	 * @param lhs The left-hand side Rational.
	 * @param rhs The right-hand side Rational.
	 * @return A new Rational representing the sum of lhs and rhs.
	 */
	Rational operator+(const Rational &lhs, const Rational &rhs); ///< Addition operator

	/**
	 * @brief Binary subtraction operator. Subtracts rhs from lhs.
	 * @param lhs The left-hand side Rational.
	 * @param rhs The right-hand side Rational.
	 * @return A new Rational representing the difference of lhs and rhs.
	 */
	Rational operator-(const Rational &lhs, const Rational &rhs); ///< Subtraction operator

	/**
	 * @brief Binary multiplication operator. Multiplies lhs by rhs.
	 * @param lhs The left-hand side Rational.
	 * @param rhs The right-hand side Rational.
	 * @return A new Rational representing the product of lhs and rhs.
	 */
	Rational operator*(const Rational &lhs, const Rational &rhs); ///< Multiplication operator

	/**
	 * @brief Binary division operator. Divides lhs by rhs.
	 * @param lhs The left-hand side Rational.
	 * @param rhs The right-hand side Rational.
	 * @return A new Rational representing the quotient of lhs and rhs.
	 */
	Rational operator/(const Rational &lhs, const Rational &rhs); ///< Division operator

	/**
	 * @brief Stream insertion operator. Inserts the string representation of a Rational into an output stream.
	 * @param os The output stream.
	 * @param i The Rational to be inserted.
	 * @return Reference to the output stream.
	 */
	std::ostream &operator<<(std::ostream &os, const Rational &i); ///< Stream insertion operator

	/**
	 * @brief Stream extraction operator. Extracts a Rational from an input stream.
	 * @param is The input stream.
	 * @param i The Rational to be extracted.
	 * @return Reference to the input stream.
	 */
	std::istream &operator>>(std::istream &is, Rational &i); ///< Stream extraction operator

	/**
	 * @brief Checks if the left-hand side Rational is greater than the right-hand side Rational.
	 * @param lhs The left-hand side Rational.
	 * @param rhs The right-hand side Rational.
	 * @return True if lhs is greater than rhs, false otherwise.
	 */
	bool operator>(const Rational &lhs, const Rational &rhs); ///< Greater than operator

	/**
	 * @brief Checks if the left-hand side Rational is less than or equal to the right-hand side Rational.
	 * @param lhs The left-hand side Rational.
	 * @param rhs The right-hand side Rational.
	 * @return True if lhs is less than or equal to rhs, false otherwise.
	 */
	bool operator<=(const Rational &lhs, const Rational &rhs); ///< Less than operator or equal to

	/**
	 * @brief Checks if the left-hand side Rational is greater than or equal to the right-hand side Rational.
	 * @param lhs The left-hand side Rational.
	 * @param rhs The right-hand side Rational.
	 * @return True if lhs is greater than or equal to rhs, false otherwise.
	 */
	bool operator>=(const Rational &lhs, const Rational &rhs); ///< Greater than operator or equal to

	/**
	 * @brief Checks if the left-hand side Rational is equal to the right-hand side Rational.
	 * @param lhs The left-hand side Rational.
	 * @param rhs The right-hand side Rational.
	 * @return True if lhs is equal to rhs, false otherwise.
	 */
	bool operator==(const Rational &lhs, const Rational &rhs); ///< Equal to operator

	/**
	 * @brief Checks if the left-hand side Rational is not equal to the right-hand side Rational.
	 * @param lhs The left-hand side Rational.
	 * @param rhs The right-hand side Rational.
	 * @return True if lhs is not equal to rhs, false otherwise.
	 */
	bool operator!=(const Rational &lhs, const Rational &rhs); ///< Not equal to operator

}

#endif
