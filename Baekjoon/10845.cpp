#include<stdio.h>
#include<string.h>
int r, f, q[20001], i, j, n, m;
char cmd[20];
int main() {
	scanf("%d", &n);
	r = f = 0;
	for (i = 1; i <= n; i++) {
		scanf("%s", &cmd);
		if (!strcmp(cmd, "push")) {
			scanf("%d", &m);
			q[++r] = m;
		}
		if (!strcmp(cmd, "front")) {
			if (r == f) printf("-1\n");
			else printf("%d\n", q[f + 1]);
		}
		if (!strcmp(cmd, "back")) {
			if (r == f) printf("-1\n");
			else printf("%d\n", q[r]);
		}
		if (!strcmp(cmd, "size"))
			printf("%d\n", r - f);
		if (!strcmp(cmd, "empty")) {
			if (r == f) printf("1\n");
			else printf("0\n");
		}
		if (!strcmp(cmd, "pop")) {
			if (r == f) printf("-1\n");
			else printf("%d\n", q[++f]);
		}
	}
	scanf("%d", &n);
}