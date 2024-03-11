#include <iostream>
using namespace std;

int tree[10000] = { 0, };

void Postorder(int left, int right) {
	if (left >= right) return;

	int i = left + 1;

	while (i < right) {

		// 루트노드 보다 노드가 크면 오른쪽
		if (tree[left] < tree[i]) break;
		i++;
	}

	Postorder(left + 1, i);
	Postorder(i, right);
	cout << tree[left] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int i = 0;
	int t;
	while (cin >> t) {
		tree[i++] = t;
	}
	Postorder(0, i);
}