// priority scheduling

#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
    char p[10][5]; // process name
    int pt[SIZE];  // process time
    int pr[SIZE];  // process priority

    int c = 0, i, j, n;
    char temp[5];
    float bst = 0.0, turn = 0.0;

    printf("Enter no of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter process %d name: ", i + 1);
        scanf("%s", &p[i][0]);
        printf("Enter process time: ");
        scanf("%d", &pt[i]);
        printf("Enter the priority of process: ");
        scanf("%d", &pr[i]);
    }

    // sort by priority
    // bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                // swap
                int temp1 = pt[i];
                pt[i] = pt[j];
                pt[j] = temp1;
                int t = pr[i];
                pr[i] = pr[j];
                pr[j] = t;
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
    printf("\n(0)-\t");
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