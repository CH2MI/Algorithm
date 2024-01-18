#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K;
	queue<int> q;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		q.push(i);
	int count = 1;
	cout << "<";
	while (!q.empty()) {
		if (count == K) {
			cout << q.front();
			if (q.size() != 1) cout << ", ";
			else cout << ">";
			q.pop();
			count = 1;
		}
		else {
			q.push(q.front());
			q.pop();
			count++;
		}
	}
}