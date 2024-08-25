# Push_swap

## Project Overview

Push_swap is a sorting algorithm project developed as part of the 42 school curriculum. The main goal of this project is to sort a stack of integers using a limited set of operations, with the objective of using the lowest possible number of actions.

## Table of Contents

1. [Project Description](#project-description)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Algorithm](#algorithm)
5. [Project Structure](#project-structure)
6. [Author](#author)

## Project Description

The push_swap program takes a list of integers as input and outputs a series of instructions to sort these integers using two stacks (stack A and stack B) and a predefined set of operations. The goal is to sort the integers in ascending order with the minimum number of operations.

Available operations:
- `sa` : swap the first two elements of stack A
- `sb` : swap the first two elements of stack B
- `ss` : perform sa and sb simultaneously
- `pa` : push the top element from stack B to stack A
- `pb` : push the top element from stack A to stack B
- `ra` : rotate stack A (shift up all elements by 1, the first element becomes the last)
- `rb` : rotate stack B
- `rr` : perform ra and rb simultaneously
- `rra` : reverse rotate stack A (shift down all elements by 1, the last element becomes the first)
- `rrb` : reverse rotate stack B
- `rrr` : perform rra and rrb simultaneously

## Installation

To compile the push_swap program, follow these steps:

1. Clone the repository: git clone https://github.com/aben-hss/push_swap.git
2. Navigate to the project directory: cd push_swap
3. Compile the program using the provided Makefile: make
   This will generate the `push_swap` executable.

## Usage

To use the push_swap program: ./push_swap [list of integers]
Example: ./push_swap 4 67 3 87 23
The program will output a list of instructions that, when applied, will sort the given integers.

## Algorithm

The push_swap program implements different sorting algorithms based on the number of integers to be sorted:

- For 2 numbers: A simple swap if necessary
- For 3 numbers: A specific algorithm for 3 numbers
- For 4 and 5 numbers: Specific algorithms optimized for these small sets
- For larger sets: An optimized algorithm that divides the numbers into chunks and sorts them efficiently

The program also includes optimizations to reduce the number of operations for larger sets of numbers.

## Project Structure

- `push_swap.c`: Main program file
- `push_swap.h`: Header file with function prototypes and struct definitions
- `parse.c`: Functions for parsing and validating input
- `rules.c`: Implementation of stack operations (swap, push, rotate)
- `sort_utils.c`: Utility functions for sorting algorithms
- `sort.c`: Main sorting algorithm for larger sets of numbers
- `t_stucks_utils.c`: Utility functions for stack manipulation

## Author

This push_swap project was developed by aben-hss as part of the 42 school curriculum.
