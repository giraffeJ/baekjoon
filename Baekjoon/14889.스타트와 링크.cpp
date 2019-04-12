#include<stdio.h>
int n, stat[30][30];
int s_team[20], l_team[20];
int min_dif = 2100000000;
int min(int a, int b) {
	return a < b ? a : b;
}
void get_input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &stat[i][j]);
		}
	}
}
int abs(int a) {
	return a < 0 ? a * -1 : a;
}
int calc_stat_dif() {
	int sum_s = 0, sum_l = 0;
	for (int i = 1; i <= n/2; i++) {
		for (int j = 1; j <= n/2; j++) {
			sum_s += stat[s_team[i]][s_team[j]];
			sum_l += stat[l_team[i]][l_team[j]];
		}
	}
	return abs(sum_s - sum_l);
}
void team_build(int pos, int start, int link) {
	if (pos == n + 1) {
		min_dif = min(min_dif, calc_stat_dif());
		return;
	}
	if (start < n / 2) {
		s_team[start + 1] = pos;
		team_build(pos + 1, start + 1, link);
	}
	if (link < n / 2) {
		l_team[link + 1] = pos;
		team_build(pos + 1, start, link + 1);
	}
}
int main() {
	get_input();
	team_build(1, 0, 0);
	printf("%d\n", min_dif);
}