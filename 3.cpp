#include <iostream>
#include <windows.h>

void main()
{
setlocale(LC_CTYPE, "Russian");
SetConsoleOutputCP(1251);
SetConsoleCP(1251);
using namespace std;
unsigned char code, code1, ch;
int r, k = 0;
while (k != 4) {
puts("Выберете число: (1 - буква латинского алфавита, 2 - буква русского алфавита, 3 - цифра, 4 - выход)");
cin >> k;
switch (k)
{
case 1:
        {
            cout << "Введите букву латинского алфавита в строчном написании" << endl;
            cin >> code;
            if (code >= 0x61 && code <= 0x7A) {
                cout << "Введите букву латинского алфавита в прописном написании" << endl;
                cin >> code1;
                if (code1 >= 0x41 && code1 <= 0x5A) {
                    r = code - code1;
                    c       out << "Разница в шестнадцатеричной системе счисления равна " << hex << r << endl;
                }
                else {
                    cout << "Некорректный вариант" << endl;
                }
            }
            else {
                cout << "Некорректный вариант" << endl;
            }
break;
        }
case 2: {
            cout << "Введите букву русского алфавита в строчном написании" << endl;
            cin >> code;
            if (code >= 0xE0 && code <= 0xFF) {
                cout << "Введите букву русского алфавита в прописном написании" << endl;
                cin >> code1;
                if (code1 >= 0xC0 && code1 <= 0xDF) {
                    r = code - code1;
                    cout << "Разница в шестнадцатеричной системе счисления равна  " << hex << r << endl;
                }
                else {
                    cout << "Некорректный вариант" << endl;
                }
            }
            else {
                cout << "Некорректный вариант" << endl;
            }
break;
        }
case 3: {
            cout << "Введите число от 0 до 9 : " << endl;
            cin >> ch;
            if (ch >= 0x30 && ch <= 0x90) {
                cout << ch << " в Windows-1251 = " << hex << static_cast<int>(ch) << endl;
                break;
            }
            else {
                cout << "Некорректный вариант" << endl;
				}
break;
}
case 4:
    break;

default: puts("Некорректный вариант"); break;
        }
    }
}

