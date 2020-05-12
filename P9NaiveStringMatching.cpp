#include <iostream>
#include<cstring>
using namespace std;

void search(char *pattern, char *text);

int main() {
    char *pattern = "AABA";
    char *text = "AABAACAADAABAAABAA";
    search(pattern, text);
    return 0;
}

void search(char *pattern, char *text) {
    int M = strlen(pattern);
    int N = strlen(text);

    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == M)
            cout<<"Pattern found at index: "<<i<<endl;
    }
}