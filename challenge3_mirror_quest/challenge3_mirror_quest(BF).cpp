#include <iostream>
#include <string>
using namespace std;

int lps_bruteforce(string s, int i, int j) {
    if (i > j)
        return 0;
    if (i == j)
        return 1;

    if (s[i] == s[j])
        return 2 + lps_bruteforce(s, i + 1, j - 1);
    else
        return max(lps_bruteforce(s, i + 1, j),
                   lps_bruteforce(s, i, j - 1));
}

int find_longest_mirror_length(string s) {
    return lps_bruteforce(s, 0, s.length() - 1);
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Longest Palindromic Subsequence Length: "
         << find_longest_mirror_length(s);

    return 0;
}
