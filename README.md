Here’s the revised README, with the reference to `file.txt` changed to `get_next_line.h`:

---

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

### Explanation of the Code:

1. **Open File**: The `open` function is used to open the `get_next_line.h` file in read-only mode (`O_RDONLY`).
2. **Read the File**: The `get_next_line` function is called repeatedly to read each line. Each line is printed, and the allocated memory for it is freed.
3. **Close File**: The file is closed using the `close` function after reading all lines.

### Step 3: Compile the Code

To compile the code, you can use a C compiler like GCC:

```bash
gcc -o gnl_example main.c get_next_line.c get_next_line_utils.c -Wall -Wextra -Werror
```

This will generate an executable named `gnl_example`.

### Step 4: Run the Code

After compiling, run the program using:

```bash
./gnl_example
```

This will read the `get_next_line.h` file line by line and print its contents to the terminal.
