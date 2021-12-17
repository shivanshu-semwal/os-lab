#include <iostream>
using namespace std;

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int bt[] = {10, 5, 8};
    int quantum = 2;

    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    int rem_bt[n]; // copy of burst time
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0; // Current time

    while (1) {
        bool done = true; // assume all are done
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = false; // There is a pending process
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true) break;
    }

    for (int i = 0; i < n; i++) tat[i] = bt[i] + wt[i];

    cout << "Processes | Burst time | Waiting time | Turn around time\n";

    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i + 1 << "\t" << bt[i] << "\t " << wt[i] << "\t " << tat[i] << endl;
    }

    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;

    return 0;
}

