# get_next_line

A C function that reads one line at a time from a file descriptor without needing the input size in advance. Developed as part of the 42 curriculum.

## Interface

```c
char *get_next_line(int fd);
```

Each successful call returns a newly allocated, null-terminated line, including its newline when present. Free the returned buffer after use. A null return indicates end of input or an error.

The implementation reads chunks controlled by `BUFFER_SIZE` and keeps leftover data between calls. The bonus implementation keeps separate state for multiple file descriptors.

## Compile with your program

Requirements: a C compiler and a POSIX environment providing `read`.

For a program with your own `main.c` and `#include "get_next_line.h"`:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
  main.c get_next_line.c get_next_line_utils.c -o reader
```

For the bonus version, include `get_next_line_bonus.h` and compile the bonus files instead:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
  main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o reader_bonus
```

Choose one implementation per executable. The repository does not have a root Makefile or a standalone application entry point.

## Layout

- `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`: base implementation.
- Files ending in `_bonus`: multi-descriptor implementation.
- `tester/`: test sources, fixtures, and existing test artifacts. Review its Makefile before running it.
