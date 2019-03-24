#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a[20010];
int n;
bool compare(string a, string b) {
	return a.length() == b.length() ? a < b : a.length() < b.length();
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, compare);
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1]) continue;
		cout << a[i] << endl;
	}
	return 0;
}