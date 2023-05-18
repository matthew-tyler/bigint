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
	 * @brief This class represents a Rational number, a ratio of two Integers.
	 */
	class Rational
	{

	public:
		/**
		 * @brief Default constructor
		 */
		Rational();
		/**
		 * @brief Constructs a Rational from a string
		 * @param str The string to convert
		 */
		Rational(const std::string &str);
		/**
		 * @brief Copy constructor
		 * @param r The Rational to copy
		 */
		Rational(const Rational &r);
		/**
		 * @brief Constructs a Rational from an Integer
		 * @param a The Integer
		 */
		Rational(const Integer &a);
		/**
		 * @brief Constructs a Rational from two Integers
		 * @param a The numerator
		 * @param b The denominator
		 */
		// a
		Rational(const Integer &a, const Integer &b);
		/**
		 * @brief Constructs a Rational from three Integers
		 * @param a The whole part
		 * @param b The numerator of the fractional part
		 * @param c The denominator of the fractional part
		 */
		// a/b
		Rational(const Integer &a, const Integer &b, const Integer &c); // a + b/c

		/**
		 * @brief Destructor
		 */
		~Rational();

		/**
		 * @brief Assignment operator
		 * @param r The Rational to assign
		 */
		Rational &operator=(const Rational &r); // q = r;

		// Unary operators
		Rational operator-() const; ///< Negation operator
		Rational operator+() const; ///< Unary plus operator

		// Arithmetic assignment operators
		Rational &operator+=(const Rational &r); ///< Addition assignment operator
		Rational &operator-=(const Rational &r); ///< Subtraction assignment operator
		Rational &operator*=(const Rational &r); ///< Multiplication assignment operator
		Rational &operator/=(const Rational &r); ///< Division assignment operator

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

	// Binary operators
	Rational operator+(const Rational &lhs, const Rational &rhs); ///< Addition operator
	Rational operator-(const Rational &lhs, const Rational &rhs); ///< Subtraction operator
	Rational operator*(const Rational &lhs, const Rational &rhs); ///< Multiplication operator
	Rational operator/(const Rational &lhs, const Rational &rhs); ///< Division operator

	std::ostream &operator<<(std::ostream &os, const Rational &i); ///< Stream insertion operator
	std::istream &operator>>(std::istream &is, Rational &i);	   ///< Stream extraction operator

	bool operator>(const Rational &lhs, const Rational &rhs);  ///< Greater than operator
	bool operator<=(const Rational &lhs, const Rational &rhs); ///< Less than operator or equal to
	bool operator>=(const Rational &lhs, const Rational &rhs); ///< Greater than operator or equal to
	bool operator==(const Rational &lhs, const Rational &rhs); ///< Equal to operator
	bool operator!=(const Rational &lhs, const Rational &rhs); ///< Not equal to operator

}

#endif
