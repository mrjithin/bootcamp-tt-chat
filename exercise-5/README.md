# Exercise 5

**Update this README with your answers to the questions below.**

## Comparing File Changes

- What's an easy way to identify the changes in source code from one exercise
  to another?
  - We can use `diff` command in the terminal. 
    
## Using Classes

- Here is one way to separate out the code into multiple files
- Is this the best way to do it? 
  - It is not the best way to do it. The functions are passing the state to other functions which handle it, which is not ideal. 
- What are the advantages and disadvantages?
  - Some advantages are the codebase is more modular with the namespaces making each function's utility clear. 
  - Some disadvantages are the lack of a class structure that can manage on its own instead of depending on other functions outputting its current state. 
  - There is also no RAII in the current codebase. 

## Introduction to Namespace

- There are different ways namespace is being used in this exercise
  - `namespace ttc = tt::chat;`
  - `tt::chat::check_error()`
  - `using namespace tt::chat;`
- Which way is better? What are the advantages and disadvantages?
  - Using either method 1 or method 2 is fine since we make it clear by explicit qualification or aliases. It is advantageous since it makes it clear the origin of the function. It is disadvantageous in the sense that we have to write more code to call a function. But when using the `using` statement, even though the amount of code needed is lesser, it may cause name collisions. 

## Abstracting Code into Classes

- Abstract the client and server logic into a `Client` and `Server` class
- **Note**: You don't have to use the code in this exercise as a starting point
- You can use the code you wrote from previous exercises instead
- How should you divide the code into files?
- What namespace and directory structure should you use? Why?

## Programming Sense of Taste

- How do you judge what makes a particular choice of namespace and directory
  structure? 
  - A particular directory and namespace structure is good if a programmer is able to get an overall idea of the structure intuitively and by just reading the names. It makes it easier to debug and work on the codebase. 
- How do you judge what makes a good naming convention or programming style?
  - A good name should be self explanatory but not too long. A good programming style should only need minimal comments to explain a small chunk of code. 

## "Senses" in Programming

- Have you ever heard of programmers referring to "code smells"? How can code
  smell?
  - "Code Smell" was popularised by Kent Beck and Martin Fowler. It refers to surface level indications that usually lead to a deeper problem in the codebase. Here smell is used as a metaphor since when something smells, it usually hints at something bad underlying. 
- What does it mean to have a sense of taste in programming? How can code
  taste?
  - Taste refers to elegance in code. A good taste means the code handles the complexity elegantly. It is also a metaphor similar to smell. 
- Is there an analogue for every sense?
  - Sight usually relates to the visual structure of the codebase like indentation.
  - Touch/Feel usually relates to the developer experience with the codebase. 
- What other code senses can you think of?
  - The code may have a sense of pain (nociception). A code with non-deterministic bugs/ runtime errors is painful. 
- How many senses do humans have?
  - Even though commonly people only consider 5 senses, humans usually have about 22-23 senses. 
- When would you want to see something before you touch it?
  - Before changing(touching) something in a new codebase, we would prefer to go through (see) the entire structure beforehand. 
- When would you want to touch something before you see it?
  - When we test out program, we touch the program and its functionality before reading through it. 