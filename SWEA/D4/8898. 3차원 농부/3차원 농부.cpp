#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void search(vector<int>& a, vector<int>& b, int& minimum, int& count) {
	for (int i : a) {
		int t = 1;
		auto itr1 = lower_bound(b.begin(), b.end(), i);
		auto itr2 = itr1;
		// itr1이 맨 앞 값이 아니면 직전 값도 가까운 값일 수 있다.
		if (itr1 != b.begin()) itr2--;
		// itr1이 end면 직전 값으로만 확인하면 된다.
		if (itr1 == b.end()) itr1--;

		int dis1 = abs(i - *itr1);
		int dis2 = abs(i - *itr2);
		int dis;
		// 두 개가 다르지만 거리가 같으면 두개를 올려준다.
		if (itr1 != itr2 && dis1 == dis2) {
			dis = dis1;
			t = 2;
		}
		// 그외에는 둘 중 거리가 작은 값으로 계산한다.
		else {
			dis = min(dis1, dis2);
		}
		//cout << i << ' ' << *itr1 << ' ' << *itr2 << ' ' << dis << '\n';
		// 최솟값, 개수 갱신
		if (dis < minimum) {
			minimum = dis;
			count = t;
		}
		else if (dis == minimum) {
			count += t;
		}
	}
}



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
		int N, M, c1, c2, c;
		cin >> N >> M >> c1 >> c2;
		c = abs(c1 - c2);
		vector<int> cow, horse;
		cow.reserve(N);
		horse.reserve(M);
		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			cow.push_back(t);
		}
		for (int i = 0; i < M; i++) {
			int t;
			cin >> t;
			horse.push_back(t);
		}
		int minimum = 2000000001;
		int count = 0;

		// 길이가 더 짧은 배열을 순회하면서 horse에서 가장 가까운 값들을 이진탐색으로 찾는다.
		if (N < M) {
			sort(horse.begin(), horse.end());
			search(cow, horse, minimum, count);
		}
		else {
			sort(cow.begin(), cow.end());
			search(horse, cow, minimum, count);
		}
		
		
		
		
		cout << "#" << test_case << ' ';
		cout << minimum + c << ' ' << count << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}