#include "Header.h"
int main()
{
	setlocale(LC_ALL, "rus");

	Date date_1, date_2;
	int new_date;

	date_1 = date_2;

	date_1.add_day();

	date_1();

	date_1 > date_2 ? cout << "\n������ ���� ������\n" : cout << "\n������ ���� ������\n";

	cout << date_2;

	return 0;
}