#include<stdio.h>
#include<string.h>
int stack[101], top = -1, n, i, x, y, z;
void push(int k) {
	if (k > 0 && stack[top] > 0) stack[top] += k;
	else stack[++top] = k;
}
int pop() { return stack[top--]; }
char a[101];
int char_to_int(char k) {
	if (k == '(') return -1;
	if (k == ')') return -3;
	if (k == '[') return -2;
	if (k == ']') return -4;
}
int main() {
	scanf("%s", &a);
	n = strlen(a);
	for (i = 0; i < n; i++) {
		x = char_to_int(a[i]);
		if (x >= -2) {
			push(x);
			continue;
		}
		if (top == -1) break;
		y = pop();
		if (y > 0) {
			z = pop();
			if (x*z == 3) push(y * 2);
			else if (x*z == 8) push(y * 3);
			else break;
		}
		else {
			if (x*y == 3) push(2);
			else if (x*y == 8) push(3);
			else break;
		}
	}
	if (i < n || top != 0 || top == 0 && stack[top] < 0) printf("0\n");
	else printf("%d\n", stack[top]);
}

/*
#include<stdio.h>
#include<string.h>
int i, j, n, m, stack[100001], top = -1, x, y, z, w, sum;
char a[100001];
void push(int k) {
	stack[++top] = k;
}
int pop() {
	if (top == -1) return -1;
	else return stack[top--];
}
int main() {
	scanf("%s", &a);
	n = strlen(a);//[][[]([])[][[]()[[]()[[[]]]]]]
	x = y = z = w = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == '(') x++;
		else if (a[i] == ')') y++;
		else if (a[i] == '[') z++;
		else if (a[i] == ']') w++;
		else break;
	}
	if (i < n || x != y || z != w) printf("0\n");
	else {
		for (i = 0; i < n; i++) {
			x = a[i];
			if (x == '(') push(2);
			else if (x == '[') push(3);
			else if (x == ')') {
				y = pop();
				if (y == 2) push(-2);
				else {
					sum = y;
					while (1) {
						y = pop();
						if (y == 2) {
							sum *= 2;
							push(sum);
							break;
						}
						else if (top == -1) break;
						sum += y;
					}
					if (top == -1) break;
				}
			}
			else {
				y = pop();
				if (y == 3) push(-3);
				else {
					sum = y;
					while (1) {
						y = pop();
						if (y == 3) {
							sum *= 3;
							push(sum);
							break;
						}
						else if (top == -1) break;
						sum += y;
					}
					if (top == -1) break;
				}
			}
		}
		sum = 0;
		while (top != -1) {
			y = pop();
			if (y == '[' || y == ']' || y == '(' || y == ')') {
				i--;
				break;
			}
			sum += y;
		}
		push(sum);
		if (i != n) printf("0\n");
		else printf("%d\n", stack[top] * -1);
	}
	scanf("%d", &n);
}
*/