# C++ Portfolio: Task Preferences Demo

This repository contains a **redacted C++ project** demonstrating problem-solving skills, data structure manipulation, and input parsing.

> The problem-specific solution has been removed to respect confidentiality, but the code shows the logic and approach used.

## Problem Overview (Redacted)

The original problem involved assigning "tasks" to "preferences" with constraints, similar to matching multiple conditions with minimum cost or conflicts. Each "entry" had multiple preferred options, and the goal was to satisfy as many preferences as possible while optimizing for a certain criterion.

The redacted version uses generic "OptionA" and "OptionB" instead of the original domain.

## Code Functionality

- Parses structured input representing multiple entries and their option preferences.
- Uses STL containers (`vector`, `unordered_map`) to store and manipulate data.
- Demonstrates nested iteration over data structures to find compatible assignments.
- Implements a simple decision logic to choose default options and satisfy at least one preference per entry.
- Shows clean class design and encapsulation.

## How to Run

1. Compile :
```bash
gcc main.cpp -o task_preferences
````
2. Run with the provided example input file:
```bash
./task_preferences input.txt
```

## Example Input

```
2 3
0 OptionA, 1 OptionB
0 OptionB, 1 OptionA
```

## Example Output

```
0 -> OptionA
1 -> OptionB
```

## Skills Highlighted

* Object-oriented programming in C++
* File and string parsing
* STL container usage (`vector`, `unordered_map`, `unordered_set`)
* Iterating nested data structures
* Writing maintainable, modular code
* Implementing logic to satisfy multiple conditions
