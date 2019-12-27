## Learning things along the way while coding CTCI

### Compiling separately

When we have some utility functions like `createSqrMatrix()` or `printMatrix()` or some other code that can be reused, we can often put that into a separate `.cpp` file. Now this should be compiled separately and then later linked with the file that contains `main()`.

Following links should help -

- [Multiple file compilation, *Florida State University*](https://www.cs.fsu.edu/~myers/c++/notes/compilation.html)
- [Note that the `.cpp` file that contains the definitions also needs to include (it's corresponding) header file, *Stackoverflow*](https://stackoverflow.com/questions/6995572/using-multiple-cpp-files-in-c-program)

### A simple C++ project structure

You can have source files (header files and .cpp files) together in `src` dir or you can have header files in `include` and .cpp files in `source` dir. Then the generated files (executables `a.out` or `.exe` or `main`, object codes `.o` and libs `.a` or `.so`) can go in their respective dirs.

The following links should help - 

- [Project Structure, *Blog*](https://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/)
- [How to make `g++` search for header files in a specific directory, *Stackoverflow*](https://stackoverflow.com/questions/12654013/how-to-make-g-search-for-header-files-in-a-specific-directory) 
    > with `-I` flag

### Makefile

So, now we have different dirs for different files and also pieces of code that can be reused (and therefore, should be compiled separately and linked later on). Separate compilation of files and their dependencies everytime is tedious. So let's write a Makefile that make use of the `make` utility to generate required files for us.

The following links should help -

- [Very Simple guide, *Florida State University*](https://www.cs.fsu.edu/~myers/howto/makefiles.txt)
- [Simple guide, a deeper look into how make works, use of variables, smart make *Boston University*](https://www.cs.bu.edu/teaching/cpp/writing-makefiles/#sep-compile)

### Comments formatted with doxygen markup syntax

Doxygen is a tool that can generate project documentation in html, pdf or Latex from code comments formatted with Doxygen markup syntax.
It resembles similar to javadoc style.

The following links should help -

- [Comments for function description, *Blog*](https://caiorss.github.io/C-Cpp-Notes/Doxygen-documentation.html#orgd315ebf)
- [VSCode extention, *Microsoft Visual Studio Code Extentions Marketplace*](https://marketplace.visualstudio.com/items?itemName=cschlosser.doxdocgen)