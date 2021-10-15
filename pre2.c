#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check_year(int);
const int month_last[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(void) {
	/*
	グレゴリオ暦が採用された1582年10月15日以降のみ対応しています。
	1582年10月4日まで - ユリウス暦
	1582年10月5日から - グレゴリオ暦
	is_leap_year関数を少し変えれば、1582年10月4日以前にも対応できます。
	*/
	
	const int year[] = { 2000, 2021 };
	const int month[] = { 1, 12 };
	const int day[] = { 31, 31 };
	
	// 閏年を考慮せずにyear[0]年1月1日からyear[1]年1月1日までの日数を代入
	int getDay = (year[1] - year[0]) * 365;

	// year[0]年1月1日からyear[1]年1月1日までのうるう年のずれを加算
	for (int i = year[0]; i < year[1]; i++) {
		if (is_leap_year(i)) getDay++;
	}

	// year[0]年の、1月1日からmonth[0]月1日までの日数を減算
	for (int i = 0; i < month[0] - 1; i++) {
	if (i == 1 && is_leap_year(year[0])) getDay -= 29;
		getDay -= month_last[i];
	}

	// year[1]年の、1月1日からmonth[1]月1日までの日数を加算
	for (int i = 0; i < month[1] - 1; i++) {
	if (i == 1 && is_leap_year(year[1])) getDay += 29;
		getDay += month_last[i];
	}

	// month[0]月の、1日からday[0]日までの日数を減算
	getDay -= day[0] - 1;

	// month[1]月の、1日からday[1]日までの日数を加算
	getDay += day[1] - 1;

	printf("%d\n", getDay);

	return 0;
}


int is_leap_year(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return 1;
	return 0;
}
