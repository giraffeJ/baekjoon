#include<stdio.h>
int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
char dow[7][5] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int month, day, res;
int main() {
	scanf("%d %d", &month, &day);
	res = days[month - 1] + day;
	res %= 7;
	printf("%s\n", dow[res]);
	scanf("%d %d", &month, &day);
}
