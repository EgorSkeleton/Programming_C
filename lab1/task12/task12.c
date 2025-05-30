#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 256
#include <stdbool.h>

bool leap_year(int year){
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int days_count(int year, int month){
	int counts[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(month == 1) return leap_year(year) ? 29: 28;
	return counts[month];  
}

char *month_is(int month){
	char *months[] = {"Jan", "Web", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	return months[month];
}

char *week_day_is(int week_day){
	char *week_days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	return week_days[week_day];
}

void current_time(){
	struct tm *local;
	time_t now;
	now = time(NULL);
	local = localtime(&now);
	printf("Current time is %s", asctime(local));
}

void calendar_for_year(int year){
	printf("--------%d---------\n", year);
	int month, i;
	for(month=0; month<12; month++){
		printf("\n---------%s---------\n", month_is(month));
		printf("Mn Tu We Th Fr St Su\n");
		
		struct tm local = {0};
		local.tm_year = year - 1900;
		local.tm_mday = 1;
		local.tm_mon = month;
		mktime(&local);
		if(local.tm_wday == 0) local.tm_wday = 7;
		for(i=1; i<local.tm_wday; i++){
			printf("   ");
		}
		
		int days = days_count(year, month);
		for(i=1; i<=days; i++){
			if(i<10){
				printf("%d  ", i);
			}else{
				printf("%d ", i);
			}
			if ((i + local.tm_wday - 1) % 7 == 0) printf("\n");
		}
		printf("\n");
	}
}

void calendar_for_month(int year, int month){
	int i;
	struct tm local = {0};
	local.tm_year = year - 1900;
	local.tm_mday = 1;
	local.tm_mon = month;
	mktime(&local);
	printf("---------%s---------\n", month_is(month));
	printf("Mn Tu We Th Fr St Su\n");
	if(local.tm_wday == 0) local.tm_wday = 7;
	for (i = 1; i<local.tm_wday; i++){
		printf("   ");
	}
	int days = days_count(year, month);
	for(i=1; i<=days; i++){
		if(i<10){
			printf("%d  ", i);
		}else{
			printf("%d ", i);
		}
		if ((i + local.tm_wday - 1) % 7 == 0) printf("\n");
	}
}

void week_day(int year, int month, int day){
	struct tm local = {0};
	local.tm_year = year - 1900;
	local.tm_mon = month;
	local.tm_mday = day;
	mktime(&local);
	printf("%s", week_day_is(local.tm_wday));
}

int main() {
	int i;
	char *input = malloc(N * sizeof(char));
	scanf("%s", input);
	if(input[0] == 'n'){
		current_time();
	}else if(strlen(input) == 7) {
		char year_str[] = {input[0], input[1], input[2], input[3], "\0"};
		char month_str[] = {input[5], input[6], "\0"};
		int year = atoi(year_str);
		int month = atoi(month_str);
		calendar_for_month(year, month-1);
		return 0;
	}else if(strlen(input) == 10){
		char year_str[] = {input[0], input[1], input[2], input[3], "\0"};
		char month_str[] = {input[5], input[6], "\0"};
		char day_str[] = {input[8], input[9], "\0"};
		int year = atoi(year_str);
		int month = atoi(month_str);
		int day = atoi(day_str);
		week_day(year, month-1, day);
		return 0;
	}
	calendar_for_year(atoi(input));
	free(input);
	return 0;
}
