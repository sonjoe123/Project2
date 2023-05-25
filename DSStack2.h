//
// Created by phant on 10/24/2022.
//

#ifndef DSSTACK2_H
#define DSSTACK2_H
#include <vector>
#include <iostream>
using namespace std;
template <typename Object>
class DSStack2{
private:
    int Top = -1;
    vector<int> stack;
public:
void push_front(int value){
   stack.push_back(value);

}
void pop_front(){
    stack.pop_back();
}
Object getTail(){
    return stack[stack.size()-1];
}
bool isEmpty(){
    if(stack.size() == 0){
        return true;
    }
}

};
#endif DSSTACK2_H
//pop, push, peek, size, is empty