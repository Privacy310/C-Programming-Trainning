#include <stdio.h>
int main(void){
    int i, j, n, s;
    char buf[8000];
    static int token1[1500][1500];
    static int edge[1500];
    int tmp = 0;
    

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d\n", &n);
    for (i=0; i<n; i++) {
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &token1[i][0], &token1[i][1], &token1[i][2], &token1[i][3], &token1[i][4], &token1[i][5], &token1[i][6], &token1[i][7], &token1[i][8], &token1[i][9], &token1[i][10], &token1[i][11], &token1[i][12], &token1[i][13], &token1[i][14], &token1[i][15], &token1[i][16], &token1[i][17], &token1[i][18], &token1[i][19], &token1[i][20], &token1[i][21], &token1[i][22], &token1[i][23], &token1[i][24], &token1[i][25], &token1[i][26], &token1[i][27], &token1[i][28], &token1[i][29]);
    }

    s = 0; 

    for (i=0; i<n; i++) {
       for (j=0; j<n; j++) {
          if(token1[i][j] > token1[i][j - 1] && token1[i][j] > token1[i - 1][j] && token1[i][j] > token1[i][j + 1] && token1[i][j] > token1[i + 1][j]) {
            edge[s] = token1[i][j];
            s++;
          }
       }
    }

    for (i=0; i<s; ++i) {
       for (j=i+1; j<s; ++j) {
          if (edge[i] < edge[j]) {
             tmp =  edge[i];
             edge[i] = edge[j];
             edge[j] = tmp;
          }
       }
    }


    for (i=0; i<s-1; i++) {
       printf("%d\n", edge[i]);
    }
    printf("%d", edge[i]);    

    return 0;
}