#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vector<int> v(s1 + s2 + s3 + 1);
    
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <=s2; j++) {
            for (int k = 1; k <= s3; k++) {
                v[i + j + k]++;
            }
        }
    }
    
    cout << max_element(v.begin(), v.end()) - v.begin();
}