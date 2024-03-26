#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include <conio.h>
#include <fstream>
#include <map>

using namespace std;

namespace rezultDouble {
	double rezDouble(int& a, double& b);
}

int CheckInt(int n);

void cinStr(char* str, int size);

void cinPassword(char* password, int len);
