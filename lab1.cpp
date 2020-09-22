
#include <string>
#include <iostream>

using namespace std;

struct Para {

	int first; // первое число
	int second; // второе число

	void	read(); // метод ввода значений для полей
	void	display(); // метод вывода значений полей на экран
	void	init(int f,int s);// метод, присваивающий полям значения
	int		summa(); // метод вычисления денежной суммы
};

int		allowed[9] = {1, 2, 5, 10, 50, 100, 500, 1000, 5000};

void Para::read() {
	int f, s;
	cout << "Введите номинал купюры: ";
	cin >> f;
	cout << "Введите количество купюр: ";
	cin >> s;
	init(f, s);
}

void Para::display() {
	string str = "Денежная пара: first = " + to_string(first);
	str += ", second = " + to_string(second);
	str += ", summa = " + to_string(summa());
	cout << str << endl;
}

void Para::init(int f, int s) {
	first = f;
	second = s;
	if (first <= 0 || second <= 0) // проверка значений пары
	{
		first = 0;
		second = 0;
		return ;
	}
	for (int i : allowed) // проверка номинала купюры
		if (first == i)
		{
			return ;
		}
	cout << "Ошибочные значения, завершение программы..." << endl;
	exit(0);
}

int		Para::summa() {
	return (first * second);
}

Para	make_Para(int f, int s)
{
	Para para = Para();
	para.init(f, s);
	return (para);
}

int		main()
{
	Para para1{};
	para1.init(2, 10);
	cout << "para1: ";
	para1.display();

	Para para2{};
	para2.read();
	cout << "para2: ";
	para2.display();

	Para para3 = make_Para(100, 5);
	cout << "para3: ";
	para3.display();
}
