# Assignment: Do My Brackets Match?

**Objectives:**

* Implement a templated list data structure.
* Developing tests and automated code testing using the catch2 framework.
* Implement a stack interface.


## Time Line 
You have about three weeks to complete the assignment. Start right away! **The lab TA will expect that you already have most of that week's work completed. Come with prepared questions and
be prepared to answer the TA's questions about your code.**

* Week 1: DSList class with CATCH2 tests and memory leak debugging using `valgrind/asan`. **Deliverables:** `DSList` implementation + test
* Week 2: DSStack classes + basic bracket checking function that can check one file (just OK/not OK), `CATCH2` tests, and valgrind. **Deliverables:** `DSStack` implementation + test, checker function.
* Week 3: Detailed error messages, cleaning up code. Runtime comparison and improving the documentation comments. **Deliverables:** completed project.


## Introduction
Writing code is fun... Well, most of the time. Sometimes I mess up
brackets (i.e., `"[]", "()", "{}"`). 
I have a library of hundreds of
source code files and do not want to manually open each one up in VS Code,
so I need a program to do the checking for me.

The program should be called in the following way:

```
check_brackets <input_file>
```

It should produce the following output:

1. If no error is found: `<input_file>: OK` and return 0 (meaning the program executed successfully)
2. If an error is found: `<input_file>: Bracket mismatch detected` and return 1 (meaning there was a problem).

   Also print debugging information that is as specific as possible. For example:
     - What type of bracket is the issue.
     - The line number of the `input_file` where the issue was detected.
     - The text of the line where the issue was detected.
     - Any information that would help me to fix the issue.

## The Algorithm
Check code for balanced brackets: push `({[` on the stack and take them off when the corresponding `)`, `}`, or `)` is seen. Any error or a non-empty stack at the end of the code indicates a problem.

## The Data
 You can get some source code (e.g., from the examples in this class) and check them. Then introduce some mistakes and check again. The `data` directory contains example files.

## Implementation Requirements
Write good, well documented code!

You **cannot use STL containers for the stack.**
You need to implement two versions of the stack. 

1. A stack based on your own list class implementation
2. A stack based on an array or a `std::vector`. 

Write two programs, one based on a list and one based on a vector/array and compare the run time on some larger source code files. See [https://github.com/mhahsler/CS2341/tree/main/Chapter2_Algorithm_Analysis](https://github.com/mhahsler/CS2341/tree/main/Chapter2_Algorithm_Analysis) for examples of how to measure runtime in C++.

For strings, you can either use your own `DSString` class or the STL class `std::string`. 

## Additional Work (Bonus)
* Check all the `clang` source code from [llvm project](https://github.com/llvm/llvm-project) in the directories `clang/include/` and `clang/lib/`.
* C++ also uses `\*` and `*\` and string delimiters `"` and `'` which can be checked for consistency.
* How would you check `<>` in C++ since it is used in templates, but can also be used as 
comparison operators?
* Better testing: Can you generate an long text file that randomly nested brackets to a specified depth that you can use to test your code better?
* You could use the function call stack as the "stack" in your program and implement the checker as a recursive program. 
* Could your program make a recommendation of where to place missing brackets? How would it do that.


## Answers
1. How long did the program take with each version (You will need more than the test data)?  Describe the reason for the difference in run-time (from your experiment).

   > Your answer: 
   > With the list version: 0.00251972
   > With the vector version: 0.00228653
   > There is this difference because in linked list you have to traverse through the list and work with lots of pointers

2. Discuss the difference in memory usage based on your implementation. You will need to think about how the versions 
 store data.

   > Your answer 
   > The linked list is heavier in memory usage since it has pointers and addresses

3. Which version would you use in practice. Why?

   > Your answer
   > I would use vector in practice because it is simpler and faster than linked list

4. Make sure that your code does not have memory leaks.

  
   Paste the output of valgrind or the AddressSanitizer to show that your code is fine. 
   > I have tried everything to set up valgrind on my computer. I followed every single steps in the instruction of Matthews but i still get this thing to run
  


## Grading Rubric

|                             | Points Possible | Points Awarded |
| :------------------         | --------------: | -------------: |
| DSList Class                | 20              |                |
| CATCH2 tests DSList         |  5              |                |
| DSStack Class (List)        | 10              |                |
| DSStack Class (Vector)      |  5              |                |
| Bracket checker (OK/not OK) | 15              |                |
| CATCH2 tests checker        |  5              |                |
| Runtime comparison          |  5              |                |
| Detailed errors for checker | 10              |                |
| Answer to questions         |  5              |                |
| Proper Memory Management (valgrind) | 10      |                |
| Formatting, Comments, etc.  |  5              |                |
| Proper use of GitHub        |  5              |                |
| Early submission bonus (48 hrs)   |  + 5      |                |
| Additional Work             | up to +10       |                |

