 /*
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, h, res=-1;
int ladder[40][20];
struct lad {
	int a;
	int b;
	bool operator<(const lad x) {
		return a == x.a ? b < x.b : a < x.a;
	}
} ladd[400];
void get_input() {
	int a, b;
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		ladder[a][b] = 1;
	}
}
int min(int a, int b) {
	return a < b ? a : b;
}
void change(int a[], int x, int y) {
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}
int connection_check() {
	int a[20];
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (ladder[i][j] == 1) {
				change(a, j, j + 1);
			}
		}
	}
	int cnt = 0;
	int a1=0, a2=0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {
			a2 = a1;
			a1 = i;
			cnt++;
		}
	}
	if (cnt == 0) return 0;
	else if (cnt == 2) {
		for (int i = 1; i <= n; i++) {
			a[i] = i;
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j < n; j++) {
				if (ladder[i][j] == 1) {
					change(a, j, j + 1);
				}
				if (ladder[i][j] + ladder[i][j - 1] + ladder[i][j + 1] == 0 && (a[j] == a1 && a[j + 1] == a2 || a[j] == a2 && a[j + 1] == a1)) {
					return 1;
				}
			}
		}
		return -1;
	}
	return -1;
}
void place_ladder(int seq, int num) {
	if (seq == 4) {
		if (ladder[1][3] == 1 && ladder[4][2] == 1) {
			n = n;
		}
		int k = connection_check();
		if (k>=0) {
			res = num+k;
		}
		return;
	}
	if (res != -1) return;
	place_ladder(seq + 1, num);
	if (num >= 2) return;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (ladder[i][j - 1] == 0 && ladder[i][j + 1] == 0 && ladder[i][j] == 0) {
				ladder[i][j] = 1;
				place_ladder(seq + 1, num + 1);
				ladder[i][j] = 0;
			}
		}
	}
}
int main() {
	get_input();
	place_ladder(1, 0);
	printf("%d\n", res);
}*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, h, res = 4;
int ladder[40][20];
void get_input() {
	int a, b;
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		ladder[a][b] = 1;
	}
}
int min(int a, int b) {
	return a < b ? a : b;
}
int connection_check() {
	int x;
	for (int i = 1; i <= n; i++) {
		x = i;
		for (int j = 1; j <= h; j++) {
			if (ladder[j][x - 1] == 1) x--;
			else if (ladder[j][x] == 1) x++;
		}
		if (x != i) return 0;
	}
	return 1;
}
void place_ladder(int x, int y, int num) {
	if (x == h+1 || num==3) {
		if (connection_check()) {
			res = min(res, num);
		}
		return;
	}
	if (num >= res) return;
	if (ladder[x][y + 2] == 1) y + 4 >= n ? place_ladder(x + 1, 1, num) : place_ladder(x, y + 4, num);
	else if (ladder[x][y + 1] == 1) y + 3 >= n ? place_ladder(x + 1, 1, num) : place_ladder(x, y + 3, num);
	else if (ladder[x][y] == 1) y + 2 >= n ? place_ladder(x + 1, 1, num) : place_ladder(x, y + 2, num);
	else y + 1 >= n ? place_ladder(x + 1, 1, num) : place_ladder(x, y + 1, num);
	if (num >= res) return;
	if (ladder[x][y - 1] == 0 && ladder[x][y] == 0 && ladder[x][y + 1] == 0) {
		ladder[x][y] = 1;
		y + 2 >= n ? place_ladder(x + 1, 1, num + 1) : place_ladder(x, y + 2, num + 1);
		ladder[x][y] = 0;
	}
}
int main() {
	get_input();
	place_ladder(1, 0, 0);
	if (res > 3) res = -1;
	printf("%d\n", res);
}
