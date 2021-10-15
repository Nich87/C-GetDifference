#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define THROW_ERROR(message) do { fprintf(stderr, "Error: %s:%d: %s\n", __FILE__, __LINE__, message); exit(1); } while(0)


int main(void){
	const int year[] = { 2000, 2021 };
	const int month[] = { 1, 12 };
	const int day[] = { 31, 31 };

	struct tm start = {}, end = {};
	start.tm_year = year[0] - 1900;
	start.tm_mon = month[0] - 1;
	start.tm_mday = day[0];
	end.tm_year = year[1] - 1900;
	end.tm_mon = month[1] - 1;
	end.tm_mday = day[1];

	long start_sec = mktime(&start);
	long end_sec = mktime(&end);

	if (!~start_sec) 
		THROW_ERROR("Failed to convert 'struct tm' to 'time_t'");

	if (!~end_sec) 
		THROW_ERROR("Failed to convert 'struct tm' to 'time_t'");

	printf("Difference: %ld\n", (end_sec - start_sec) / (60 * 60 * 24));

	return 0;
}
