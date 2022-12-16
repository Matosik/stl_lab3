#include <conio.h>
#include <vector>
#include "polynominal.h"


int menu1()
{
	cout << "\n\t'->' - C������� �������\n\t'<-' - ���������� �������"; // 77 75 ok===============
	cout << "\n\t[1] - �������� ���������";								// 49 ok=============================================
	cout << "\n\t[2] - �������� ��� ������ �";							// 50 ��===========================================
	cout << "\n\t[3] - ������� ��� ��������";							// 51 ��============================================
	cout << "\n\t[4] - �������� ���� �����������";						// 52 ��============================================
	cout << "\n\t[5] - �������� ���� �����������";						// 53 ��============================================
	cout << "\n\t[6] - �������� ��������� �� ������������ �����";		// 54 ��==========================
	cout << "\n\t[7] - ���������� � ������������ �� �������";			// 55 ��
	cout << "\n\t[8] - ������ ������ 1 � 2 ��������";					// 56
	cout << "\n\t[BackSpace] - ������� ������� �� �������";				// 8 ��===============================
	cout << "\n\n\tEsc - �����";										// 27============================================================
	while (true)
	{
		int key = _getch();
		if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56) || (key == 8) || (key == 77) || (key == 75))
		{
			return key;
		}
	}
}

int menu1_null()
{
	cout << "\n\t'->' - C������� �������\n\t'<-' - ���������� �������"; // 77 75 ok
	cout << "\n\t[1] - �������� ���������";								// 49 ok
	cout << "\n\t[2] - �������� ��� ������ �";							// 50 ��
	cout << "\n\t[3] - ������� ��� ��������";							// 51 ��
	cout << "\n\t[4] - �������� ���� �����������";						// 52 ��
	cout << "\n\t[5] - �������� ���� �����������";						// 53 ��
	cout << "\n\t[6] - �������� ��������� �� ������������ �����";		// 54 ��
	cout << "\n\t[7] - ���������� � ������������ �� �������";			// 55 ��
	cout << "\n\t[8] - ������ ������ 1 � 2 ��������";					// 56 ��
	cout << "\n\t[BackSpace] - ������� ������� �� �������";				// 8 ��
	cout << "\n\n\tEsc - �����";										// 27
	while (true)
	{
		int key = _getch();
		if ((key == 27) || (key == 49))
		{
			return key;
		}
	}
}

template <typename T>
T check()
{
	T number = 0;

	while (!(cin >> number) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			system("cls");
			cout << "\t������� ���������� �����: ";
		}
	}
	return number;
}

template <typename T>
void add_collection(vector<T>& coll, int& size)
{
	system("cls");
	size++;
	int step;
	cout << "\n\n\t\t ������� ������� ����������: ";
	step = check<int>();
	while ((step <= 0) || (step > 55))
	{
		system("cls");
		cout << "\n\n\t\t������� ��� ��� ������� ����������: ";
		step = check<int>();
	}
	system("cls");
	cout << "������� ����������:  " << step << "\n";
	Polynominal<T> tmp(step);
	T value;
	for (int i = 0; i <= step; i++)
	{
		cout << "\t���������� ����� �^" << i << " - ";
		value = check<T>();
		tmp.set_coef(i, value);
	}
	coll.push_back(tmp);
}

template <typename T>
void roots(Polynominal<T> coll)
{
	system("cls");
	T* root = new T[2];
	try
	{
		int root_counter = coll.equation_roots(root);
		cout << "\n\n\n\t\t" << coll;
		for (int i = 0; i < root_counter; i++)
		{
			cout << "\n\t\t\t x" << i + 1 << " = " << root[i];
		}
	}
	catch (string problem)
	{
		cout << problem;
	}
	cout << "\n\n\t\t\t������� ����� ������� ����� ���������� ";
	_getch();
}

template <typename T>
int MainMenu()
{
	int size = 0;
	int i = 0;
	int index;
	vector<Polynominal> coll;
	coll.reserve(5);
	T x;
	T value;
	T c;
menu1:
	system("cls");
	if (coll.size() == 0)
	{
		i = 0;
		cout << ("\t\t\t <����������� ����>  ^_^");
		int m1 = menu1_null();
		switch (m1)
		{
		case 27:
			return 0;
		case 49:
			add_collection(coll, size);
			goto menu1;
		}
	}
	else
	{
		cout << "index [" << i << "]"
			<< "\t\t\t\t";
		cout << coll[i] << " = 0";
		int m1 = menu1();
		switch (m1)
		{
		case 27:
			return 0;
		case 50: // valueX 
			system("cls");
			cout << "\n\n\n\t\t\t\t\t������� �������� �: ";
			x = check<T>();
			value = coll[i].valueX(x);
			cout << "\n\n\t\t\t";
			cout << coll[i];
			cout << "\t��� � = " << x << " == " << value;
			cout << "\n\n\t\t\t������� ����� ������� ����� ���������� ";
			_getch();
			goto menu1;
		case 51: // all delete
			coll.clear();
			goto menu1;
		case 52: // �������� ���� �����������
			system("cls");
			int index;
			cout << "\n\n\t\t ������� ������ ����������, ������� ����� ������� � �������: ";
			index = check<int>();
			while ((index > size - 1) || (index < 0))
			{
				cout << "\n\n\t\t ������� ��� ��� ������ ����������, ������� ����� ������� � �������, ��� ��� ������ ������� ���: ";
				index = check<int>();
			}
			cout << "\n\n\n\t\t" << coll[i] << "\n\t\t+++++++++++++++++++\n\t\t" << coll[index] << "\n\t\t===============================\n\t\t" << coll[i] + coll[index];
			cout << "\n\n\t\t\t������� ����� ������� ����� ���������� ";
			_getch();
			goto menu1;
		case 53: // �������� ���� �����������
			system("cls");
			cout << "\n\n\t\t ������� ������ ����������, ������� ����� ������� �� �������: ";
			index = check<int>();
			while ((index > size - 1) || (index < 0))
			{
				cout << "\n\n\t\t ������� ��� ��� ������ ����������, ������� ����� ������� � �������, ��� ��� ������ ������� ���: ";
				index = check<int>();
			}
			cout << "\n\n\n\t\t" << coll[i] << "\n\t\t+++++++++++++++++++\n\t\t" << coll[index] << "\n\t\t===============================\n\t\t" << coll[i] - coll[index];
			cout << "\n\n\t\t\t������� ����� ������� ����� ���������� ";
			_getch();
			goto menu1;
		case 8: // �������� �������� �� ��������� 
			auto iter = coll.begin();
			advance(iter, i);
			coll.erase(iter);
			goto menu1;
		case 77: // ��������� �� 
			if (i == (coll.size() - 1))
			{
				goto menu1;
			}
			else
			{
				i++;
				goto menu1;
			}
		case 54: // �������� ��������� �� ������������ �����
			system("cls");
			cout << "\n\n\n\t\t\t ������� ����� �� ������� ����� �������� ���������: ";
			c = check<T>();
			if (c == T(0)) {
				cout << "\n\n\t\t( " << coll[i] << ") * " << c << " = 0";
			}
			else {
				cout << "\n\n\t\t( " << coll[i] << ") * " << c << "\n\t\t======================================\n\t\t" << coll[i] * c;
			}
			cout << "\n\n\t\t\t������� ����� ������� ����� ���������� ";
			_getch();
			goto menu1;
		case 55: // ���������� � ������������ �� �������
			system("cls");
			int id;
			cout << "\n\n\n\t\t������� ������ ������������ � �������� ������ ���������� \n\t\t\t" << coll[i] << "\n\t\t\t index :";
			cin >> id;
			try
			{
				cout << "\t\t\t\t = " << coll[i][id];
				cout << "\n\n\t\t\t������� ����� ������� ����� ���������� ";
				_getch();
				goto menu1;
			}
			catch (string problem)
			{
				cout << "\n\n\t\t" << problem;
				cout << "\n\n\t\t\t������� ����� ������� ����� ���������� ";
				_getch();
				goto menu1;
			}

			case 56: // ������ ������ 1 � 2 ��������
				roots(coll[i]);
				goto menu1;
		case 75: // ��������� ��
			if (i == 0)
			{
				goto menu1;
			}
			else
			{
				i--;
				goto menu1;
			}
		case 49: // �������� ���������  OK====================================
			add_collection(coll, size);
			goto menu1;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	while (true)
	{
		system("cls");
		cout << "\n\t\t�������� ��� ������ ��� ����� �����������:";
		cout << "\n\t\t\t[1] - int";
		cout << "\n\t\t\t[2] - float";
		cout << "\n\t\t\t[3] - double";
		cout << "\n\t\t\t[4] - complex (float)";
		cout << "\n\t\t\t[5] - complex (double)";
		cout << "\n\t\t\t[ESC] - �����";

		int Choice = _getch();
		switch (Choice)
		{
		case 49:
			MainMenu<int>();
			break;
		case 50:
			MainMenu<float>();
			break;
		case 51:
			MainMenu<double>();
			break;
		case 52:
			MainMenu<complex<float>>();
			break;
		case 53:
			MainMenu<complex<double>>();
			break;
		case 27:
			return 0;
		}
	}
}