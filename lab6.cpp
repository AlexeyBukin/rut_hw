
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#define MAX_SIZE 255

class Array {

protected:
	unsigned char	*array;
	unsigned char	initial_value; // значение по умолчанию для элемента
	unsigned char	size; // размер массива

public:
	Array(unsigned char arr_size); // конструктор инициализации
	Array(unsigned char arr_size, unsigned char init_val); // конструктор инициализации
	Array(const Array &a); // конструктор копирования
	Array() : size(0), initial_value(0), array(nullptr) {}; // конструктор без аргументов

	virtual unsigned char&	operator[](int index); // оператор индексирования
	virtual void	sum_with(Array &a); //функция поэлементного сложения
	virtual string	toString();
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

class BitString : public Array {

public:
	BitString(unsigned char arr_size): Array(arr_size) {}; // конструктор инициализации
	BitString() : Array(0) {}; // конструктор без аргументов

	virtual unsigned char&	operator[](int index); // оператор индексирования

	virtual void		sum_with(Array &a); //функция поэлементного сложения
	virtual string		toString();

};

string BitString::toString() {
	ostringstream s;
	s << "BitString: \'";
	for (int i = 0; i < size; i++)
		s << (int)array[i];
	s << "\'";
	return s.str();
}

// оператор индексирования
unsigned char&	BitString::operator[](const int index) {
	if (index < 0 || index >= size)
		return (initial_value);
	return array[index];
}

void BitString::sum_with(Array &a) {
	Array::sum_with(a);
	for (int i = 0; i < size; i++)
		array[i] = array[i] ? 1 : 0;
}

int		main()
{
	cout << "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑" << endl;
	cout << "|  Демонстрация работы функций       |" << endl;
	cout << "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙" << endl << endl;

	Array a1 = Array();
	Array a2 = Array(4);
	Array a3 = Array(5, 7);

	cout << "По умолчанию    : " << a1.toString() << endl;
	cout << "С размером 4    : " << a2.toString() << endl;
	cout << "С заполнением 7 : " << a3.toString() << endl;

	BitString b1 = BitString(2);
	BitString *b2 = new BitString(2);
	Array a4 = BitString(2);
	Array *a5 = new BitString(2);

	cout << endl;
	cout << "b1 : " << b1.toString() << endl;
	cout << "b2 : " << b2->toString() << endl;
	cout << "a4 : " << a4.toString() << endl;
	cout << "a5 : " << a5->toString() << endl; // в объекте типа Array лежит BitString
	// вызывается виртуальная функция BitString из объекта Array

	Array *a6 = new BitString(5);
	Array *a7 = new Array(5, 9);
	(*a7)[1] = 0;
	(*a7)[3] = 0;

	cout << endl;
	cout << "a6 : " << a6->toString() << endl;
	cout << "a7 : " << a7->toString() << endl;

	a6->sum_with(*a7); // сработала виртуальная функция сложения из BitString
	cout << "a6 после сложения с a7: " << a6->toString() << endl;

	return (0);
}
