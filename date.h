#pragma once

#include <iostream>
#define SIZE 12

using namespace std;

class date
{
private:
	int day;
	int month;
	int year;
	char* week_day;
public:
	date() : date(25, 1, 2000, nullptr) {}
	explicit date(int day_p) : date(day_p, 1, 2000, nullptr) {}
	date(int day_p, int month_p, int year_p, char* week_day_p) : day{ day_p }, month{ month_p }, year{ year_p }, week_day{ week_day_p ? new char[strlen(week_day_p) + 1] : nullptr }
	{
		if (week_day)
		{
			strcpy_s(week_day, strlen(week_day_p) + 1, week_day_p);
		}
	}
	date(const date& date) : day{ date.day }, month{ date.month }, year{ date.year }, week_day{ new char[strlen(date.week_day) + 1] }
	{
		strcpy_s(week_day, strlen(date.week_day) + 1, date.week_day);
	}

	void set_day(int day_p)
	{
		if (day_p > 30 || day_p <= 0)
		{
			cout << "Введено недопустимое значение!";
			return;
		}

		day = day_p;
	}
	void set_month(int month_p)
	{
		if (month_p > 12 || month_p <= 0)
		{
			cout << "Введено недопустимое значение!";
			return;
		}
		month = month_p;
	}
	void set_year(int year_p)
	{
		if (year_p < 0)
		{
			cout << "Введено недопустимое значение!";
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
	void print()
	{
		printf("Текущая дата: %d.%d.%d", day, month, year);
	}

	friend const date operator+(const date& obj_p, int num)
	{
		int count = 0, count_2 = 0;
		int buffer = obj_p.day + num, buffer_2 = obj_p.month;// 30.12.2024 + 15 = 15.1.2025

		while (buffer > 30)
		{
			count++;
			buffer -= 30;
		} // buf = 15, count = 1

		buffer += count;

		while (buffer_2 > 12)
		{
			count_2++;
			buffer_2 -= 12;
		} // buf_2 = 1, count_2 = 1

		return date(buffer, buffer_2, obj_p.year + count_2, obj_p.week_day);
	}

	friend const date operator-(const date& obj_p, int num)
	{
		int count = 0, count_2 = 0;
		int buffer = obj_p.day - num, buffer_2 = obj_p.month;

		while (buffer <= 0)
		{
			count++;
			buffer += 30;
		}

		while (buffer_2 - count <= 0)
		{
			count_2++;
			buffer_2 += 12;
		}

		return date(buffer, buffer_2, obj_p.year - count_2, obj_p.week_day);
	}

	friend const date operator++(const date& obj_p)
	{
		int count = 0, count_2 = 0;
		int buffer = obj_p.day + 1, buffer_2 = obj_p.month;

		if (buffer > 30)
		{
			count++;
			buffer -= 30;
		}

		if (buffer_2 + count > 12)
		{
			count_2++;
			buffer_2 -= 12;
		}

		return date(buffer, buffer_2, obj_p.year + count_2, obj_p.week_day);
	}

	friend const date operator--(const date& obj_p)
	{
		int count = 0, count_2 = 0;
		int buffer = obj_p.day - 1, buffer_2 = obj_p.month;

		if (buffer <= 0)
		{
			count++;
			buffer += 30;
		}

		if (buffer_2 - count <= 0)
		{
			count_2++;
			buffer_2 += 12;
		}

		return date(buffer, buffer_2, obj_p.year - count_2, obj_p.week_day);
	}

	const date& operator=(const date& date)
	{
		if (&date != this)
		{
			day = date.day;
			month = date.month;
			year = date.year;
		}
	}

	friend ostream& operator<<(ostream& cout, const date& date)
	{
		printf("%d.%d.%d %s", date.day, date.month, date.year, date.week_day);
		return cout;
	}

	friend istream& operator>>(istream& cin, date& date)
	{
		char buf[SIZE];

		cin >> date.day;
		cin >> date.month;
		cin >> date.year;
		gets_s(buf);
		strcpy_s(date.week_day, strlen(buf) + 1, buf);
		return cin;
	}

	friend bool operator>(const date& date, const date& date_2)
	{
		return date.year < date2.year ? 1 : date.month < date2.month ? 1 : date.day < date2.day ? 1 : 0;
	}

	friend bool operator<(const date& date, const date& date2)
	{
		return date.year > date2.year ? 1 : date.month > date2.month ? 1 : date.day > date2.day ? 1 : 0;
	}

	friend bool operator==(const date& date, const date& date2)
	{
		return date.year == date2.year ? 0 : date.month == date2.month ? 0 : date.day == date2.day ? 0 : 1;
	}

	friend bool operator<=(const date& date, const date& date2)
	{
		return date.year <= date2.year ? 1 : date.month <= date2.month ? 1 : date.day <= date2.day ? 1 : 0;
	}

	friend bool operator>=(const date& date, const date& date2)
	{
		return date.year >= date2.year ? 1 : date.month >= date2.month ? 1 : date.day >= date2.day ? 1 : 0;
	}

	friend bool operator!=(const date& date, const date& date2)
	{
		return date.year != date2.year ? 0 : date.month != date2.month ? 0 : date.day != date2.day ? 0 : 1;
	}


	~date()
	{
		delete[] week_day;
	}
};

void print(date obj)
{
	cout << obj.get_day() << ".";
	cout << obj.get_month() << ".";
	cout << obj.get_year() << "\n";
}
