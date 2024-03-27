#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NO_OF_CHARS 256

// Brute-Force String Matching Algorithm
void bruteForceStringMatch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            printf("Brute-Force: Pattern found at index %d\n", i);
    }
}

// Knuth-Morris-Pratt (KMP) Algorithm
void computeLPSArray(char *pattern, int m, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPStringMatch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m];
    computeLPSArray(pattern, m, lps);

    int i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == m) {
            printf("KMP: Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

// Boyer-Moore Algorithm
int max(int a, int b) {
    return (a > b) ? a : b;
}

void badCharHeuristic(char *pattern, int m, int badchar[NO_OF_CHARS]) {
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
    for (i = 0; i < m; i++)
        badchar[(int) pattern[i]] = i;
}

void boyerMooreStringMatch(char *text, char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    int badchar[NO_OF_CHARS];

    badCharHeuristic(pattern, m, badchar);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j])
            j--;
        if (j < 0) {
            printf("Boyer-Moore: Pattern found at index %d\n", s);
            s += (s + m < n) ? m - badchar[text[s + m]] : 1;
        } else
            s += max(1, j - badchar[text[s + j]]);
    }
}

int main() {
    char text[1000], pattern[100];
    printf("Enter the text: ");
    scanf("%[^\n]%*c", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    bruteForceStringMatch(text, pattern);
    KMPStringMatch(text, pattern);
    boyerMooreStringMatch(text, pattern);

    return 0;
}
