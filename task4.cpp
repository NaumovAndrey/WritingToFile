#include "iostream"
#include "vector"
#include "random"
#include "fstream"
#include "string"

int countB = 0;
int totalSum = 0;

void viewConsole1(std::string text)
{
    std::cout << text << std::endl;
}

/*Пополнение банкомата под завязку*/
void initBank(std::vector<int> &atmBill, const int* bill, const size_t &size)
{
    // todo проверить если файл существует считать из него данные txt, bin (проверка соответствия файлов)
    int maxAtm = 1000 - atmBill.size();
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distIndex(0, size - 1);

    std::ofstream file;
    file.open("atmBank.txt", std::ios::app);

    std::ofstream fileBin; //todo почему при открытии второго файла оба не создаются и не пишет данные
    fileBin.open("atmBank.bin", std::ios::binary);

    int countBill = 0;
    int sum = 0;
    for (size_t i = 0; i < maxAtm; i++)
    {
        int temp = bill[distIndex(mt)];
        atmBill.push_back(temp);
        fileBin << temp << std::endl;
        countBill++;
        sum += temp;
    }
    totalSum += sum;
    countB += countBill;

    file << "Пополнение: " << sum << " добавлено " << countBill << " купюр" << std::endl;
    file.close();
    fileBin.close();
}

bool isNumber1(std::string num)
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

void cashOut(std::string cash)
{
    if (isNumber1(cash))
    {
        int cashh = std::stoi(cash);
        totalSum -= cashh;

        //todo перекинуть в метод перебора по вектору (найти нужные купюры и удалить их из вектора), вызвать сообщение о выдаче стредств
        // todo перекинут в метод записи в файл txt условных данных и перезаписать вектор или удалить из файла записи банкнот в бинарном файле
    }
}

void atm(std::vector<int>& atmBill, const int* bill, const size_t& size)
{
    std::string usEn;
    viewConsole1("Введите операцию: ");
    std::cin >> usEn;

    if (usEn == "+")
    {
        if (atmBill.size() < 1000)
        {
            viewConsole1("вызываю инкасаторов для пополнения");
            initBank(atmBill, bill, size);
            viewConsole1("Операция пополнения выполнена");
        } else
        {
            viewConsole1("Операция прервана. Банкомат заполнен!");
        }
    } else if (usEn == "-")
    {
        viewConsole1("Операция снятия:\nВведите сумму: ");
        std::cin >> usEn;
        //todo передать методу на снятие 
    }
}

void task4()
{
	std::vector<int> atmBill;
	const int bill[] = { 100, 200, 500, 1000, 2000, 5000 };
    const size_t billSize = sizeof(bill) / sizeof(bill[0]);
	initBank(atmBill, bill, billSize);// изначально набиваем банкомат

}