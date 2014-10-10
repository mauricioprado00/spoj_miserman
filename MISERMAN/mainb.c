#include <cstdio>
#include <stdlib.h>

int main() {
    int N, M; //N = number jumps, M = number of buses
    scanf("%d %d", &N, &M);

    int **sums = new int*[2];
    int **values = new int*[2];
    int i, j, k, currentPos, previousPos, best, currentAmount;


    //create and initialize the sum holders
    for (j = 0; j < 2; j++) {
        sums[j] = new int[M];
        values[j] = new int[M];
        for (i = 0; i < M; i++) {
            sums[j][i] = 0;
            values[j][i] = 0;
        }
    }

    for (j = 0; j < N; j++) {
        currentPos = j % 2;
        previousPos = (j + 1) % 2;
        for (i = 0; i < M; i++) {
            scanf("%d", &currentAmount);
            values[currentPos][i] = currentAmount;

            if (j == 0) {
                best = 0;
            } else {
                best = -1;

                for (k = 0; k < M; k++) {
                    if (//At every city, he has to change the bus
                            //i == k ||
                            //And he can'T switch to those buses which have number either equal or 1 less or 1 greater to the previous.
                            //abs(currentAmount - values[previousPos][k]) <= 1) {
                            abs(i - k) > 1) {
                        continue;
                    }
                    if (best == -1 || best > sums[previousPos][k]) {
                        best = sums[previousPos][k];
                    }
                }
            }
            sums[currentPos][i] = best + currentAmount;
        }
    }
    previousPos = (j + 1) % 2;
    best = sums[previousPos][0];
    for (i = 1; i < M; i++) {
        if (best > sums[previousPos][i]) {
            best = sums[previousPos][i];
        }
    }
    printf("%d\n", best);

}
