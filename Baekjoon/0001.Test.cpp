#include<string>
#include<iostream>
using namespace std;
char c[110];
string add(string a, string b) {
	int n = a.length();
	int m = b.length();
	int index = 101;
	int x, y;
	string res = "";
	while (1) {
		x = y = 0;
		if (n>0) x = a[n - 1] - '0';
		if (m>0) y = b[m - 1] - '0';
		if (n == 0 && m == 0) break;
		if (x + y >= 10) {
			c[index] = c[index] + x + y - 10 + '0';
			c[index - 1]++;
		}
		else if (x + y == 9 && c[index] == 1) {
			c[index] = '0';
			c[index - 1]++;
		}
		else c[index] = c[index] + x + y + '0';
		if (n>0) n--;
		if (m>0) m--;
		index--;
	}
	if (c[index] == 1) c[index--] = '1';
	for (int i = index + 1; i <= 101; i++) {
		res += c[i];
		c[i] = 0;
	}
	return res;
}
int main() {
	int k;
	int a[10] = { 0, 1, 2, 3 };
	int i = 1;
	printf("%d\n", a[(i++) + 1]);
	/*
	string a, b;
	string res, ans;
	while (1) {
		printf("input : ");
		cin >> a >> b;
		printf("true answer : ");
		cin >> ans;
		res = add(a, b);
		cout << "function result : " << res << "." << endl;
		if (ans == res) cout << "Correct!" << endl;
		else cout << "Wrong answer!" << endl;
		cout << "exit ? (1)test again ? (2) : ";
		cin >> k;
		if (k == 1) break;
	}
	*/
}

/*
99999¡¦x100
99999x100
199¡¦998

0 0
0
0

999999
111111
1111110

45
55
100

85462
333
85795

0
9999
9999

111
92857
92968

99999999999
1
100000000000






58239473 810294839
471375 372529139
118281

*/