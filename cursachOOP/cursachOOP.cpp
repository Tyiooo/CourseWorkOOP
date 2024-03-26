#include "Account.h"
#include "ExtraForClothes.h"

int LogIn(vector<Account>& Accounts, Account& user);

void mainMenu(vector<Account>& Accounts, vector<Clothes*>& clothes);

void userMenu(vector<Clothes*>& clothes);

void menuAdmin(vector<Account>& Accounts, vector<Clothes*>& clothes);

void menuClothes(vector<Clothes*>& clothes);

void menuAccounts(vector<Account>& Accounts);

int LogIn(vector<Account>& Accounts, Account& user);


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	shared_ptr<Account[]> ptr(new Account[5]);
	shared_ptr<Account[]> temp(new Account[5]);
	vector <Account>Accounts;
	vector<Clothes*> clothes;
	Account tmp;

	tmp.readAccsInFile(Accounts);
	readClothesInFile(clothes);

	mainMenu(Accounts, clothes);

	tmp.writeAccsToFile(Accounts);
	writeClothestoFile(clothes);
	return 0;
}

int LogIn(vector<Account>& Accounts, Account& user) {
	char tmp[30];
	Account acc;
	cout << "\n\tВведите логин :  ";
	cinStr(tmp, 30);
	int pos = acc.findAccount(Accounts, tmp);
	if (pos != -1) {
		user = Accounts[pos];
		if (!Accounts[pos].isActive()) {
			cout << "\n\tВаша учётная запись еще не подтверждена (" << endl;
			return 0;
		}
		cout << "\n\tВведите пароль : ";
		cinPassword(tmp, 30);

		cout << "\n";
		if (!strcmp(tmp, Accounts[pos].getPass())) {
			if (Accounts[pos].isAdmin()) {
				return 1;
			}
			else {
				return 2;
			}
		}
		else {
			cout << "\n\tНекорректно введён пароль ! " << endl;
		}
	}
	else {
		cout << "\n\tАккаунт " << tmp << " не найден..." << endl;
		return 0;
	}
}

void menuAccounts(vector<Account>& Accounts) {
	Account tmp;
	while(1) {
		cout << "\n\t---------------------Меню аккаунтов----------------------\n\t1.Просмотр\n\t2.Редактирование\n\t3.Удаление\n\t0.Выход\n\t";
		switch (_getch()) {
		case '1': {
			system("cls");
			tmp.readAccsInVector(Accounts);
			system("pause");
			break;
		}
		case '2': {
			system("cls");
			tmp.readAccsInVector(Accounts);
			tmp.editAccounts(Accounts);
			system("pause");
			break;
		}
		case '3': {
			system("cls");
			tmp.delAccount(Accounts);
			tmp.readAccsInVector(Accounts);
			system("pause");
			break;
		}
		case '0': {
			system("cls");
			return;
		}
		}
	}
}

void menuClothes(vector<Clothes*>& clothes) {
	int m = 0;
	while (1) {
		cout << "\n\t---------------------Меню одежды----------------------\n\t1.Добавить одежду в список\n\t2.Посмотреть список одежды\n\t3.Удалить одежду из списка\n\t4.Изменить спиок одежды\n\t5.Поиск одежды из списка\n\t6.Отсортировать одежду\n\t0.Выход\n\t";
		switch (_getch()) {
		case '1': { system("cls");
			addInVectorCls(clothes);
			break;
		}
		case '2': { system("cls");
			ReadVector(clothes);
			break;
		}
		case '3': { system("cls");
			delCls(clothes);
			break;
		}
		case '4': { system("cls");
			editClothes(clothes);
			break;
		}
		case '5': { system("cls");
			findcls(clothes);
			break;
		}
		case '6': { system("cls");
			ReadVector(clothes);
			cout << "\n\tВыберите сортировку :\n\t1 - По размеру\n\t2 - По количеству\n";
			int m = 0;
			try
			{
				cin >> m;
				if (!cin || m < 1 || m > 2)
					throw exception("\n\tВы должны ввести число 1 или 2 !!!!\n");
			}
			catch (exception& x)
			{
				cout << endl << x.what() << endl;
				continue;
			}
			if (m == 1)
			{
				sortSize(clothes);
			}
			if (m == 2)
			{
				sortAmount(clothes);
			}
			cout << "\n\t---------------------Соортииировкааа---------------------\n" << endl;
			ReadVector(clothes);
			break;
		}
		case '0': { system("cls");
			return;
		}
		}
	}
}

void menuAdmin(vector<Account>& Accounts, vector<Clothes*>& clothes) {
	while (1) {
		cout << "\n\t---------------------Меню Администратора----------------------\n\t1.Работа с учётными записями\n\t2.Работа с одеждой\n\t0.Выход\n\t";
		switch (_getch()) {
		case'1': {
			system("cls");
			menuAccounts(Accounts);
			break;
		}
		case '2': {
			system("cls");
			menuClothes(clothes);
			break;
		case '0': {
			system("cls");
			return;
		}
		}
		}
	}
}

void userMenu(vector<Clothes*>& clothes) {
	int m = 0;
	while (1) {
		cout << "\n\t---------------------Меню клиента----------------------\n\t1.Просмотреть список одежды\n\t2.Найти количество одежды определенного типа\n\t3.Сортировка одежды\n\t4.Сделать заказ одежды\n\t0.Выход\n\t";
		switch (_getch()) {
		case '1': { system("cls");
			ReadVector(clothes);
			break;
		}
		case '2': { system("cls");
			findcls(clothes);
			break;
		}
		case '3': { system("cls");
			ReadVector(clothes);
			cout << "\n\tВыберите сортировку :\n\t1 - По размеру\n\t2 - По количеству\n";
			int m = 0;
			try
			{
				cin >> m;
				if (!cin || m < 1 || m > 2)
					throw exception("\n\tВы должны ввести число 1 или 2 !!!!\n");
			}
			catch (exception& x)
			{
				cout << endl << x.what() << endl;
				continue;
			}
			if (m == 1)
			{
				sortSize(clothes);
			}
			if (m == 2)
			{
				sortAmount(clothes);
			}				
			cout << "\n\t---------------------Соортииировкааа---------------------\n" << endl;
			ReadVector(clothes);
			break;
		}
		case '4': { system("cls");
			makeAnOrder(clothes);
			break;
		}
		case '0': { system("cls");
			return;
		}
		}
	}

}

void mainMenu(vector<Account>& Accounts, vector<Clothes*>& clothes) {
	while (1) {
		system("cls");
		cout << "\n\t---------------------Главное меню----------------------\n\t1.Авторизация\n\t2.Регистрация\n\t0.Выход\n\t";
		switch (_getch()) {
		case '1': {
			Account user;
			switch (LogIn(Accounts, user)) {
			case 0:
				cout << "\n\tВозврат на главное меню...\n";
				system("pause");
				break;
			case 1:	system("cls");
				menuAdmin(Accounts, clothes);
				break;
			case 2:	system("cls");
				userMenu(clothes);
				system("pause");
				break;
			}
			break;
		}
		case '2': {
			Account tmp;
			tmp.regAccount(Accounts);
			Accounts.push_back(tmp);
			cout << "\n\tВаша учётная запись создана, ожидайте подтверждения администратора !\n\t";
			system("pause");
			break;
		}
		case '0': {
			cout << "\n\t Всего хорошего !\n\n";
			system("pause");
			return;
		}
		}
	}
}