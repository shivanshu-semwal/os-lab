// fifo page replacement

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int size; // current size of list
    int cs;   // counter at which to insert new page
    int nf;   // no of free pages
    int *f;   // array to store page
} list;

list *newlist(int nf) {
    list *l = (list *)malloc(sizeof(list));
    l->cs = 0;
    l->f = (int *)malloc(sizeof(int) * nf);
    l->nf = nf;
    return l;
}

int find(list *l, int x) {
    for (int i = 0; i < l->size; i++)
        if (l->f[i] == x)
            return 1;
    return 0;
}

/* 
    insert the page x 
    if full replace it with oldest page
*/
void insert(list *l, int x) {
    if (l->size < l->nf) l->size++;
    if (l->cs == l->nf)
        // list full
        l->cs = 0;
    l->f[l->cs] = x;
    l->cs++;
}

void display(list *l) {
    int i;
    for (i = 0; i < l->size; i++)
        printf("%d ", l->f[i]);
    for (i = l->size; i < l->nf; i++)
        printf("_ ");
    // printf("\n");
}

int main() {
    int pf = 0; // no of page faults
    int rfs;    // reference string length
    int *rf;    // reference string
    int i, nf;

    printf("FIFO page replacement\n");

    printf("Enter the size of reference string: ");
    scanf("%d", &rfs);

    rf = (int *)malloc(sizeof(int) * rfs);
    printf("Enter the reference string: ");
    for (i = 0; i < rfs; i++) {
        scanf("%d", &rf[i]);
    }

    printf("Enter the number of free frames: ");
    scanf("%d", &nf);

    // make a list with number of pages equal to nf
    list *l = newlist(nf);

    insert(l, rf[0]);
    display(l);
    printf("\tMiss! %d\n", rf[0]);
    pf = 1; // first page fault will always occur

    for (i = 1; i < rfs; i++) {
        if (!find(l, rf[i])) {
            // element not found
            pf++; // pagefault
            insert(l, rf[i]);
            display(l);
            printf("\tMiss! %d\n", rf[i]);
        } else {
            display(l);
            printf("\tHit!! %d\n", rf[i]);
        }
    }

    printf("No of page faults: %d\n", pf);

    return 0;
}