#include "iostream"
#include <conio.h>
#include <clocale>
#include <cstdlib>

void lesson();
void task1();
void task2();
void task3();
void task4();
void task5();

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Домашняя работа ко второй лекции. Запись в файлы" << std::endl;

    while (true)
    {
        std::cout << "0: lesson" << std::endl;
        std::cout << "1: " << std::endl;
        std::cout << "2: " << std::endl;
        std::cout << "3: " << std::endl;
        std::cout << "4: " << std::endl;
        std::cout << "5: " << std::endl;
        std::cout << "Введите число от 0 до 5 или что-то другое для выхода: ";

        int task = 0;
        //std::cin >> task;

        if (task == 0)
        {
            system("cls");
            std::cout << "lesson" << std::endl;
            lesson();
            _getch();
            system("cls");
        }

        else if (task == 1)
        {
            system("cls");
            std::cout << "Задача 1 " << std::endl;
            task1();
            _getch();
            system("cls");;
        } else if (task == 2)
        {
            system("cls");
            std::cout << "Задача 2 " << std::endl;
            task2();
            _getch();
            system("cls");;
        } else if (task == 3)
        {
            system("cls");
            std::cout << "Задача 3 " << std::endl;
            task3();
            _getch();
            system("cls");;
        } else if (task == 4)
        {
            system("cls");
            std::cout << "Задача 4 " << std::endl;
            task4();
            _getch();
            system("cls");;
        } else if (task == 5)
        {
            system("cls");
            std::cout << "Задача 5 " << std::endl;
            task5();
            _getch();
            system("cls");;
        } else
        {
            system("cls");
            std::cout << "некорректный ввод. Выход из программы";
            break;
        }
    }
}