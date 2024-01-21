#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct absolute {
	bool operator() (const long long& a, const long long& b) {
		long long a1 = abs(a);
		long long b1 = abs(b);
		if (a1 == b1) return a > b;
		return a1 > b1;
 	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<long long, vector<long long>, absolute> heap;
	int N, op, t;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> op;
		if (op) {
			heap.push(op);
		}
		else {
			if (!heap.size()) cout << "0\n";
			else {
				cout << heap.top() << '\n';
				heap.pop();
			}
		}
	}
}