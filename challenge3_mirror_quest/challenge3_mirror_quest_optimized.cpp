#include <iostream>
#include <string>
using namespace std;

int find_longest_mirror_length(string s) {
    int n = s.length();
    static int dp[1000][1000];  // static -> stack overflow fix

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                if (len == 2)
                    dp[i][j] = 2;
                else
                    dp[i][j] = 2 + dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Longest Palindromic Subsequence Length: "
         << find_longest_mirror_length(s);

    return 0;
}
