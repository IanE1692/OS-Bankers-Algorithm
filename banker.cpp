// Ian Esselburn
// OS project 2 
// Bankers Algorithm

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if the system is in a safe state using Banker's Algorithm
bool isSafeState(const vector<vector<int>>& alloc, const vector<vector<int>>& max, const vector<int>& avail) {
    int n = alloc.size(); // Number of processes
    int m = avail.size(); // Number of resource types

    vector<int> work(avail); // Available resources
    vector<bool> finish(n, false); // Flag to track if process is finished

    vector<int> safeSequence; // Safe sequence

    // Iterate until all processes are finished or deadlock detected
    bool deadlock = false;
    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < m; ++j) {
                    if (max[i][j] - alloc[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < m; ++j)
                        work[j] += alloc[i][j];
                    safeSequence.push_back(i);
                    finish[i] = true;
                    found = true;
                    ++count;
                }
            }
        }
        if (!found) {
            deadlock = true;
            break;
        }
    }

    // if deadlock detected, system is not in a safe state
    if (deadlock)
        return false;

    // system is in a safe state
    cout << "System is in a safe state" << endl;
    cout << "Safe sequence: ";
    for (int i = 0; i < n; ++i) {
        cout << "P" << safeSequence[i];
        if (i != n - 1)
            cout << " -> ";
    }
    cout << endl;
    return true;
}

int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    int n, m;
    file >> n >> m;

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> max(n, vector<int>(m));
    vector<int> avail(m);

    // read allocated resources matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            file >> alloc[i][j];

    // read maximum resources matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            file >> max[i][j];

    // read available resources vector
    for (int j = 0; j < m; ++j)
        file >> avail[j];

    // check if the system is in a safe state using Algorithm
    if (!isSafeState(alloc, max, avail))
        cout << "System is not in a safe state." << endl;

    return 0;
}
