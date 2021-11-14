// sjf using pointers

#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char name[3];
    int burst;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
} queue;

void insert(queue *q) {
    node *p, *temp;

    p = (node *)malloc(sizeof(node));

    printf("Enter the process name: ");
    scanf("%s", p->name);

    printf("Enter Burst time: ");
    scanf("%d", &(p->burst));
    p->next = NULL;

    if (q->front == NULL) {
        // first element
        q->front = p;
        q->rear = p;
    } else if (p->burst < q->front->burst) {
        // insert in front
        p->next = q->front;
        q->front = p;
    } else if (p->burst > q->rear->burst) {
        // insert at last
        q->rear->next = p;
        q->rear = p;
    } else {
        // insert in between
        temp = q->front;
        while (p->burst > (temp->next)->burst)
            temp = temp->next;
        p->next = temp->next;
        temp->next = p;
    }
}

void display(queue *q, int n) {
    node *temp = q->front;
    int c = 0;
    float turn = 0.0, wttime = 0.0;
    if (q->front != NULL) {

        // Make Gantt chart

        printf("\n\n");
        while (temp != NULL) {
            printf("\t%s\t", temp->name);
            temp = temp->next;
        }

        temp = q->front;
        printf("\n");
        while (temp != NULL) {
            printf("\t(%d)\t ", temp->burst);
            temp = temp->next;
        }

        temp = q->front;
        printf("\n(0)\t-");
        while (temp != NULL) {
            wttime += c;
            turn += c + temp->burst;
            c = c + temp->burst;
            printf("-\t(%d)\t-", c);
            temp = temp->next;
        }
        printf("\n");
        printf("Average waiting time: %f\n", wttime / n);
        printf("Turn around time: %f\n", turn / n);
    }
}

int main() {
    int i, n;
    queue *q = (queue *)malloc(sizeof(queue));

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        insert(q);

    printf("Executing processes: \n");
    display(q, n);
    return 0;
}