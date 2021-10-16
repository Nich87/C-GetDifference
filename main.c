#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check_year(int); //関数のプロトタイプ宣言
const int month_last[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //月末日

int main(void) {

	/*
	* 定数化する場合はここ
	const int year[] = { 2003, 2021 };
	const int month[] = { 12, 10 };
	const int day[] = { 14, 15 };
	*/

	int year[] = {0,0};
	int month[] = {0,0};
	int day[] = {0,0};
	char YN[] = "";

	inputs:
	//do-whileで個別範囲指定すると安全(1-12月まで等)
	printf("誕生年(西暦)を入力:");
	scanf("%d", &year[0]);
	printf("\n誕生月を入力:");
	scanf("%d", &month[0]);
	printf("\n誕生日を入力:");
	scanf("%d", &day[0]);
	printf("\n指定する年を入力:");
	scanf("%d", &year[1]);
	printf("\n指定する月を入力:");
	scanf("%d", &month[1]);
	printf("\n指定する日を入力:");
	scanf("%d", &day[1]);
	printf("\n\x1b[4m%d年%d月%d日\x1b[0mから\x1b[4m%d年%d月%d日\x1b[0mまでの計算をしますか？(Y/N):", year[0], month[0], day[0], year[1], month[1], day[1]);

	do {
		scanf("%c", &YN[0]);
		if (YN[0] == 'Y') break;
		else if(YN[0] == 'N') goto inputs;
	} while ('Y' != YN[0] && 'N' != YN[0]);



	// 閏年を考慮せずにyear[0]年1月1日からyear[1]年1月1日までの日数を代入
	int getDay = (year[1] - year[0]) * 365;

	// year[0]年1月1日からyear[1]年1月1日までのうるう年のずれを加算
	for (int i = year[0]; i < year[1]; i++) {
		if (check_year(i)) getDay++;
	}

	// year[0]年の、1月1日からmonth[0]月1日までの日数を減算
	for (int i = 0; i < month[0] - 1; i++) {
		if (i == 1 && check_year(year[0])) getDay -= 29; //閏年の2月
		getDay -= month_last[i];
	}

	// year[1]年の、1月1日からmonth[1]月1日までの日数を加算
	for (int i = 0; i < month[1] - 1; i++) {
		if (i == 1 && check_year(year[1])) getDay += 29;  //閏年の2月
		getDay += month_last[i];
	}

	// month[0]月の、1日からday[0]日までの日数を減算
	getDay -= day[0] - 1;

	// month[1]月の、1日からday[1]日までの日数を加算
	getDay += day[1] - 1;

	printf("\n\x1b[4m%d年%d月%d日\x1b[0mから\x1b[4m%d年%d月%d日\x1b[0mまでは\x1b[4m%d日\x1b[0mです。\n", year[0], month[0], day[0], year[1], month[1], day[1], getDay);

	return 0;
}

/*
 *	 グレゴリオ暦が採用された1582年10月15日以降のみ対応
 *	 1582年10月4日まで - ユリウス暦
 *	 1582年10月5日から - グレゴリオ暦
 *	 chech_year関数を少し変えれば、1582年10月4日以前にも対応可能
 */

int check_year(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return 1;
	return 0;
}
