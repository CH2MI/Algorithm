#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; ++test_case) {
		multiset<int> ms;

		int N; 
		cin >> N;

		for (int i = 0; i < N; i++) {
			char c;
			int t;
			cin >> c >> t;

			// 넣을 때 오름차순 정렬해서 들어간다.
			if (c == 'I') 
				ms.insert(t);
			
			else {
				if (ms.empty()) continue;

				// 최댓값 삭제는 맨 뒤에서 삭제
				if (t == 1) {
					auto itr = ms.end();
					ms.erase(--itr);
				}
				
				// 최솟값 삭제는 맨 앞에서 삭제
				else {
					auto itr = ms.begin();
					ms.erase(itr);
				}
			}
		}
		if (ms.empty()) cout << "EMPTY\n";
		else {
			cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
		}
	}
} 