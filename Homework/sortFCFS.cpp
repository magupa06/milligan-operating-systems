#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Process {
    char pJob;
    int pArrival;
    int pCpu;
};

bool compareProcess(Process p1, Process p2) {
    if (p1.pCpu < p2.pCpu) {
        return true;
    }
    return false;
}

double calTurnaround(Process cArray[]) {
    int finishTime = 0;
    int turnaround = 0;
    int total = 0;

    cout << "\nJob  Arrival Times  Cpu Cycle  Turnaround Time\n";

    for (int i = 0; i < 10; i++) {
        finishTime = finishTime + cArray[i].pCpu;

        turnaround = finishTime - cArray[i].pArrival;

        total = total + turnaround;

        cout << cArray[i].pJob << "\t" << cArray[i].pArrival << "\t" << cArray[i].pCpu << "\t" << turnaround << endl;
    }

    return total / 10.0;
}

int main() {
    Process jobs[10] = {
        {'A', 0, 16},
        {'B', 0, 2},
        {'C', 0, 11},
        {'D', 0, 6},
        {'E', 0, 1},
        {'F', 0, 9},
        {'G', 0, 4},
        {'H', 0, 14},
        {'I', 0, 1},
        {'J', 0, 8}
    };

    cout << "Job  Arrival Times  Cpu Cycle\n";

    for (int i = 0; i < 10; i++) {
        cout << jobs[i].pJob << "\t"
             << jobs[i].pArrival << "\t"
             << jobs[i].pCpu << endl;
    }

    sort(jobs, jobs + 10, compareProcess);

    double average = calTurnaround(jobs);

    cout << fixed << setprecision(2); cout << "Average Turnaround Time: " << average << endl;

    return 0;
}
