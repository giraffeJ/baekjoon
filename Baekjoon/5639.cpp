#include<stdio.h>
int tre[20001], i, j, k, n, m, l;
struct tree {
	int value;
	int parent;
	int left;
	int right;
} a[20001];
void put(int val, int x) {
	int pos = 1;
	while (1) {
		if (val < a[pos].value) {
			if (a[pos].left != 0)
				pos = a[pos].left;
			else {
				a[pos].left = x;
				a[x].parent = pos;
				break;
			}
		}
		else {
			if (a[pos].right != 0)
				pos = a[pos].right;
			else {
				a[pos].right = x;
				a[x].parent = pos;
				break;
			}
		}
	}
}
void postsearch(int pos) {
	if (a[pos].left == 0 && a[pos].right == 0) {
		printf("%d\n", a[pos].value);
		return;
	}
	else {
		if (a[pos].left != 0) postsearch(a[pos].left);
		if (a[pos].right != 0) postsearch(a[pos].right);
		printf("%d\n", a[pos].value);
	}
}
int main() {
	while (scanf("%d", &n) != EOF) {
		a[++m].value = n;
	}
	for (i = 2; i <= m; i++) {
		put(a[i].value, i);
	}
	postsearch(1);
	scanf("%d", &n);
}