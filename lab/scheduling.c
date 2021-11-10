#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;            // id for the process
    int val;           // time duration for the process
    struct node *next; // next process
} nodetype;

/*
    enqueue an element in the queue
*/
nodetype *enqueue(nodetype *rear) {
    nodetype *p;
    int m, n;
    printf("Enter an (ID, value) [-1 to stop]:");
    scanf("%d %d", &n, &m);

    if (n == -1) return NULL;

    p = (nodetype *)malloc(sizeof(nodetype));
    if (p != NULL) {
        p->id = n;
        p->val = m;
        if (rear == NULL)
            rear = p;
        else {
            rear->next = p;
            rear = p;
        }
        rear->next = NULL;
    } else {
        printf("Failed to allocate memory.");
        return NULL;
    }
    return rear;
}

/* 
    remove a node with val = 0 or -1
*/
void del(nodetype *p) {
    if (p == NULL) return;

    int t = 0, pos = 0;
    nodetype *ptr = p;
    nodetype *ptr_next = ptr->next;

    while (ptr_next != NULL) {
        if (ptr_next->val == 0 || ptr_next->val == -1) break;
        ptr = ptr->next;
        ptr_next = ptr_next->next;
    }
    if (ptr == p) {
        if (p->val == 0 || p->val == -1) {
            // remove it
            printf("Job with ID %d and time %d will be removed.\n", p->id, p->val);
            free(p);
            return;
        }
    } else if (ptr_next == NULL) {
        return;
    } else {
        // remove ptr_next
        printf("Job with ID %d and time %d will be removed.\n", ptr_next->id, ptr_next->val);
        ptr->next = ptr_next->next;
        free(ptr_next);
        return;
    }
}

// void fcfs(nodetype *p) {
//     printf("\n\nRoundRobin Will Start on the following List:\n");
//     printf("Linked List Contain the following values:\n");
//     while (p != NULL) {
//         printf("Node ID %d with value %d\n", p->id, p->val);
//         p = p->next;
//     }
//     printf("\n\n");
// }

void round_robin(nodetype *p, int z) {

    nodetype *temp = p;
    nodetype *temp2;

    while (p != NULL) {
        temp2 = p;
        while (temp2 != NULL) {
            printf("Current Node %d :time value before %d, after quantum %d\n", temp2->id, temp2->val, (temp2->val) - z);
            temp2->val = (temp2->val) - z;
            temp2 = temp2->next;
        }

        for (int i = 0; i < 20; i++) printf("#");
        printf("\n");

        temp = p;
        temp2 = p->next;

        // for start element
        while (temp->val <= 0) {
            //remove it
            printf("removing process: id=%d, val=%d\n", temp->id, temp->val);
            free(temp);

            if (temp2 == NULL) {
                // no elements are remaining
                p = NULL;
                break;
            }

            // new value
            temp = temp2;
            p = temp2;

            temp2 = temp->next;
        }
        // rest of the elements
        while (temp2 != NULL) {
            // removing temp2 if val is less
            if (temp2->val <= 0) {
                // remove temp2
                temp->next = temp2->next;
                printf("removing process: id=%d, val=%d\n", temp2->id, temp2->val);
                free(temp2);
                temp2 = temp->next;
                continue;
            }
            temp = temp->next;
            temp2 = temp->next;
        }

        for (int i = 0; i < 20; i++) printf("#");
        printf("\nIteration completed, RoundRobin Will Start from begining of the list\n\n");
    }
}

int main() {
    nodetype *first = NULL, *last = NULL;

    printf("Round Robin simulation program\n");

    int q;
    printf("Enter a quantum Value to be used:");
    scanf("%d", &q);

    /* taking values */
    while (1) {
        nodetype *temp = enqueue(last);
        if (temp == NULL)
            break;
        else
            last = temp;
        if (first == NULL) first = last;
    }

    // fcfs(first);
    round_robin(first, q);
    printf("\n\nRoundRobin:: All Jobs Completed");
    return 0;
}