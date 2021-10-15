#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check_year(int);
const int month_last[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main(void) {
	
	int year[2] = { 2000,2021 };
    int month[2] = { 1,12 };
	int day[2] = { 31,31 };
	
	int getDay = (year[1] - year[0]) * 365;
	while (year[1] == 0) {
		if (check_year(year[1])) getDay++;
		year[1]--;
	}
	while (month[0] > 1 && month[1] >1) {
		if (month[0] > 1) {
			getDay += month_last[month[0] - 1];
			month[0]--;
		}

		if (month[1] > 1) {
			getDay += month_last[month[1] - 1];
			month[1]--;
		}
	}
	getDay += day[0] + day[1];

	printf("%d", getDay);

	return 0;
}


int check_year(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return 1;
	return 0;
}
