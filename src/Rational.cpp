#include "Rational.h"

namespace cosc326
{

	Rational::Rational()
	{
	}

	Rational::Rational(const std::string &str)
	{
	}

	Rational::Rational(const Rational &r)
	{
		this->numerator = r.getNumerator();
		this->denominator = r.getDenominator();
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

		standardizeSigns();
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

		standardizeSigns();
	}

	Rational::~Rational()
	{
	}

	Rational &Rational::operator=(const Rational &r)
	{
		if (*this != r)
		{
			this->numerator = r.getNumerator();
			this->denominator = r.getDenominator();
		}
		return *this;
	}

	Rational Rational::operator-() const
	{
		return Rational(*this);
	}

	Rational Rational::operator+() const
	{
		return Rational(*this);
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

	Integer Rational::getNumerator() const
	{
		return Integer(this->numerator.getSign(), this->numerator.getDigits());
	}

	Integer Rational::getDenominator() const
	{
		return Integer(this->denominator.getSign(), this->denominator.getDigits());
	}

	void Rational::standardizeSigns()
	{

		if (this->numerator.getSign() != this->denominator.getSign())
		{
			this->numerator = Integer(-1, this->numerator.getDigits());
			this->denominator = Integer(1, this->denominator.getDigits());
		}
		else
		{
			this->numerator = Integer(1, this->numerator.getDigits());
			this->denominator = Integer(1, this->denominator.getDigits());
		}
	}

	Rational operator+(const Rational &lhs, const Rational &rhs)
	{
		Integer new_numerator = (lhs.getNumerator() * rhs.getDenominator()) + (rhs.getNumerator() * lhs.getDenominator());
		Integer new_denominator = lhs.getDenominator() * rhs.getDenominator();
		return Rational(new_numerator, new_denominator);
	}

	Rational operator-(const Rational &lhs, const Rational &rhs)
	{
		Integer new_numerator = (lhs.getNumerator() * rhs.getDenominator()) - (rhs.getNumerator() * lhs.getDenominator());
		Integer new_denominator = lhs.getDenominator() * rhs.getDenominator();
		return Rational(new_numerator, new_denominator);
	}

	Rational operator*(const Rational &lhs, const Rational &rhs)
	{
		Integer new_numerator = lhs.getNumerator() * rhs.getNumerator();
		Integer new_denominator = lhs.getDenominator() * rhs.getDenominator();
		return Rational(new_numerator, new_denominator);
	}

	Rational operator/(const Rational &lhs, const Rational &rhs)
	{
		Integer new_numerator = lhs.getNumerator() * rhs.getDenominator();
		Integer new_denominator = lhs.getDenominator() * rhs.getNumerator();
		return Rational(new_numerator, new_denominator);
	}

	std::ostream &operator<<(std::ostream &os, const Rational &i)
	{
		if (i.getNumerator() % i.getDenominator() == Integer("0"))
		{
			os << (i.getNumerator() / i.getDenominator());
			return os;
		}

		if (Integer(1, i.getNumerator().getDigits()) < Integer(1, i.getDenominator().getDigits()))
		{
			os << i.getNumerator() << "/" << +i.getDenominator();
			return os;
		}

		os << (i.getNumerator() / i.getDenominator()) << "." << (Integer(1, i.getNumerator().getDigits()) % Integer(1, i.getDenominator().getDigits())) << "/" << i.getDenominator();

		return os;
	}
	std::istream &operator>>(std::istream &is, Rational &i)
	{
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
