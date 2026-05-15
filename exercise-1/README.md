# Exercise 1

**Update this README with your answers to the questions below.**

## How to Approach This Exercise

Before you scroll down to the questions, try this:

1. **Don't peek at the questions yet.** Pretend you've just been handed a brief
   that says: *"Learn these topics as deeply as you can — g++ CLI, Make, Git,
   sockets, and memory management in C++."* That's the whole assignment.
   How would you go about it? What would you read, what would you try, in what
   order, and how would you know when you've understood something well enough?
   Write that plan down in this README, then actually follow it.
   - I would start with searching through google for easy to follow resources and official docs of each topic. 
   - Then I would ask an LLM to suggest me good resources to get the basics of all the topics quick enough since I am short on time. 
   - Then based on these two lists, I would follow one resource of my liking for each topic.
   - Afterwards I will ask AI to give a summary of each topic somewhat like a cheatsheet. 
   - I would assume I understood something when I get the overall idea of how it works and am able to explain it to myself from scratch clearly. 

2. **Now go through the questions below and answer them like you're an LLM.**
   No live Googling, no Stack Overflow, no asking ChatGPT mid-question. You may
   refer to notes *you* took during step 1 — that's your context window. Answer
   from what you've internalised.

3. **Reflect on how it went.** Honestly:
   - Did your self-directed learning actually prepare you for the questions, or
     did you over-study things that never came up?
   - Which questions blindsided you? Why — was the topic missing from your
     plan, or did you skim past it?
   - Map your experience onto the *known knowns / known unknowns / unknown
     unknowns* idea. The interesting category is usually the last one: things
     you didn't even realise you should have learned. What were yours, and how
     could a better learning plan have surfaced them earlier?

The point of this exercise isn't to get the questions "right" — it's to notice
the gap between how you *think* you learn and how you actually do, so you can
close it.

## Learning How to Learn

- Answer the following questions in this file and commit and push your changes.
- Bonus sections are more difficult and optional.
- How can you find the information required to complete these tasks?
  - There are official docs for most of the topics like g++, Makefile, git. For the others there are popular guides like Beej's guide for socket programming. Nowadays we can also use AI to learn new topics. 
- How can you tell if the source of your information is good?
  - A good resource is something that is easy to follow, is accurate and up-to-date, is popular i.e. used by many and has a good flow of topics. 
- How would you define "good" in this situation?
  - In my situation, I wanted a resource that is not extremely cryptic, and goes into the main parts instead of the nitty-gritty details. 
## Learn Basics of g++ CLI

- Compile the TCP client and server using `g++` from command line.
  - Commands used:
  ```
  g++ ./src/tcp_echo_server.cc -o ./build/tcp_echo_server
  g++ ./src/tcp_echo_client.cc -o ./build/tcp_echo_client
  ```
- What are the most important command line arguments to learn for `g++`?
  - The most important ones are: 
  `-o, -c, -std=c++xx, -Wall, -Wextra, -O2, -O3, -g`
- What is the difference between debug vs release versions?
  - Debug version has debugging symbols like line numbers corresponding to each assembly instruction and is not optimised. Release version doesn't contain these information and is highly optimised. 
- What are the tradeoffs between debug and release versions?
  - Debug version is unoptimised but is easier to debug with tools like gdb. Release verion is highly optimised with all information stripped hence difficult to debug. 
- What arguments would you use in a debug build?
  - `-g -O0 -Wall -Wextra`
- What about for release?
  - `-O2 or -O3`
- What other kinds of build types are useful?
  - I am not sure of any other build type. But on looking afterwards I found out the flag `-Os` which optimises for size.  

## Learn Basics of Make

- Create a Makefile that will speed up the process.
- [Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
  fundamentals with practical examples and common patterns.
- How else can you learn about make?
  - We can learn about make from the GNU make manual. 
- How can you tell if the resource you are using is correct?
  - Since the resource is followed by many people and recommended to beginners, we can be mostly sure that it is correct. 
- Create a makefile such that when you run `make` with no arguments, it will:
  - Create `build/` directory if it does not exist
  - Create executables **client** and **server** in `build/`, if needed
  - How does make know when it needs to rebuild the executables?
    - Make checks the last modified time of prerequisites and compares it with that of the target. If the prereqs changed later, then make will run the commands in the given rule. 
  - Change your Makefile such that `make clean` will remove `build/` and all
    its contents
- What are the most important command line arguments to learn for make?
  - make usually runs without arguments or the name of the target is given as the second word in the command. I forgot to look into other arguments. 
- What are the most important directives to learn about in Makefile?
  - The most important directive is .PHONY used to tell make that a target is not a file. 
- What are the most important commands to implement in your Makefile?
  - The most important commands to implement are the g++ compilation command, the clean command, the mkdir command and the all command. 
- Which ones are essential, which ones are nice to haves?
  - Essential ones are the compilation commands and all command. The nice to haves are the cleanup command. 
## Learn Basics of Git

- Read through the code in `src/`
- Answer any `#Questions` as a comment
- Commit and push your changes to git
- Each commit should be responding to a single task or question
- Why is it important to keep your commit to a single task or question?
- Is it better to have a lot of very small commits, or one big commit when 
  everything is working?
- What are the most important commands to know in git?

## Introduction to Sockets

- Read the code in `src/tcp-echo-client.cc` and add a way to change the 
  message sent using command line arguments
- **Example**: `./client "hello message from the command prompt"` should send
  `"hello message from the command prompt"` to the server
- Commit your changes into git
- What do all these headers do?
- How do you find out which part of the below code comes from which header?
- How do you change the code so that you are sending messages to servers
  other than localhost?
- How do you change the code to send to a IPv6 address instead of IPv4?
- **Bonus**: How do you change the client code to connect by hostname instead
  of IP address?
  
## Introduction to Memory Management

- What is happening in line 26 of `tcp-echo-client.cc`? 
  `if (inet_pton(AF_INET, kServerAddress.c_str(), &address.sin_addr) <= 0) {`
- What is happening in line 31 of `tcp-echo-client.cc`?
  `if (connect(my_sock, (sockaddr *)&address, sizeof(address)) < 0) {`
- What is the difference between a pointer and a reference?
- When is it better to use a pointer?
- When is it better to use a reference?
- What is the difference between `std::string` and a C-style string?
- What type is a C-style string?
- What happens when you iterate a pointer?
- What are the most important safety tips to know when using pointers?

## Learn Basics of Creating a C++ Project in Your IDE

- How do you compile and run your project in your IDE?

## Improving Interactions with LLMs

- What is the most authoritative source of information about `socket()`
  from `<sys/socket.h>`?
- What is the most authoritative source of information about the TCP and IP
  protocols?
- What is the most authoritative source of information about the C++
  programming language?
- What information can you find about using Markdown when structuring prompts 
  to LLMs?
- What is the difference between LLM and AI?
- Is it grammatically correct in English to say "a LLM" or "an LLM"? Why?