#pragma once
#include "proverki.h"

class Clothes
{
	char size[5];
	int amount;
	char type[20];
	double price;
public:
	virtual void input_info() {};
	virtual void show_info(int n) {};
	void setSize();
	char* getSize();
	void setType();
	char* getType();
	void setAmount(int n); 
	int getAmount();
	void setPrice();
	double getPrice();
};