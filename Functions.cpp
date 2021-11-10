#include "Functions.h"

// test
void DataEntry(Data* (&d), int& n)
{
	cout << "Ââåäèòå êîëè÷åñòâî äàííûõ: ";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Ââåäèòå ÔÈÎ: ";
		cin >> d[i]._initial.surname;
		cin >> d[i]._initial.name;
		cin >> d[i]._initial.patronymic;

		cout << "Ââåäèòå äàòó (äåíü, ìåñÿö, ãîä): ";
		cin >> d[i]._date.day;
		cin >> d[i]._date.month;
		cin >> d[i]._date.year;

		cout << "______________________" << endl;

	}
}

void ReadingData(Data* (&d), int& n, string fileName)
{
	//ñîçäà¸ì ïîòîê äëÿ ÷òåíèÿ
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
		cout << "Äàííûå ñ÷èòàíû!" << endl;
	}
	else
		cout << "Îøèáêà îòêðûòèÿ ôàéëà!" << endl;
	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Äàííûå ¹" << i + 1 << endl;
		cout << "ÔÈÎ: " << d[i]._initial.surname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
		cout << "Äàòà: ";
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
	cout << "Ââåäèòå íîìåð ýëåìåíòà (îò 1 äî " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");

	// ïðîâåðêà, ÷òî ââåëè ïðàâèëüíîå çíà÷åíèå
	if (_n >= 0 && _n < n) {
		cout << "Ââåäèòå ÔÈÎ: ";
		cin >> d[_n]._initial.surname;
		cin >> d[_n]._initial.name;
		cin >> d[_n]._initial.patronymic;

		cout << "Ââåäèòå äàòó: ";
		cin >> d[_n]._date.day;
		cin >> d[_n]._date.month;
		cin >> d[_n]._date.year;

		system("cls");

		cout << "Äàííûå èçìåíåíû!" << endl;
	}
	else
		cout << "Íîìåð ââåä¸í íåâåðíî!" << endl;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	cout << "Ââåäèòå íîìåð ýëåìåíòà (îò 1 äî " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");

	if (_n >= 0 && _n < n) {
		// âðåìåííûé ìàññèâ
		Data* buf = new Data[n];

		Copy(buf, d, n);

		// âûäåëÿåì íîâóþ ïàìÿòü
		--n;
		d = new Data[n];
		int q = 0;

		// çàïîëíÿåì íåóäàëåííûå äàííûå
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;
		cout << "Äàííûå óäàëåíû!" << endl;
	}
	else
		cout << "Íîìåð ââåä¸í íåâåðíî!" << endl;
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
	//âðåìåííûé ìàññèâ äàííûõ
	Data* buf;
	buf = new Data[n];

	//ñîõðàíèå äàííûõ âî âðåìåííûé ìàññèâ
	Copy(buf, d, n);

	//âûäåëÿåì íîâóþ ïàìÿòü
	n++;
	d = new Data[n];

	//âîçâðàùàåì äàííûå
	Copy(d, buf, --n);

	cout << "Ââåäèòå ÔÈÎ: ";
	cin >> d[n]._initial.surname >> d[n]._initial.name >> d[n]._initial.patronymic;

	cout << "Ââåäèòå äàòó: ";
	cin >> d[n]._date.day >> d[n]._date.month >> d[n]._date.year;

	system("cls");
	cout << "Äàííûå äîáàâëåíû!" << endl;
	delete[]buf;
}

void DataSorting(Data* d, int n)
{
	//Âðåìåííàÿ ïåðåìåííàÿ
	Data buf;

	//ñîðòèðîâêà ìåòîäîì ïóçûðüêà
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i]._initial.surname > d[j]._initial.surname) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}

	cout << "Äàííûå îòñîðòèðîâàíû!" << endl;
}

void SavingData(Data* d, int n, string fileName)
{
	// ñîçäàåòñÿ ïîòîê äëÿ çàïèñè
	// îòêðûâàåò fileName è äåëàåò òàê, ÷òîáû îí áûë ïóñòîé
	ofstream record(fileName, ios::out);

	// óñëîâèå: åñëè ôàéë îòêðûëñÿ
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
		cout << "Îøèáêà îòêðûòèÿ ôàéëà!" << endl;

	record.close();
}
