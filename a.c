#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int month_last[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int check_year(int);

int main(void){
	int year[1], month[1], day[1];

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
	printf("月:");
	scanf("%d", &day[1]);

	//誕生日 - 日数計算
	int birth = 365 * year[0];
	//閏年ならプラスする
	while (year[0] == 0){
	if (check_year(year[0])){ 
		birth++;
		year[0]--;
	}
	}
	
	//
	int birth_month_day = month_last[month[0]];
	birth = birth + birth_month_day + (birth_month_day - day[0]);


	//現在 - 日数計算
	int now = 365 * year[1];
	//閏年ならプラスする
	while (year[1] == 0){
		if (check_year2(year[1])){
			now++;
			year[1]--;
		}
	}

	int birth_month_day2 = month_last[month[1]];
	now = now + birth_month_day2 + (birth_month_day2 - day[0]);

	int res = now - birth;

	printf("%d日",res);

	return 0;
}

int check_year(int year) {
	if (year % 400 == 0) return 1;
	if (year % 4 == 0 && year % 100 != 0) return 1;
	return 0;
}
