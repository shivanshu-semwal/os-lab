// fcfs

#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char pname[3];
    int burst;
    int arrival;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
} queue;

void insert(queue *q) {
    node *p;
    int bt;      // burst time
    int at;      // arrival time
    char str[3]; // process name

    p = (node *)malloc(sizeof(node));

    printf("Enter the process name : ");
    scanf("%s", p->pname);

    printf("Enter Burst time : ");
    scanf("%d", &(p->burst));

    printf("Enter arrival time : ");
    scanf("%d", &(p->arrival));

    p->next = NULL;

    if (q->front == NULL) {
        q->front = p;
        q->rear = p;
    } else {
        q->rear->next = p;
        q->rear = p;
    }
}

void display(queue *q, int n) {
    node *temp = q->front;
    int wttime = 0; // wait time
    int ct = 0;     // completion time
    float turn = 0.0;

    // if queue is not empty
    if (q->front != NULL) {

        // Make Gantt chart

        printf("\n\n");
        while (temp != NULL) {
            printf("\t%s\t", temp->pname);
            temp = temp->next;
        }

        temp = q->front;
        printf("\n");
        while (temp != NULL) {
            printf("\t(%d)\t", temp->burst);
            temp = temp->next;
        }

        temp = q->front;
        printf("\n(0)\t-");
        while (temp != NULL) {
            wttime += ct;             // calculating total wait time
            turn += ct + temp->burst; // calculating turnaround time
            ct = ct + temp->burst;
            printf("-\t(%d)\t-", ct);
            temp = temp->next;
        }

        printf("\n\n");
        printf("Average wait time = %d\n", wttime / n);
        printf("Turn around time = %f\n", turn / n);
    }
}

int main() {
    int i, n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    queue *q = (queue *)malloc(sizeof(queue));

    for (i = 0; i < n; i++)
        insert(q);

    printf("Executing processes: \n");
    display(q, n);

    return 0;
}