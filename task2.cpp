#include "iostream"
#include <cstdlib>
#include <ctime>
#include <vector>
#include "fstream"

/**/
void writeToFile(const std::vector<std::vector<bool>>& v)
{
    std::ofstream file;
    file.open("pic.txt");

    if (file.is_open())
    {
        for (const auto& vec : v)
        {
            for (int elem : vec)
            {
                file << elem;
            }
            file << std::endl;
        }
        file.close();
    } else
    {
        std::cerr << "error. Unable to open file.\n";
    }
    file.close();
}


void picture(const int& x, const int& y)
{
    std::vector<std::vector<bool>> line;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int j = 0; j < y; ++j)
    {
        std::vector<bool> tempLine;
        for (int i = 0; i < x; ++i)
        {
            bool randomBool = std::rand() % 2 == 1;
            tempLine.push_back(randomBool);
        }
        line.push_back(tempLine);
    }

    writeToFile(line);
}


void inputSize(std::string text)
{
    std::cout << text;
}

void task2()
{
    int x, y;
    inputSize("enter the size of the field by X and Y: ");
    std::cin >> x >> y;
    picture(x, y);
}