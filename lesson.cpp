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

void writeFile() //запись бинарного файла int
{
	int number;
	std::cin >> number;

	std::ofstream filebinary("fileBinary.bin", std::ios::binary);
	filebinary.write((char*) &number, sizeof(number));
	filebinary.close();
 }

void readFile(std::string &file) //чтение бинарного файла int
{
	int number;
	std::ifstream filebinary(file, std::ios::binary);
	filebinary.read((char*) &number, sizeof(number));
	filebinary.close();

	std::cout << number << std::endl;
}

void writeFileString() //запись бинарного файла string
{
	const char* title = "GeekBrains";

	std::ofstream filebinary("title.bin", std::ios::binary);
	filebinary.write(title, std::strlen(title)); //длина нультерминированно си строки, сколько в ней чаров
	filebinary << std::endl << 23;
	filebinary.close();
	std::cout << "запись завершена";
}

void lesson()
{
	//sign();
	//writingBool();
	//array();

	//writeFile(); //запись бинарного файла

	//std::string binaryfile = "fileBinary.bin";
	//readFile(binaryfile); //чтение бинарного файла
	//writeFileString();
}