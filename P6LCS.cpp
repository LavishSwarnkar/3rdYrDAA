#include <bits/stdc++.h>
using namespace std;

int L[100][100];
set<string> get_all_lcs(string s1, string s2, int m, int n);
int get_lcs_len(string X, string Y, int m, int n);

int main() {
    string s1 = "PLDDSS", s2 = "PSS";
    int m = s1.length()
            , n = s2.length();

    cout << "LCS length = " << get_lcs_len(s1, s2, m, n) << endl;
    set<string> lcs = get_all_lcs(s1, s2, m, n);
    for (const string& str : lcs)
        cout << str << endl;

    return 0;
}

set<string> get_all_lcs(string s1, string s2, int m, int n) {
    set<string> lcs;
    if (m == 0 || n == 0){
        lcs.insert("");
        return lcs;
    }

    if (s1[m - 1] == s2[n - 1]) {
        set<string> tmp = get_all_lcs(s1, s2, m - 1, n - 1);
        for (const string& s : tmp)
            lcs.insert(s + s1[m - 1]);
    } else {
        if (L[m - 1][n] >= L[m][n - 1])
            lcs = get_all_lcs(s1, s2, m - 1, n);

        if (L[m][n - 1] >= L[m - 1][n]) {
            set<string> tmp = get_all_lcs(s1, s2, m, n - 1);
            lcs.insert(tmp.begin(), tmp.end());
        }
    }
    return lcs;
}

int get_lcs_len(string X, string Y, int m, int n){
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}