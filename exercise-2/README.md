# Exercise 2

**Update this README with your answers to the questions below.**

## Sources of Information for Questions from Before

### Socket 
- https://man7.org/linux/man-pages/man2/socket.2.html - System call reference
  for creating communication endpoints
- Or type `man socket` in terminal
- https://man7.org/linux/man-pages/man7/socket.7.html - Socket interface 
  overview and protocol families
- Or type `man 7 socket` in terminal
- When would you want to use a `SOCK_RAW` stream?
  - We use raw sockets when we want to directly interact with the network layer. 
  - We may use it for custom protocol development. 
  - It also is used for packet sniffing in which it is used to read all incoming packets.

### TCP and IP Protocols
- [IPv4](https://www.rfc-editor.org/info/rfc791) - Internet Protocol 
  specification defining packet structure and routing
- [IPv6](https://www.rfc-editor.org/info/rfc8200) - Next-generation Internet 
  Protocol with expanded address space
- [TCP](https://datatracker.ietf.org/doc/html/rfc9293) - Transmission Control 
  Protocol providing reliable, ordered data delivery
    
### C++
- [C++23 ISO standard draft](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/n4950.pdf) - 
  Working draft of the C++ language specification
- Is the above the official C++23 spec?
  - No it is just a working draft that reflects the changes made before final publication. 
- Where is the official C++23 spec?
  - www.iso.org/standard/83626.html
- Why was this link chosen instead?
  - The official ISO spec is not free and must be purchased. The working draft is technically identical to the final spec. 
- Is this a helpful reference for learning C++?
  - It is a highly technical document that is used by compiler developers and hence is not appropriate from a learning point of view. 
- Can the various implementations of C++ compilers be different from the
  C++ standard?
  - The various implementation may introduce many compiler specific extensions to the language. The spec also defines some parts as implementation defined. Due to these the various implementations are different from each other. 
- What are the most widely used and most significant C++ compilers?
  - GCC, Clang, MSVC
- Where is the equivalent spec for C++26?
  - C++26 is currently under development and released the final spec. The working draft is found here: https://github.com/cplusplus/draft

- Where do you find the spec for the HTTP protocol?
  - It is published by IETF as Request for Comments (RFC). 
- What about HTTPS? Is there a spec for that protocol?
  - Since it is just HTTP with an encrypted TLS connection, it doesn't have a separate spec. 

## Introduction to C++ and Sockets Programming

- Read the code in `src/`
- Are there any bugs in this code? 
  - In the client as well as the server code, the receiving buffer has a size of 1024 and the read system call also reads 1024 bytes. In case the response recieved has >=1024 bytes, the buffer will be entirely filled without space for the null terminator (`\0`). To avoid this we should use kBufferSize-1.
  - We also need to zero initialize the sin_zero property in sockaddr_in. Otherwise it may cause unexpected issues. 
- What can you do to identify if there are bugs in the code?
  - We can use compiler warning flags like -Wall, -Wextra.
  - We can use debuggers like gdb. 
  - We can also write tests and do unit testing and other kinds of testing. 

## Refactoring: Extract Function

- What is different in this code compared to exercise-1?
  - The code is modular and each function does a specific part of the process instead of having a single huge block of code that does everything. 
- Is this code better or worse than exercise-1?
  - The code is certainly better than exercise-1 since it's more readable, organised easier to debug and test as well as maintainable. 
- What are the tradeoffs compared to exercise-1?
  - The code has become more verbose and longer. There may also be some overhead when calling functions. But these are minor and doesn't make any noticeable changes. 
- Are you able to spot any mistakes or inconsistencies in the changes?
  - In the receiving buffer, in exercise 1, same buffer is overwritten for each client which results in left over data in the buffer whereas in exercise 2, we zero-initialise the buffer for every client that connects. 
  
## Thinking About Performance

- Does writing code this way have any impact on performance?
  - When we write the code with lots of functions, there is some overhead when calling these functions. We also zero initialize the buffer for every client. These things affect the performance of code in exercise-2. 
- What do we mean when we say performance?
  - Performance considers the time to execute as well as the memory used. These are the most important aspects of performance. 
- How do we measure performance in a program?
  - We can find execution times using chrono library. We can also do profiling using tools like Valgrind. 

## Play with Git

- There isn't necessarily a single correct answer for how to abstract the 
  code from exercise-1 into functions
- Try different ways to refactor the code from exercise-1 to make it more
  readable.
- Make sure to commit each change as small and self-contained commit
- This will make it easier to revert your code if you need to
- What is `git tag`? How is `git tag` different from `git branch`?
  - git tag is used to label a specific commit with a permanent name. It is used by developers to mark release versions. 
  - git branch is used to continue a line of development. Once it is assigned to a commit, it moves to the next commit whenever new commits are made. 
- How can you use `git tag` and `git branch` to make programming easier and
  more fun?
  - Tags allow us to mark stable versions which we can return to in case something breaks during development. Branches allow us to try adding new features while the original code remains safe. This allows us to develop safely and minimises the risk of loss of progress. 

## Learn Basics of Debugging in Your IDE

- How do you enable debug mode in your IDE?
  - To start debug mode, first we compile with the -g flag. 
  - Then in VSCode, press the Run and Debug icon. 
  - The code starts to run in debug mode.
- In debug mode, how do you add a watch?
  - To watch any expression, we expand the WATCH section on the left and add any expression we want. 
- In debug mode, how do you add a breakpoint?
  - To set a breakpoint, we can click to the left of the line number at which we want to add a breakpoint. 
- In debug mode, how do you step through code?
  - We can step over using F10, step into using F11 and step out using Shift+F11 once we reach a breakpoint. 

### Memory Management and Debug Mode in Your IDE

- How do you see the memory layout of a `std::string` from your IDE debug mode?
  - To examine the memory layout, we can use the gdb cli and type `-exec x/32xb &stringName` to examine 32 bytes starting from the address of the string. 
- How do you see the memory layout of a struct from your IDE debug mode?
  - To examine the memory layout, we can use the gdb cli and type `-exec x/32xb &structName` to examine 32 bytes starting from the address of the struct. 