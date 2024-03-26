#include "Account.h"

static const char* SYPHER_SYMBOLS = "abcdefghijklmnopqrstuvwxyz";

void Account::makeCipherFromPass()
{
	for (int i = 0; i < 20; i++)
		cypher[i] = SYPHER_SYMBOLS[rand() % 10];
	cypher[20] = '\0';
	int k;
	int i = 0;
	for (i; i < (strlen(password) * 3); i++)
	{
		k = i % 20;
		cypher_password[i] = password[i / 3] + cypher[k] - 'a';
	}
	cypher_password[i] = '\0';
}

void Account::makePassFromCipher()
{
	int k;
	int i = 0;
	for (i; i < strlen(cypher_password); i++)
	{
		k = i % 20;
		password[i / 3] = -cypher[k] + 'a' + cypher_password[i];
	}
	password[i / 3] = '\0';
}

void Account::createLogin(vector <Account>& Accounts) {
	while (1) {
		cout << "\n\tЛогин : ";
		cinStr(login, 30);
		cout << "\n\tЛогин успешно задан!" << endl;
		return;
		if (findAccount(Accounts, login) == -1) {
			cout << "\n\tЛогин успешно задан!" << endl;
			return;
		}
		else {
			cout << "\n\tТакой логин уже есть !" << endl;
		}
	}
}

void Account::replaceLogin(vector <Account>& Accounts) {
	while (1) {
		cout << "\n\tЛогин : ";
		cinStr(login, 30);
		cout << "\n\tЛогин успешно задан!" << endl;
		return;
	}
}

void Account::createPass() {
	while (1) {
		cout << "\n\tПароль : ";
		cinStr(password, 30);
		if (checkPass(password)) {
			cout << "\n\tПароль успешно задан!" << endl;
			makeCipherFromPass();
			return;
		}
	}
}

char* Account::getLog() { return login; }

char* Account::getPass() { return password; }

char* Account::getCypherPass() { return cypher_password; }

void Account::regAccount(vector<Account>& Accounts) {
	createLogin(Accounts);
	createPass();
	this->active = true;
	this->admin = false;
}

bool Account::checkPass(char* password) {
	bool isNumb = false;
	if (strlen(password) < 6) {
		cout << "\n\tДлина пароля должна составлять минимум 6 символов!\n";
		return false;
	}
	for (int i = 0; i < strlen(password); i++) {
		if (password[i] >= '0' && password[i] <= '9') {
			isNumb = true;
		}
	}
	if (isNumb) {
		return true;
	}
	else {
		cout << "\n\tПароль должен содержать хотя бы одну цифру!\n";
		return false;
	}
}

bool Account::isAdmin() { return admin; }

bool Account::isActive() { return active; }

void Account::readAccsInFile(vector<Account>& Accounts) {
	ifstream file("Accounts.txt");
	if (file.is_open()) {
		Account tmp;
		while (file.read((char*)&tmp, sizeof(Account))) {
			Accounts.push_back(tmp);
		}
		file.close();
	}
	for (int i = 0; i < Accounts.size(); i++)
		Accounts[i].makePassFromCipher();
}

void Account::writeAccsToFile(vector <Account>& Accounts) {
	ofstream file("Accounts.txt");
	for (int i = 0; i < Accounts.size(); i++)
		Accounts[i].passClear();
	if (file.is_open()) {
		for (int i = 0; i < Accounts.size(); i++) {
			file.write((char*)&Accounts[i], sizeof(Account));
		}
		file.close();
	}
}

void Account::passClear() 
{
	for (int i = 0; i < strlen(password);i++)
		password[i] = ' ';
}

void Account::readAccsInVector(vector<Account>& Accounts) {
	if (Accounts.empty()) {
		cout << "\n\tСписок аккаунтов пуст!!!" << endl;
		return;
	}
	cout << "\n\t-----------------------------------------------------------------------------------------";
	cout << "\n\t|                                 Список учётных записей                                |";
	cout << "\n\t|---------------------------------------------------------------------------------------|";
	cout << "\n\t|" << " N№ " << "|" << setw(30) << "Логин" << "|" << setw(30) << "Пароль" << "|"
		<< setw(6) << "Роль" << "|" << setw(13) << "Статус" << "|";
	string role;
	string status;
	for (int i = 0; i < Accounts.size(); i++) {
		if (Accounts[i].isAdmin()) {
			role = "Админ";
		}
		else {
			role = "Клиент";
		}
		if (Accounts[i].isActive()) {
			status = "Активна";
		}
		else {
			status = "Заблокирована";
		}
		cout << "\n\t|----|------------------------------|------------------------------|------|-------------|";
		cout << "\n\t|" << " " << i + 1 << "  " << "|" << setw(30) << Accounts[i].getLog() << "|" << setw(30) << Accounts[i].getPass() << "|"
			<< setw(6) << role << "|" << setw(13) << status << "|";
		//cout << Accounts[i].getCypherPass() << endl;
	}
	cout << "\n\t-----------------------------------------------------------------------------------------\n\n";
}

int Account::findAccount(vector <Account>& Accounts, char* login) {
	for (int i = 0; i < Accounts.size(); i++) {
		if (!strcmp(Accounts[i].login, login)) {
			return i;
		}
	}
	return -1;
}

void Account::editAccounts(vector <Account>& Accounts) {
	int pos = 0;
	int size = Accounts.size();
	cout << "\n\tВведите номер аккаунта для редактирования(от 1 до " << size << "):  " << endl;
	pos = CheckInt(size);
	while (1) {
		system("cls");
		Account tmp;
		tmp = Accounts[pos - 1];
		cout << "\n\t--------------------- Что изменить??? ------------------------\n\t1.Логин\n\t2.Пароль\n\t3.Подтвердить аккаунт\n\t4.Сохранить и выйти\n\t";
		switch (_getch()) {
		case '1': {
			Accounts[pos - 1].replaceLogin(Accounts);
			break;
		}
		case'2': {
			Accounts[pos - 1].createPass();
			break;
		}
		case '3': {
			Accounts[pos - 1].active = true;
			cout << "\n\tУчётная запись подтверждена !" << endl;
			break;
		}
		case '4': {
			cout << "\n\tИзменения сохранены!\n";
			Accounts[pos - 1] = tmp;
			return;
		}
		}
	}
}


void Account::delAccount(vector <Account>& Accounts) {
	int pos = 0;
	int size = Accounts.size();
	cout << "\n\tВведите номер аккаунта для удаления(от 1 до " << size << "):" << endl;
	pos = CheckInt(size);
	if (Accounts[pos - 1].isAdmin()) {
		cout << "\n\tНельзя удалить акканут администратора!" << endl;
		return;
	}
	while (1) {
		system("cls");
		cout << "\n\t\tВы уверены, что хотите удалить аккаунт " << Accounts[pos - 1].getLog() << " ?\n\t1.Да\n\t2.Нет\n\t";
		switch (_getch()) {
		case '1': {
			cout << "\n\tАккаунт " << Accounts[pos - 1].getLog() << " успешно удалён!" << endl;
			Accounts.erase(Accounts.begin() + pos - 1);
			return;
		}
		case '2': {
			cout << "\n\tВозврат в меню администратора...\n\t";
			return;
		}
		}
	}
}