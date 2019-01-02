#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
char haab[20][20] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
char tzolkin[25][20] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
int i, j, n;
int day, year, month, daysum;
int dayt, yeart, montht;
int main() {
	scanf("%d", &n);
	char monthstr[20];
	printf("%d\n", n);
	for (i = 1; i <= n; i++) {
		scanf("%d. %s %d", &day, &monthstr, &year);
		for (j = 0; j < 19; j++) {
			if (strcmp(monthstr, haab[j]) == 0) {
				month = j;
			}
		}
		daysum = year * 365 + month * 20 + day + 1;
		yeart = (daysum - 1) / 260;
		daysum = daysum - yeart * 260;
		montht = ((daysum - 1) % 13) + 1;
		dayt = ((daysum - 1) % 20);
		printf("%d %s %d\n", montht, tzolkin[dayt], yeart);
	}
	scanf("%d %d", &n, &i);
}