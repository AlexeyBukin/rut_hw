
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

struct Money_s {
	long rub; // рубли
	unsigned char cop; // копейки
};

Money_s		init(long r, unsigned char c) {
	if (c > 99) { // проверка значений копеек
		cout << "Ошибочные значения, завершение программы..." << endl;
		exit(0);
	}
	Money_s mon{r, c};
	return (mon);
}

Money_s		toMoney_s(double n) {
	auto rub = (long)n;
	auto cop_d = n - (double)((long)n);
	auto cop = (unsigned char)abs(round((cop_d) * 100.0));
	if (n < 0.0)
	{
		rub--;
		cop = 100 - cop;
	}
	Money_s mon = init(rub, cop);
	return (mon);
}

int			sign(long num) {
	return (num < 0 ? -1 : 1);
}

double 		toDouble(Money_s m) {
	int cop = m.cop;
	if (m.rub < 0) {
		cop -= 100;
		m.rub++;
	}
	return ((double) m.rub + (double) cop / 100.0);
}

Money_s		read() {
	double sum;
	cout << "Введите сумму: ";
	cin >> sum;
	return (toMoney_s(sum));
}

string		toString(Money_s money) {
	char buf[100];
	int res = snprintf(buf, sizeof(buf), "%.2f", toDouble(money));
	string str = "0.00";
	if (res >= 0 && res < sizeof(buf))
		str = buf;
	size_t pos = str.find('.');
	str.replace(pos, 1, ",");
	return (str);
}

void		display(Money_s money) {
	cout << "Сумма: " << toString(money) << endl;
}

int			compare(Money_s mon1, Money_s mon2) {
	double m1 = toDouble(mon1);
	double m2 = toDouble(mon2);
	if (m1 == m2)
		return (0);
	return (m1 > m2 ? 1 : -1);
}

Money_s		summa(Money_s mon1, Money_s mon2) {
	return (toMoney_s(toDouble(mon1) + toDouble(mon2)));
}

Money_s		raznost(Money_s mon1, Money_s mon2) {
	double m1 = round(toDouble(mon1) * 100);
	double m2 = round(toDouble(mon2) * 100);
	double m3 = round(m1 - m2) / 100;
	return (toMoney_s(m3));
}

double		divide(Money_s mon1, Money_s mon2) {
	double m1 = round(toDouble(mon1) * 100);
	double m2 = round(toDouble(mon2) * 100);
	if (round(m2) == 0.0)
		return (0.0);
	return (m1 / m2);
}

Money_s		multiply_num(Money_s m, double n) {
	return (toMoney_s(toDouble(m) * n));
}

Money_s		divide_num(Money_s m, double n) {
	if (n == 0.0)
		return (toMoney_s(0.0));
	double res = round(toDouble(m) * 100) / n / 100;
	return (toMoney_s(res));
}

void		demo_struct()
{
	cout << "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑" << endl;
	cout << "| Демонстрация структурного варианта |" << endl;
	cout << "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙" << endl << endl;

	Money_s mon1 = init(2, 02);
	Money_s mon2 = init(3, 55);

	cout << "mon1: "; display(mon1);
	cout << "mon2: "; display(mon2);
	cout << endl;

	cout << "sum: " + toString(summa(mon1, mon2)) << endl;
	cout << "raz: " + toString(raznost(mon1, mon2)) << endl;
	cout << "cmp: " + to_string(compare(mon1, mon2)) << endl;
	cout << "div: " + to_string(divide(mon1, mon2)) << endl;
	cout << endl;

	double num = 1.5;
	cout << "num: " + to_string(num) << endl;

	Money_s mon3 = read();
	cout << "mon: " + toString(mon3) << endl;
	cout << endl;

	cout << "multiplication : " + toString(multiply_num(mon3, num)) << endl;
	cout << "division       : " + toString(divide_num(mon3, num)) << endl;
}



//----------------------------------------------------------//

class Money_c {
	long		rub; // рубли
	unsigned	char cop; // копейки



public:
	Money_c(long r, unsigned char c);
	Money_c(double n);
	Money_c();

	string		toString();
	double		toDouble();
	void		display();

	void		add(Money_c c);
	void		substract(Money_c c);

	static int		compare(Money_c mon1, Money_c mon2);
	static double	divide(Money_c mon1, Money_c mon2);

	void mult_num(double d);

	void divide_num(double n);
};

//Money_c toMoney_c(double d);

string Money_c::toString() {
	char buf[100];
	int res = snprintf(buf, sizeof(buf), "%.2f", toDouble());
	string str = "0.00";
	if (res >= 0 && res < sizeof(buf))
		str = buf;
	size_t pos = str.find('.');
	str.replace(pos, 1, ",");
	return (str);
}

double Money_c::toDouble() {
	int icop = cop;
	if (rub < 0) {
		icop -= 100;
		rub++;
	}
	return ((double) rub + (double) icop / 100.0);
}

Money_c::Money_c(long r, unsigned char c) {
	this->rub = r;
	this->cop = c;
}

void Money_c::display() {
	cout << "Сумма: " << toString() << endl;
}

void Money_c::add(Money_c a) {
	Money_c tmp = Money_c(toDouble() + a.toDouble());
	this->rub = tmp.rub;
	this->cop = tmp.cop;
}

Money_c::Money_c(double n) {
	auto lrub = (long)n;
	auto cop_d = n - (double)((long)n);
	auto icop = (unsigned char)abs(round((cop_d) * 100.0));
	if (n < 0.0)
	{
		lrub--;
		icop = 100 - icop;
	}
	this->rub = lrub;
	this->cop = icop;
}

void Money_c::substract(Money_c s) {
	Money_c tmp = Money_c(toDouble() - s.toDouble());
	this->rub = tmp.rub;
	this->cop = tmp.cop;
}

int Money_c::compare(Money_c mon1, Money_c mon2) {
	double m1 = mon1.toDouble();
	double m2 = mon2.toDouble();
	if (m1 == m2)
		return (0);
	return (m1 > m2 ? 1 : -1);
}

double Money_c::divide(Money_c mon1, Money_c mon2) {
	double m1 = round(mon1.toDouble() * 100);
	double m2 = round(mon2.toDouble() * 100);
	if (round(m2) == 0.0)
		return (0.0);
	return (m1 / m2);
}

Money_c::Money_c() {
	double sum;
	cout << "Введите сумму: ";
	cin >> sum;
	Money_c tmp = Money_c(sum);
	this->rub = tmp.rub;
	this->cop = tmp.cop;
}

void Money_c::mult_num(double n) {
	Money_c tmp = Money_c(toDouble() * n);
	this->rub = tmp.rub;
	this->cop = tmp.cop;
}

void Money_c::divide_num(double n) {
	if (n == 0.0) {
		this->rub = 0;
		this->cop = 0;
		return ;
	}
	Money_c tmp = Money_c(toDouble() / n);
	this->rub = tmp.rub;
	this->cop = tmp.cop;
}

void		demo_class()
{
	cout << "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑" << endl;
	cout << "|  Демонстрация классового варианта  |" << endl;
	cout << "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙" << endl << endl;

	Money_c mon1 = Money_c(2, 02);
	Money_c mon2 = Money_c(3, 55);

	cout << "mon1: "; mon1.display();
	cout << "mon2: "; mon2.display();
	cout << endl;

	Money_c sum = mon1;
	sum.add(mon2);
	cout << "sum: " + sum.toString() << endl;

	Money_c raz = mon1;
	raz.substract(mon2);
	cout << "raz: " + raz.toString() << endl;

	cout << "cmp: " + to_string(Money_c::compare(mon1, mon2)) << endl;
	cout << "div: " + to_string(Money_c::divide(mon1, mon2)) << endl;
	cout << endl;

	double num = 1.5;
	Money_c input = Money_c(); // вводится из терминала
	cout << "number: " + to_string(num) << endl;
	cout << "money : " + input.toString() << endl;
	cout << endl;

	Money_c mult = input;
	mult.mult_num(num);
	cout << "multiplication : " + mult.toString() << endl;

	Money_c div = input;
	div.divide_num(num);
	cout << "division       : " + div.toString() << endl;
}

//--------------------------//

int		main()
{
	demo_struct();
	cout << endl;
	demo_class();
}
