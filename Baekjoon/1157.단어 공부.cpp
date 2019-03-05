#include<stdio.h>
#include<string.h>
int i, n, cn[26], max, l;
char a[1000002];
int main() {
	scanf("%s", &a);
	n = strlen(a);
	max = -1;
	for (i = 0; i < n; i++) {
		if (a[i] >= 97) {
			a[i] -= 32;
		}
		cn[a[i] - 65]++;
		if (cn[a[i] - 65] > max) max = cn[a[i] - 65];
	}
	for (i = 0; i <= 25; i++) {
		if (cn[i] == max && l != 0) {
			printf("?\n");
			l = -1;
			break;
		}
		else if (cn[i] == max) {
			l = i+1;
		}
	}
	if (l != -1) {
		printf("%c\n", l + 64);
	}
	scanf("%d", &n);
}
