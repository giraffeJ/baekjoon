#include<stdio.h>
//#include<iostream>
#include<map>
using namespace std;
map<char, int> trans = { {'U', 1}, {'D', 2}, {'F', 3}, {'B', 4}, {'L', 5}, {'R', 6}, {'-', 0}, {'+', 1} };
map<int, char> color = { {1, 'w'}, {2, 'y'}, {3, 'r'}, {4, 'o'}, {5, 'g'}, {6, 'b'} };
int tcn, n;
int cube[7][4][4];
int rotation_table[2][4][4] = { { {0, 0, 0, 0}, {0, 3, 6, 9}, {0, 2, 5, 8}, {0, 1, 4, 7} }, {{0, 0, 0, 0}, {0, 7, 4, 1}, {0, 8, 5, 2}, {0, 9, 6, 3}} };
int coor[10][2] = { {0, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3} };
int rot_seq[7][2][5] = { {0, 0, 0, 0, 0}, {{0, 3, 5, 4, 6}, {0, 3, 6, 4, 5}}, {{0, 3, 6, 4, 5}, {0, 3, 5, 4, 6}}, {{0, 1, 6, 2, 5}, {0, 1, 5, 2, 6}}, {{0, 1, 5, 2, 6}, {0, 1, 6, 2, 5}}, {{0, 1, 3, 2, 4}, {0, 1, 4, 2, 3}}, {{0, 1, 4, 2, 3}, {0, 1, 3, 2, 4}} };
int rot_num[7][2][5] = { {0, 0, 0, 0, 0}, {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}, {{0, 1, 1, 1, 1}, {0, 1, 1, 1, 1}}, {{0, 1, 2, 1, 4}, {0, 1, 4, 1, 2}}, {{0, 5, 2, 5, 4}, {0, 5, 4, 5, 2}}, {{0, 2, 2, 4, 4}, {0, 2, 4, 4, 2}}, {{0, 4, 2, 2, 4}, {0, 4, 4, 2, 2}} };
int rot_type[10][3] = { {1, 2, 3}, {7, 8, 9}, {1, 4, 7}, {9, 8, 7}, {9, 6, 3}, {3, 2, 1}, {7, 4, 1}, {3, 6, 9} };
void cube_init() {
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				cube[i][j][k] = i;
			}
		}
	}
}
void cubing(int pos, int dir) {
	int temp[4][4];
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			temp[i][j] = cube[pos][coor[rotation_table[dir][i][j]][0]][coor[rotation_table[dir][i][j]][1]];
		}
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cube[pos][i][j] = temp[i][j];
		}
	}
	int temp2[4];
	for (int i = 0; i < 3; i++) {
		temp2[i] = cube[rot_seq[pos][dir][1]][coor[rot_type[rot_num[pos][dir][1]][i]][0]][coor[rot_type[rot_num[pos][dir][1]][i]][1]];
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[rot_seq[pos][dir][i]][coor[rot_type[rot_num[pos][dir][i]][j]][0]][coor[rot_type[rot_num[pos][dir][i]][j]][1]] = cube[rot_seq[pos][dir][i + 1]][coor[rot_type[rot_num[pos][dir][i + 1]][j]][0]][coor[rot_type[rot_num[pos][dir][i + 1]][j]][1]];
		}
	}
	for (int i = 0; i < 3; i++) {
		cube[rot_seq[pos][dir][4]][coor[rot_type[rot_num[pos][dir][4]][i]][0]][coor[rot_type[rot_num[pos][dir][4]][i]][1]] = temp2[i];
	}
}
void print_upper_side() {
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			//cout << color[cube[1][i][j]];
			printf("%c", color[cube[1][i][j]]);
		}
		//cout << endl;
		printf("\n");
	}
}
int main() {
	//cin >> tcn;
	scanf("%d", &tcn);
	char pos, dir;
	for (int tc = 1; tc <= tcn; tc++) {
		cube_init();
		//cin >> n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			//cin >> pos >> dir;
			scanf(" %c%c", &pos, &dir);
			cubing(trans[pos], trans[dir]);
		}
		print_upper_side();
	}
	
}