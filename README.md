# OS-Bankers-Algorithm


This program implements the Banker's Algorithm for deadlock avoidance in resource allocation scenarios.


Source Code:
   - The source code is provided in the "banker.cpp" file and includes inlined comments to help read the code.
   - This C++ program reads input from an "input.txt" file and implements the Banker's Algorithm to determine if the system is in a safe state.
   - If the system is in a safe state, it prints the safe sequence of processes.

Input File Format:
   - The input file "input.txt" follows the following format
   - The first line contains two integers: the number of processes 5 and the number of resource types 3.
   - The next 5 lines represent the allocated resources matrix, where each line contains 3 integers representing the allocated resources for each process.
   - The next 5 lines represent the maximum resources matrix, where each line contains 3 integers representing the maximum resources that each process may request.
   - The last line contains 3 integers representing the available resources vector.



To compile and run, use the following:

g++ banker.cpp -o banker

./banker



Here is a example output in the terminal. 

![OS proj 2](https://github.com/IanE1692/OS-Bankers-Algorithm/assets/127979786/5f1fd5a8-5232-4347-8710-d0cda8c4d9cf)
