# CSES Solutions

GNU C++17 solutions for the [CSES Problem Set](https://cses.fi/problemset/),
organized by category with one source file per problem.

## Current progress

| Category | Solutions |
|---|---:|
| [Introductory Problems](./Introductory%20Problems) | 11 |
| [Sorting and Searching](./Sorting%20and%20Searching) | 34 |
| [Dynamic Programming](./Dynamic%20Programming) | 22 |
| **Total** | **67** |

File names follow the corresponding CSES problem titles, using underscores in
place of spaces.

## Compile and run

Compile any solution directly with GNU C++17:

```bash
g++ -std=gnu++17 -O2 -Wall -Wextra \
  "Sorting and Searching/Concert_Tickets.cpp" \
  -o solution
./solution < input.txt
```

Some solutions use GNU-specific competitive-programming facilities, so GCC is
recommended over Apple Clang.

## Repository conventions

- each problem has a standalone `main` function
- solutions read from standard input and write to standard output
- categories mirror the structure of the official CSES Problem Set
- source files contain the implementation only, keeping them easy to review and
  submit
