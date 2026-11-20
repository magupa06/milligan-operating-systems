
#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

struct Process {
    char pName;
    int pArrival;
    int pCpu;
};

bool compareProcess(Process a, Process b) {
    return a.pCpu < b.pCpu;
}

double calTurnaround(list<Process> jobs) {
    int time = 0;
    double total = 0;
    int count = jobs.size();

    cout << "Job  Arrival  CPU  Turnaround" << endl;

    while (!jobs.empty()) {
        jobs.sort(compareProcess);

        auto shortest = jobs.end();

        for (auto i = jobs.begin(); i != jobs.end(); i++) {
            if (i->pArrival <= time) {
                shortest = i;
                break;
            }
        }

        if (shortest == jobs.end()) {
            time++;
        }
        else {
            time = time + shortest->pCpu;

            int turnaround = time - shortest->pArrival;
            total = total + turnaround;

            cout << shortest->pName << "    " << shortest->pArrival << "        " << shortest->pCpu << "     " << turnaround << endl;

            jobs.erase(shortest);
        }
    }

    return total / count;
}

int main() {
    Process p1 = {'A', 0, 16};
    Process p2 = {'B', 3, 2};
    Process p3 = {'C', 5, 11};
    Process p4 = {'D', 9, 6};
    Process p5 = {'E', 10, 2};
    Process p6 = {'F', 12, 9};
    Process p7 = {'G', 14, 4};
    Process p8 = {'H', 16, 14};
    Process p9 = {'I', 17, 1};
    Process p10 = {'J', 19, 8};

    list<Process> pList = {
        p1, p2, p3, p4, p5,
        p6, p7, p8, p9, p10
    };

    double average = calTurnaround(pList);

    cout << "Average Turnaround Time = " << fixed << setprecision(2) << average << endl;

    return 0;
}
