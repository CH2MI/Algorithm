#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T, test_case;
	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		priority_queue<int> MaxHeap;
		priority_queue<int, vector<int>, greater<int>> MinHeap;
		int N;
		cin >> N;
		int n1, n2;
		cin >> n1;
		cout << N / 2 + 1 << '\n' << n1 << ' ';
		MaxHeap.push(n1);
		for (int i = 0; i < N / 2; i++) {
			cin >> n1 >> n2;
			if (n1 < n2) {
				MaxHeap.push(n2);
				MinHeap.push(n1);
			}
			else {
				MaxHeap.push(n1);
				MinHeap.push(n2);
			}
			if (MaxHeap.top() > MinHeap.top()) {
				n1 = MaxHeap.top();
				n2 = MinHeap.top();
				MaxHeap.pop(); MinHeap.pop();
				MaxHeap.push(n2); MinHeap.push(n1);
			}
			cout << MaxHeap.top() << ' ';
		}
		cout << '\n';
	}
}