#include<stdio.h>
int gear[5][9];
void get_gears() {
	char c[10];
	for (int i = 1; i <= 4; i++) {
		scanf(" %s", &c);
		for (int j = 0; j < 8; j++) {
			gear[i][j + 1] = c[j] - 48;
		}
	}
}
void move(int a[], int dir) {
	if (dir == 0) return;
	if (dir == -1) {
		a[0] = a[1];
		for (int i = 1; i <= 7; i++)
			a[i] = a[i + 1];
		a[8] = a[0];
		return;
	}
	a[0] = a[8];
	for (int i = 8; i >= 2; i--)
		a[i] = a[i - 1];
	a[1] = a[0];	
}
int score() {
	int sum = 0, k = 1;
	for (int i = 1; i <= 4; i++) {
		sum += gear[i][1] * k;
		k *= 2;
	}
	return sum;
}
int m_dir[5], n, num, dir;
int main() {
	get_gears();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &num, &dir); // -1 : left / 1: right
		m_dir[num] = dir;
		for (int j = num; j >= 2; j--) {
			if (gear[j][7] != gear[j - 1][3])
				m_dir[j - 1] = m_dir[j] * -1;
			else
				m_dir[j - 1] = 0;
		}
		for (int j = num; j < 4; j++) {
			if (gear[j][3] != gear[j + 1][7])
				m_dir[j + 1] = m_dir[j] * -1;
			else
				m_dir[j + 1] = 0;
		}
		for (int j = 1; j <= 4; j++) {
			move(gear[j], m_dir[j]);
		}
	}
	printf("%d\n", score());
}