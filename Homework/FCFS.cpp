#include <iostream>
#include <iomanip>
using namespace std;

struct Process {
    char pJob;
    int pArrival;
    int pCpu;
};

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

    cout << "Job  Arrival Times  Cpu Cycle\n";

    for (int i = 0; i < 10; i++) {
        cout << jobs[i].pJob << "\t"
             << jobs[i].pArrival << "\t"
             << jobs[i].pCpu << endl;
    }

    double average = calTurnaround(jobs);

    cout << fixed << setprecision(2); cout << "Average Turnaround Time: " << average << endl;

    return 0;
}
