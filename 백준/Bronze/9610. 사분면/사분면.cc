#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int q[5] = { 0, };
	
	int N;
	cin >> N;
	
	for (int i = 0; i < N; ++i) {
	    int x, y;
	    cin >> x >> y;
	    
	    // 축 확인
	    if (!x || !y) ++q[0];
	    
	    else if (x > 0) {
	        
	        // 1사분면
	        if (y > 0) ++q[1];
	        
	        // 4사분면
	        else ++q[4];
	    }
	    
	    else {
	        
	        // 2사분면
	        if (y > 0) ++q[2];
	        
	        // 3사분면
	        else ++q[3];
	    }
	}
	
	cout << "Q1: " << q[1] << '\n';
	cout << "Q2: " << q[2] << '\n';
	cout << "Q3: " << q[3] << '\n';
	cout << "Q4: " << q[4] << '\n';
	cout << "AXIS: " << q[0] << '\n';
}
