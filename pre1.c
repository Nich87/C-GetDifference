#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check_year(int);
const int month_last[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main(void) {

	int year[2] = { 2000,2021 };
	int month[2] = { 1,12 };
	int day[2] = { 31,31 };


	/*
	printf("誕生年:");
	scanf("%d", &year[0]);
	printf("誕生月:");
	scanf("%d", &month[0]);
	printf("誕生日:");
	scanf("%d", &day[0]);

	printf("年:");
	scanf("%d", &year[1]);
	printf("月:");
	scanf("%d", &month[1]);
	printf("日:");
	scanf("%d", &day[1]);
	*/

	//誕生日 - 日数計算
	int birth = 365 * year[0];
	//閏年ならプラスする
	while (year[0] == 0) {
		if (check_year(year[0])) {
			birth++;
			year[0]--;
		}
	}
	birth += day[0];

	for (int i = 0; i > month[0] - 1; i++) birth += month_last[month[0] - 1];


	//現在 - 日数計算
	int now = 365 * year[1];
	//閏年ならプラスする
	while (year[1] == 0) {
		if (check_year(year[1])) {
			now++;
			year[1]--;
		}
	}
	now += day[1];
	for (int i = 0; i > month[1] - 1; i++) birth += month_last[month[1] - 1];
	int res = now - birth;

	printf("%d日", res); //8005になるはず

	return 0;
}


int check_year(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return 1;
	return 0;
}
