#include "Integer.h"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>

namespace cosc326
{

	Integer::Integer()
	{
		this->sign = 1;
		this->digits.push_back(0);
	}

	Integer::Integer(const Integer &i)
	{
		this->sign = i.get_sign();
		this->digits = i.get_digits();
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
			int_fast8_t digit = s[i] - digit_offset;

			if (0 <= digit && digit <= 9)
			{
				this->digits.push_back(digit);
			}
		}
	}

	Integer::Integer(const int_fast8_t sign, const std::vector<int_fast8_t> digits) : sign(sign), digits(digits)
	{
	}

	Integer::~Integer()
	{
	}

	bool abs_greater_than(const std::vector<int_fast8_t> &lhs, const std::vector<int_fast8_t> &rhs)
	{

		if (lhs.size() != rhs.size())
		{
			return lhs.size() > rhs.size();
		}

		for (size_t i = lhs.size() - 1; i < lhs.size(); --i)
		{
			if (lhs[i] != rhs[i])
			{
				return lhs[i] > rhs[i];
			}
		}

		return false;
	}

	Integer &Integer::operator=(const Integer &i)
	{
		if (this != &i)
		{
			this->sign = i.get_sign();
			this->digits = i.get_digits();
		}
		return *this;
	}

	Integer Integer::operator-() const
	{
		return Integer(this->sign * -1, this->get_digits());
	}

	Integer Integer::operator+() const
	{
		return *this;
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
		*this = *this * i;
		return *this;
	}

	Integer &Integer::operator/=(const Integer &i)
	{
		*this = *this / i;
		return *this;
	}

	Integer &Integer::operator%=(const Integer &i)
	{
		*this = *this % i;
		return *this;
	}

	std::vector<int_fast8_t> Integer::get_digits() const
	{
		return this->digits;
	}

	int_fast8_t Integer::get_sign() const
	{
		return this->sign;
	}

	std::vector<Integer> Integer::divide_internal(const Integer &numerator, const Integer &denominator)
	{
		Integer i("0");
		Integer remainder(numerator);

		Integer ZERO("0");

		while (remainder > ZERO)
		{
			remainder = remainder - denominator;

			if (remainder >= ZERO)
			{
				i = i + Integer("1");
			}
		}

		if (remainder != ZERO)
		{
			remainder = remainder + denominator;
		}
		return {i, remainder};
	}

	std::vector<Integer> Integer::divide(const Integer &numerator, const Integer &denominator)
	{

		std::vector<int_fast8_t> answer;
		std::vector<int_fast8_t> current_mod = {numerator.get_digits().back()};

		int_fast8_t numerator_original_sign = numerator.get_sign();
		int_fast8_t denominator_original_sign = denominator.get_sign();

		Integer current_numerator;
		Integer current_denominator = Integer(1, denominator.get_digits());

		for (int i = numerator.digits.size() - 2; i >= -1; i--)
		{
			current_numerator = Integer(1, current_mod);
			std::vector<Integer> division = divide_internal(current_numerator, current_denominator);

			if (!(division[0] == Integer("0") && answer.empty()))
			{
				answer.insert(answer.end(), division[0].digits.begin(), division[0].digits.end());
			}

			current_mod = division[1].get_digits();

			if (i >= 0)
			{
				int_fast8_t ins = numerator.digits[i];

				if (current_mod.back() == 0)
				{
					current_mod.pop_back();
				}
				current_mod.insert(current_mod.begin(), ins);
			}
		}

		if (answer.empty())
		{
			answer.push_back(0);
		}

		int_fast8_t result_sign = numerator_original_sign * denominator_original_sign;
		std::reverse(answer.begin(), answer.end());

		return {Integer(result_sign, answer), Integer(numerator_original_sign, current_mod)};
	}

	// Start here
	Integer operator+(const Integer &lhs, const Integer &rhs)
	{

		std::vector<int_fast8_t> a = lhs.get_digits();
		int_fast8_t a_sign = lhs.get_sign();

		std::vector<int_fast8_t> b = rhs.get_digits();
		int_fast8_t b_sign = rhs.get_sign();

		int_fast8_t result_sign = 1;

		if (abs_greater_than(rhs, lhs)) // |lhs| > |rhs|
		{
			a = rhs.get_digits();
			a_sign = rhs.get_sign();

			b = lhs.get_digits();
			b_sign = lhs.get_sign();
		}

		if (a_sign != b_sign)
		{
			if ((a_sign == -1 && abs_greater_than(a, b)) || (b_sign == -1 && abs_greater_than(b, a)))
			{
				a_sign = a_sign * -1;
				b_sign = b_sign * -1;

				result_sign = -1;
			}
		}
		else if (a_sign == -1 && b_sign == -1)
		{
			a_sign = 1;
			b_sign = 1;
			result_sign = -1;
		}

		int_fast8_t carry = 0;

		for (size_t i = 0; i < b.size(); i++)
		{
			// Take the addition of their numbers, multiply the sign so negatives are added correctly
			// Add the carry from the last addition at the end.
			int_fast8_t sum = (a[i] * a_sign) + ((b[i] * b_sign) + carry);
			// As the carry has been used, set it back to 0

			carry = 0;
			// Check the absolute value of the addition. If greater than 9, add to the carry and just take the first digit
			if (0 > sum || sum > 9)
			{
				carry = 1 * a_sign * b_sign;
			}

			a[i] = (sum + 10) % 10;
		}

		size_t index = b.size();

		while (carry != 0)
		{

			int_fast8_t add;
			if (index < a.size())
			{
				add = (a[index] * a_sign) + carry;
			}
			else
			{
				add = (0 * a_sign) + carry;
			}
			carry = 0;

			if (0 > add || add > 9)
			{
				carry = 1 * a_sign * b_sign;
			}

			if (index < a.size())
			{
				a[index] = (add + 10) % 10;
			}
			else
			{
				a.push_back((add + 10) % 10);
			}

			index++;
		}

		// Removes leading zeros.
		while (a.back() == 0)
		{
			a.pop_back();

			// In case where the most significant digit is 0, sets it to a positive 0.
			if (a.empty())
			{
				a.push_back(0);
				result_sign = 1;
				break;
			}
		}

		Integer output(result_sign, a);

		return output;
	}

	Integer operator-(const Integer &lhs, const Integer &rhs)
	{
		return lhs + -rhs;
	}
	Integer Integer::multiplication_internal(const Integer &num, int_fast8_t multiplier, size_t numTens)
	{
		Integer answer("0");

		if (multiplier != 0)
		{
			for (int_fast8_t i = 0; i < multiplier; i++)
			{
				answer = answer + num;
			}

			for (size_t i = 0; i < numTens; i++)
			{
				answer.digits.insert(answer.digits.begin(), 0);
			}
		}

		return answer;
	}

	Integer operator*(const Integer &lhs, const Integer &rhs)
	{

		Integer result("0");
		Integer multiplicand(1, lhs.get_digits());
		Integer multiplier(1, rhs.get_digits());

		if (multiplicand < multiplier)
		{
			multiplicand = Integer(1, rhs.get_digits());
			multiplier = Integer(1, lhs.get_digits());
		}

		for (size_t i = 0; i < multiplier.digits.size(); i++)
		{
			result = result + Integer::multiplication_internal(multiplicand, multiplier.digits[i], i);
		}

		result.sign = lhs.get_sign() * rhs.get_sign();

		return result;
	}

	Integer operator/(const Integer &lhs, const Integer &rhs)
	{
		return Integer::divide(lhs, rhs)[0];
	}

	Integer operator%(const Integer &lhs, const Integer &rhs)
	{
		return Integer::divide(lhs, rhs)[1];
	}

	std::ostream &operator<<(std::ostream &os, const Integer &i)
	{

		if (i.sign == -1)
		{
			os << "-";
		}

		for (int j = i.digits.size() - 1; j >= 0; --j)
		{
			os << (int)i.digits[j];
		}
		return os;
	}

	std::istream &operator>>(std::istream &is, Integer &i)
	{
		std::string input;
		is >> input;
		i = Integer(input);

		return is;
	}

	bool operator<(const Integer &lhs, const Integer &rhs)
	{
		return !(lhs > rhs);
	}

	bool operator>(const Integer &lhs, const Integer &rhs)
	{

		if (lhs.sign != rhs.sign)
		{
			return lhs.sign == 1;
		}

		if (lhs.digits.size() != rhs.digits.size())
		{
			return (lhs.sign == 1 && lhs.digits.size() > rhs.digits.size()) || (lhs.sign == -1 && lhs.digits.size() < rhs.digits.size());
		}

		for (size_t i = lhs.digits.size() - 1; i < lhs.digits.size(); --i)
		{
			if (lhs.digits[i] != rhs.digits[i])
			{
				return (lhs.sign == 1 && lhs.digits[i] > rhs.digits[i]) || (lhs.sign == -1 && lhs.digits[i] < rhs.digits[i]);
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
		if (lhs.get_digits().size() == 1 && rhs.get_digits().size() == 1 && lhs.get_digits()[0] == 0 && rhs.get_digits()[0] == 0)
		{
			return true;
		}
		return lhs.sign == rhs.sign && lhs.digits == rhs.digits;
	}

	bool operator!=(const Integer &lhs, const Integer &rhs)
	{
		return !(lhs == rhs);
	}

	Integer gcd(const Integer &a, const Integer &b)
	{
		Integer a_c(1, a.get_digits());
		Integer b_c(1, b.get_digits());

		Integer ZERO("0");

		while ((a_c > ZERO) && (b_c > ZERO))
		{
			if (a_c > b_c)
			{
				a_c = a_c % b_c;
			}
			else
			{
				b_c = b_c % a_c;
			}
		}

		if (a_c == ZERO)
		{
			return b_c;
		}

		return a_c;
	}

	bool abs_greater_than(const Integer &lhs, const Integer &rhs)
	{
		if (lhs.digits.size() != rhs.digits.size())
		{
			return lhs.digits.size() > rhs.digits.size();
		}

		for (size_t i = lhs.digits.size() - 1; i < lhs.digits.size(); --i)
		{
			if (lhs.digits[i] != rhs.digits[i])
			{
				return lhs.digits[i] > rhs.digits[i];
			}
		}

		return false;
	}

}
