#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
	string name;
	unordered_map<string, int> childs;
};

vector<Node> Folders;
int Findex;

int main() {
	int T; cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int N, M;
		cin >> N >> M;

		Folders.clear();
		Findex = 1;
		Folders.push_back({ "/", unordered_map<string, int>() });
		for (int k = 0; k < N; k++) {
			string s; cin >> s;
			int i = 1;
			int j = 0;
			while (i < s.size()) {
				string t;
				while (i < s.size() && s[i] != '/') {
					t.push_back(s[i++]);
				}
				if (Folders[j].childs.find(t) == Folders[j].childs.end()) {
					Folders.push_back({ t, unordered_map<string, int>() });
					Folders[j].childs.insert({ t, Findex++ });
				}
				j = Folders[j].childs[t];
				i++;
			}
		}
		
		int cnt = 0;
		for (int k = 0; k < M; k++) {
			string s; cin >> s;
			int i = 1;
			int j = 0;
			while (i < s.size()) {
				string t;
				while (i < s.size() && s[i] != '/') {
					t.push_back(s[i++]);
				}
				if (Folders[j].childs.find(t) == Folders[j].childs.end()) {
					Folders.push_back({ t, unordered_map<string, int>() });
					Folders[j].childs.insert({ t, Findex++ });
					cnt++;
				}
				j = Folders[j].childs[t];
				i++;
			}
		}
		cout << "Case #" << tc + 1 << ": " << cnt << '\n';
	}
}