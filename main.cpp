#include <iostream>
#include <iomanip>
using namespace std;

struct Process {
    char pJob;
    int pArrival;
    int pCpu;
};

double calTurnaround(struct Process cArray[]) {
    int finishTime = 0;
    int turnaroundTime;
    int totalTurnaround = 0;

    cout << "\njob  Arrival Times   Cpu Cycle   Turnaround Time\n";

    for (int i = 0; i < 10; i++) {
        if (finishTime < cArray[i].pArrival) {
            finishTime = cArray[i].pArrival;
        }

        finishTime += cArray[i].pCpu;
        turnaroundTime = finishTime - cArray[i].pArrival;
        totalTurnaround += turnaroundTime;

        cout << left << setw(5) << cArray[i].pJob
             << setw(16) << cArray[i].pArrival
             << setw(12) << cArray[i].pCpu
             << turnaroundTime << endl;
    }
    double average = totalTurnaround / 10.0;

    return average;
}

int main() {
    Process jobs[10] = {
        {'A', 0, 16},
        {'B', 3, 2},
        {'C', 5, 11},
        {'D', 9, 6},
        {'E', 10, 1},
        {'F', 12, 9},
        {'G', 14, 4},
        {'H', 16, 14},
        {'I', 17, 1},
        {'J', 19, 8}
    };

    cout << "job  Arrival Times   Cpu Cycle\n";

    for (int i = 0; i < 10; i++) {
        cout << left << setw(5) << jobs[i].pJob
             << setw(16) << jobs[i].pArrival
             << jobs[i].pCpu << endl;
    }

    double average = calTurnaround(jobs);

    cout << fixed << setprecision(2);
    cout << "Average Turnaround Time:  "
         << average << endl;

    return 0;
}
