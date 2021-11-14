// sjf using arrays

#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
    char p[SIZE][5]; // process names
    int pt[SIZE];    // process interval

    int c = 0, i, j, n, temp1;
    float bst = 0.0, turn = 0.0;

    printf("Enter no of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter process %d name: ", i + 1);
        scanf("%s", &p[i][0]);
        printf("Enter process time: ");
        scanf("%d", &pt[i]);
    }

    // sorting according to the process time
    // using bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pt[i] > pt[j]) {
                // swap
                char temp[5];
                temp1 = pt[i];
                pt[i] = pt[j];
                pt[j] = temp1;
                strcpy(temp, p[i]);
                strcpy(p[i], p[j]);
                strcpy(p[j], temp);
            }
        }
    }

    // Make Gantt chart
    
    printf("\n\n");
    for (i = 0; i < n; i++) {
        printf("\t%s\t", p[i]);
    }

    printf("\n");
    for (i = 0; i < n; i++) {
        printf("\t(%d)\t", pt[i]);
    }

    printf("\n(0)\t-");
    for (i = 0; i < n; i++) {
        bst += c;
        turn += c + pt[i];
        c = c + pt[i];
        printf("-\t%d\t-", c);
    }

    printf("\n\n");
    printf("Average time: %f\n", bst / n);
    printf("Turn around time: %f\n", turn / n);

    return 0;
}