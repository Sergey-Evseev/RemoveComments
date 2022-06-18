#include <iostream>

class Fraction
{
private:
	int m_numerator = 0;
	int m_denominator = 1;

public:
	
	Fraction(int numerator = 0, int denominator = 1) : //конструктор с параметрами?
		m_numerator(numerator), m_denominator(denominator)
	{
	}
	void setNum(int n) { this->m_numerator = n; }
	void setDen(int n) { this->m_denominator = n; }


	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}
	//декларация дружественных функций - перегрузки оператора умножения - для доступа к полям класса//
	friend Fraction operator * (const Fraction & f1, const Fraction & f2);
	friend Fraction operator * (const Fraction & f1, int value);
	friend Fraction operator * (int value, const Fraction & f1);
};

Fraction operator*(const Fraction &f1, const Fraction &f2)//передаем ссылки на два объекта Fraction с двумя инициализированнми полями
{
	int numerator = f1.m_numerator * f2.m_numerator;//находим общий числитель
	int denominator = f1.m_denominator * f2.m_denominator;	//находим общий знаменатель
	return Fraction(numerator, denominator); //возвращаем объект с новыми значениями
	//либо кратко (все тело): return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction &f1, int value)//дробь на целое 
{
	int numerator = f1.m_numerator * value;
	int denominator = f1.m_denominator;	
	return Fraction(numerator, denominator); 
	//кратко (все тело): return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction &f1)//целое на дробь
{
	int numerator = f1.m_numerator * value;
	int denominator = f1.m_denominator;
	return Fraction(numerator, denominator); //возвращаем объект с новыми значениями
	//кратко: return Fraction(f1.m_numerator * value, f1.m_denominator);
}


int main()
{
	Fraction f1(3, 4);
	f1.print();

	Fraction f2(2, 7);
	f2.print();

	Fraction f3 = f1 * f2; //дробь на дробь
	f3.print();

	Fraction f4 = f1 * 3; //дробь на целое
	f4.print();

	Fraction f5 = 3 * f2; //целое на дробь
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();

	
	return 0;
}

