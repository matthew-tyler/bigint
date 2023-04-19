#include "Integer.h"
#include <sstream>
#include <iostream>

namespace cosc326
{

	Integer::Integer()
	{
	}

	Integer::Integer(const Integer &i)
	{
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

	Integer Integer::operator-() const
	{
		return Integer(*this);
	}

	// Start here
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

	Integer operator+(const Integer &lhs, const Integer &rhs)
	{

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

		for (int i = lhs.digits.size() - 1; i >= 0; --i)
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
