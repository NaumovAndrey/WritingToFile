#include "iostream"
#include "fstream"
#include "string"

/**/

void sign()
{
	std::ofstream file;
	file.open("file.txt", std::ios::app); // ������� � ��������
	file.setf(std::ios::showpos); //����� ����� �� ������ + - +36.6
	double doubleNumber = 36.6;
	file << std::endl << doubleNumber; //������ � ����: +36.6
	file.close();
}

void writingBool()
{
	std::ofstream file;
	file.open("file.txt", std::ios::app); // ������� � ��������
	file.setf(std::ios::showpos); //����� ����� �� ������ + - +36.6
	file.setf(std::ios::boolalpha); //����� ����� "true / falese" ������ "1" ��� "0"
	file.setf(std::ios::showpoint); // �������� ����� ��� ������ --> 20 ������� +20.0000
	file.precision(3); // --> +20.0 �������� 3 �����
	bool light = true;
	double doubleNumber = 20;
	file << std::endl << doubleNumber; 
	file.close();
}

void array()
{
	std::ofstream file;
	file.open("file.txt", std::ios::app); // ������� � ��������
	file.setf(std::ios::showpos); //����� ����� �� ������ + - +36.6
	file.setf(std::ios::boolalpha); //����� ����� "true / falese" ������ "1" ��� "0"
	file.setf(std::ios::showpoint); // �������� ����� ��� ������ --> 20 ������� +20.0000
	file.setf(std::ios::fixed); // �� ������ ����� � ��������� ������ ������������, ��� ���� �������� "file.precision(3)" ������� ���� ������� �����, � �� ����� ���������� ����
	file.precision(1); // --> +20.0 �������� 3 ����� -->1

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