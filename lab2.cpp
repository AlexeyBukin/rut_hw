
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

Money_s		read() {
	long r;
	unsigned char c;
	cout << "Введите рубли: ";
	cin >> r;
	cout << "Введите копейки: ";
	cin >> c;
	return init(r, c);
}

string		toString(Money_s money) {
	return (to_string(money.rub) + "," + to_string(money.cop));
}

void		display(Money_s money) {
	cout << "Сумма: " << toString(money) << endl;
}

int			sign(long num) {
	return (num < 0 ? -1 : 1);
}

int			sign(Money_s money) {
	return (sign(money.rub));
}

double 		toDouble(Money_s m) {
	return ((double) m.rub + (double) m.cop * (double)sign(m) / 100.0);
}

int			compare(Money_s mon1, Money_s mon2) {
	double m1 = toDouble(mon1);
	double m2 = toDouble(mon2);
	if (m1 == m2)
		return (0);
	return (m1 > m2 ? 1 : -1);
}

Money_s		toMoney_s(double n) {
	Money_s m{};
	m.rub = (long)n;
	m.cop = (unsigned char) abs((n - (double)(m.rub)) * 100.0);
	return (m);
}

Money_s		summa(Money_s mon1, Money_s mon2) {
	mon1.cop = (mon1.cop * sign(mon1) + mon2.cop * sign(mon2)) * sign(mon1);
	if ((mon1.cop * sign(mon1)) > 99) {
		mon1.rub += sign(mon1) * 1;
		mon1.cop = (mon1.cop * sign(mon1) - 100) * sign(mon1);
	}
	mon1.rub += mon2.rub;
	return (mon1);
}

Money_s		raznost(Money_s mon1, Money_s mon2) {
	long cop = (mon1.cop * sign(mon1) - mon2.cop * sign(mon2)) * sign(mon1);
	long rub = mon1.rub - mon2.rub;

	cout << "cop = " << cop << endl;
	cout << "rub = " << rub << endl;

	if (sign(cop) != sign(rub))
		rub--;

//	cout << "cop = " << cop << endl;
//
//	if (cop < 0) {
//		mon1.rub -= sign(mon1) * 1;
//		mon1.cop = abs(cop);
//		if (sign(rub) == sign(mon1.rub)) {
//			mon1.rub += sign(mon1);
//		}
//	}
//	mon1.cop = abs(cop);
//	if (sign(mon1) == sign(mon2)) {
//		mon1.cop = abs(cop);
//	}
//	else {
//		if (cop < 0) {
//			mon1.rub -= sign(mon1) * 1;
//			mon1.cop = cop + 100;
//		}
//	}
	//	mon1.cop = abs(cop);

//	mon1.rub -= mon2.rub;

	mon1.cop = cop;
	mon1.rub = rub;
	return (mon1);
}

double		divide(Money_s mon1, Money_s mon2) {
	double m1 = toDouble(mon1);
	double m2 = toDouble(mon2);
	if (m2 == 0.0)
		return (0.0);
	return (m1 / m2);
}

Money_s		multiply_num(Money_s m, double n) {
	n = toDouble(m) * n;
	return (toMoney_s(n));
}

Money_s		divide_num(Money_s m, double n) {
	if (n == 0.0)
		return (toMoney_s(0.0));
	n = toDouble(m) / n;
	return (toMoney_s(n));
}

int		main()
{
	double num = 1.5;
	Money_s mon1 = init(-1, 10);
	Money_s mon2 = init(-1, 55);

	cout << "mon1: "; display(mon1);
	cout << "mon2: "; display(mon2);
	cout << endl;
	cout << "sum: " + toString(summa(mon1, mon2)) << endl;
	cout << "raz: " + toString(raznost(mon1, mon2)) << endl;
	cout << "cmp: " + to_string(compare(mon1, mon2)) << endl;
	cout << "div: " + to_string(divide(mon1, mon2)) << endl;
	cout << endl;
	cout << endl;
	cout << "num: " + to_string(num) << endl;
	cout << "mon: " + toString(mon1) << endl;
	cout << endl;
	cout << "multiplication : " + toString(multiply_num(mon1, num)) << endl;
	cout << "division       : " + toString(divide_num(mon1, num)) << endl;
}
