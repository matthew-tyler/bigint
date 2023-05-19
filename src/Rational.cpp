#include "Rational.h"

namespace cosc326
{

	Rational::Rational()
	{
		this->numerator = Integer("0");
		this->denominator = Integer("1");
	}

	Rational::Rational(const std::string &str)
	{

		int denom_index = -1;
		int num_index = -1;

		int integer_index = -1;

		for (int i = str.size(); i >= 0; i--)
		{
			if (str[i] == '/' && denom_index == -1)
			{
				denom_index = i;
			}

			if (str[i] == '.')
			{
				num_index = i;

				break;
			}
		}
	}

	Rational::Rational(const Rational &r)
	{
		this->numerator = r.get_numerator();
		this->denominator = r.get_denominator();
	}

	Rational::Rational(const Integer &a)
	{
		this->numerator = a;
		this->denominator = Integer("1");
	}

	Rational::Rational(const Integer &a, const Integer &b)
	{

		if (b == Integer("0"))
		{
			throw std::invalid_argument("Denominator cannot be zero");
		}
		this->numerator = a;
		this->denominator = b;

		standardize_signs();
	}

	Rational::Rational(const Integer &a, const Integer &b, const Integer &c)
	{
		if (c == Integer("0"))
		{
			throw std::invalid_argument("Denominator cannot be zero");
		}
		this->numerator = b;
		this->denominator = c;

		this->numerator = (a * this->denominator) + this->numerator;

		standardize_signs();
	}

	Rational::~Rational()
	{
	}

	Rational &Rational::operator=(const Rational &r)
	{
		if (*this != r)
		{
			this->numerator = r.get_numerator();
			this->denominator = r.get_denominator();
		}
		return *this;
	}

	Rational Rational::operator-() const
	{
		return Rational(-(this->numerator), this->denominator);
	}

	Rational Rational::operator+() const
	{
		return *this;
	}

	Rational &Rational::operator+=(const Rational &r)
	{
		*this = *this + r;
		return *this;
	}

	Rational &Rational::operator-=(const Rational &r)
	{
		*this = *this - r;
		return *this;
	}

	Rational &Rational::operator*=(const Rational &r)
	{
		*this = *this * r;
		return *this;
	}

	Rational &Rational::operator/=(const Rational &r)
	{
		*this = *this / r;
		return *this;
	}

	Integer Rational::get_numerator() const
	{
		return Integer(this->numerator.get_sign(), this->numerator.get_digits());
	}

	Integer Rational::get_denominator() const
	{
		return Integer(this->denominator.get_sign(), this->denominator.get_digits());
	}

	void Rational::standardize_signs()
	{

		if (this->numerator.get_sign() != this->denominator.get_sign())
		{
			this->numerator = Integer(-1, this->numerator.get_digits());
			this->denominator = Integer(1, this->denominator.get_digits());
		}
		else
		{
			this->numerator = Integer(1, this->numerator.get_digits());
			this->denominator = Integer(1, this->denominator.get_digits());
		}
	}

	Rational operator+(const Rational &lhs, const Rational &rhs)
	{
		Integer new_numerator = (lhs.get_numerator() * rhs.get_denominator()) + (rhs.get_numerator() * lhs.get_denominator());
		Integer new_denominator = lhs.get_denominator() * rhs.get_denominator();
		return Rational(new_numerator, new_denominator);
	}

	Rational operator-(const Rational &lhs, const Rational &rhs)
	{
		Integer new_numerator = (lhs.get_numerator() * rhs.get_denominator()) - (rhs.get_numerator() * lhs.get_denominator());
		Integer new_denominator = lhs.get_denominator() * rhs.get_denominator();
		return Rational(new_numerator, new_denominator);
	}

	Rational operator*(const Rational &lhs, const Rational &rhs)
	{
		Integer new_numerator = lhs.get_numerator() * rhs.get_numerator();
		Integer new_denominator = lhs.get_denominator() * rhs.get_denominator();
		return Rational(new_numerator, new_denominator);
	}

	Rational operator/(const Rational &lhs, const Rational &rhs)
	{
		Integer new_numerator = lhs.get_numerator() * rhs.get_denominator();
		Integer new_denominator = lhs.get_denominator() * rhs.get_numerator();
		return Rational(new_numerator, new_denominator);
	}

	std::ostream &operator<<(std::ostream &os, const Rational &i)
	{
		if (i.get_numerator() % i.get_denominator() == Integer("0"))
		{
			os << (i.get_numerator() / i.get_denominator());
			return os;
		}

		if (Integer(1, i.get_numerator().get_digits()) < Integer(1, i.get_denominator().get_digits()))
		{
			os << i.get_numerator() << "/" << +i.get_denominator();
			return os;
		}

		os << (i.get_numerator() / i.get_denominator()) << "." << (Integer(1, i.get_numerator().get_digits()) % Integer(1, i.get_denominator().get_digits())) << "/" << i.get_denominator();

		return os;
	}
	std::istream &operator>>(std::istream &is, Rational &i)
	{
		// TODO
		return is;
	}

	bool operator<(const Rational &lhs, const Rational &rhs)
	{
		return (lhs.numerator * rhs.denominator) > (rhs.numerator * lhs.denominator);
	}

	bool operator>(const Rational &lhs, const Rational &rhs)
	{
		return !(lhs < rhs);
	}

	bool operator<=(const Rational &lhs, const Rational &rhs)
	{
		return (lhs < rhs) || (lhs == rhs);
	}

	bool operator>=(const Rational &lhs, const Rational &rhs)
	{
		return (lhs > rhs) || (lhs == rhs);
	}

	bool operator==(const Rational &lhs, const Rational &rhs)
	{
		return !(lhs > rhs) && !(lhs < rhs);
	}

	bool operator!=(const Rational &lhs, const Rational &rhs)
	{
		return !(lhs == rhs);
	}

}
