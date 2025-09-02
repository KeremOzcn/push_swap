<p align="center">
  <img src="https://github.com/jotavare/jotavare/blob/main/42/banners/piscine_and_common_core/github_piscine_and_common_core_banner_push_swap.png" alt="push_swap Banner"/>
</p>

# push_swap

This project is a C implementation of a sorting algorithm designed to sort a stack of integers using a limited set of operations. The goal is to find the shortest possible sequence of commands to sort the numbers.

This project is part of my university coursework and focuses on algorithmic thinking, efficiency, and stack manipulation.

## The Challenge

You are given two stacks, `A` and `B`:
-   Stack `A` initially contains a random list of unique integers.
-   Stack `B` is initially empty.

The objective is to sort the integers in stack `A` in ascending order using the fewest possible moves. You can only use the operations listed below.

## Allowed Operations

| Command | Action                                       |
| :-----: | -------------------------------------------- |
|  `sa`   | **Swap A**: Swap the first 2 elements of stack A. |
|  `sb`   | **Swap B**: Swap the first 2 elements of stack B. |
|  `ss`   | `sa` and `sb` at the same time.                |
|  `pa`   | **Push A**: Take the first element from B and push it to A. |
|  `pb`   | **Push B**: Take the first element from A and push it to B. |
|  `ra`   | **Rotate A**: Shift up all elements of stack A by 1. |
|  `rb`   | **Rotate B**: Shift up all elements of stack B by 1. |
|  `rr`   | `ra` and `rb` at the same time.                |
|  `rra`  | **Reverse Rotate A**: Shift down all elements of stack A by 1. |
|  `rrb`  | **Reverse Rotate B**: Shift down all elements of stack B by 1. |
|  `rrr`  | `rra` and `rrb` at the same time.              |

## Algorithm Overview

The sorting strategy changes based on the number of elements to be sorted:

1.  **Trivial Cases (2, 3, or 5 numbers)**:
    -   For 2 numbers, a single `sa` is used if needed.
    -   For 3 numbers, a specific set of moves is applied to sort them in a maximum of 3 operations.
    -   For 5 numbers, the two smallest numbers are pushed to stack B, the remaining 3 are sorted in stack A, and then the two numbers are pushed back to A in the correct position.

2.  **General Case (More than 5 numbers)**:
    -   First, all but the three largest numbers are pushed from stack `A` to stack `B`. This leaves stack `A` with three numbers, which are then easily sorted.
    -   The core of the algorithm involves intelligently moving numbers back from stack `B` to stack `A`. For each number in stack `B`, the program calculates the "cost" of moving it to its correct sorted position in stack `A`.
    -   The "cost" is the total number of rotate (`ra`, `rb`) or reverse-rotate (`rra`, `rrb`) operations needed to bring the target number in `B` and its destination spot in `A` to the top of their respective stacks.
    -   The number with the **lowest movement cost** is chosen and moved from `B` to `A`.
    -   This process is repeated until stack `B` is empty and all numbers are sorted in stack `A`.

## How to Compile and Run

1.  **Clone and navigate to the project directory.**
2.  **Compile the source files using the `Makefile`:**
    ```bash
    make
    ```
3.  **Run the `push_swap` program with a list of numbers:**
    ```bash
    ./push_swap 4 67 3 -1 8
    ```
    The program will output the sequence of operations to sort the numbers.

### Using the Checker (Optional)

A `checker` program is included to verify if the output of `push_swap` correctly sorts the list.

1.  **Run `push_swap` and pipe its output to the `checker`:**
    ```bash
    ARG="4 67 3 -1 8"; ./push_swap $ARG | ./checker $ARG
    ```
2.  **Output:**
    -   If the stack is sorted, the checker will print `OK`.
    -   If not, it will print `KO`.
