# Exercise 5

**Update this README with your answers to the questions below.**

## Comparing File Changes

- What's an easy way to identify the changes in source code from one exercise
  to another?
  - We can use `diff` command in the terminal. 
    
## Using Classes

- Here is one way to separate out the code into multiple files
- Is this the best way to do it? 
- What are the advantages and disadvantages?

## Introduction to Namespace

- There are different ways namespace is being used in this exercise
- Which way is better? What are the advantages and disadvantages?

## Abstracting Code into Classes

- Abstract the client and server logic into a `Client` and `Server` class
- **Note**: You don't have to use the code in this exercise as a starting point
- You can use the code you wrote from previous exercises instead
- How should you divide the code into files?
- What namespace and directory structure should you use? Why?

## Programming Sense of Taste

- How do you judge what makes a particular choice of namespace and directory
  structure? 
- How do you judge what makes a good naming convention or programming style?

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