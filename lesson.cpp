#include "iostream"
#include "fstream"
#include "string"

/**/

void sign()
{
	std::ofstream file;
	file.open("file.txt", std::ios::app); // открыть и дописать
	file.setf(std::ios::showpos); //вывод будет со знаком + - +36.6
	double doubleNumber = 36.6;
	file << std::endl << doubleNumber; //запись в файл: +36.6
	file.close();
}

void writingBool()
{
	std::ofstream file;
	file.open("file.txt", std::ios::app); // открыть и дописать
	file.setf(std::ios::showpos); //вывод будет со знаком + - +36.6
	file.setf(std::ios::boolalpha); //вывод будет "true / falese" вместо "1" или "0"
	file.setf(std::ios::showpoint); // показать точку при выводе --> 20 выведет +20.0000
	file.precision(3); // --> +20.0 точность 3 знака
	bool light = true;
	double doubleNumber = 20;
	file << std::endl << doubleNumber; 
	file.close();
}

void array()
{
	std::ofstream file;
	file.open("file.txt", std::ios::app); // открыть и дописать
	file.setf(std::ios::showpos); //вывод будет со знаком + - +36.6
	file.setf(std::ios::boolalpha); //вывод будет "true / falese" вместо "1" или "0"
	file.setf(std::ios::showpoint); // показать точку при выводе --> 20 выведет +20.0000
	file.setf(std::ios::fixed); // он делает числа с плавающей точкой фиксированно, при этом изменяет "file.precision(3)" терперь надо указать дробь, а не общее количество цифр
	file.precision(1); // --> +20.0 точность 3 знака -->1

	double temps[] = { 10.5, 8.3, 0, -1,1, -2 };
	const char* conditions[] = { "sunny", "cloudy", "windy", "snowy", "stormy" };

	for (size_t i = 0; i < 5; i++)
	{
		file.width(5);
		file << temps[i];
		file.width(10);
		file << conditions[i] << std::endl;
	}

	file.close();
}

void lesson()
{
	//sign();
	//writingBool();
	array();
}