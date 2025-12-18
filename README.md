# ft_printf - My Custom Printf

**Score:** 100/100

## About

`ft_printf` is a recreation of the standard C library function `printf`. The goal is to handle variable numbers of arguments and format them into a string output. This project is a deep dive into **variadic functions** in C.

## Variadic Functions

Standard functions in C have a fixed number of arguments. `printf`, however, can take 1, 2, or 100 arguments depending on the format string.

```c
int ft_printf(const char *format, ...);
```

To handle this, we use the `<stdarg.h>` macros:
1. `va_start`: Initializes the list
2. `va_arg`: Retrieves the next argument (you must know the type!)
3. `va_end`: Cleans up the list

## Supported Conversions

- `%c`: Characters
- `%s`: Strings
- `%p`: Pointers (memory addresses in hex)
- `%d` / `%i`: Integers
- `%u`: Unsigned integers
- `%x` / `%X`: Hexadecimal (lowercase/uppercase)
- `%%`: The percent sign itself

## Challenges I Faced

### The "Missing Character" Bug

I had a tricky bug where printing two formats back-to-back without spaces (e.g., `"%d%i"`) would cause characters to be skipped.

**The cause:** My parsing logic for finding the `%` symbol was too aggressive. When I found a `%`, I would check the next character to determine the type, advancing the index by 2. If the next character was another `%`, my logic would desync.

**The fix:** Refined the parsing loop to handle consecutive format specifiers properly.

### File Descriptors

Unlike `get_next_line`, `printf` prints to **stdout**. While the standard `printf` uses buffered IO, my implementation writes directly using `write`, so I had to be careful about return values to accurately mimic the character count return.

## Usage

```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello %s, you are %d years old.\n", "User", 42);
    ft_printf("Pointer address: %p\n", &main);
    return (0);
}
```

## Compilation

```bash
make        # Compiles the library
make clean  # Removes object files
make fclean # Removes everything
make re     # Recompiles from scratch
```

## What I Learned

- **Variadic functions:** How to handle unknown numbers of arguments
- **Type handling:** Managing different data types through a single interface
- **Parsing:** Building a robust format string parser

---

*Project developed at 42 Lausanne*
