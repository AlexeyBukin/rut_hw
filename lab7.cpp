
#include <iostream>
#include <string>

using namespace std;

// Структура, описываюшщая время
struct MyTime {
	int hours;
	int mins;
 
	MyTime(int phours, int pmins) :
		hours(phours), mins(pmins) {}
};

// собственный класс исключение
class MyTimeException {
	int hours;
	int mins;

	public:

	string message;

	MyTimeException(int phours, int pmins, const string& s) :
		hours(phours), mins(pmins), message(s) {}
};

class MyTimeException2 : public invalid_argument {
	int hours;
	int mins;

	public:

	string message;

	MyTimeException2(int phours, int pmins, const string& s) :
		hours(phours), mins(pmins), invalid_argument(s) {}
};

int TimeSfirst(MyTime Time) {
// не проверяются параметры
	return (Time.hours * Time.mins * 60);
}

int TimeSsecond(MyTime Time) {
// проверяются параметры и в случае их несоответствия генерируются исключения
	if (Time.hours < 0) throw 1;
	if (Time.mins < 0) throw 2;
	return (Time.hours * Time.mins * 60);
}

int TimeSthird(MyTime Time) {
// проверяются параметры и в случае их несоответствия генерируются исключения
	if (Time.hours < 0) throw MyTimeException(Time.hours, Time.mins, "hours < 0");
	if (Time.mins < 0) throw MyTimeException(Time.hours, Time.mins, "mins < 0");
	return (Time.hours * Time.mins * 60);
}

int TimeSfour(MyTime Time) {
// проверяются параметры и в случае их несоответствия генерируются исключения
	if (Time.hours < 0) throw MyTimeException2(Time.hours, Time.mins, "hours < 0");
	if (Time.mins < 0) throw MyTimeException2(Time.hours, Time.mins, "mins < 0");
	return (Time.hours * Time.mins * 60);
}

//Главная функция
int main(int argc, char* argv[])
{

	int hours = 0, mins = 0;
	cout << "Введите часы: ";
	cin >> hours;
	cout << "Введите минуты: ";
	cin >> mins;

	MyTime mytime(hours, mins); 
	// обработка исключения
	try {
		int sec = TimeSfirst(mytime);
		cout << sec << endl;
	}
	catch (int) {
		cout << "Error" << endl;
    }
	try {
		int sec = TimeSsecond(mytime);
		cout << sec << endl;
	}
	catch (int) {
		cout << "Error" << endl;
    }
	try {
		int sec = TimeSthird(mytime);
		cout << sec << endl;
	}
	catch (MyTimeException e) {
		cout << e.message.c_str() << endl;
	}

	try {
		int sec = TimeSfour(mytime);
		cout << sec << endl;
	}
	catch (MyTimeException2 e) {
		cout << e.what() << endl;
	}
 
	return 0;
}
