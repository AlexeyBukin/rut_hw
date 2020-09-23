
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Money {

private:
	long			rub; // рубли
	unsigned char	cop; // копейки

public:
	Money(long r, unsigned char c) : rub(r), cop(c) {}; // конструктор инициализации
	Money(double n); // конструктор инициализации
	Money(const Money &m); // конструктор копирования
	Money(); // конструктор без аргументов

	string		toString();
	double		toDouble();
	void		display();

	void		add(Money a);
	void		substract(Money s);

	static int		compare(Money mon1, Money mon2);
	static double	divide(Money mon1, Money mon2);

	void	mult_num(double n);
	void	divide_num(double n);
};

Money::Money(double n) {
	long lrub = (long)n;
	double cop_d = n - (double)((long)n);
	int icop = (unsigned char)abs(round((cop_d) * 100.0));
	if (n < 0.0)
	{
		lrub--;
		icop = 100 - icop;
	}
	rub = lrub;
	cop = icop;
}

Money::Money(const Money &m) {
	rub = m.rub;
	cop = m.cop;
}

Money::Money() {
	double sum;
	cout << "Введите сумму: ";
	cin >> sum;
	Money tmp = Money(sum);
	rub = tmp.rub;
	cop = tmp.cop;
}

string Money::toString() {
	char buf[100];
	int res = snprintf(buf, sizeof(buf), "%.2f", toDouble());
	string str = "0.00";
	if (res >= 0 && res < sizeof(buf))
		str = buf;
	size_t pos = str.find('.');
	str.replace(pos, 1, ",");
	return (str);
}

double Money::toDouble() {
	int icop = cop;
	if (rub < 0) {
		icop -= 100;
		rub++;
	}
	return ((double) rub + (double) icop / 100.0);
}

void Money::display() {
	cout << "Сумма: " << toString() << endl;
}

void Money::add(Money a) {
	Money tmp = Money(toDouble() + a.toDouble());
	rub = tmp.rub;
	cop = tmp.cop;
}

void Money::substract(Money s) {
	Money tmp = Money(toDouble() - s.toDouble());
	rub = tmp.rub;
	cop = tmp.cop;
}

int Money::compare(Money mon1, Money mon2) {
	double m1 = mon1.toDouble();
	double m2 = mon2.toDouble();
	if (m1 == m2)
		return (0);
	return (m1 > m2 ? 1 : -1);
}

double Money::divide(Money mon1, Money mon2) {
	double m1 = round(mon1.toDouble() * 100);
	double m2 = round(mon2.toDouble() * 100);
	if (round(m2) == 0.0)
		return (0.0);
	return (m1 / m2);
}

void Money::mult_num(double n) {
	Money tmp = Money(toDouble() * n);
	rub = tmp.rub;
	cop = tmp.cop;
}

void Money::divide_num(double n) {
	if (n == 0.0) {
		rub = 0;
		cop = 0;
		return ;
	}
	Money tmp = Money(toDouble() / n);
	rub = tmp.rub;
	cop = tmp.cop;
}

int		main()
{
	cout << "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑" << endl;
	cout << "|    Демонстрация работы функций     |" << endl;
	cout << "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙" << endl << endl;

	Money mon1 = Money(2, 2);
	Money mon2 = Money(3, 55);

	cout << "mon1: "; mon1.display();
	cout << "mon2: "; mon2.display();
	cout << endl;

	Money sum = mon1;
	sum.add(mon2);
	cout << "sum: " + sum.toString() << endl;

	Money raz = mon1;
	raz.substract(mon2);
	cout << "raz: " + raz.toString() << endl;

	cout << "cmp: " + to_string(Money::compare(mon1, mon2)) << endl;
	cout << "div: " + to_string(Money::divide(mon1, mon2)) << endl;
	cout << endl;

	double num = 1.5;
	Money input = Money(); // вводится из терминала
	cout << "number: " + to_string(num) << endl;
	cout << "money : " + input.toString() << endl;
	cout << endl;

	Money mult = input;
	mult.mult_num(num);
	cout << "multiplication : " + mult.toString() << endl;

	Money div = input;
	div.divide_num(num);
	cout << "division       : " + div.toString() << endl;

	cout << "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑" << endl;
	cout << "|  Демонстрация работы с классами    |" << endl;
	cout << "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙" << endl << endl;

	Money *money_heap = new Money(1, 99);
	cout << "money_heap: "; money_heap->display();

	int money_num = 8;
	Money *array[money_num];

	for (int i = 0; i < money_num; i++) {
		array[i] = new Money(i, i);
		cout << "array[" << i << "] : "; array[i]->display();
	}
}
