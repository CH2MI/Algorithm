#include <iostream>
#include <vector>
using namespace std;

vector<int> seq;
vector<int> op;

void cal(vector<int> tmpOp, int& min, int& max) {
	int sum = seq[0];
	for (int i = 0; i < tmpOp.size(); i++) {
		if (tmpOp[i] == 0)
			sum += seq[i + 1];
		else if (tmpOp[i] == 1)
			sum -= seq[i + 1];
		else if (tmpOp[i] == 2)
			sum *= seq[i + 1];
		else
			sum /= seq[i + 1];
	}
	if (sum < min) min = sum;
	if (sum > max) max = sum;
}

void dfs(vector<bool> selected, vector<int> tmpOp, int selcount, int count, int N, int& min, int& max) {
	if (count == N) return;

	for (int i = 0; i < op.size(); i++) {
		if (!selected[i]) {
			selected[i] = true;
			selcount++;
			tmpOp.push_back(op[i]);
			if (selcount < op.size()) dfs(selected, tmpOp, selcount, count, N, min, max);
			else {
				count++;
				cal(tmpOp, min, max);
			}
			selcount--;
			selected[i] = false;
			tmpOp.erase(--tmpOp.end());
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	vector<bool> selected;
	vector<int> tmpOp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		seq.push_back(t);
	}
	for (int i = 0; i < 4; i++) {
		int t;
		cin >> t;
		for (int j = 0; j < t; j++) {
			op.push_back(i);
			selected.push_back(false);
		}
	}
	int min = 1000000001, max = -1000000001;
	int N = 1;
	for (int i = 1; i < n; i++) {
		N *= i;
	}
	dfs(selected, tmpOp, 0, 0, N, min, max);
	cout << max << '\n' << min;
}