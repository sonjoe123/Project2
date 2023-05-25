//
// Created by phant on 10/25/2022.
//

#ifndef ASSIGNMENT3_BRACKETS_CHECKING_H
#define ASSIGNMENT3_BRACKETS_CHECKING_H
#include "DSStack.h"
#include "DSStack2.h"
#include <vector>
#include <iostream>
using namespace std;
class Checking{
public:
    bool processStack(DSStack<char>& stack, char character);
    bool processVector(DSStack2<char> vector, char character);
    void checkingStack(char inputName[50]);
    void checkingVector(char inputName[50]);


};
#endif //ASSIGNMENT3_BRACKETS_CHECKING_H
