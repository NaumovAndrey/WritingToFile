#include "iostream"
#include <conio.h>
#include <clocale>
#include <cstdlib>

void lesson();
void task1();
void task2();
void task3();
void task4();


int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Домашняя работа ко второй лекции. Запись в файлы" << std::endl;

    while (true)
    {
        std::cout << "0: lesson" << std::endl;
        std::cout << "1: Реализовать запись в ведомость учёта" << std::endl;
        std::cout << "2: Реализовать рисование случайных картин" << std::endl;
        std::cout << "3: Реализовать симуляцию игры «Рыбалка»." << std::endl;
        std::cout << "4: Реализовать симуляцию работы банкомата." << std::endl;
        std::cout << "Введите число от 0 до 4 или что-то другое для выхода: ";

        int task;
        std::cin >> task;

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
            std::cout << "Задача 1 Реализовать запись в ведомость учёта" << std::endl;
            task1();
            _getch();
            system("cls");;
        } else if (task == 2)
        {
            system("cls");
            std::cout << "Задача 2 Реализовать рисование случайных картин" << std::endl;
            task2();
            _getch();
            system("cls");;
        } else if (task == 3)
        {
            system("cls");
            std::cout << "Задача 3 Реализовать симуляцию игры «Рыбалка»." << std::endl;
            task3();
            _getch();
            system("cls");;
        } else if (task == 4)
        {
            system("cls");
            std::cout << "Задача 4 Реализовать симуляцию работы банкомата." << std::endl;
            task4();
            _getch();
            system("cls");;
        }  else
        {
            system("cls");
            std::cout << "некорректный ввод. Выход из программы";
            break;
        }
    }
}

//начинал делать в Clion, но там ещё не разобрался с кодировкой и очень нужным компонентом как debug, потому сдаю в visual studio