#include<stdio.h>
int board[30][30];
int n, res;
int max_(int a, int b) {
	return a > b ? a : b;
}
void get_board() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
}
void copy_board(int a[][30], int b[][30]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			a[i][j] = b[i][j];
	}
}
int find_max_value(int origin[][30]) {
	int max = -999;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (origin[i][j] > max) max = origin[i][j];
		}
	}
	return max;
}
int inci[5] = { 0, 1, 0, -1, 0 };
int incj[5] = { 0, 0, -1, 0, 1 };
int si[5] = { 0, 1, 0, 30, 0 };
int sj[5] = { 0, 0, 30, 0, 1 };
void move(int board[][30], int dir) {
	int temp[30], i, j, tn, posi, posj, l;
	for (int k = 1; k <= n; k++) {
		tn = 0;
		posi = i = k * (1 - dir % 2) + si[dir];
		posj = j = k * (dir % 2) + sj[dir];
		for (l = 1; l <= n; l++) {
			if (board[i][j] > 0) temp[++tn] = board[i][j];
			board[i][j] = 0;
			i += inci[dir];
			j += incj[dir];
		}
		for (l = 1; l < tn; l++) {
			if (temp[l] == temp[l + 1]) {
				board[posi][posj] = temp[l] * 2;
				l++;
			}
			else board[posi][posj] = temp[l];
			posi += inci[dir];
			posj += incj[dir];
		}
		if (l == tn) board[posi][posj] = temp[l];
	}
}
int search(int origin[][30], int cnt) {
	int backup[30][30], max_val = -999;
	if (cnt == 6) {
		return find_max_value(origin);
	}
	copy_board(backup, origin);
	for (int i = 1; i <= 4; i++) {
		move(origin, i);
		max_val = max_(max_val, search(origin, cnt + 1));
		copy_board(origin, backup);
	}
	return max_val;
}
int main() {
	scanf("%d", &n);
	si[3] = sj[2] = n;
	get_board();
	res = search(board, 1);
	printf("%d\n", res);
}