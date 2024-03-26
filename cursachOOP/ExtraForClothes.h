#pragma once
#include "Clothes.h"
#include "Pants.h"
#include "Sweaters.h"

void findcls(vector<Clothes*>& clothes); //������� ���  ������ ������ � �������
void delCls(vector<Clothes*>& clothes); //�������� ������ 
void addInVectorCls(vector<Clothes*>& clothes); //���������� � ������ ������
void editClothes(vector<Clothes*>& clothes); //�������������� ������ ������
void readClothesInFile(vector<Clothes*>& clothes); //������� ������ �� ������� 
void writeClothestoFile(vector<Clothes*>& clothes); //�������� ����� � ������
void sortAmount(vector<Clothes*>& vec); //���������� ������ �� ���������� �� ��������
void sortSize(vector<Clothes*>& vec); //���������� ������ �� ������� �� ��������
void ReadVector(vector<Clothes*> clothes); //���������� ������ � �������

void ReadVector(vector<Clothes*> clothes)
{
	if (clothes.empty()) {
		cout << "\n������ ����!\n";
	}
	cout << "\n\t" << setfill('-') << setw(108) << right << ' ';
	cout << "\n\t|                                             ������ ������                                               |";
	cout << "\n\t|---------------------------------------------------------------------------------------------------------|";
	cout << "\n\t| N |   ����    | ��� - ��  |  ������   |     ��� ������      |     ���������       |     ���� ������     |";
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
	cout << "\n\t����� ������ ������� ��������?\n\n\t�������� �� �����) :";
	ReadVector(clothes);
	int pos, n = 0;
	pos = CheckInt(clothes.size());
	cout << "\n\t������� ���������� ������, ������� ������ �������� : ";
	n = CheckInt(50);
	clothes[pos - 1]->setAmount(clothes[pos - 1]->getAmount() - n);
	cout << "\n\t��� �������, ��� ����� � ���������, �������� . . . ";
	return;
}

void editClothes(vector<Clothes*>& clothes) {
	ReadVector(clothes);
	int pos;
	cout << "\n\t������� ����� ������, ������� ������� �������� :\n ";
	pos = CheckInt(clothes.size());
	while (1) {
		system("cls");
		cout << "\n\t--------------------- ��� ��������??? ------------------------\n\t1.������\n\t2.���\n\t3.����\n\t0.��������� � �����\n\t";
		switch (_getch()) {
		case '1': {
			clothes[pos - 1]->setSize();
			cout << "\n\t������ ������� !" << endl;
			break;
		}
		/*case'2': {
			clothes[pos - 1]->setAmount();
			cout << "\n\t���������� �������� !" << endl;
			break;
		}*/
		case '2': {
			clothes[pos - 1]->setType();
			cout << "\n\t��� ������� !" << endl;
			break;
		}
		case '3': {
			clothes[pos - 1]->setPrice();
			cout << "\n\t���� �������� !" << endl;
			break;
		}
		case '0': {
			cout << "\n\t��������� ���������!\n";
			return;
		}
		}
	}
	ReadVector(clothes);
}

void addInVectorCls(vector<Clothes*>& clothes) {
	int count = 0, i = 0, m = 0;
	cout << "\n\t������� ������� ������� ��������?\n";
	count = CheckInt(5);
	while (i < count)
	{
		cout << "\n\t����� ��������� " << i + 1 << " ������ �� ������ ��������?\n\t1 - �����\n\t2 - �����\n";
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
	cout << "\n\t�� ������ ������� :\n\t1 - ��� ������, 2 - ���� ���\n";
	m = CheckInt(2);
	if (m == 1)
	{
		clothes.clear();
		cout << "\n\t�������� ������ �������!\n";
	}
	if (m == 2)
	{
		ReadVector(clothes);
		int f;
		cout << "\n\t������� ����� ������ ��� �������� :\n ";
		f = CheckInt(clothes.size());
		clothes.erase(clothes.begin() + f - 1);
		cout << "\n\t�������� ������ �������!\n";
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

	cout << "\n\t������� ��� ������, ���������� ������� ������ ������ : ";
	cin >> name;
	mapPtr = tofind.find(name);
	if (mapPtr != tofind.end()) {
		cout << "\n\t���-�� : " << mapPtr->second << endl;
		return;
	}
	else
	{
		cout << "\n\t� ��������� ������ ������ ���� ��� (\n";
		return;
	}
}