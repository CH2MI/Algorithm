#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int left;
	int right;
	TreeNode() {
		left = -1;
		right = -1;
	}
};

vector<TreeNode> tree;

void VLR(int index) {
	if (index == -1) return;

	cout << (char)(index + 'A');
	VLR(tree[index].left);
	VLR(tree[index].right);
}

void LVR(int index) {
	if (index == -1) return;

	LVR(tree[index].left);
	cout << (char)(index + 'A');
	LVR(tree[index].right);
}

void LRV(int index) {
	if (index == -1) return;

	
	LRV(tree[index].left);
	LRV(tree[index].right);
	cout << (char)(index + 'A');
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	tree.assign(26, TreeNode());

	for (int i = 0; i < N; i++) {
		char A, B, C;
		cin >> A >> B >> C;
		if (B != '.') tree[A - 'A'].left = B - 'A';
		if (C != '.') tree[A - 'A'].right = C - 'A';
	}

	VLR(0);
	cout << '\n';

	LVR(0);
	cout << '\n';

	LRV(0);
}