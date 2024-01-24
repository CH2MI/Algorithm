#include <cstring>
#include<iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Trie {
	static const size_t M = 26;
	static const char OFFSET = 'a';
	struct TrieNode {
		int index;
		int child[M];
		bool is_Last;
		TrieNode() {
			memset(child, -1, sizeof(int) * M);
			is_Last = false;
			index = -1;
		}
	};
	vector<TrieNode> nodes;
public:
	Trie() : nodes(1) {}
	void init() {
		nodes.resize(1);
		nodes[0] = TrieNode();
	}
	void insert(const string& str, const int& i) {
		int node_id = 0;
		for (const auto& c : str) {
			// 해당 문자열의 자식이 없으면 만들어 준다.
			if (nodes[node_id].child[c - OFFSET] == -1) {
				nodes[node_id].child[c - OFFSET] = nodes.size();
				nodes.emplace_back();
			}
			node_id = nodes[node_id].child[c - OFFSET];
		}
		// 마지막 부분임을 나타낸다.
		nodes[node_id].is_Last = true;
		nodes[node_id].index = i;
	}
	void dfs(int index, const int& k, int& count, int& value) {
		if (nodes[index].is_Last) {
			count++;
			if (k == count) {
				value = nodes[index].index;
				return;
			}
		}
		for (int i = 0; i < M; i++) {
			if (nodes[index].child[i] != -1) {
				dfs(nodes[index].child[i], k, count, value);
			}
			if (k == count) return;
		}
	}
};


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Trie trie;
		trie.init();
		set<string> set;
		int N;
		cin >> N;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 1; j <= s.size() - 0; j++) {
				set.insert(s.substr(i, j));
			}
		}
		int i = 0;
		for (auto& c : set) {
			trie.insert(c, i++);
		}
		int count = 0, value = 0;
		trie.dfs(0, N, count, value);
		cout << "#" << test_case << ' ';
		auto itr = set.begin();
		for (int j = 0; j < i; j++) {
			if (j == value) {
				cout << *itr << '\n';
				break;
			}
			itr++;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}