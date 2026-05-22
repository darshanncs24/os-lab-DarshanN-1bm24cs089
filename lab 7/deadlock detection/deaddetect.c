#include <stdio.h>
#include <stdbool.h>

#define P 5
#define R 3

int main() {
    int alloc[P][R] ;
    int request[P][R];
    int avail[R] ;
    bool finish[P] = {false};
    int work[R];
 printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
 printf("Enter Request Matrix:\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            scanf("%d", &request[i][j]);
        }
    }
    printf("Enter Available Resources:\n");
    for (int i = 0; i < R; i++) {
        scanf("%d", &avail[i]);
    }
    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }
    int count = 0;
    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < R; j++) {
                    if (request[i][j] > work[j])
                        break;
                }
                if (j == R) {
                    for (int k = 0; k < R; k++) {
                        work[k] += alloc[i][k];
                    }
                    finish[i] = true;
                    found = true;
                    count++;
                    printf("P%d is completed\n", i);
                }
            }
        }
        if (!found)
            break;
    }
    bool deadlock = false;
    for (int i = 0; i < P; i++) {
        if (!finish[i]) {
            deadlock = true;
            printf("P%d is in Deadlock\n", i);
        }
    }
    if (!deadlock)
        printf("No Deadlock Detected\n");

    return 0;
}