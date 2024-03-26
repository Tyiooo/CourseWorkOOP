#pragma once
#include "proverki.h"
#include "Clothes.h"

class Pants : public Clothes
{
	char accessory[20];

public:
	void setAccessory();
	char* getAccessory();
	void input_info()
	{
		this->setType();
		this->setAmount(100);
		this->setSize();
		this->setPrice();
		this->setAccessory();
	}
	void show_info(int n)
	{
		cout << "\n\t|" << " " << n << " " << "|" << " " << setfill(' ') << left << setw(10) << this->getPrice() << '|' << " " << left << setw(10) << this->getAmount() << '|' << " " << left << setw(10) << this->getSize()
			<< '|' << " " << left << setw(20) << this->getType() << '|' << " " << left << setw(20) << this->getAccessory() << '|' << " " << left << setw(20) << "-" << '|';
	}
};

void Pants::setAccessory()
{
	cout << "\n\t”кажите фурнитуру штанов:  ";
	cin >> accessory;
}
char* Pants::getAccessory() { return accessory; }