#include "iostream"
#include "fstream"
#include <string>

void safeFile(std::string& name,
              std::string& surname,
              std::string& date,
              int& salary)
{
    std::ofstream file;
    if (!file.good())
    {
        file.open("file.txt");
        file << name << " " << surname << " " << date << " " << salary << std::endl;
    } else
    {
        file.open("file.txt", std::ios::app);
        file << name << " " << surname << " " << date << " " << salary << std::endl;
    }
    std::cout << "update date";
}

bool isAlphabetic(std::string& str)
{
    for (char c : str)
    {
        if (!isalpha(c))
        {
            return false;
        }
    }
    return true;
}

void checkingForLineEntry(std::string& name)
{
    while (!isAlphabetic(name))
    {
        std::cerr << "input error, please try again: ";
        std::cin >> name;
    }
    return;
}

bool isNumber(std::string num)
{
    for (size_t i = 0; i < num.length(); ++i)
    {
        if (!std::isdigit(num[i]))
        {
            return false;
        }
    }
    return true;
}

void dateValidation(std::string& date)
{
    if (date.substr(2, 1) != "." && date.substr(5, 1) != "." && date.size() != 10)
    {
        std::cerr << "Invalid date input. Please try again." << std::endl;
        std::cin >> date;
        dateValidation(date);
    }

    if (!isNumber(date.substr(0, 2)) || !isNumber(date.substr(3, 2)) || !isNumber(date.substr(6, 4)))
    {
        std::cerr << "Invalid date input. Please try again: ";
        std::cin >> date;
        dateValidation(date);
    }

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900)
    {
        std::cerr << "Invalid date input. Please try again: ";
        std::cin >> date;
        dateValidation(date);
    }
}


void task1()
{
    std::string name;
    std::string surname;
    std::string date;
    int salary;



    std::cout << "Enter the name: ";
    std::cin >> name;
    checkingForLineEntry(name);

    std::cout << "Enter the surname: ";
    std::cin >> surname;
    checkingForLineEntry(surname);

    std::cout << "Enter the date: ";
    std::cin >> date;
    dateValidation(date);

    std::cout << "Enter the salary: ";
    std::cin >> salary;

    safeFile(name, surname, date, salary);
}