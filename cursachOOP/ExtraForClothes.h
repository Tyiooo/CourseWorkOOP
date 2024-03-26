#pragma once
#include "Clothes.h"
#include "Pants.h"
#include "Sweaters.h"

void findcls(vector<Clothes*>& clothes); //функция для  поиска одежды в векторе
void delCls(vector<Clothes*>& clothes); //удаление одежды 
void addInVectorCls(vector<Clothes*>& clothes); //добавление в вектор одежды
void editClothes(vector<Clothes*>& clothes); //редактирование ветора одежды
void readClothesInFile(vector<Clothes*>& clothes); //считать одежду из вектора 
void writeClothestoFile(vector<Clothes*>& clothes); //записать одеду в вектор
void sortAmount(vector<Clothes*>& vec); //сортировка одежды по количеству по убыванию
void sortSize(vector<Clothes*>& vec); //сортировка одежды по размеру по убыванию
void ReadVector(vector<Clothes*> clothes); //считывание ветора в консоль

void ReadVector(vector<Clothes*> clothes)
{
	if (clothes.empty()) {
		cout << "\nВектор пуст!\n";
	}
	cout << "\n\t" << setfill('-') << setw(108) << right << ' ';
	cout << "\n\t|                                             Список одежды                                               |";
	cout << "\n\t|---------------------------------------------------------------------------------------------------------|";
	cout << "\n\t| N |   Цена    | Кол - во  |  Размер   |     Тип одежды      |     Фурнитура       |     Цвет одежды     |";
	for (int i = 0; i < clothes.size(); i++)
	{
		cout << "\n\t|---|-----------|-----------|-----------|---------------------|---------------------|---------------------|";
		clothes[i]->show_info(i + 1);
	}
	cout << "\n\t" << setfill('-') << setw(108) << right << ' ' << "\n\n";
}

template <typename T>
int getType(T& obj) {
	if (typeid(obj) == typeid(Sweaters))
		return 1;
	else return 2;
}

void sortSize(vector<Clothes*>& vec) {
	for (int i = 1; i < vec.size(); i++) {
		for (int j = i; j > 0 && strcmp(vec[j - 1]->getSize(), vec[j]->getSize()) > 0; j--) {
			Clothes* tmp = vec[j - 1];
			vec[j - 1] = vec[j];
			vec[j] = tmp;
		}
	}
}

void sortAmount(vector<Clothes*>& vec)
{
	for (int i = 1, j = i; i < vec.size(); j = ++i)
	{
		while (j > 0 && vec[j]->getAmount() < vec[j - 1]->getAmount())
		{
			Clothes* tmp = vec[j - 1];
			vec[j - 1] = vec[j];
			vec[j] = tmp;
			--j;
		}
	}
};

istream& operator>>(istream& s, vector<Clothes*>& vec)
{
	int size = 0;
	int i = 0;
	int ctype;
	vec.clear();
	while (1)
	{
		s.read((char*)&ctype, sizeof(ctype));
		if (s.eof()) break;
		switch (ctype)
		{
		case 1:
			size = sizeof(Sweaters);
			vec.push_back(new Sweaters);
			break;
		case 2:
			size = sizeof(Pants);
			vec.push_back(new Pants);
			break;
		}
		s.read((char*)&(*vec[i]), size);
		i++;
	}
	return s;
}

ostream& operator<<(ostream& s, vector<Clothes*>& vec)
{
	int size = 0;
	int ctype;
	for (int i = 0; i < vec.size(); i++) {
		ctype = getType(*vec[i]);
		s.write((char*)&ctype, sizeof(ctype));
		switch (ctype) {
		case 1:
			size = sizeof(Sweaters); break;
		case 2:
			size = sizeof(Pants); break;
		}
		s.write((char*)&(*vec[i]), size);
	}
	return s;
}

void writeClothestoFile(vector<Clothes*>& clothes) {
	ofstream ofs;
	ofs.open("Clothes.txt", ios::binary);
	ofs << clothes;
	ofs.close();
}

void readClothesInFile(vector<Clothes*>& clothes) {
	ifstream ifs;
	ifs.open("Clothes.txt", ios::binary);
	ifs >> clothes;
	ifs.close();

}

void makeAnOrder(vector<Clothes*> clothes) 
{
	cout << "\n\tКакую одежду желаете заказать?\n\n\tВыберите из спика) :";
	ReadVector(clothes);
	int pos, n = 0;
	pos = CheckInt(clothes.size());
	cout << "\n\tВведите количество одежды, которое хотите оформить : ";
	n = CheckInt(50);
	clothes[pos - 1]->setAmount(clothes[pos - 1]->getAmount() - n);
	cout << "\n\tВсе отлично, ваш заказ в обработке, ожидайте . . . ";
	return;
}

void editClothes(vector<Clothes*>& clothes) {
	ReadVector(clothes);
	int pos;
	cout << "\n\tВведите пункт одежды, который желаете изменить :\n ";
	pos = CheckInt(clothes.size());
	while (1) {
		system("cls");
		cout << "\n\t--------------------- Что изменить??? ------------------------\n\t1.Размер\n\t2.Тип\n\t3.Цену\n\t0.Сохранить и выйти\n\t";
		switch (_getch()) {
		case '1': {
			clothes[pos - 1]->setSize();
			cout << "\n\tРазмер изменен !" << endl;
			break;
		}
		/*case'2': {
			clothes[pos - 1]->setAmount();
			cout << "\n\tКоличество изменено !" << endl;
			break;
		}*/
		case '2': {
			clothes[pos - 1]->setType();
			cout << "\n\tТип изменен !" << endl;
			break;
		}
		case '3': {
			clothes[pos - 1]->setPrice();
			cout << "\n\tЦена изменена !" << endl;
			break;
		}
		case '0': {
			cout << "\n\tИзменения сохранены!\n";
			return;
		}
		}
	}
	ReadVector(clothes);
}

void addInVectorCls(vector<Clothes*>& clothes) {
	int count = 0, i = 0, m = 0;
	cout << "\n\tСколько пунктов желаете добавить?\n";
	count = CheckInt(5);
	while (i < count)
	{
		cout << "\n\tКакую конкретно " << i + 1 << " одежду вы хотите добавить?\n\t1 - Кофту\n\t2 - Штаны\n";
		m = CheckInt(2);
		if (m == 1)
		{
			//shared_ptr<Sweaters[]> cc(new Sweaters[5]);
			Sweaters* cc = new Sweaters;
			cc->input_info();
			clothes.push_back(cc);
		}
		if (m == 2)
		{
			Pants* wc = new Pants;
			wc->input_info();
			clothes.push_back(wc);
		}
		i++;
	}
	i = 0;
	cout << endl;
	return;
}

void delCls(vector<Clothes*>& clothes) {
	int m = 0;
	cout << "\n\tВы хотите удалить :\n\t1 - Всю одежду, 2 - Один тип\n";
	m = CheckInt(2);
	if (m == 1)
	{
		clothes.clear();
		cout << "\n\tУдаление прошло успешно!\n";
	}
	if (m == 2)
	{
		ReadVector(clothes);
		int f;
		cout << "\n\tВведите пункт одежды для удаления :\n ";
		f = CheckInt(clothes.size());
		clothes.erase(clothes.begin() + f - 1);
		cout << "\n\tУдаление прошло успешно!\n";
		ReadVector(clothes);
	}
	return;
}

void findcls(vector<Clothes*>& clothes) {
	map <string, int> tofind;
	string name;
	for (int i = 0; i < clothes.size(); i++)
	{
		tofind.insert(pair<string, int>(clothes[i]->getType(), clothes[i]->getAmount()));
	}
	map<string, int>::iterator mapPtr;
	ReadVector(clothes);

	cout << "\n\tВведите тип одежды, количество которой хотите узнать : ";
	cin >> name;
	mapPtr = tofind.find(name);
	if (mapPtr != tofind.end()) {
		cout << "\n\tКол-во : " << mapPtr->second << endl;
		return;
	}
	else
	{
		cout << "\n\tК сожалению одежды такого типа нет (\n";
		return;
	}
}