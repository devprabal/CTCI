## Linked Lists

### Include guards
When the code is spread over several files (headers and cpp files), it becomes necessary to have include guards so that there is only one declaration of our functions, class, etc. 
Include guards also protect against recursive inclusion.

The following links give in-depth explanations - 

 - [`#ifndef`, `#define`, `#endif`, *Stackoverflow*](https://stackoverflow.com/questions/3246803/why-use-ifndef-class-h-and-define-class-h-in-h-file-but-not-in-cpp)
 - [don't use `#pragma once`, *Stackoverflow*](https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files)

### Default parameters
 Should be in function declaration only. However, you should comment the default value in the definition for better readability.

 - [don't redefine the default parameter in the function definition,*Stackoverflow*](https://stackoverflow.com/questions/2545720/error-default-argument-given-for-parameter-1/2545733)

### Random number generator
 Make use of `rand()` or `srand()` in `<cstdlib>` to generate random numbers.

 To generate random numbers between lower bound `L` and upper bound  `U` , do the following - 

```
 L+rand()%(U - L)
```
  - [lower bound inclusive, upper bound exclusive, *University of Alaska*](http://www.math.uaa.alaska.edu/~afkjm/csce211/handouts/RandomFunctions)

### Dependency chart for loop detection program to explain the concept of writing codes across several files

![Dependency chart image for loop detection program draw using [draw.io](https://www.draw.io/)](https://i.imgur.com/WmXxIwS.png)
