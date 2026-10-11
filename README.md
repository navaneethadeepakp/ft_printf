# ft_printf

A custom implementation of the standard C library `printf` function. This project demonstrates a deep understanding of variadic functions, low-level standard output operations, and recursive base conversions without relying on external string-formatting libraries.

## Technical Highlights

*   **Variadic Argument Handling:** Utilizes the `<stdarg.h>` library (`va_start`, `va_arg`, `va_end`) to dynamically parse and process an unknown number of arguments based on the format string.
*   **Recursive Conversions:** Implements memory-efficient recursive functions to handle integer and hexadecimal conversions on the fly, avoiding the need for secondary string buffer allocations.
*   **Strict Error Handling:** Continuously monitors the return value of system `write` calls. If any write operation fails, the function immediately cascades a `-1` return value back to the caller, perfectly mimicking the standard `printf` error handling.
*   **Edge Case Management:** Safely handles extreme edge cases, such as explicitly printing `"(null)"` for empty string pointers and managing the exact bounds of `INT_MIN` (`-2147483648`) during signed integer conversions.

## Supported Format Specifiers

The function parses the format string and routes processing based on the following specifiers:

*   `%c` : Prints a single character.
*   `%s` : Prints a string (handles `NULL` gracefully).
*   `%p` : Prints a `void *` pointer argument in hexadecimal format, prefixed with `0x`.
*   `%d` / `%i` : Prints a signed decimal (base 10) integer.
*   `%u` : Prints an unsigned decimal (base 10) integer.
*   `%x` : Prints a number in hexadecimal (base 16) lowercase format (`0123456789abcdef`).
*   `%X` : Prints a number in hexadecimal (base 16) uppercase format (`0123456789ABCDEF`).
*   `%%` : Prints a literal percent sign.

## Build & Integration

The project uses a strict `Makefile` (`-Wall -Wextra -Werror`) to compile the source code into a static library archive. 

**1. Compile the Library**
```bash
make
```
This generates the libftprintf.a static library.

**2. Link During Compilation**
Compile executable by linking the generated static library:

```bash
cc main.c libftprintf.a
```
