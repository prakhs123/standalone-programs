#include <cstdio>
#include <cstdlib>

class stack {
	private:
	static const int MAXSIZE = 100;
	int s[MAXSIZE];
	int t;
	public:
	stack(void);
	int size(void);
	void push(int item);
	int empty(void);
	int pop(void);
	int top(void);
	~stack();
};

stack::stack() {
		t = -1;
	}
stack::~stack() {
		delete s;
	}
int stack:: size() {
		return t+1;
	}
void stack:: push (int item) {
		if (t == MAXSIZE-1) {
			printf("Overflow\n");
			exit(1);
		}
		s[++t] = item;
	}

int stack:: empty() {
		if (t == -1)
			return 1;
		else
			return 0;
	}

int stack:: pop() {
		if (empty()) {
			printf("Underflow\n");
			exit(1);
		}
		return s[t--];
	}

int stack:: top() {
		if (empty()) {
			printf("Underflow\n");
			exit(1);
		}
		return s[t];
	}
main()
{
	stack mystack;
	printf("%d\n", mystack.size());
	while(1) {
		int n;
		printf("1.Push\n2.Pop\n3.Top\n4.Isempty\n5.Size\n6.Exit\n");
		scanf("%d", &n);
		int flag = 0;
		switch(n) {
			case 1:
				int num;
				printf("Enter a number\n");
				scanf("%d", &num);
				mystack.push(num);
				break;
			case 2:
				printf("%d\n", mystack.pop());
				break;
			case 3:
				printf("%d\n", mystack.top());
				break;
			case 4:
				if (mystack.empty())
					printf("Empty\n");
				else
					printf("Not Empty\n");
				break;
			case 5:
				printf("%d\n", mystack.size());
				break;
			case 6:
				flag = 1;
				break;
			default:
				flag = 1;
				break;
		}
		if (flag)
			break;
	}
	return 0;
}
