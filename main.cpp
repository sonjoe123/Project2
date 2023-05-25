#include <iostream>
#include <algorithm>

#include "DSList.h"
#include "DSStack.h"
#include "Checking.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <chrono>

using namespace std;

int main(int argc, char **argv)
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start1, end1;
    Checking model;
    start1 = std::chrono::high_resolution_clock::now();
    model.checkingVector(argv[1]);
    end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time1 = end1 - start1;
    cout << time1.count() << endl;
    cout << endl;
    std::chrono::time_point<std::chrono::high_resolution_clock> start2, end2;
    start2 = std::chrono::high_resolution_clock::now();
    model.checkingStack(argv[2]);
    end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time2 = end2 - start2;
    cout << time2.count() << endl;

    return 0;

}

// in the terminal type `cd build` and then `./check_brackets test_data/*`