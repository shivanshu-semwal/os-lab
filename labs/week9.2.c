// fcfs

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
    char p[SIZE][5]; // process name
    int pt[SIZE];    // process time

    int c = 0, i, j, n;
    float at = 0.0, turn = 0.0;

    printf("Enter no of processes:");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter process %d name: ", i + 1);
        scanf("%s", &p[i][0]);

        printf("Enter process time: ");
        scanf("%d", &pt[i]);
    }

    // Make Gantt chart

    printf("\n");
    for (i = 0; i < n; i++) {
        // print process name
        printf("\t%s\t", p[i]);
    }

    printf("\n");
    for (i = 0; i < n; i++) {
        // print process time
        printf("\t(%d)\t", pt[i]);
    }

    printf("\n0\t-");
    for (i = 0; i < n; i++) {
        at += c;
        turn += c + pt[i];
        c = c + pt[i];
        printf("-\t(%d)\t-", c);
    }

    printf("\n");
    printf("Average time: %f\n", at / n);
    printf("Turn around time: %f\n", turn / n);
    return 0;
}