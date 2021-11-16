#include "Functions.h"

void DataEntry(Data* (&d), int& n)
{
	cout << "������� ���������� ������: ";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "������� ���: ";
		cin >> d[i]._initial.surname;
		cin >> d[i]._initial.name;
		cin >> d[i]._initial.patronymic;

		cout << "������� ���� (����, �����, ���): ";
		cin >> d[i]._date.day;
		cin >> d[i]._date.month;
		cin >> d[i]._date.year;

		cout << "______________________" << endl;

	}
}

void ReadingData(Data* (&d), int& n, string fileName)
{
	//������ ����� ��� ������
	ifstream reading(fileName);

	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i]._initial.surname;
			reading >> d[i]._initial.name;
			reading >> d[i]._initial.patronymic;

			reading >> d[i]._date.day;
			reading >> d[i]._date.month;
			reading >> d[i]._date.year;
		}
		cout << "������ �������!" << endl;
	}
	else
		cout << "������ �������� �����!" << endl;
	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "������ �" << i + 1 << endl;
		cout << "���: " << d[i]._initial.surname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
		cout << "����: ";
		if (d[i]._date.day <= 9)
			cout << "0" << d[i]._date.day << " ";
		else
			cout << d[i]._date.day << " ";
		if (d[i]._date.month <= 9)
			cout << "0" << d[i]._date.month << " ";
		else
			cout << d[i]._date.month << " ";
		cout << d[i]._date.year << endl;
		cout << "_____________________" << endl;
	}
}

void DataChange(Data* (&d), int n)

{
	int _n;
	cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");

	// ��������, ��� ����� ���������� ��������
	if (_n >= 0 && _n < n) {
		cout << "������� ���: ";
		cin >> d[_n]._initial.surname;
		cin >> d[_n]._initial.name;
		cin >> d[_n]._initial.patronymic;

		cout << "������� ����: ";
		cin >> d[_n]._date.day;
		cin >> d[_n]._date.month;
		cin >> d[_n]._date.year;

		system("cls");

		cout << "������ ��������!" << endl;
	}
	else
		cout << "����� ����� �������!" << endl;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");

	if (_n >= 0 && _n < n) {
		// ��������� ������
		Data* buf = new Data[n];

		Copy(buf, d, n);

		// �������� ����� ������
		--n;
		d = new Data[n];
		int q = 0;

		// ��������� ����������� ������
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;
		cout << "������ �������!" << endl;
	}
	else
		cout << "����� ����� �������!" << endl;
}

void Copy(Data* (&d_n), Data* (&d_o), int n)
{
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void Copy(Data& d_n, Data& d_o)
{
	d_n._initial.surname = d_o._initial.surname;
	d_n._initial.name = d_o._initial.name;
	d_n._initial.patronymic = d_o._initial.patronymic;

	d_n._date.day = d_o._date.day;
	d_n._date.month = d_o._date.month;
	d_n._date.year = d_o._date.year;
}

void AddDate(Data* (&d), int& n)
{
	//��������� ������ ������
	Data* buf;
	buf = new Data[n];

	//�������� ������ �� ��������� ������
	Copy(buf, d, n);

	//�������� ����� ������
	n++;
	d = new Data[n];

	//���������� ������
	Copy(d, buf, --n);

	cout << "������� ���: ";
	cin >> d[n]._initial.surname >> d[n]._initial.name >> d[n]._initial.patronymic;

	cout << "������� ����: ";
	cin >> d[n]._date.day >> d[n]._date.month >> d[n]._date.year;

	system("cls");
	cout << "������ ���������!" << endl;
	delete[]buf;
}

void DataSorting(Data* d, int n)
{
	//��������� ����������
	Data buf;

	//���������� ������� ��������
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i]._initial.surname > d[j]._initial.surname) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}

}

void DataSelectionSorting(Data* (&d), int n)
{
	int smallest_id;

	//���������� �������
	for (int i = 0; i < n; i++) {
		smallest_id = i;
		for (int j = i + 1; j < n; j++) {
			if (d[j]._initial.surname < d[smallest_id]._initial.surname)
				smallest_id = j;
		}
		swap(d[smallest_id], d[i]);
	}

}

void DataSortingYbivanie(Data* d, int n) {
	//��������� ����������
	Data buf;

	//���������� ������� ��������
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i]._initial.surname < d[j]._initial.surname) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}

}

void DataSelectionSortingYbivanie(Data* (&d), int n) {
	int higher_id;

	//���������� �������
	for (int i = 0; i < n; i++) {
		higher_id = i;
		for (int j = i + 1; j < n; j++) {
			if (d[j]._initial.surname > d[higher_id]._initial.surname)
				higher_id = j;
		}
		swap(d[higher_id], d[i]);
	}

}

void DataBinarySearch(Data* d, string value, int n) {
	int mid;
	int left = 0;
	int right = n;
	
	// ��������� ��������� �� ��������� �������
	Data* buf;
	buf = new Data[n];
	Copy(buf, d, n);
	
	// ���������� ��������� ��� ��������� ������
	DataSelectionSorting(d, n);

	// �������� �����
	while (right >= left) {
		mid = (left + right) / 2;
		if (d[mid]._initial.surname == value) {

			cout << d[mid]._initial.surname << " " << d[mid]._initial.name << " " << d[mid]._initial.patronymic << endl;
			if (d[mid]._date.day < 10)
				cout << "0" << d[mid]._date.day << " ";

			else
				cout << d[mid]._date.day << " ";

			if (d[mid]._date.month < 10)
				cout << "0" << d[mid]._date.month << " " << d[mid]._date.year << endl;

			else
				cout << d[mid]._date.month << " " << d[mid]._date.year << endl;
			Copy(d, buf, n);
			return;

		}
		if (d[mid]._initial.surname < value)
			left = mid + 1;

		if (d[mid]._initial.surname > value)
			right = mid - 1;
	}
	cout << "������ �� �������!" << endl;
	Copy(d, buf, n);
}

void SavingData(Data* d, int n, string fileName)
{
	// ��������� ����� ��� ������
	// ��������� fileName � ������ ���, ����� �� ��� ������
	ofstream record(fileName, ios::out);

	// �������: ���� ���� ��������
	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i]._initial.surname << endl;
			record << d[i]._initial.name << endl;
			record << d[i]._initial.patronymic << endl;

			record << d[i]._date.day << " ";
			record << d[i]._date.month << " ";
			if (i < n - 1)
				record << d[i]._date.year << endl;
			else
				record << d[i]._date.year;
		}
	}
	else
		cout << "������ �������� �����!" << endl;

	record.close();
}