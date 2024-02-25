#include "iostream"
#include "fstream"
#include "vector"
#include "string"


/*Вывести сообщение в консоль*/
void viewConsole(std::string text)
{
    std::cout << text << std::endl;
}

/*Прочитать из речки все рыбки, получить вектор*/
void readFile(std::vector<std::string>& vec)
{
    std::string fish;
    std::ifstream file("river.txt");

    if (file.is_open())
    {
        while (std::getline(file, fish))
        {
            if (!fish.empty())
            {
                vec.push_back(fish);
            }
        }

        file.close();
    } else
    {
        std::cerr << "Ошибка: Не удается открыть файл для чтения.\n";
    }
}

/*Записать в корзинку(файл) рыбку*/
void writeFile(std::string fish)
{
    std::ofstream file;
    file.open("basket.txt", std::ios::app);
    if (file.good())
    {
        file << fish << std::endl;
    } else
    {
        std::cerr << "Ошибка: Не удается открыть или записать в файл.\n";
    }
    file.close();
}

/*Перезаписать файл*/
void updatingRiver(std::vector<std::string>& vec)
{
    std::ofstream file;
    file.open("river.txt", std::ofstream::trunc);
    if (file.is_open())
    {
        for (const std::string& new_line : vec)
        {
            file << new_line << std::endl;
        }

        file.close();
    }
    else
    {
        std::cerr << "Ошибка: Не удается открыть или записать в файл.\n";
    }
}

/*Принимаю вектор рыбок и рыбку от рыбока перебираю вектор на совподение*/
void fishing(std::vector <std::string> &vec, const std::string &fish)
{
    bool flag = true;
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        if (*i == fish)
        {
            writeFile(fish); //добавил в корзинку
            vec.erase(i); //удалил из речки. Удалить элемент из вектора
            updatingRiver(vec); //обновил речку. Презаписал файл
            flag = false;
            viewConsole("Рыбка поймана! Положил в корзинку.");
            break;
        }
        flag = true;
    }

    if(flag){
        viewConsole("Смени наживку!!");
    }
}



void task3()
{
    std::vector<std::string> vec;
    readFile(vec);
    std::string fish;
    std::ofstream file("basket.txt", std::ofstream::trunc);
    file.close();

    while(true)
    {
        viewConsole("рыбка: ");
        std::cin >> fish;
        fishing(vec, fish);
    }
}