#include <conio.h>
#include "ConteinerArray.h"

bool chois()
{
	char str{};
	bool chois;
	while (true)
	{
		str = _getch();
		if (str == 32)
		{
			chois = true;
			break;
		}
		else if (str == 27)
		{
			chois = false;
			break;
		}
		else cout << " � � ������, ���������: ";
	}

	return chois;

}
int checkDigit(char a, char b)
{
	int digit(0);
	char str[1]{ '\0' };

	while (true)
	{
		str[0] = _getch();
		if (str[0] >= a && str[0] <= b)
		{
			cout << str[0] << "\n";
			digit = atoi(str);
			break;
		}
		else
		{
			continue;
		}
	}

	cout << "\n";
	return digit;
}


int main()
{
	setlocale(LC_ALL, "");
	int length{ 0 };
	int number{ 0 };
	int oper{ 0 };
	bool lenDel{ true };
	bool work{ true };
	char global{ true };

	
	while (global)
	{
		Conteiners mass(length);
		mass.completion();
		mass.showCont();
		cout << "\n ������ ����������:";
		cout << mass.getLength();
		cout << "\n";

		work = true;
		while (work)
		{
			cout << "\n �������� ��������:\n 1 - �������� ������, \n 2 - �������� ������� \n 3 - ������� ������� \n 4 - �������� ������� \n 5 - ����� ������� \n 6 - ��������� ������ \n >> ";
			oper = checkDigit('1', '6');

			if (oper == 6) break;

			switch (oper)
			{
			case 1:
				cout << " ������ ������� ������� ���������?";
				length = mass.interLength();
				mass.resize(length);
				mass.showCont();
				cout << "\n ������ ����������: ";
				cout << mass.getLength() << "\n";
				break;
			case 2:
				cout << " ������� ��������: ";
				cin >> number;
				mass.incertElement(number);
				mass.showCont();
				cout << "\n ������ ����������: ";
				cout << mass.getLength() << "\n";
				break;
			case 3:
				mass.deleteElement(&lenDel);
				if (lenDel == false)
				{
					cout << " ��������� �����! \n";
					oper = 0;
					work = false;
					break;
				}
				mass.showCont();
				cout << "\n ������ ����������: ";
				cout << mass.getLength() << "\n";
				break;
			case 4:
				cout << " ������� ��������: ";
				cin >> number;
				mass.removeElement(number);
				mass.showCont();
				cout << "\n ������ ����������: ";
				cout << mass.getLength() << "\n";
				break;
			case 5:
				mass.search();
				mass.showCont();
				cout << "\n ������ ����������: ";
				cout << mass.getLength() << "\n";
				break;

			default:
				break;
			}


		}
		cout << "\n ������� ����� ���������?  �� -  \"������\", ��������� - \"Esc\": \n";
		global = chois();
		if (global == false) break;
		lenDel = true;
	}
		cout << "\n\n\n\n\n\n\n\n                   ��������� ���! \n\n\n\n\n\n\n\n";
}
