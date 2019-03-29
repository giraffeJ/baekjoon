#include<stdio.h>
#include<string>
using namespace std;
int deque[20010], front=10000, back=10000, n, value;
char temp[15];
string order;
 
void push_front(int k) { deque[front--] = k; }
void push_back(int k) { deque[++back] = k; }
int pop_front() { return back == front ? -1 : deque[++front]; }
int pop_back() { return back == front ? -1 : deque[back--]; }
int size() { return back - front; }
int empty() { return back == front; }
int front_() { return back == front ? -1 : deque[front + 1]; }
int back_() { return back == front ? -1 : deque[back]; }

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &temp);
		order = temp;
		if (order == "push_front") {
			scanf("%d", &value);
			push_front(value);
		}
		else if (order == "push_back") {
			scanf("%d", &value);
			push_back(value);
		}
		else if (order == "pop_front") printf("%d\n", pop_front());
		else if (order == "pop_back") printf("%d\n", pop_back());
		else if (order == "size") printf("%d\n", size());
		else if (order == "empty") printf("%d\n", empty());
		else if (order == "front") printf("%d\n", front_());
		else if (order == "back") printf("%d\n", back_());
	}
}