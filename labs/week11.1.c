// priority scheduling

#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char process[3];
    int burst;
    int priority;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
} queue;

void insert(queue *q) {
    node *p, *temp;
    int b, pri;

    p = (node *)malloc(sizeof(node));

    printf("Enter the process name: ");
    scanf("%s", p->process);

    printf("Enter Burst time: ");
    scanf("%d", &(p->burst));

    printf("Enter Priority: ");
    scanf("%d", &(p->priority));
    p->next = NULL;

    /*
        inserting the new node so
        it is sorted according to
        priority
    */

    if (q->front == NULL) {
        // first element
        q->front = p;
        q->rear = p;
    } else if (p->priority < q->front->priority) {
        // at start
        p->next = q->front;
        q->front = p;
    } else if (p->priority > q->rear->priority) {
        // at end
        q->rear->next = p;
        q->rear = p;
    } else {
        // in between
        temp = q->front;
        while (p->priority > (temp->next)->priority)
            temp = temp->next;
        p->next = temp->next;
        temp->next = p;
    }
}
void display(queue *q, int n) {
    node *temp;
    int c = 0;
    float turn = 0.0, wttime = 0.0;

    if (q->front != NULL) {

        // Make Gantt chart
        
        temp = q->front;
        printf("\n\n");
        while (temp != NULL) {
            printf("\t%s\t", temp->process);
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
        printf("\n\n");
        printf("Average wait time = %f\n", wttime / n);
        printf("Turn around time = %f\n", turn / n);
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
