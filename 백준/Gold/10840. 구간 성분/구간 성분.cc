#include <iostream>
#include <vector>
#include <string>
using namespace std;

string A, B;
int Alen, Blen;
vector<int> Asum, Bsum;

bool IsSame(int a, int b, int mid) {
    int arr[26] = {0};
    for (int i = a; i < a + mid; i++) {
        arr[A[i] - 'a']++;
    }
    for (int i = b; i < b + mid; i++) {
        arr[B[i] - 'a']--;
    }
    for (auto i : arr) if (i) return false;
    return true;
}

bool solve(int mid) {
    for (int i = 1; i <= Alen - mid + 1; i++) {
        int asum = Asum[i + mid - 1] - Asum[i - 1];
        for (int j = 1; j <= Blen - mid + 1; j++) {
            int bsum = Bsum[j + mid - 1] - Bsum[j - 1];
            if (asum == bsum) {
                if (IsSame(i - 1, j - 1, mid)) return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> A >> B;
    Alen = (int)A.size();
    Blen = (int)B.size();

    Asum.assign(Alen + 1, 0);
    Bsum.assign(Blen + 1, 0);
    
    for (int i = 1; i <= Alen; i++) {
        Asum[i] = Asum[i - 1] + A[i - 1] - 'a' + 1;
    }
    for (int i = 1; i <= Blen; i++) {
        Bsum[i] = Bsum[i - 1] + B[i - 1] - 'a' + 1;
    }

    int i = min(Alen, Blen);
    for (; i > 0; i--) {
        if (solve(i)) break;
    }
    cout << i;
}