
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Pair {

protected:
	double			x; // число 1
	double			y; // число 2

public:
	Pair(double x, double y) : x(x), y(y) {}; // конструктор инициализации
	Pair(const Pair &p) : x(p.x), y(p.y) {}; // конструктор копирования
	Pair() : x(0.0), y(0.0) {}; // конструктор без аргументов

	string		toString();
	double		mult() { return (x * y); };

	void		setX();
	void		setY();

	double		getX();
	double		getY();
};

string Pair::toString() {
	ostringstream s;
	s << "Пара: { " << x << ", " << y << " }";
	return s.str();
}

class Rectangle : Pair {
public:
	Rectangle(double nx, double ny) { // конструктор инициализации
		if (nx < 0.0 || ny < 0.0) {
			cout << "Ошибочные значения, завершение программы..." << endl;
			exit(0);
		}
		x = nx;
		y = ny;
	};
	Rectangle(const Rectangle &p) { x = p.x; y = p.y; }; // конструктор копирования
	Rectangle(); // конструктор без аргументов

	string		toString(); //подстановка функции (override)

	double		square() { return mult(); }; // использование функции из предка
	double		perimeter() { return ((x + y) * 2); };
};

Rectangle::Rectangle() {
	double nx;
	double ny;
	cout << "Введите первую сторону: ";
	cin >> nx;
	cout << "Введите вторую сторону: ";
	cin >> ny;
	if (nx <= 0.0 || ny <= 0.0) {
		cout << "Ошибочные значения, завершение программы..." << endl;
		exit(0);
	}
	x = nx;
	y = ny;
}

string Rectangle::toString() {
	ostringstream s;
	s << "Прямоугольник: { " << x << ", " << y << " } c периметром "
		<< perimeter() << " и площадью " << square();
	return s.str();
}

int		main()
{
	cout << "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑" << endl;
	cout << "|  Демонстрация работы перегрузок    |" << endl;
	cout << "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙" << endl << endl;

	Pair p1 = Pair();
	cout << "По умолчанию : " << p1.toString() << endl;

	Pair p2 = Pair(1, 3);
	cout << "Произведение пары " << p2.toString() << " равно " << p2.mult() << endl;

	Pair p3 = Pair(p2);
	cout << endl << "Копирование : " << p2.toString() << " -> " << p3.toString() << endl;



	Rectangle r = Rectangle(); // введение данных с терминала
	cout << endl << r.toString() << endl << endl; // использование принципа подстановки

	cout << "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑" << endl;
	cout << "|  Демонстрация работы с классами    |" << endl;
	cout << "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙" << endl << endl;

	Pair *pair_heap = new Pair(2, 5);
	cout << "pair_heap: " << pair_heap->toString() << endl << endl;

	int rect_num = 5;
	Rectangle *array[rect_num];

	for (int i = 1; i <= rect_num; i++) {
		array[i] = new Rectangle(i * 2, i * 3);
		cout << array[i]->toString() << endl;
	}
}
