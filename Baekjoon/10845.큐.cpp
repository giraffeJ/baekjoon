#include<stdio.h> //#include<iostream>
#include<string>
using namespace std;
int q[10010], r, f, n, value;
string order;
char c[11];
int main() {
	scanf("%d", &n); //cin >> n;
	r = f = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s", &c); // cin >> order;
		order.clear();
		order += c;
		if (order == "push") {
			scanf("%d", &value); //cin >> value;
			q[++r] = value;
		}
		if (order == "front") {
			if (r == f) printf("-1\n"); //cout << "-1\n";
			else printf("%d\n", q[f + 1]); // cout << q[f + 1] << endl;
		}
		if (order == "back") {
			if (r == f) printf("-1\n"); //cout << "-1\n";
			else printf("%d\n", q[r]); //cout << q[r] << endl;
		}
		if (order == "size")
			printf("%d\n", r - f); //cout << r - f << endl;
		if (order == "empty")
			printf("%d\n", (r == f)); //cout << (r == f) << endl;
		if (order == "pop") {
			if (r == f) printf("-1\n"); //cout << "-1\n";
			else printf("%d\n", q[++f]); //cout << q[++f] << endl;
		}
	}
	return 0;
}
/*
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
*/