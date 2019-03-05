#include<stdio.h>
#include<string.h>
int i, n, m;
char a[1000002];
int main() {
	gets_s(a);
	n = strlen(a);
	for (i = 1; i < n; i++) {
		if (a[i] == ' ') m++;
	}
	if (a[n - 1] != ' ') m++;
	printf("%d\n", m);
	scanf("%d", &n);
}