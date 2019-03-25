#include<iostream>
#include<string>
using namespace std;
int stack[10010], top = -1;
int pop() {
	if (top == -1) return -1;
	return stack[top--];
}
void push(int k) {
	stack[++top] = k;
}
int top_() {
	if (top == -1) return -1;
	return stack[top];
}
int n, value;
string mode;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> mode;
		if (mode == "push") {
			cin >> value;
			push(value);
		}
		else if (mode == "pop")
			cout << pop() << endl;
		else if (mode == "top")
			cout << top_() << endl;
		else if (mode == "empty")
			cout << (top == -1) << endl;
		else if (mode == "size")
			cout << top + 1 << endl;
	}
}


/*
#include<stdio.h>
#include<string.h>
int i, j, top = -1, stack[20001], n, m;
char cmd[20];
int pop() {
	if (top != -1)	return stack[top--];
	else return -1;
}
void push(int k) {
	stack[++top] = k;
}
int isempty() {
	if (top == -1) return 1;
	else return 0;
}
int seetop() {
	if (top == -1) return -1;
	else return stack[top];
}
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", &cmd);
		if (!strcmp(cmd, "push")) {
			scanf("%d", &m);
			push(m);
		}
		if (!strcmp(cmd, "top"))
			printf("%d\n", seetop());
		if (!strcmp(cmd, "size"))
			printf("%d\n", top + 1);
		if (!strcmp(cmd, "empty"))
			printf("%d\n", isempty());
		if (!strcmp(cmd, "pop"))
			printf("%d\n", pop());
	}
	scanf("%d", &n);
}
*/