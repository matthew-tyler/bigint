
// Most compilers understand the once pragma, but just in case...
#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include <stdint.h>

namespace cosc326
{

	class Integer
	{

	public:
		Integer();					   // Integer i;
		Integer(const Integer &i);	   // Integer j(i);
		Integer(const std::string &s); // Integer k("123");

		Integer(const int_fast8_t sign, const std::vector<int_fast8_t> digits); //

		~Integer();

		Integer &operator=(const Integer &i); // j = i;

		// Unary operators
		Integer operator-() const; // -j;
		Integer operator+() const; // +j;

		// Arithmetic assignment operators
		Integer &operator+=(const Integer &i); // j += i;
		Integer &operator-=(const Integer &i); // j -= i;
		Integer &operator*=(const Integer &i); // j *= i;
		Integer &operator/=(const Integer &i); // j /= i;
		Integer &operator%=(const Integer &i); // j %= i;

		// lhs < rhs -- a 'friend' means operator isn't a member, but can access the private parts of the class.
		// You may need to make some other functions friends, but do so sparingly.

		// Sparingly....
		// We can either do this or do a more java esque getter for the internal vector
		friend bool operator>(const Integer &lhs, const Integer &rhs);	// lhs > rhs
		friend bool operator==(const Integer &lhs, const Integer &rhs); // lhs == rhs

		friend Integer operator*(const Integer &lhs, const Integer &rhs); // lhs * rhs;
		friend Integer operator/(const Integer &lhs, const Integer &rhs); // lhs / rhs;
		friend Integer operator%(const Integer &lhs, const Integer &rhs); // lhs % rhs;

		friend std::ostream &operator<<(std::ostream &os, const Integer &i); // std::cout << i << std::endl;
		friend std::istream &operator>>(std::istream &is, Integer &i);		 // std::cin >> i;

		friend Integer gcd(const Integer &a, const Integer &b); // i = gcd(a, b);

		friend bool absGreaterThan(const Integer &lhs, const Integer &rhs); // |A| > |B|;
		friend bool absGreaterThan(const std::vector<int_fast8_t> &lhs, const std::vector<int_fast8_t> &rhs);

		std::vector<int_fast8_t> getDigits() const;
		int_fast8_t getSign() const;

	private:
		// 1 for positive, -1 for negative. This is to make it easy to flip signs during operations with *sign.
		int_fast8_t sign;
		// Digits representing a column, in powers of 10, in reverse order.
		// That is, digits[0] is the 1s column, digits[1] the 10s etc.
		std::vector<int_fast8_t> digits;

		static std::vector<Integer> divideInternal(const Integer &numerator, const Integer &denominator);
		static std::vector<Integer> divide(const Integer &numerator, const Integer &denominator);

		static Integer multiplicationInternal(const Integer &num, int_fast8_t multiplier, size_t numTens);
	};

	bool operator<(const Integer &lhs, const Integer &rhs);
	bool operator<=(const Integer &lhs, const Integer &rhs); // lhs <= rhs
	bool operator>=(const Integer &lhs, const Integer &rhs); // lhs >= rhs
	bool operator!=(const Integer &lhs, const Integer &rhs); // lhs != rhs

	// Binary operators
	Integer operator+(const Integer &lhs, const Integer &rhs); // lhs + rhs;
	Integer operator-(const Integer &lhs, const Integer &rhs); // lhs - rhs;
}

#endif
