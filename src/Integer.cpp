#include "Integer.h"
#include <sstream>
#include <iostream>
#include <cstdlib>

namespace cosc326
{

	Integer::Integer()
	{
		this->sign = 1;
		this->digits.push_back(0);
	}

	Integer::Integer(const Integer &i)
	{
		// should have just done getters for the digits and signs.
	}

	Integer::Integer(const std::string &s)
	{
		char digit_offset = '0';

		this->sign = 1;

		if (s[0] == '-')
		{
			this->sign = -1;
		}

		for (int i = s.length(); i >= 0; i--)
		{
			short digit = s[i] - digit_offset;

			if (0 <= digit && digit <= 9)
			{
				this->digits.push_back(digit);
			}
		}
	}

	Integer::~Integer()
	{
	}

	Integer &Integer::operator=(const Integer &i)
	{
		return *this;
	}

	// This but flip the sign bit?
	Integer Integer::operator-() const
	{
		return Integer(*this);
	}

	// Wrong plus
	Integer Integer::operator+() const
	{
		return Integer(*this);
	}

	Integer &Integer::operator+=(const Integer &i)
	{
		return *this;
	}

	Integer &Integer::operator-=(const Integer &i)
	{
		return *this;
	}

	Integer &Integer::operator*=(const Integer &i)
	{
		return *this;
	}

	Integer &Integer::operator/=(const Integer &i)
	{
		return *this;
	}

	Integer &Integer::operator%=(const Integer &i)
	{
		return *this;
	}

	void Integer::setDigits(std::vector<short> digits)
	{
		this->digits = digits;
	}

	void Integer::setSign(short sign)
	{
		this->sign = sign;
	}

	std::string Integer::debugPrint()
	{

		std::ostringstream debugString;

		if (this->sign == -1)
		{
			debugString << "-";
		}

		if (this->sign == 1)
		{
			debugString << "+";
		}

		for (short digit : digits)
		{
			debugString << digit;
		}
		return debugString.str();
	}

	// Start here
	Integer operator+(Integer &lhs, Integer &rhs)
	{

		// This could be a lot cleaner. Just setting it so that A is the larger of the two
		std::vector<short> A = (lhs.digits.size() > rhs.digits.size()) ? lhs.digits : rhs.digits;
		short A_SIGN = (lhs.digits.size() > rhs.digits.size()) ? lhs.sign : rhs.sign;

		std::vector<short> B = (lhs.digits.size() > rhs.digits.size()) ? rhs.digits : lhs.digits;
		short B_SIGN = (lhs.digits.size() > rhs.digits.size()) ? rhs.sign : lhs.sign;

		short carry = 0;

		for (size_t i = 0; i < B.size(); i++)
		{
			// Take the addition of their numbers, multiply the sign so negatives are added correctly
			// Add the carry from the last addition at the end.
			short sum = (A[i] * A_SIGN) + (B[i] * B_SIGN) + carry;
			// As the carry has been used, set it back to 0

			carry = 0;
			// Check the absolute value of the addition. If greater than 9, add to the carry and just take the first digit
			if (0 > sum || sum > 9)
			{
				carry = 1 * A_SIGN * B_SIGN;
			}

			printf("A: %hd B: %hd Carry: %hd Sum: %hd ", A[i], B[i], carry, sum);

			A[i] = (sum + 10) % 10;

			printf("Mod: %hd\n", A[i]);
		}

		size_t index = B.size();

		while (carry != 0)
		{
			short add = (A[index] * A_SIGN) + carry;

			printf("add: %hd carry: %hd\n", add, carry);

			carry = 0;

			if (0 > add || add > 9)
			{
				carry = 1 * A_SIGN * B_SIGN;
			}

			if (index < A.size())
			{

				A[index] = (add + 10) % 10;
			}
			else
			{
				A.push_back((add + 10) % 10);
			}

			printf("Mod: %hd\n", A[index]);
			index++;
		}

		lhs.digits = A;

		return lhs;
	}

	Integer operator-(const Integer &lhs, const Integer &rhs)
	{
		return lhs;
	}

	Integer operator*(const Integer &lhs, const Integer &rhs)
	{
		return lhs;
	}

	// Start here
	Integer operator/(const Integer &lhs, const Integer &rhs)
	{
		return lhs;
	}

	Integer operator%(const Integer &lhs, const Integer &rhs)
	{
		return lhs;
	}

	std::ostream &operator<<(std::ostream &os, const Integer &i)
	{

		if (i.sign == -1)
		{
			os << "-";
		}

		for (int j = i.digits.size() - 1; j >= 0; --j)
		{
			os << i.digits[j];
		}
		return os;
	}

	std::istream &operator>>(std::istream &is, Integer &i)
	{
		return is;
	}

	bool operator<(const Integer &lhs, const Integer &rhs)
	{
		return !(lhs > rhs);
	}

	bool operator>(const Integer &lhs, const Integer &rhs)
	{
		// If left hand sign is negative, must be less.
		if (lhs.sign < rhs.sign)
		{
			return false;
		}

		// If lhs sign is larger must be true;
		if (lhs.sign > rhs.sign)
		{
			return true;
		}

		// If they're negative numbers, the lhs has more digits must be false;
		if (lhs.sign == -1 && lhs.digits.size() > rhs.digits.size())
		{
			return false;
		}
		// If they're positive numbers, the lhs has fewer digits must be false;
		if (lhs.digits.size() < rhs.digits.size())
		{
			return false;
		}

		for (size_t i = lhs.digits.size() - 1; i >= 0; --i)
		{
			if (lhs.digits[i] > rhs.digits[i])
			{
				return true;
			}
		}

		return false;
	}

	bool operator<=(const Integer &lhs, const Integer &rhs)
	{
		return !(lhs > rhs);
	}

	bool operator>=(const Integer &lhs, const Integer &rhs)
	{
		return (lhs > rhs) || (lhs == rhs);
	}

	bool operator==(const Integer &lhs, const Integer &rhs)
	{
		return lhs.sign == rhs.sign && lhs.digits == rhs.digits;
	}

	bool operator!=(const Integer &lhs, const Integer &rhs)
	{
		return !(lhs == rhs);
	}

	Integer gcd(const Integer &a, const Integer &b)
	{

		return a;
	}

}
