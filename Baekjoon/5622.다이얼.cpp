#include<stdio.h>
#include<string.h>
int n, res;
int sec[27]= { 0, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
char a[17];
int main() {
	scanf("%s", &a);
	n = strlen(a);
	for (int i = 0; i < n; i++) {
		res += sec[a[i] - 64];
	}
	printf("%d\n", res);
	scanf("%d", &n);
}