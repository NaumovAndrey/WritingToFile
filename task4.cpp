#include "iostream"
#include "vector"
#include "random"

void atm(std::vector<int> atmBill)
{
	 
}

void initBank(std::vector<int> &atmBill, const int* bill, size_t size)
{
    int maxAtm = 1000 - atmBill.size();
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distIndex(0, size - 1);

    for (size_t i = 0; i < maxAtm; i++)
    {
        atmBill.push_back(bill[distIndex(mt)]);
    }
}

void task4()
{
	std::vector<int> atmBill;
	const int bill[] = { 100, 200, 500, 1000, 2000, 5000 };
    const size_t billSize = sizeof(bill) / sizeof(bill[0]);
	initBank(atmBill, bill, billSize);// изначально набиваем банкомат

}