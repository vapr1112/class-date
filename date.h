#pragma once

#include <iostream>
#define SIZE_YEAR 12
#define SIZE_MONTH 30

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
	char* week_day;

public:
	Date() : Date(30, 12, 2000, "Monday") {}

	explicit Date(int day_p) : Date(day_p, 1, 2000, nullptr) {}

	Date(const int day_p, const int month_p, const int year_p, const char* week_day_p);//������� �����������

	Date(const Date& date);//����������� �����������

	//��������� � ������������
	void set_day(int day_p)
	{
		if (day_p > SIZE_MONTH || day_p <= 0)
		{
			cout << "\n������� ������������ ��������!\n";
			return;
		}

		day = day_p;
	}

	void set_month(int month_p)
	{
		if (month_p > SIZE_YEAR || month_p <= 0)
		{
			cout << "\n������� ������������ ��������!\n";
			return;
		}
		month = month_p;
	}

	void set_year(int year_p)
	{
		if (year_p < 0)
		{
			cout << "\n������� ������������ ��������!\n";
			return;
		}
		year = year_p;
	}

	void set_week_day(char* week_day_p)
	{
		if (week_day)
		{
			delete[] week_day;
		}

		week_day = new char[strlen(week_day_p) + 1];

		strcpy_s(week_day, strlen(week_day_p) + 1, week_day_p);
	}

	int get_day() const
	{
		return day;
	}

	int get_month() const
	{
		return month;
	}

	int get_year() const
	{
		return year;
	}

	const char* get_week_day() const
	{
		return week_day;
	}

	void add_day()
	{
		day++;
		if (day > SIZE_MONTH)
		{
			day = 1;
			month++;
			if (month > SIZE_YEAR)
			{
				month = 1;
				year++;
			}
		}
	}

	void print()const//���������� ����
	{
		printf("������� ����: %d.%d.%d %s", day, month, year, week_day);
	}

	//���������� ����������
	//���������� ���������� ++ � --
	friend const Date operator++(const Date& obj_p)
	{
		int count = 0, count_2 = 0;//���������� ��������, ����� ��� ����, ����� � ������, ���� ����� ���� �������� 30 ��� ����� �������
		//�������� 12, �� � �������� ����������� ��� ���������� � � ������ ��� � ���� ���������� ����������� ������ ��������
		//count ������������ � �������, count_2 ������������ � �����
		int buffer = obj_p.day + 1, buffer_2 = obj_p.month;//�������� ��������, � ������� ������������ �������� 

		if (buffer > SIZE_MONTH)//��������� ������� ������
		{
			count++;
			buffer = 1;
		}

		if (buffer_2 + count > SIZE_YEAR)//��������� ������� ����
		{
			count_2++;
			buffer_2 = 1;
		}

		return Date(buffer, buffer_2, obj_p.year + count_2, obj_p.week_day);
	}

	friend const Date operator--(const Date& obj_p)
	{
		int count = 0, count_2 = 0;//���������� � ����������� ��������� ++
		int buffer = obj_p.day - 1, buffer_2 = obj_p.month;

		if (buffer <= 0)
		{
			count++;
			buffer = 1;
		}

		if (buffer_2 - count <= 0)
		{
			count_2++;
			buffer_2 = 1;
		}

		return Date(buffer, buffer_2, obj_p.year - count_2, obj_p.week_day);
	}

	const Date& operator=(const Date& date)//���������� ��������� ����������� ������������
	{
		if (&date != this)//�������� �� ���������������
		{
			day = date.day;
			month = date.month;
			year = date.year;
			
			delete[] week_day;

			week_day = new char[strlen(date.week_day) + 1];

			strcpy_s(week_day, strlen(date.week_day) + 1, date.week_day);
		}
		return* this;
	}

	// ���������� ���������� ������������
	const Date& operator+=(const Date& date)
	{
		day += date.day;
		month += date.month;
		year += date.year;

		delete[] week_day;

		week_day = new char[strlen(date.week_day) + 1];

		strcpy_s(week_day, strlen(date.week_day) + 1, date.week_day);
		return*this;
	}

	const Date& operator-=(const Date& date)
	{
		day -= date.day;
		month -= date.month;
		year -= date.year;

		delete[] week_day;

		week_day = new char[strlen(date.week_day) + 1];

		strcpy_s(week_day, strlen(date.week_day) + 1, date.week_day);
		return*this;
	}

	friend ostream& operator<<(ostream& cout, const Date& date)
	{
		printf("%d.%d.%d %s", date.day, date.month, date.year, date.week_day);
		return cout;
	}

	friend istream& operator>>(istream& cin, Date& date)
	{
		char buf[SIZE_YEAR];

		cin >> date.day;
		cin >> date.month;
		cin >> date.year;
		gets_s(buf);
		strcpy_s(date.week_day, strlen(buf) + 1, buf);
		return cin;
	}
	

	//���������� ���������� ����������
	friend bool operator>(const Date& date, const Date& date2)
	{
		return date.year < date2.year ? 1 : date.month < date2.month ? 1 : date.day < date2.day ? 1 : 0;
	}

	friend bool operator<(const Date& date, const Date& date2)
	{
		return date.year > date2.year ? 1 : date.month > date2.month ? 1 : date.day > date2.day ? 1 : 0;
	}

	friend bool operator==(const Date& date, const Date& date2)
	{
		return date.year == date2.year ? 0 : date.month == date2.month ? 0 : date.day == date2.day ? 0 : 1;
	}

	friend bool operator<=(const Date& date, const Date& date2)
	{
		return date.year <= date2.year ? 1 : date.month <= date2.month ? 1 : date.day <= date2.day ? 1 : 0;
	}

	friend bool operator>=(const Date& date, const Date& date2)
	{
		return date.year >= date2.year ? 1 : date.month >= date2.month ? 1 : date.day >= date2.day ? 1 : 0;
	}

	friend bool operator!=(const Date& date, const Date& date2)
	{
		return date.year != date2.year ? 0 : date.month != date2.month ? 0 : date.day != date2.day ? 0 : 1;
	}
	//���������� ()
	void operator()()
	{
		printf("\n������� ����: [ %d.%d.%d ] { %s }", day, month, year, week_day);
	}

	~Date()//����������
	{
		delete[] week_day;
	}
};


