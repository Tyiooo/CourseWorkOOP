#include "Clothes.h"

void Clothes::setSize()
{
	cout << "\n\t������� ������ ������ :  ";
	cinStr(size, 5);
}
char* Clothes::getSize() { return size; }

void Clothes::setType()
{
	cout << "\n\t������� ��� ������ :  ";
	cinStr(type, 20);
}

char* Clothes::getType() { return type; }

void Clothes::setAmount(int n)
{
	//cout << "\n\t������� ���������� ���� :  ";
	amount = n;
}
int Clothes::getAmount() { return amount; }
void Clothes::setPrice()
{
	cout << "\n\t������� ���� �� ����� :  ";
	price = CheckInt(100);
}
double Clothes::getPrice() { return price; }
