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
		this->sign = i.sign;
		this->digits = i.digits;
	}

	Integer::Integer(const std::string &s)
	{
		char digit_offset = '0';

		this->sign = 1;

		if (s[0] == '-')
		{
			this->sign = -1;
		}

		for (int i = s.length() - 1; i >= 0; i--)
		{
			short digit = s[i] - digit_offset;

			if (0 <= digit && digit <= 9)
			{
				this->digits.push_back(digit);
			}
		}
	}

	Integer::Integer(const short sign, const std::vector<short> digits) : sign(sign), digits(digits)
	{
	}

	Integer::~Integer()
	{
	}

	bool absGreaterThan(const std::vector<short> &lhs, const std::vector<short> &rhs)
	{
		if (lhs.size() < rhs.size())
		{
			return false;
		}

		if (lhs.size() > rhs.size())
		{
			return true;
		}

		for (size_t i = lhs.size() - 1; i >= 0; --i)
		{
			if (lhs[i] > rhs[i])
			{
				return true;
			}
			if (lhs[i] < rhs[i])
			{
				return false;
			}
		}

		return false;
	}

	Integer &Integer::operator=(const Integer &i)
	{
		if (this != &i)
		{
			this->sign = i.getSign();
			this->digits = i.getDigits();
		}
		return *this;
	}

	Integer Integer::operator-() const
	{
		return Integer(-1, this->getDigits());
	}

	Integer Integer::operator+() const
	{
		return Integer(1, this->getDigits());
	}

	Integer &Integer::operator+=(const Integer &i)
	{
		*this = *this + i;
		return *this;
	}

	Integer &Integer::operator-=(const Integer &i)
	{
		*this = *this - i;
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

	std::vector<short> Integer::getDigits() const
	{
		return this->digits;
	}

	short Integer::getSign() const
	{
		return this->sign;
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
	Integer operator+(const Integer &lhs, const Integer &rhs)
	{

		std::vector<short> A = lhs.getDigits();
		short A_SIGN = lhs.getSign();

		std::vector<short> B = rhs.getDigits();
		short B_SIGN = rhs.getSign();

		short result_sign = 1;

		if (absGreaterThan(rhs, lhs)) // |lhs| > |rhs|
		{
			A = rhs.getDigits();
			A_SIGN = rhs.getSign();

			B = lhs.getDigits();
			B_SIGN = lhs.getSign();
		}

		if (A_SIGN != B_SIGN)
		{
			if ((A_SIGN == -1 && absGreaterThan(A, B)) || (B_SIGN == -1 && absGreaterThan(B, A)))
			{
				A_SIGN = A_SIGN * -1;
				B_SIGN = B_SIGN * -1;

				result_sign = -1;
			}
		}
		else if (A_SIGN == -1 && B_SIGN == -1)
		{
			A_SIGN = 1;
			B_SIGN = 1;
			result_sign = -1;
		}

		short carry = 0;

		for (size_t i = 0; i < B.size(); i++)
		{
			// Take the addition of their numbers, multiply the sign so negatives are added correctly
			// Add the carry from the last addition at the end.
			short sum = (A[i] * A_SIGN) + ((B[i] * B_SIGN) + carry);
			// As the carry has been used, set it back to 0

			carry = 0;
			// Check the absolute value of the addition. If greater than 9, add to the carry and just take the first digit
			if (0 > sum || sum > 9)
			{
				carry = 1 * A_SIGN * B_SIGN;
			}

			A[i] = (sum + 10) % 10;
		}

		size_t index = B.size();

		// for (const auto &val : A)
		// {
		// 	std::cout << val << ' ';
		// }
		// std::cout << std::endl;

		while (carry != 0)
		{

			short add;
			if (index < A.size())
			{
				add = (A[index] * A_SIGN) + carry;
			}
			else
			{
				add = (0 * A_SIGN) + carry;
			}

			// std::cout << add << std::endl;
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

			index++;
		}

		// In case where the most significant digit is 0, sets it to a positive 0.
		while (A.back() == 0)
		{
			A.pop_back();
			if (A.empty())
			{
				A.push_back(0);
				result_sign = 1;
				break;
			}
		}
		Integer output(result_sign, A);

		return output;
	}

	Integer operator-(const Integer &lhs, const Integer &rhs)
	{
		return lhs + -rhs;
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

			if (lhs.digits[i] < rhs.digits[i])
			{
				return false;
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

	bool absGreaterThan(const Integer &lhs, const Integer &rhs)
	{

		if (lhs.digits.size() < rhs.digits.size())
		{
			return false;
		}

		if (lhs.digits.size() > rhs.digits.size())
		{
			return true;
		}

		for (size_t i = lhs.digits.size() - 1; i >= 0; --i)
		{

			if (lhs.getDigits()[i] > rhs.getDigits()[i])
			{
				return true;
			}

			if (lhs.getDigits()[i] < rhs.getDigits()[i])
			{
				return false;
			}
		}

		return false;
	}

}
