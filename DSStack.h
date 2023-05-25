// Implement a class that provides a stack interface for your DSLists class.
#ifndef DSStack_h
#define DSStack_h
#include "DSList.h"
template <typename Object>
class DSStack : public DSList<Object>{
private:


public:
    //Default constructor
    DSStack() : DSList<Object>(){

    }
    //Overload constructor
    DSStack(Object Obj) : DSList<Object>(Obj){

    }
    //Destructor
    ~DSStack(){

    }
    //Copy constructor
    DSStack(const DSStack<Object> &copyObj) : DSList<Object>(copyObj){

    }

};

#endif