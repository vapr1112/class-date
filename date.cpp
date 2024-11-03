#include "date.h"

//главный конструктор
Date::Date(const int day_p, const int month_p, const int year_p, const char* week_day_p) : day{ day_p }, month{ month_p }, year{ year_p }, week_day{ week_day_p ? new char[strlen(week_day_p) + 1] : nullptr }
{
	if (week_day)
	{
		strcpy_s(week_day, strlen(week_day_p) + 1, week_day_p);
	}
}

//конструктор копирования
Date::Date(const Date& date) : day{ date.day }, month{ date.month }, year{ date.year }, week_day{ new char[strlen(date.week_day) + 1] }
{
	strcpy_s(week_day, strlen(date.week_day) + 1, date.week_day);
}