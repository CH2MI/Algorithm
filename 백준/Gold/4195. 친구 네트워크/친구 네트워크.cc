#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> hashmap;
vector<int> parent;
vector<int> fcount;
int mcount;

int GetIndex(const string& s) {
	auto itr = hashmap.find(s);
	if (itr != hashmap.end()) 
		return itr->second;

	int index = mcount++;
	hashmap.insert({ s, index });
	parent.push_back(-1);
	fcount.push_back(1);
	return index;
}

int Find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = Find(parent[x]);
}

int Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	if (A == B) return fcount[A] > fcount[B] ? fcount[A] : fcount[B];

	if (fcount[A] > fcount[B]) {
		parent[B] = A;
		fcount[A] += fcount[B];
		return fcount[A];
	}
	parent[A] = B; 
	fcount[B] += fcount[A];
	return fcount[B];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		hashmap.clear();
		parent.clear();
		fcount.clear();
		mcount = 0;

		int F;
		cin >> F;

		for (int i = 0; i < F; i++) {
			string A, B;
			cin >> A >> B;
			int a = GetIndex(A);
			int b = GetIndex(B);
			cout << Union(a, b) << '\n';
		}
	}
}