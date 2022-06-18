#include <iostream>

class Fraction
{
private:
	int m_numerator = 0;
	int m_denominator = 1;

public:
	
	Fraction(int numerator = 0, int denominator = 1) : 
		m_numerator(numerator), m_denominator(denominator)
	{
	}
	void setNum(int n) { this->m_numerator = n; }
	void setDen(int n) { this->m_denominator = n; }


	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}
	
	friend Fraction operator * (const Fraction & f1, const Fraction & f2);
	friend Fraction operator * (const Fraction & f1, int value);
	friend Fraction operator * (int value, const Fraction & f1);
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	int numerator = f1.m_numerator * f2.m_numerator;
	int denominator = f1.m_denominator * f2.m_denominator;	
	return Fraction(numerator, denominator); 
	
}

Fraction operator*(const Fraction &f1, int value)
{
	int numerator = f1.m_numerator * value;
	int denominator = f1.m_denominator;	
	return Fraction(numerator, denominator); 
	
}

Fraction operator*(int value, const Fraction &f1)
{
	int numerator = f1.m_numerator * value;
	int denominator = f1.m_denominator;
	return Fraction(numerator, denominator); 
	
}


int main()
{
	Fraction f1(3, 4);
	f1.print();

	Fraction f2(2, 7);
	f2.print();

	Fraction f3 = f1 * f2; 
	f3.print();

	Fraction f4 = f1 * 3; 
	f4.print();

	Fraction f5 = 3 * f2; 
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();

	
	return 0;
}


