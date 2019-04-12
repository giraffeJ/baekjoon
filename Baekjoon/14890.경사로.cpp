#include<stdio.h>
int n, l, map[110][110];
int abs(int a) {
	return a < 0 ? a * -1 : a;
}
void get_input() {
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int check(int x) {
	int count = 1, res = 0, i, j;
	for (i = 2; i <= n; i++) {
		if (abs(map[x][i] - map[x][i - 1]) > 1) break;
		if (map[x][i] != map[x][i - 1]) {
			if (map[x][i] < map[x][i - 1]) {
				for (j = i; j <= i + l - 1; j++) {
					if (map[x][j] != map[x][i] || j>n) break;
				}
				if (j == i + l) {
					i = i + l - 1;
					count = 0;
				}
				else break;
			}
			else {
				if (count < l) break;
				count = 1;
			}
		}
		else count++;
	}
	if (i == n + 1) res++;
	count = 1;
	for (i = 2; i <= n; i++) {
		if (abs(map[i][x] - map[i - 1][x]) > 1) break;
		if (map[i][x] != map[i - 1][x]) {
			if (map[i][x] < map[i - 1][x]) {
				for (j = i; j <= i + l - 1; j++) {
					if (map[j][x] != map[i][x] || j>n) break;
				}
				if (j == i + l) {
					i = i + l - 1;
					count = 0;
				}
				else break;
			}
			else {
				if (count < l) break;
				count = 1;
			}
		}
		else count++;
	}
	if (i == n + 1) res++;
	return res;
}
int count_road() {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		count+=check(i);
	}
	return count;
}
int main() {
	get_input();
	printf("%d\n", count_road());
}