# Exercise 3

**Update this README with your answers to the questions below.**

## Re-using Code

- Read the code in `src/tcp_echo_client.cc`
- A new function `check_error()` has been created and `create_socket()` from 
  exercise-2 has been refactored to make use of it
- What are the benefits of writing code in this way?
  - It eliminates repetition. It also useful if instead of logging the error, we need to perform some other action. Then in such a case we only need to modify the `check_error()` function. 
- Are there any costs to writing code like this?
  - There is a function call overhead associated with this. We also pass the error message by value which is unnecessary and can be changed to be a const reference. 
- Apply `check_error` to all the code in `src/`

## Introduction to Compiler Explorer

- Try out the old `create_socket()` and the new `check_error()` and 
  `create_socket()` in [Compiler Explorer](https://godbolt.org) - Interactive 
  tool for exploring how C++ code compiles to assembly
- What is happening here?
  - For the new `check_error()`, the compiler makes two different versions of this function for each case. There are also more number of instructions in the second case due to more no of instructions. 
- Can you think of any different approaches to this problem?
  - We can pass `inline` keyword to hint the compiler to inline the `check_error()` function. We can also make the parameter a `std::string_view` so as to eliminate the allocation overhead for the error message in case of no error. 
- How can you modify your Makefile to generate assembly code instead of
  compiled code?
  - We can pass the `-S` flag for it to output assembly code. 
- **Note**: You can save the generated assembly from Compiler Explorer
- **Bonus**: Can you view assembly code using your IDE?
  - In VS Code debug mode, we can use the Open Disassembly View to open assembly code.
- **Bonus**: How do you see the assembly when you step through each line in
  debugging mode from your IDE?
  - When paused on a breakpoint, VS Code disassembly view highlights the current instruction. 
- [x86 assembly reference](http://ref.x86asm.net/) - Comprehensive reference 
  for x86 assembly language instructions and syntax

## More About Memory Management

- Make sure you have `-fsanitize=address` in both your `CXX_FLAGS` and 
  `LD_FLAGS` in your Makefile
- What do `-fsanitize=address`, `CXX_FLAGS` and `LD_FLAGS` mean?
  - `-fsanitize=address` enables ASan which helps catch memory bugs like memory leaks at runtime. 
  - `CXX_FLAGS` is a standard variable to pass compilation flags. 
  - `LD_FLAGS` is a standard variable to pass linker flags. 
- With the new tool of the Compiler Explorer, and keeping in mind what you 
  have learned about how to use debug mode
- What happens when you look at a `std::string` using the above methods?
  - If a `std::string` has less no of characters, then due to SSO optimisation, the string is directly allocated on the stack whereas larger strings are allocated on the heap. This is visible from the call to `"operator new(unsigned long)"` in the assembly code. 
- Where is the text in your `std::string`?
  - If a `std::string` has less no of characters, then due to SSO optimisation, the string is directly allocated on the stack whereas larger strings are allocated on the heap. This is visible from the call to `"operator new(unsigned long)"` in the assembly code. 
- What is `std::optional`?
  - It is a class in C++ that is used to represent a scenario when it may or may not contain a value. 
- How do you find out the memory layout of a `std::optional`?
  - We can find the memory layout by either reading cppreference or by printing the sizeof so as to get the alignment. 
- Read https://en.cppreference.com/w/cpp/memory#Smart_pointers - Guide to 
  modern C++ memory management using smart pointers
- Which pointer types are the most important to know about?
  - The most important ones are `std::unique_ptr`, `std::shared_ptr` and `std::weak_ptr`. 
- Which smart pointer should you use by default if you can?
  - The default choice should be unique_ptr as it has unique ownership and no overhead of reference counting. 
- Does changing your optimization level in `CXXFLAGS` from `-O0` to `-O3` have
  any impact on the answers to any of the above questions?
  - When increasing the optimisation level, the compiler optimises away some of the variables and inlines functions. But the basic allocations of string and other data structures remain the same. 

## More Thinking About Performance

- After your experiments with Compiler Explorer, do you have any updates for
  your answers in exercise-2?
  - Other than function call overhead, there's also overhead of making copy of parameters when we make our code more modular. 
### Bonus: Do Not Watch Now 

- [More about Compiler Explorer](https://www.youtube.com/watch?v=bSkpMdDe4g4) - 
  Deep dive into compiler optimization and assembly analysis
  - Create a struct which contain many different data types
  - Look at the memory layout in the debugger
  - Create a `char` or `uint8_t` pointer to the beginning of the struct, 
    iterate to the end of the struct, printing out the value of each byte in 
    hexadecimal
  - Try accessing different parts of the struct and see in compiler explorer
    what the assembly looks like
  - What happens if you iterate the pointer to outside the bounds of your
    array?
    - If we iterate outside bounds, it is UB. It may segfault or read garbage values.
  - Let's say your struct is called `Foo`
  - What is the difference between `std::vector<Foo>` and `std::vector<Foo*>`?
    - The first one stores an array of Foo structs with each element occupying sizeof(Foo). In second case we make an array of pointers with each element storing a pointer (size is 8 byte usually in 64bit machines).
  - What are the tradeoffs between using `std::vector<Foo>` vs 
    `std::vector<Foo*>`? 
    - `std::vector<Foo>` is better for cache locality due to contiguous storage of structs. There is also no need for separate storage of pointers. 
    - `std::vector<Foo*>` is better for large structs since if we want to move the objects it is easier since only pointers need to be moved. 
  - Give an example where `std::vector<Foo>` is a better choice than 
    `std::vector<Foo*>`
    - For a small struct like
    ```cpp
    struct Point{
      int x;
      int y;
    }
    ```
    `std::vector<Point>` is better since they structs are relatively small and the pointer overhead + cache locality issues are significantly more. 
  - Give another example where the opposite is true
    - Suppose there exists a struct:
    ```cpp
    struct User{
      int id;
      std::string name;
      std::string role;
    }
    ```
    since we need to assign different users to different locations, it is easier to pass the pointer instead of passing a copy. 
  - Can you create `std::vector<Foo&>`? 
    - No this is not allowed since a std::vector requires the element inside to be assignable. Since a reference cannot be reassigned, this is compilation error. 
  - Can you create `std::vector<std::optional<Foo>>`?
    - Yes this is valid. 
  - What happens if your struct contains another struct?
    - The outer struct uses the inner struct's alignment requirement which in turn corresponds to its own largest datatype's size, along with other members of the outer struct. 
  - What is the difference between a struct and a class?
    - In a struct, members are public by default whereas in a class they are private by default. 