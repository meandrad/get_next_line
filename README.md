# Get Next Line (GNL)

The **Get Next Line** project implements a function that reads a line from a file descriptor, one at a time. It is designed to be memory-efficient, processing the file without loading the entire content at once.

## Project Files

- **get_next_line.c**: Implementation of the `get_next_line` function.
- **get_next_line.h**: Header file with function prototypes.
- **get_next_line_utils.c**: Utility functions used in the project, such as string manipulation and memory management.

## How It Works

The `get_next_line` function reads a file until it finds a newline or reaches the end of the file. It dynamically allocates memory to store the line and returns it. You must free the memory after using each line to avoid memory leaks.

## How to Use

### Step 1: Clone the Repository

To get started, clone the repository using the Git command:

```bash
git clone https://github.com/meandrad/get_next_line.git
```

### Step 2: Include the Header File

Include the `get_next_line.h` file in your C project to use the `get_next_line` function.

### Example Usage

Here’s a simple example of using `get_next_line` to read a file line by line:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("get_next_line.h", O_RDONLY); // Open the header file
    char *line;

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read file line by line
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);  // Print the line
        free(line);          // Free allocated memory
    }

    close(fd);  // Close the file
    return 0;
}
```
### Step 3: Compile the Code

To compile the code, you can use a C compiler like CC:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
The command compiles the project as follows:

1. **`cc`**: Calls the C compiler (could be GCC or Clang).
2. **`-Wall`**: Enables general warnings.
3. **`-Wextra`**: Enables additional, less common warnings.
4. **`-Werror`**: Treats warnings as errors, so compilation will fail if there are any warnings.
5. **`-D BUFFER_SIZE=42`**: Defines the macro `BUFFER_SIZE` to be 42, which is used in the `get_next_line` function to set the buffer size.
6. **`main.c get_next_line.c get_next_line_utils.c`**: Specifies the source files to be compiled and linked into the executable.

This will generate an executable named `./a.out`.

### Step 4: Run the Code

After compiling, run the program using:

```bash
./a.out
```

### Step 5: Run the Test

To run the tests with **Valgrind** and ensure there are no memory leaks or errors, use the following command:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out tests/*
```

This command will check for memory leaks, show detailed information about them, and track the origins of memory allocations. It passes all the test files (located in the `tests/` folder) as arguments to your compiled program (`./a.out`).

For additional tests and resources to validate your **Get Next Line** project, you can use the **GNL Tester** repository by Tripouille. It provides a more extensive set of tests for evaluating your implementation.

Check out the repository here: [https://github.com/Tripouille/gnlTester](https://github.com/Tripouille/gnlTester).
