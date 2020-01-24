## Stacks and Queues

### Makefile and project structure

Well, it's time we dig a little bit deep into the build system. The following links and extentions (for VSCode) should help - 

 - [Video on Introduction to GNU make,*Coursera*](https://www.coursera.org/lecture/introduction-embedded-systems/7-makefiles-part-1-4d7SV)
 - [C/C++ project generator with Makefile generator, *VSCode Extention Marketplace*](https://marketplace.visualstudio.com/items?itemName=danielpinto8zz6.c-cpp-project-generator). However, you should first know to make all what this does manually. 
 - `make` is intelligent to figure out the dependencies of header files.
 - [`shell` function, *GNU dot org*](https://www.gnu.org/software/make/manual/html_node/Shell-Function.html)
 - [`patsubst pattern,replacement, text` function, *GNU dot org*](https://www.gnu.org/software/make/manual/html_node/Text-Functions.html)
 - [`var:pattern=replacement` Substitution Reference, *GNU dot org*](https://www.gnu.org/software/make/manual/html_node/Substitution-Refs.html#Substitution-Refs)
 - `find`, shell command, use `man` pages to know more.
 - `$^` all prerequisites, `$@` the target, `$<` first prerequisite

### Default Constructor 
```
class Stack {
private:
    int j;
    StackNode *top;
public:
    Stack::Stack() {
        std::cout<<top<<j;
        }
```
The data members are initialized to zero by default if no initialization is provided.
The following line of code - 

`Stack* myOtherStack = new Stack();`

outputs - 

```
00
```

`0` for `top` means `NULL`.

### What to return when the data structure is empty?

It depends on your implementation. The STL's `pop()` has `void` as return type. It does something interesting. However, the user must call `isEmpty()` before calling `pop()`, i.e. the precondition must be met. I have aborted with `exit(1)`.
 - [an exception, a unique value, NULL,or abort?,*Stackoverflow*](https://stackoverflow.com/questions/7390126/what-should-the-pop-method-return-when-the-stack-is-empty)

### Inheritance

  - [In order to override them, the inherited member functions should be declared in the child class also, *Stackoverflow*](https://stackoverflow.com/questions/15117591/why-is-inherited-member-not-allowed)
  - [Struct Inheritance is same as class inheritance in C++, *Stackoverflow*](https://stackoverflow.com/questions/979211/struct-inheritance-in-c)

### Operator overloading

 - [Syntax, *Geeks for geeks*](https://www.geeksforgeeks.org/operator-overloading-c/)
    
    ```
    bool operator<(date_of_arrival const &other)
    ```
    Remember operator functions are different and are declared outside the class. Also, if the operator function needs to access the private members of the class, then it should be declared as a `friend` to the class.
    An operator function would look like - 

    ```
    bool operator<(date_of_arrival const &first ,date_of_arrival const &other)
    ```

 - [We can do everything with a `struct` what we can do with a `class` in C++ (not C). The only difference being that by default, the members are public in `struct`, *Stackoverflow*](https://stackoverflow.com/questions/13480135/operator-overloading-in-struct)

### Initialize private static members in a `class`
 - [Do it outside all functions and in the `.cpp` file, not in the header file, *Stackoverflow*](https://stackoverflow.com/questions/185844/how-to-initialize-private-static-members-in-c)

### `typedef` in C++

 - [To declare a typename, *Blog*](https://www.codesdope.com/cpp-typedef/)

```
 typedef struct date_of_arrival {
  int dd;
  int mm;
  int yyyy;
  bool operator<(date_of_arrival const &other) {

    if (yyyy < other.yyyy)
      return true;
    if (yyyy == other.yyyy && mm < other.mm)
      return true;
    if (yyyy == other.yyyy && mm == other.mm && dd < other.dd)
      return true;
    return false;
  }
} date;

```

Now `date` is a typename just as `int`, `class`, `float`, etc.

### Templates in C++

 - [A reference, for quick go-through through examples, *cplusplus dot com*](http://www.cplusplus.com/doc/oldtutorial/templates/)
 ...use of either the keyword `class` or the keyword `typename`. Its use is indistinct, since both expressions have exactly the same meaning and behave exactly the same way.

### Template member function definition outside of its class template

 - [The syntax is shown below,*IBM Knowledge Center*](https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/member_function_templates.htm)
 
 the declaration in header file looks like -

```
 template <class T> class Stack {
  public:
    T pop();
    void push(T data);
    ...
```

the definition in `.cpp` file would look like - 

```
  template <class T> T Stack<T>::pop(){
      ...
  }

  template <class T> void Stack<T>::push(T data){
      ...
  }
```

### Template functions

  > Source: Balagurusamy book

in header file

```
template <class T> void printStack(Stack<T>* myStack);
```

in source file

```
template <class T> void printStack(Stack<T>* myStack){
    if(myStack !=NULL){
        T* top = myStack->getTopNode();
        ...
```

Explicit template function instantiation syntax - 

```
template return-type function-name<template arguments>(function arguments);
```

Explicit template class instantiation syntax -

```
template class class-name<template arguments>;
```

 - [These explicit instantiations should be done at the end of `.cpp` file which contains the function definition, not in the header file, *cppreference dot com*](https://en.cppreference.com/w/cpp/language/function_template)


### Error: undefined reference to `void printStack<StackNode<int>, int>(Stack<StackNode<int>, int>*)` a template function or a member function of a template class using template arguments.

1. The compiler is not going to compile every overloaded template function definition. 
Example, 
```
template <typename T> void func(T);
```
can have many definitions including -
```
void func(char),
void func(int),
void func(user-defined-datatype), etc.
```
2. If the code where function is called (say `main.cpp`) doesn't have the defintion of template function (which maybe present in `otherfile.cpp`) there, then the compiler cannot compile the appropriate template function according to the arguments in the function call at the compile time.
This leads to the above error.

3. The `otherfile.cpp` and its header file `otherfile.h` gets compiled with no errors because the check at compile time will be only to match the function declaration (in `otherfile.h`) with the function definition (in `otherfile.cpp`).

4. The **Solution Number 1** is to include the definition in the header file.
i.e., to copy-paste the entire code from `otherfile.cpp` to `otherfile.h` and include the `otherfile.h` in `main.cpp` (which obviously was included previously too).
Now, when our project is spread in multiple files and we don't want to give the definition (but only the header file, i.e. only the declaration) to the user of our program, then we shouldn't do the Solution Number 1.

5. The **Solution Number 2** is to explicitly instantiate the template function or the template class with the template argument that we are most likely to use in `main.cpp`. This instantiation should be done in `otherfile.cpp`, as discussed above.

example, for class, 

```
template class Queue<Node<int>, int>;
```

example, for function,

```
template void printStack<Node<int>, int>(Stack<Node<int>, int>*);
```

6. The advantages of Solution 1 is that we don't have to explicitly tell the compiler to compile a particular overloaded function, since the function definition is present in the corresponding file (`main.cpp` having included `otherfile.h` which has all the contents of `otherfile.cpp`) at the time of compilation. This may be good for small codes, but maybe the code has only been tested for template arguments - `int`, `char` , `Node` , etc. but has not been tested for `newDataStructure`. Thus, explicitly instantiation can sometimes prevent unexpected bugs.

The following links should help -
 
 - [There are two valid answers to this. There are advantages and disadvantages to both answers and your choice will depend on context. The choice is yours. *Stackoverflow*](https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor)

### Syntax for definition of member functions of class in other file

 ctor-

 ```
 template <class T, class T2> Queue<T,T2>::Queue(T2 data){
   ...
 }
 ```

 member function -

 ```
 template <class T, class T2> T *Queue<T, T2>::getFrontNode() 
 { return front; 
 }
 ```

 [*Stackoverflow*](https://stackoverflow.com/questions/3960849/c-template-constructor)

### `delete` operator

 1. Use `delete` for memory allocated with `new` only
 2. `delete` releases the memory occupied by the data structure that the pointer points to.
 3. the pointer still points to the same memory location but that memory location no longer has the data structure.
 4. The standard does not say what happens to the value of the pointer; all it says is that you are no longer allowed to use that value until you assign your pointer a valid value. This state of the pointer is called dangling.
 5. So, you can just make the pointer point to `nullptr` (use `nullptr` instead of `NULL` or `O` which are used for backward compatibility to older programs).
 6. the pointer `ptr` is dangling after `delete` has completed, but before the `ptr = NULL` assignment is performed. After that it becomes a `NULL` pointer.

 The following links should help -
 
  - [*Stackoverflow*](https://stackoverflow.com/questions/23621677/what-happens-to-the-pointer-itself-after-delete)
  - [*Microsoft Docs*](https://docs.microsoft.com/en-us/cpp/cpp/delete-operator-cpp?view=vs-2019)


### How makefile can sometimes cause problems?

Let's take this case which happened to me.

The proj structure with some of the files that are required for out discussion here look as shown below -


```
Stacks and Queues
|-doc
|-bin
|-build
|-bin
|-include
|  |-Queue.h
|  |-Node.h
|  |-printStackOrQueue.h
|-src
   |-Queue.cpp
   |-printStackOrQueue.cpp
   |-AnimalData.h
   |-AnimalShelter.cpp

```

The AnimalData `struct` looks as - 

```

struct AnimalData {
  int id;
  int timestamp;
  char type;
};

```

Compiling the files with Makefile does the job. It is correct.

`AnimalShelter.cpp` has the following includes - 

```

#include "Node.h"
#include "Queue.h"
#include "printStackOrQueue.h"
#include "AnimalData.h"

```

`printStackOrQueue.h` has the following includes -

```

#include "Queue.h"
#include "Node.h"

```

`printStackOrQueue.cpp` has the following includes -

```
#include"printStackOrQueue.h"

```

`Queue.cpp` has the following includes -

```

#include "Queue.h"
#include "Node.h"
#include "AnimalData.h"

```

Now, if we change the `AnimalData` struct in the `AnimalData.h` file to the one shown below

```

struct AnimalData {
  int timestamp;
  char type;
};

```

 and re-compile the proj with `make`, then only `AnimalShelter.cpp` will be compiled again and a new `AnimalShelter.o` will be generated and linked when the binary `a.out` is being created. Rest other `.o` files (`Queue.o` and `printStackOrQueue.o`) will not be changed and remain same.

This gave a Segmentation fault when binary was executed.

But when the proj was re-made (`make`) **after `make clean`** then there was no such Segmentation error with the same codes.

This shows that, although make figures out what should be recompiled and what not, sometimes, we should do a `make clean` and then `make` the entire proj. 

I am still searching an answer to why this happened.

Why wasn't `Queue.cpp` recompiled when it depends on `AnimalData.h` ? Also, since `Queue.cpp` has the explicit instantiation line at the end for defining methods specific to `AnimalData` struct then it should have been recompiled, shouldn't it?

```
template class Queue<Node<AnimalData>,AnimalData>;

```

The figure below shows the dependencies of various files involved as stated above -

![Dependencies for `AnimalShelter.cpp` and other related files, drawn with [draw.io](https://www.draw.io/)](https://i.imgur.com/Y4zmX8Z.jpg)

