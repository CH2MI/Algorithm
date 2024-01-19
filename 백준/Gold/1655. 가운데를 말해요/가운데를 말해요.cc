#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int> MaxHeap;
	priority_queue<int, vector<int>, greater<int>> MinHeap;
	int n1, n2;
	cin >> n1; 
	// 첫번째는 무조건 최대 힙에 넣는다.
	MaxHeap.push(n1);
	cout << n1 << '\n';
	for (int i = 1; i < N; i++) {
		
		cin >> n1;
		// 두 힙의 크기가 같으면 최대 힙에, 최대힙이 더 많으면 최소 힙에 넣는다.
		if (MaxHeap.size() == MinHeap.size()) MaxHeap.push(n1);
		else MinHeap.push(n1);	

		// 최대 힙의 탑과 최소 힙의 탑을 비교해서 최대 힙의 탑이 더 클 때 위치를 바꿔주면 중앙 값을 찾을 수 있다.
		n1 = MaxHeap.top(); n2 = MinHeap.top();
		if (n1 > n2) {
			MaxHeap.pop(); MinHeap.pop();
			MaxHeap.push(n2); MinHeap.push(n1);
		}
		cout << MaxHeap.top() << '\n';
	}
}