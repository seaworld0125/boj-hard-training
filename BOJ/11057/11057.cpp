#include <iostream>
using namespace std;

int dp[1010][10]; // [자릿수][0 ~ 9]

int recursive(int n, int now) {
    if(dp[n][now]) return dp[n][now];
    if(n == 1) return 1;

    dp[n][now] = 0;
    for(int i = now; i < 10; i++) {
        dp[n][now] += recursive(n - 1, i);
        dp[n][now] %= 10007;
    }
    return dp[n][now];
}

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for(int i = 0; i < 10; i++) {
        ans += recursive(N, i);
        ans %= 10007;
    }
    cout << ans;
}