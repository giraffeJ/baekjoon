#include<stdio.h>
#include<string.h>
int i, n, cnt;
char a[101];
int main() {
	scanf("%s", &a);
	n = strlen(a);
	cnt = 0;
	for (i = 0; i < n; i++) {
		printf("%c", a[i]);
		cnt++;
		if (cnt == 10) {
			cnt = 0;
			printf("\n");
		}
	}
}