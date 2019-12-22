#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class queue {
	private :
		int	*nodes;
		int head, tail;
		int len;
	public :
		queue (int size = 100) {
			nodes = new int[size];
			head = tail = 0;
			len = size;
		}
		int size () {
			return	(len-head+tail) % len;
		}
		bool empty() {
			return head == tail;
		}
		void enqueue (int o) {
			if (size() == len-1) {
				printf("Queue Overflow\n");
				exit(1);
			}
			nodes[tail] = o;
			tail = (tail + 1) % len;
		}
		int dequeue () {
			if (empty()) {
				printf("Queue Underflow\n");
				exit(1);
			}
			int p = nodes[head];
			head = (head + 1) % len;
			return p;
		}
		int front () {
			if (empty()) {
				printf("Queue Underflow\n");
				exit(1);
			}
			return nodes[head];
		}
		int back () {
			if (empty()) {
				printf("Queue Underflow\n");
				exit(1);
			}
			if (tail == 0)
				return nodes[len-1];
			else
				return nodes[tail-1];
		}
		~queue () {
			delete nodes;
		}
};

int main() {
	int size;
	cin >> size;
	queue myqueue(size);
	while (1) {
		int n;
		printf("1.enqueue\n2.deque\n3.front\n4.back\n5.empty\n6.size\n7.exit\n");
		cin >> n;
		if (n == 1) {
			int num;
			cin >> num;
			myqueue.enqueue(num);
		}
		else if (n == 2) {
			cout << myqueue.dequeue() << endl;
		}
		else if (n == 3) {
			cout << myqueue.front() << endl;
		}
		else if (n == 4) { 
			cout << myqueue.back() << endl;
		}
		else if (n == 5) {
			cout << myqueue.empty() << endl;
		}
		else if (n == 6) {
			cout << myqueue.size() << endl;
		}
		else 
			break;
	}
	
	return 0;
}
