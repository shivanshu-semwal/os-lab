// least recently use
// (lru) page replacement

#include <stdio.h>
#include <stdlib.h>

int fsize;       // frame size
int ssize;       // reference string size
int rstring[30]; // reference string
int frame[10];   // list to store the pages
int arrive[30];  // arrive time for the pages

/* return 1 if page is found in the list */
int pagefound(int x) {
    for (int i = 0; i < fsize; i++) {
        if (x == frame[i]) {
            return 1;
        }
    }
    return 0;
}

/* display the list */
void display() {
    int i;
    for (i = 0; i < fsize; i++) {
        if (frame[i] >= 0) {
            printf("%d ", frame[i]);
        } else
            printf("_ ");
    }
}

/* returns the index of page with least arrival time */
int leastused() {
    int i, min = 0;
    for (i = 0; i < fsize; i++) {
        if (arrive[i] < arrive[min]) {
            min = i;
        }
    }
    return min;
}

/* return the index at which pageno is located */
int pagelocation(int pageno) {
    int i;
    for (i = 0; i < fsize; i++) {
        if (frame[i] == pageno) {
            return i;
        }
    }
    return i;
}

int main() {
    int pf = 0; // no of page faults
    int cs = 0; // current size
    int lfi;    // last recently used page index
    int i, idx;
    int f, ls = 0;
    int j = 0, y, k, z = 0, time = 0;

    printf("LRU Page Replacement\n");

    printf("Enter the frame size: ");
    scanf("%d", &fsize);

    printf("Enter the reference string size: ");
    scanf("%d", &ssize);

    printf("Enter the reference string: ");
    for (i = 0; i < ssize; i++)
        scanf("%d", &rstring[i]);

    // initilise time and frame for page
    for (k = 0; k < fsize; k++) {
        frame[k] = -3;
        arrive[k] = 0;
    }

    for (i = 0; i < ssize; i++) {
        y = pagefound(rstring[i]);
        if (y == 0) {
            // page fault
            pf++;
            if (cs >= fsize) {
                // replace with lru page
                lfi = leastused();
                frame[lfi] = rstring[i];
                arrive[lfi] = ++time;
            } else if (cs < fsize) {
                // if list still have some space
                frame[cs] = rstring[i];
                arrive[cs] = ++time;
            }
            display();
            printf("\tMiss! %d\n", rstring[i]);
        } else {
            // page found
            idx = pagelocation(rstring[i]);
            arrive[idx] = ++time;
            display();
            printf("\tHit!! %d\n", rstring[i]);
        }
        cs++;
    }

    printf("Page fault=%d\n", pf);

    return 0;
}