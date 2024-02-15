/**
 * Subsequence test
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


void print_matrix(int** dp, int n, int m) {
    for(int i =0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}


int substring(char* s1, char* s2, int n, int m, int** dp)
{
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > res) res = dp[i][j];
            }else {
                dp[i][j] = 0;
            }
        }
        print_matrix(dp, n, m);
        printf("\n");
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char s1[] = "oaktree";
    char s2[] = "treehouse";

    int n = strlen(s1);
    int m = strlen(s2);

    int** dp = (int**)malloc((n+1) * sizeof(int*));
    for(int i = 0; i < n; i++) {
        dp[i] = (int*)calloc(m+1, sizeof(int));
    }

    print_matrix(dp, n, m);

    substring(s1, s2, n, m, dp);

    // free inner
    for(int i = 0; i < n; i++) {
        free(dp[i]);
    }
    // free outer
    free(dp);

    return 0;

}
