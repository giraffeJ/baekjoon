#include<stdio.h>
#include<string.h>
int i, j, k, n, m, d[1500], p[1500][1500], max, temp, l, tmax, tl;
char a[1500], b[1500], res[1500];
int main() {
	scanf("%s", &a);
	scanf("%s", &b);
	n = strlen(a);
	m = strlen(b);
	for (i = 0; i < n; i++) {
		l = tl = -1;
		max = tmax = 0;
		for (j = 0; j < m; j++) {
			if (d[j] > max) {
				tmax = d[j];
				tl = j;
			}
			if (b[j] == a[i] && d[j]<max + 1) {
				d[j] = max + 1;
				p[max + 1][j] = l;
			}
			l = tl;
			max = tmax;

		}
	}
	max = -999;
	for (i = 0; i < m; i++) {
		if (d[i] > max) {
			max = d[i];
			l = i;
		}
	}
	printf("%d\n", max);
	temp = max;
	while (1) {
		res[temp] = b[l];
		l = p[temp--][l];
		if (l == -1) break;
	}
	for (i = 1; i <= max; i++) {
		printf("%c", res[i]);
	}
	printf("\n");
	scanf("%d", &n);
}