#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include <string>
#include "Header.h"

using namespace std;
unsigned short int nz;

int i, j;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, ".1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		cout << "������� ����� ������� (0 - ��� �� �����) : ";
		cin >> nz;
		cin.get();

		if (nz == 0)
		{
			break;
			system("exit");
		}

		else if (nz == 1)
		{
			system("cls");
			/*1.���� ������ �� ���������� ����. ����� ���������� ���� �� ����� ��������� ��� ��������. ������� �����, ������������ � ��������������� ����� � ��� �� ������.*/
			char str[256];
			cout << "������� ������: ";
			gets_s(str);
			char seps[] = ", ";
			char *token;
			int str_count = 0;
			char* currentStr = 0;
			int count_equal = 0;
			token = strtok(str, seps);
			while (token != NULL)
			{
				cout << token << endl;
				if (token[0] == token[strlen(token) - 1])
				{
					cout << count_equal + 1 << " ��������� ����� - " << token << endl;
					count_equal++;
				}
				token = strtok(NULL, seps);
			}

			cout << "������� " << count_equal << " ����(�)" << endl;
		}

		else if (nz == 2)
		{
			/*2.	��� ������ ��������, � ������� ����������� ��������� <i> � </i>. �������� ������ ��������� <i> �� </i>, � ������ ��������� </i> �� <#>.
			���������: � ��������� ������� ������, ��� ����� i ����� ����, ��� ��������, ��� � ���������*/
			system("cls");
			char * a = "<i>", *b = "<#>";
			char * m = createDunamicChar(150);

			strcpy(m, "<i><body><hr><ul><i> ������ ��������</i><i>����������� ���������</i><i>������ ���������</i><i>��� ��������</i></ul><hr></body>");
			printf("\n Before replace : %s \n", m);
			replacestr(m, a, b);
			printf("\n After replace : %s \n", m);
		}

		else if (nz == 4)
		{
			system("cls");
			/*4.��� ������ ��������, ���������� �����. ���������� ����� ������������ � ��� ������������ ����� ��������, �������� �� ����.*/
			static char str[256] = "abc38494defghi4959384759387i0874598398579438759438435\0";
			printf("string = %s\n", str);

			char output[256] = "\0";
			int max_len = 0, pos = max_len;
			for (int i = 0; str[i] != '\0'; i++)
				if (isdigit(str[i]))
				{
					int l = i, n = 0; char digits[256] = "\0";
					while (isdigit(str[i]) && str[i] != '\0')
						digits[n++] = str[i++];

					if (abs(l - i) > max_len || max_len == 0)
					{
						strcpy(output, digits);
						max_len = abs(l - i);
						pos = l;
					}
				}

			printf("output = %s pos = %d len = %d\n", output, pos, max_len);

		}

		else if (nz == 6)
		{
			/*6.��� ������ ��������. ������� �� �����, ������� �������� ���� �� ���� ����� k*/
			system("cls");
			char *str = "��� ������ �k������� . �������k �� ��k���";
			char * word = (char*)calloc(50, sizeof(char));
			int n = 0, kon = 0, ws = 0;

			while (kon < strlen(str))
			{
				while (str[kon] != ' '&&str[kon] != ',')
				{
					if (kon != strlen(str))
						kon++;
					else break;
				}

				for (int i = n;i < kon;i++)
				{
					word[ws] = str[i];
					ws++;
				}

				word[ws] = '\0';
				for (int i = 0;i < strlen(word);i++)
				{
					if (word[i] == 'k')
					{
						printf("%s \n", word);
						break;
					}
				}
				n = kon + 1;
				if (str[kon] != ' ' || str[kon] != ',') kon++;
				ws = 0;
			}
		}

		else
		{
			printf("������ ������� ���!");
			exit(EXIT_FAILURE);
		}
	}
}
