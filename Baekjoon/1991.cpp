#include<stdio.h>
int i, j, n, m, a[1001], x, y, z, pos[30];
char q, w, e;
void pre(int x) {
	if (a[x * 2] == 0 && a[x * 2 + 1] == 0) {
		printf("%c", a[x] + 64);
	}
	else {
		printf("%c", a[x] + 64);
		if (a[x * 2] != 0) pre(x * 2);
		if (a[x * 2 + 1] != 0) pre(x * 2 + 1);
	}
}
void mid(int x) {
	if (a[x * 2] == 0 && a[x * 2 + 1] == 0) {
		printf("%c", a[x] + 64);
	}
	else {
		if (a[x * 2] != 0) mid(x * 2);
		printf("%c", a[x] + 64);
		if (a[x * 2 + 1] != 0) mid(x * 2 + 1);
	}
}
void post(int x) {
	if (a[x * 2] == 0 && a[x * 2 + 1] == 0) {
		printf("%c", a[x] + 64);
	}
	else {
		if (a[x * 2] != 0) post(x * 2);
		if (a[x * 2 + 1] != 0) post(x * 2 + 1);
		printf("%c", a[x] + 64);
	}
}
int main() {
	scanf("%d", &n);
	pos[1] = 1;
	a[1] = 1;
	for (i = 1; i <= n; i++) {
		scanf(" %c %c %c", &x, &y, &z);
		if (y != '.') {
			a[pos[x - 64] * 2] = y - 64;
			pos[y - 64] = pos[x - 64] * 2;
		}
		if (z != '.') {
			a[pos[x - 64] * 2 + 1] = z - 64;
			pos[z - 64] = pos[x - 64] * 2 + 1;
		}
	}
	pre(1);
	printf("\n");
	mid(1);
	printf("\n");
	post(1);
	printf("\n");

	scanf("%d", &n);
}