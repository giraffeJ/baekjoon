#include<stdio.h>
int i, j, ind[20000001], k, n, m, s, siz, x, y;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void set(int pos) {
	if (pos >= s && pos < siz) {
		return;
	}
	else {
		set(pos * 2);
		set(pos * 2 + 1);
		ind[pos] = min(ind[pos * 2], ind[pos * 2 + 1]);
	}
}
int findmin(int s, int e) {
	int res = 2100000000;
	while (s <= e) {
		if (s % 2 == 1)
			if (ind[s] < res) res = ind[s];
		s = (s + 1) / 2;
		if (e % 2 == 0)
			if (ind[e] < res) res = ind[e];
		e = (e - 1) / 2;
	}
	return res;
}
int main() {
	scanf("%d %d", &n, &m);
	siz = 1;
	while (siz < n) {
		siz = siz * 2;
	}
	s = siz;
	siz = siz * 2;
	for (i = 1; i <= n; i++) {
		scanf("%d", &ind[s + i - 1]);
	}
	for (i = n + s; i < siz; i++) {
		ind[i] = 2100000000;
	}
	set(1);
	for (i = 1; i <= n; i++) {
		x = i - m + 1;
		y = i;
		if (x <= 0) x = 1;
		printf("%d ", findmin(x + s - 1, y + s - 1));
	}
	scanf("%d %d", &n, &m);
}