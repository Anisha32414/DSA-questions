#include <bits/stdc++.h>
using namespace std;
long long power(long long mid, int m, long long n) {
    long long ans = 1;
    for (int i = 0; i < m; i++) {
        ans *= mid;
        if (ans > n) return n + 1; 
    }
    return ans;
}

int floorRoot(int n, int m) {
    int left = 1, right = n, res = 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long val = power(mid, m, n);
        if (val <= n) {
            res = mid;      
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return res;
}

int main() {
    int n, m;
    cout << "Enter the number n ";
    cin >> n;
    cout << "Enter the value of m ";
    cin >> m;

    int ans = floorRoot(n, m);
    cout << "Floor of " << m << "-th root of " << n << " = " << ans << endl;

    return 0;
}
