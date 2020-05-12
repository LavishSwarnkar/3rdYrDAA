#include<bits/stdc++.h>

using namespace std;

void print_answer(int i, int j, int n, int *b, char &name);
void calc_min_cost(const int *p, int n);

int main() {
    int a[] = {30, 35, 15, 5, 10};
    calc_min_cost(a, sizeof(a) / sizeof(a[0]));
    return 0;
}

void print_answer(int i, int j, int n, int *b, char &name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    print_answer(i, *((b + i * n) + j), n, b, name);
    print_answer(*((b + i * n) + j) + 1, j, n, b, name);
    cout << ")";
}

void calc_min_cost(const int *p, int n) {
    int m[n][n];
    int bracket[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    char name = 'A';
    cout<<"Answer = ";
    print_answer(1, n - 1, n, (int *) bracket, name);
    cout<<endl<<"Min Cost is : " << m[1][n - 1];
}