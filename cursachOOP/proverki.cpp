#include "proverki.h"

int CheckInt(int n) {
	int temp = 0;
	while (1) {
		cin >> temp;
		if (!cin || temp <= 0 || temp > n) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\n\tВы должны ввести целое положительное число меньше чем " << n << " !!!!!!\n\t";
		}
		else {
			cin.ignore(32767, '\n');
			return temp;
		}
	}
}

double rezDouble(int& a, double& b) {
	double c = double(a) * b;
	return c;
}

void cinStr(char* str, int size) {
	do {
		if (!cin.getline(str, size)) {
			cout << "\n\tДо " << size - 1 << " символов! Повторите попытку  ";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else break;
	} while (true);
}

void cinPassword(char* password, int len) {
	int i = 0;
	char ch = ' ';
	while (i != len - 1) {
		ch = _getch();
		if (ch == 13) {
			if (i != 0) {
				break;
			}
		}
		else if (ch == '\b') {
			if (i != 0) {
				i -= 1;
				std::cout << "\b \b";
			}
		}
		else if (ch != 27) {
			std::cout << "*";
			password[i] = ch;
			i++;
		}
	}
	password[i] = '\0';
}