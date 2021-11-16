#include "Functions.h"

int _stateMenu;

void Menu() {
	cout << "Выберите действие:" << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод" << endl
		<< "(3) Изменение" << endl
		<< "(4) Выборочное удаление" << endl
		<< "(5) Удаление всех файлов" << endl
		<< "(6) Добавление" << endl
		<< "(7) Сортировка по фамилии" << endl
		<< "(8) Поиск по фамилии" << endl
		<< "(9) Сохранение в файле" << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

int main() {
	// руссификация консоли ввода и вывода 
	SetConsoleCP(1251); // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // утсановка кодов страницы win-cp 1251 в поток вывода

	Menu();

	// инициализация данных
	int _actions,
		amountOfData = 0;
	string fileName, surname;

	// массив данных
	Data* d = new Data[amountOfData];
	while (_stateMenu != 0) {

		switch (_stateMenu)
		{
		case 1:
			system("cls"); // очистка консоли
			cout << "Ввод вручную, из Input.txt или из другого файла(1 - вручную, 2 - из Input.txt, 3 - другой файл): ";
			cin >> _actions;
			system("cls");

			if (_actions == 1) {
				//ввод вручную
				DataEntry(d, amountOfData);
			}

			if (_actions == 2){
				//ввод из файла
				ReadingData(d, amountOfData, "Input.txt");
			}

			if (_actions == 3) {
				//ввод из собственного файла
				cout << "Введите название файла: ";
				cin >> fileName;
				ReadingData(d, amountOfData, fileName);
			}

			if (_actions != 1 && _actions != 2 && _actions != 3) {
				cout << "Неверно введен номер действия!" << endl;
			}

			system("pause"); // задержка консоли
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 2:
			system("cls");

			if (amountOfData != 0) {
				Print(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 3:
			system("cls");

			if (amountOfData != 0) {
				DataChange(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 4:
			system("cls");

			if (amountOfData != 0) {
				DeleteData(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 5:
			system("cls");

			amountOfData = 0;
			d = new Data[amountOfData];

			cout << "Данные удалены!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 6:
			system("cls");

			if (amountOfData != 0) {
				AddDate(d, amountOfData);
				amountOfData++;
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 7:
			system("cls");
			int metod_menu;

			cout << "Выберите метод сортировки: " << endl;
			cout << "(1) Пузырьком (по возрастанию)" << endl;
			cout << "(2) Пузырьком (по убыванию)" << endl;
			cout << "(3) Выбором (по возрастанию)" << endl;
			cout << "(4) Выбором (по убыванию)" << endl;

			cin >> metod_menu;

			switch (metod_menu)
			{
			case 1:
				system("cls");

				if (amountOfData != 0) {
					DataSorting(d, amountOfData);
					cout << "Данные отсортированы!" << endl;
				}
				else
					cout << "Данные пусты!" << endl;
				break;

			case 2:
				system("cls");

				if (amountOfData != 0) {
					DataSortingYbivanie(d, amountOfData);
					cout << "Данные отсортированы!" << endl;
				}
				else
					cout << "Данные пусты!" << endl;
				break;

			case 3:
				system("cls");

				if (amountOfData != 0) {
					DataSelectionSorting(d, amountOfData);
					cout << "Данные отсортированы!" << endl;
				}
				else
					cout << "Данные пусты!" << endl;
				break;

			case 4:
				system("cls");

				if (amountOfData != 0) {
					DataSelectionSortingYbivanie(d, amountOfData);
					cout << "Данные отсортированы!" << endl;
				}
				else
					cout << "Данные пусты!" << endl;
				break;

			default:
				system("cls");
				cout << "Неверно введен номер действия!" << endl;
			}
			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 8:
			system("cls");

			if (amountOfData != 0) {
				cout << "Введите фамилию:" << endl;
				cin >> surname;
				DataBinarySearch(d, surname, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		case 9:
			system("cls");
			
			cout << "Вывод в Input.txt или в другой файл (1 - в Input.txt, 2 - в другой файл):" << endl;
			cin >> _actions;

			if (_actions == 1) {
				fileName = "Input.txt";
			}

			if (_actions == 2) {
				cout << "Введите название файла: ";
				cin >> fileName;
			}

			if (_actions != 1 && _actions != 2) {
				cout << "Неверно введен номер действия!" << endl;

				system("pause");
				system("cls");
				Menu();
				break;
			}

			if (amountOfData != 0) {
				SavingData(d, amountOfData, fileName);
				cout << "Данные сохранены!" << endl;
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
			////////////////////////////////////
		default:
			cout << "Неверно введен номер действия!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
}