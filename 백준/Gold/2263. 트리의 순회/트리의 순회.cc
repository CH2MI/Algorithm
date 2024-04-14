#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> inorder, postorder;
int N;

void recursion(int is, int ie, int ps, int pe) {
	if (ie < is || pe < ps) return;

	cout << postorder[pe] << ' ';

	int i = find(inorder.begin() + is, inorder.begin() + ie + 1, postorder[pe]) - inorder.begin();
	
	int n = i - 1 - is;

	recursion(is, i - 1, ps, ps + n);
	recursion(i + 1, ie, ps + n + 1, pe - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	inorder.assign(N, 0);
	postorder.assign(N, 0);

	for (int i = 0; i < N; i++) cin >> inorder[i];
	for (int i = 0; i < N; i++) cin >> postorder[i];

	recursion(0, N - 1, 0, N - 1);
}