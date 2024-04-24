# Push Swap

The `push_swap` project is a sorting algorithm project that focuses on sorting a set of integers using two stacks (stack 'a' and stack 'b') and a specific set of instructions. The goal is to sort the numbers in an efficient manner. I have implemented this using a variation of merge sort algorithm

## Instructions Set

- **sa** (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
- **sb** (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
- **ss** : sa and sb at the same time.
- **pa** (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
- **pb** (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
- **ra** (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
- **rb** (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
- **rr** : ra and rb at the same time.
- **rra** (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
- **rrb** (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
- **rrr** : rra and rrb at the same time.

## Key Features

- Sort a set of integers in ascending order using two stacks (`a` and `b`) and a set of instructions
- Implement various stack manipulation operations such as swap, push, rotate, and reverse rotate
- Design the program to display the smallest list of instructions possible to sort the stack `a`

## Knowledge Gained

- Understanding of sorting algorithms and their complexity
- Manipulation of stacks and stack-based data structures using linked lists

## Usage

To compile your project, use the provided Makefile:

```sh
make
```

Run your program with a list of integers as arguments:

```sh
./push_swap 2 1 3 6 5 8
```

The program will display the list of instructions required to sort the integers.
