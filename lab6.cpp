
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#define MAX_SIZE 255

class Array {

protected:
	unsigned char	*array;
	unsigned char	size; // размер массива
	unsigned char	initial_value; // значение по умолчанию для элемента

public:
	Array(unsigned char arr_size); // конструктор инициализации
	Array(unsigned char arr_size, unsigned char init_val); // конструктор инициализации
	Array(const Array &a); // конструктор копирования
	Array() : size(0), initial_value(0), array(nullptr) {}; // конструктор без аргументов

	unsigned char&	operator[](int index); // оператор индексирования
	virtual void	sum_with(Array &a); //функция поэлементного сложения
	string			toString();

};

Array::Array(unsigned char arr_size) {
	array = new unsigned char [arr_size];
	size = arr_size;
	initial_value = 0;
	for (int i = 0; i < size; i++)
		array[i] = initial_value;
}

Array::Array(unsigned char arr_size, unsigned char init_val) {
	array = new unsigned char [arr_size];
	size = arr_size;
	initial_value = init_val;
	for (int i = 0; i < size; i++)
		array[i] = initial_value;
}

Array::Array(const Array &a) {
	array = new unsigned char [a.size];
	size = a.size;
	initial_value = a.initial_value;
	for (int i = 0; i < size; i++)
		array[i] = initial_value;
}

// оператор индексирования
unsigned char&	Array::operator[](const int index) {
	if (index < 0 || index >= size)
		return (initial_value);
	return array[index];
}

string			Array::toString() {
	ostringstream s;
	s << "Массив: { ";
	if (size > 0) {
		for (int i = 0; i < size - 1; i++)
			s << (int)array[i] << ", ";
		s << (int)array[size - 1];
	}
	s << " }";
	return s.str();
}

void			Array::sum_with(Array &a) {
	int max_size = size > a.size ? size : a.size;
	unsigned char *max_arr = new unsigned char [max_size];
	for (int i = 0; i < max_size; i++)
	{
		max_arr[i] = (*this)[i] + a[i];
	}
	size = max_size;
	delete[] array;
	array = max_arr;
}


int		main()
{
	cout << "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑" << endl;
	cout << "|  Демонстрация работы массивов      |" << endl;
	cout << "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙" << endl << endl;

	Array a1 = Array();
	Array a2 = Array(4);
	Array a3 = Array(5, 7);

	cout << "По умолчанию    : " << a1.toString() << endl;
	cout << "С размером 4    : " << a2.toString() << endl;
	cout << "С заполнением 7 : " << a3.toString() << endl;

//	cout << "Произведение пары " << p2.toString() << " равно " << p2.mult() << endl;
//
//	Pair p3 = Pair(p2);
//	cout << endl << "Копирование : " << p2.toString() << " -> " << p3.toString() << endl;
//
//
//
//	Rectangle r = Rectangle(); // введение данных с терминала
//	cout << endl << r.toString() << endl << endl; // использование принципа подстановки
//
//	cout << "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑" << endl;
//	cout << "|  Демонстрация работы с классами    |" << endl;
//	cout << "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙" << endl << endl;
//
//	Pair *pair_heap = new Pair(2, 5);
//	cout << "pair_heap: " << pair_heap->toString() << endl << endl;
//
//	int rect_num = 5;
//	Rectangle *array[rect_num];
//
//	for (int i = 1; i <= rect_num; i++) {
//		array[i] = new Rectangle(i * 2, i * 3);
//		cout << array[i]->toString() << endl;
//	}
	return (0);
}
