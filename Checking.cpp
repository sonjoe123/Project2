//
// Created by phant on 10/25/2022.
//

#include "Checking.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <vector>
#include "DSStack.h"
using namespace std;
bool Checking::processStack(DSStack<char> &stack, char character) {
    if (character == '{' || character == '[' || character == '(') {
        stack.push_front(character);
    }

    if (!stack.isEmpty() && character == '}' && stack.getTail() == '{') {

        stack.pop_front();
    } else if (character == '}' && stack.getTail() != '{') {
        stack.push_front(character);
        return false;
    }
    if (!stack.isEmpty() && character == ']' && stack.getTail() == '[') {

        stack.pop_front();
    } else if (character == ']' && stack.getTail() != '[') {
        stack.push_front(character);
        return false;
    }
    if (!stack.isEmpty() &&character == ')' && stack.getTail() == '(') {

        stack.pop_front();
    } else if (character == ')' && stack.getTail() != '(') {
        stack.push_front(character);
        return false;
    }
    return true;
}
bool Checking::processVector(DSStack2<char> stack, char character) {
    if (character == '{' || character == '[' || character == '(') {
        stack.push_front(character);
    }

    if (!stack.isEmpty() && character == '}' && stack.getTail() == '{') {

        stack.pop_front();
    } else if (character == '}' && stack.getTail() != '{') {
        stack.push_front(character);
        return false;
    }
    if (!stack.isEmpty() && character == ']' && stack.getTail() == '[') {

        stack.pop_front();
    } else if (character == ']' && stack.getTail() != '[') {
        stack.push_front(character);
        return false;
    }
    if (!stack.isEmpty() &&character == ')' && stack.getTail() == '(') {

        stack.pop_front();
    } else if (character == ')' && stack.getTail() != '(') {
        stack.push_front(character);
        return false;
    }
    return true;
}

void Checking::checkingStack(char inputName[50]){

    ifstream readFile(inputName);
    DSStack<char> myCharStack;
    string line;
    string wrongLine;

    bool loopBreak = true;
    int lineNumber = 0;
    while (readFile.good()) {

        getline(readFile, line);

        wrongLine = line;
        for (char character : line) {
            if (!processStack(myCharStack, character)) {
                // if error

                loopBreak = false;

                break;
            }
        }
        lineNumber+=1;
        if(!loopBreak){
            break;
        }

        // Prevent EOF bug: https://stackoverflow.com/a/21656/14426823
        if (readFile.eof()) break;
    }

if(!loopBreak) {
    cout << "<input_file>: Bracket mismatch detected" << endl;
    cout << "The wrong line is: " << wrongLine << endl;
    cout << "Line Number: " << lineNumber << endl;
    cout << "The wrong bracket is: " << myCharStack.getTail() << endl;
} else {
    cout << "<input_file>: OK" << endl;
}
}
void Checking::checkingVector(char *inputName) {

    ifstream readFile(inputName);
    DSStack<char> myCharStack;
    string line;
    string wrongLine;

    bool loopBreak = true;
    int lineNumber = 0;
    while (readFile.good()) {

        getline(readFile, line);

        wrongLine = line;
        for (char character : line) {
            if (!processStack(myCharStack, character)) {
                // if error

                loopBreak = false;

                break;
            }
        }
        lineNumber+=1;
        if(!loopBreak){
            break;
        }

        // Prevent EOF bug: https://stackoverflow.com/a/21656/14426823
        if (readFile.eof()) break;
    }

    if(!loopBreak) {
        cout << "<input_file>: Bracket mismatch detected" << endl;
        cout << "The wrong line is: " << wrongLine << endl;
        cout << "Line Number: " << lineNumber << endl;
        cout << "The wrong bracket is: " << myCharStack.getTail() << endl;
    } else {
        cout << "<input_file>: OK" << endl;
    }
}
