#pragma once
#include "proverki.h"

class Account {
public:
	/*static*/ void createLogin(vector <Account>&);//����� ��� �������� � �������� ������
	void createPass(); //����� ��� �������� � �������� ������
	char* getLog(); //��������� ������
	char* getPass();//��������� ������ 
	void regAccount(vector<Account>&); //����������� ��������
	bool checkPass(char*); //�������� ������ �� ������������
	bool isAdmin(); //�������� �������� �� ������� ���������������
	bool isActive(); //�������� �������� �� ������� ��������
	void readAccsInFile(vector <Account>&); //����������  ��������� ��  ����� 
	void readAccsInVector(vector<Account>&); //���������� ��������� �� �������   � �������
	void writeAccsToFile(vector<Account>&); //������ ��������� � ����
	int findAccount(vector<Account>&, char*); //����� ��������� �� ������
	void editAccounts(vector<Account>&); //�������������� ���������
	void delAccount(vector<Account>&); //�������� ��������(���������)
	void makePassFromCipher(); //����� ��� ���������� ������  �� �����
	void makeCipherFromPass(); // ����� ��� ���������� ����� �� ������
	char* getCypherPass(); //��������� �������������� ������
	void passClear(); //����� ��� ������� ����  � �������
	void replaceLogin(vector <Account>& Accounts); // ������ ������ ��� �������������� ��������
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
