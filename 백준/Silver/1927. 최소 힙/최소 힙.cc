#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<long long, vector<long long>, greater<long long>> heap;
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