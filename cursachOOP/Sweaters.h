#pragma once
#include "proverki.h"
#include "Clothes.h"

class Sweaters : public Clothes
{
	char color[20];

public:
	void setColor();
	char* getColor();
	void input_info()
	{
		this->setType();
		this->setAmount(200);
		this->setSize();
		this->setPrice();
		this->setColor();
		}
	void show_info(int n)
	{
		cout << "\n\t|" << " " << n << " " << "|" << " " << setfill(' ') << left << setw(10) << this->getPrice() << '|' << " " << left << setw(10) << this->getAmount() << '|' << " " << left << setw(10) << this->getSize()
			<< '|' << " " << left << setw(20) << this->getType() << '|'<< " " << left << setw(20) << "-" << '|' << " " << left << setw(20) << this->getColor() << '|';
	}
};

void Sweaters::setColor()
{
	cout << "\n\tУкажите цвет кофты:  ";
	cin >> color;
}
char* Sweaters::getColor() { return color; }