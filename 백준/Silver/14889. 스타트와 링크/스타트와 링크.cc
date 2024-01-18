#include <iostream>
#include <set>
#include <cmath>
using namespace std;

set<int> start, link;
int N;
int cal(int** arr) {
	int startSum = 0, linkSum = 0;
	for (auto i = start.begin(); i != start.end(); i++) {
		auto j = i;
		for (j++; j != start.end(); j++) {
			if (i != j) {
				startSum += arr[*i][*j] + arr[*j][*i];
			}
		}
	}
	for (auto i = link.begin(); i != link.end(); i++) {
		auto j = i;
		for (j++; j != link.end(); j++) {
			if (i != j) {
				linkSum += arr[*i][*j] + arr[*j][*i];
			}
		}
	}
	return abs(startSum - linkSum);
}

void dfs(int** arr, int& dif, int index) {
	if (link.size() == start.size()) {
		int t = cal(arr);
		if (dif > t) dif = t;
		return;
	}
	if (index == 0) {
		link.insert(0);
		start.erase(start.begin());
		index++;
	}
	for (int i = index; i < N; i++) {
		auto itr1 = start.find(i);
		if (itr1 == start.end()) continue;
		link.insert(*itr1);
		start.erase(itr1);
		dfs(arr, dif, i + 1);
		itr1 = link.find(i);
		start.insert(*itr1);
		link.erase(itr1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	
	cin >> N;
	int** arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
		start.insert(i);
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int dif = 100;
	dfs(arr, dif, 0);
	cout << dif;
}