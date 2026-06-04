# Exercise 4

**Update this README with your answers to the questions below.**

## Learning Multi-File C++ Projects

- Move code that can be shared between `tcp_echo_server.cc` and 
  `tcp_echo_client.cc` to separate `.h` and `.cc` files
- How would you compile from the command line?
  - 
  ```bash
  g++ -c setup.cpp tcp_echo_server.cpp tcp_echo_client.cpp
  g++ setup.o tcp_echo_server.o -o tcp_echo_server
  g++ setup.o tcp_echo_client.o -o tcp_echo_client
  ```
- How would you compile using make?
  - I have added the Makefile. Run the command `make`. 
- How would you compile using VS Code?
  - In `.vscode/tasks.json` in the build command, add `setup.cpp` also to `args` and then press the run icon. 
### Compiling vs Linking

- What is the difference between compiling and linking in C++?
  - Compilation translates the C++ code to machine code and outputs an object file. 
  Linker combines many object files to a single output file resolving all the interdependent function calls in files. 
- What is the difference between creating an executable and creating a 
  library?
  - Library is a collection of compiled object files that are not standalone and needs to be linked with other programs to run. An executable is a standalone binary with a `main()` entry point. 
- How do you compile a library, and then use that library to compile an
  executable?
  - 
    ```bash
    g++ -c setup.cpp -o setup.o
    ar rcs libsetup.a setup.o
    g++ tcp_echo_server.cpp -L. -lsetup -o server
    ```
  We compile to object file and then archive it to a static library and then link it to the executable. 

### Reminder 
[Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
fundamentals with practical examples and common patterns.

## Experiments in Performance

- Is it better to have many small files spread across many directories, or
  a few large files across fewer directories?
  - In general having many small files is better since the amount of recompilation that needs to be done on any modification is less. But having too many files will have a relatively large overhead for compilation and linking. 
- Is there a difference in compilation time between the two?
  - Only changed files are recompiled and hence it is faster with many small files. 
- How can you assess performance other than compilation speed?
  - We can assess performance using tools like `perf`, `Callgrind` for CPU time, `Valgrind` for memory management. 