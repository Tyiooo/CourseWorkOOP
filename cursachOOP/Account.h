#pragma once
#include "proverki.h"

class Account {
public:
	/*static*/ void createLogin(vector <Account>&);//метод для создания и проверки логина
	void createPass(); //метод для создания и проверки пароля
	char* getLog(); //получение логина
	char* getPass();//получение пароля 
	void regAccount(vector<Account>&); //регистрация аккаунта
	bool checkPass(char*); //проверка пароля на правильность
	bool isAdmin(); //проверка является ли аккаунт администратором
	bool isActive(); //проверка является ли аккаунт активным
	void readAccsInFile(vector <Account>&); //считывание  аккаунтов из  файла 
	void readAccsInVector(vector<Account>&); //считывание аккаунтов из вектора   в консоль
	void writeAccsToFile(vector<Account>&); //запись аккаунтов в файл
	int findAccount(vector<Account>&, char*); //поиск аккаунтов по логину
	void editAccounts(vector<Account>&); //редактирование аккаунтов
	void delAccount(vector<Account>&); //удаление аккаунта(аккаунтов)
	void makePassFromCipher(); //метод для извлечение пароля  из шифра
	void makeCipherFromPass(); // метод для извлечения шифра из пароля
	char* getCypherPass(); //получение зашифрованного пароля
	void passClear(); //метод для очистки поля  с паролем
	void replaceLogin(vector <Account>& Accounts); // замены логина при редактировании аккаунта
protected:
	char login[30]; 
	char password[30];
	char cypher[21];
	char cypher_password[91];
	bool admin;
	bool active;
};

/*Account::Account() {
	char tmp[30] = " ";
	strcpy_s(login, tmp);
	strcpy_s(password, tmp);
	admin = false;
	active = true;
}*/

/*Account::Account(char* login, char* password, bool admin, bool active) {
	strcpy_s(this->login, login);
	strcpy_s(this->password, password);
	this->admin = admin;
	this->active = active;
}*/
