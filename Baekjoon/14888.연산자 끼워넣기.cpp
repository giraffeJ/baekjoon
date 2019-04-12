#include<stdio.h>
int n, max_val=-2100000000, min_val=2100000000;
int num[20], oper[20];
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
void get_input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 1; i <= 4; i++) {
		scanf("%d", &oper[i]);
	}
}
int cal(int val1, int val2, int op) {
	if (op == 1) return val1 + val2;
	if (op == 2) return val1 - val2;
	if (op == 3) return val1 * val2;
	return val1 / val2;
}
void calc_val(int pos, int val) {
	if (pos == n) {
		max_val = max(max_val, val);
		min_val = min(min_val, val);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		if (oper[i] >= 1) {
			oper[i]--;
			calc_val(pos + 1, cal(val, num[pos + 1], i));
			oper[i]++;
		}
	}
}
int main() {
	get_input();
	calc_val(1, num[1]);
	printf("%d\n%d\n", max_val, min_val);
}