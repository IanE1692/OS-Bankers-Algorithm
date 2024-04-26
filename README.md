# OS-Bankers-Algorithm

This project implements the Bankers ALgoithim to avoid deadlock and allocate resources for proccesses. The source code is provided in the "bankers.cpp" file and includes inlined comments to help read the code. This C++ program reads input from an "input.txt" file and implements the Banker's Algorithm to determine if the system is in a safe state. If the system is in a safe state, it prints the safe sequence of processes. 

Source Code:
   - The source code is provided in the "bankers.cpp" file.
   - This C++ program reads input from an "input.txt" file and implements the Banker's Algorithm to determine if the system is in a safe state.
   - If the system is in a safe state, it prints the safe sequence of processes.

Input File Format:
   - The input file "input.txt" follows the following format
   - The first line contains two integers: the number of processes (n) and the number of resource types (m).
   - The next n lines represent the allocated resources matrix, where each line contains m integers representing the allocated resources for each process.
   - The next n lines represent the maximum resources matrix, where each line contains m integers representing the maximum resources that each process may request.
   - The last line contains m integers representing the available resources vector.

To compile and run, use the following:

g++ banker.cpp -o banker

./banker


Here is a example output in the terminal. 

![OS proj 2](https://github.com/IanE1692/OS-Bankers-Algorithm/assets/127979786/5f1fd5a8-5232-4347-8710-d0cda8c4d9cf)
