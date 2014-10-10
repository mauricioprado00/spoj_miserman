#include <cstdio>
#include <stdlib.h>

void printArray(int *, int);

int main() {
    int N, M; //N = number jumps, M = number of buses
    printf("reading sizesx\n");
    scanf("%d %d", &N, &M);

    int **sums = new int*[2];
    int **values = new int*[2];
    int i, j, k, currentPos, previousPos, best, currentAmount;


    printf("initializing arrays\n");
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
        printf("reading data stop %d (%d values)\n", j, M);
        for (i = 0; i < M; i++) {
            printf("reading one\n");
            scanf("%d", &currentAmount);
            printf("calculating best\n");
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
                        printf("newbest %d (index %d)\n", best, k);
                    }
                }
            }
            printf("best value for %d (index %d): %d  ->>> %d\n", currentAmount, i, best, best + currentAmount);
            sums[currentPos][i] = best + currentAmount;
            /**
             * 
5 5
1   3 1 2 6
10  2 5 4 15
10  9 6 7 1
2   7 1 5 3
8   2 6 1 9

             * @return 
             */
        }
        printArray(sums[currentPos], M);
        printf("-----\n");
    }
    printf("\n");
    previousPos = (j + 1) % 2;
    printArray(sums[previousPos], M);
    best = sums[previousPos][0];
    for (i = 1; i < M; i++) {
        if (best > sums[previousPos][i]) {
            best = sums[previousPos][i];
        }
    }
    printf("%d\n", best);

}

void printArray(int * array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}
/*
int main() {
    int N, M; //N = number jumps, M = number of buses
    scanf("%d %d", &N, &M);
    int spent = 0, lasti = -1, lastv = 200;
    int min, diff, i, j, current;
    for (j = 0; j < N; j++) {
        min = 101;
        lasti = M - 1;
        for (i = 0; i < M; i++) {
            if (i == lasti) continue;

            scanf("%d", &current);
            if ((current - min) < 0) {
                if (abs(lastv - current) > 1) {
                    lasti = i;
                    min = current;
                    if (current == 1) {
                        printf("broken\n");
                        break;
                    }
                }
            }
        }
        lastv = min;
        spent += lastv;
        printf("%d>", lastv);
    }
}

 */