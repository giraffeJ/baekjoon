#include<stdio.h>
#include<algorithm>
int i, j, k, n, m;
struct list {
	int num;
	int val;
	int cnt;
} run[10001], temp1[10001], temp2[10001];
bool comp(list a, list b) {
	if (a.num < b.num) return true;
	else return false;
}
void merge(int s1, int e1, int s2, int e2) {
	int i, x, y;
	for (i = s1; i <= e1; i++) 
		temp1[i] = run[i];
	for (i = s2; i <= e2; i++)
		temp2[i] = run[i];
	x = s1;
	y = s2;
	for (i = s1; i <= e2; i++) {
		if (x == e1 + 1) 
			run[i] = temp2[y++];
		else if (y == e2 + 1)
			run[i] = temp1[x++];
		else if (temp1[x].val > temp2[y].val) 
			run[i] = temp1[x++];
		else if (temp1[x].val < temp2[y].val) {
			temp2[y].cnt += (e1 - x + 1);
			run[i] = temp2[y++];
		}
	}
}
void ms(int s, int e) {
	if (s == e) {
		return;
	}
	else {
		int m = (s + e) / 2;
		ms(s, m);
		ms(m + 1, e);
		merge(s, m, m + 1, e);
	}
}
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &run[i].val);
		run[i].num = i;
	}
	ms(1, n);
	std::sort(run + 1, run + n + 1, comp);
	for (i = 1; i <= n; i++) {
		printf("%d\n", run[i].num - run[i].cnt);
	}
	scanf("%d", &n);
}