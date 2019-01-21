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