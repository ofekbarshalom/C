# System Programming Assignment 2 - C Language

This project contains solutions to various programming tasks implemented in the C language. The focus of the assignment is on pointers, arrays, matrix operations, and algorithmic problem-solving using efficient techniques.

## Features

1. **Grade Management**
   - Read grades for 50 students.
   - Calculate the average grade.
   - Print grades above the average.

2. **Palindrome Checker**
   - Check if a given string is a palindrome.

3. **Matrix Transposition**
   - Transpose a square matrix in place.
   - Display the matrix before and after transposition.

4. **Magic Square Validation**
   - Validate if a square matrix is a magic square.
   - Print appropriate messages based on validation.

5. **Shortest Path in Adjacency Matrix**
   - Calculate the shortest path between two nodes using the Floyd-Warshall algorithm.
   - Handle disconnected nodes gracefully.

6. **Knapsack Problem**
   - Solve the 0/1 knapsack problem.
   - Determine the maximum profit and which items to include.

7. **Pointer Subarray Size**
   - Calculate the size of a subarray between two pointers efficiently.

8. **Target Sum in Sorted Array**
   - Check if two numbers in a sorted array sum up to a target value.
   - Print the indices of the numbers if found.

9. **Cycle Detection in an Array**
   - Detect the first index of a loop in an array of jumps.

10. **Subarray Containment**
    - Check if one array is contained within another.
    - Return pointers to the start of the subarray.

## Requirements

- **C Compiler**: GCC or any other standard C compiler.
- **Make Utility**: For building the project.

## Project Structure

```
|-- main.c              # Entry point of the program
|-- functions.c         # Contains all the function implementations
|-- functions.h         # Header file with function declarations
|-- Makefile            # Build script for the project
```

## Running the Program

1. **Build the project**:
   ```bash
   make
   ```

2. **Run the program**:
   ```bash
   ./main
   ```

3. **Program Interaction**:
   - The program will present a menu to the user with the list of questions.
   - Enter the number corresponding to the question to execute its functionality.

## Testing

- Test the program by providing various inputs for each question.
- Ensure the outputs match the requirements outlined in the assignment.

## Notes

- The program assumes valid user input.
- The `Makefile` automates the build process, ensuring all dependencies are compiled properly.
- Modular design ensures code is organized and easy to maintain.

## Additional Resources

- Refer to the assignment PDF for detailed explanations of each question.
- Use the `Makefile` to clean the build directory:
  ```bash
  make clean
  ```

## Authors

This project was completed as part of the System Programming course (Assignment 2). It showcases proficiency in pointers, memory management, and algorithm implementation in C.

## License

This project is for educational purposes only and should not be reused or distributed without permission.
