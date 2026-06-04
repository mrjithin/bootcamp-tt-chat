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
- What is the difference between creating an executable and creating a 
  library?
- How do you compile a library, and then use that library to compile an
  executable?

### Reminder 
[Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
fundamentals with practical examples and common patterns.

## Experiments in Performance

- Is it better to have many small files spread across many directories, or
  a few large files across fewer directories?
- Is there a difference in compilation time between the two?
- How can you assess performance other than compilation speed?