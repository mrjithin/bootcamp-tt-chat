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
- What can you do to identify if there are bugs in the code?

## Refactoring: Extract Function

- What is different in this code compared to exercise-1?
- Is this code better or worse than exercise-1?
- What are the tradeoffs compared to exercise-1?
- Are you able to spot any mistakes or inconsistencies in the changes?
  
## Thinking About Performance

- Does writing code this way have any impact on performance?
- What do we mean when we say performance?
- How do we measure performance in a program?

## Play with Git

- There isn't necessarily a single correct answer for how to abstract the 
  code from exercise-1 into functions
- Try different ways to refactor the code from exercise-1 to make it more
  readable.
- Make sure to commit each change as small and self-contained commit
- This will make it easier to revert your code if you need to
- What is `git tag`? How is `git tag` different from `git branch`?
- How can you use `git tag` and `git branch` to make programming easier and
  more fun?

## Learn Basics of Debugging in Your IDE

- How do you enable debug mode in your IDE?
- In debug mode, how do you add a watch?
- In debug mode, how do you add a breakpoint?
- In debug mode, how do you step through code?

### Memory Management and Debug Mode in Your IDE

- How do you see the memory layout of a `std::string` from your IDE debug mode?
- How do you see the memory layout of a struct from your IDE debug mode?