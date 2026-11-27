*This project has been created as part of the 42 curriculum by majesus.*

# ft_printf

## Description

In this project, I implement my own version of `printf()` from the C standard library, `ft_printf()`, to understand how the original function works.

One of the main concepts explored is **variadic functions**, which accept a variable number of arguments. Each variadic function defines its own way of knowing how many arguments it received and of which types: in `ft_printf()`, this is determined at runtime from the conversion specifiers in the format string.

The implementation reproduces the main behaviors of the original function, following the requirements of the **mandatory part** of the 42 project.

## Table of Contents

- [Function Overview](#function-overview)
  - [Prototype](#prototype)
  - [Parameters](#parameters)
  - [Return Value](#return-value)
  - [Supported Conversions](#supported-conversions)
  - [Special Cases](#special-cases)
  - [Limitations](#limitations)
- [Algorithm and Data Structures](#algorithm-and-data-structures)
  - [Algorithm Overview](#algorithm-overview)
  - [Recursive Number Conversion](#recursive-number-conversion)
  - [Output and Error Handling](#output-and-error-handling)
  - [Variadic Arguments with va_list](#variadic-arguments-with-va_list)
  - [Lookup Tables for Hexadecimal Conversion](#lookup-tables-for-hexadecimal-conversion)
  - [String Traversal](#string-traversal)
  - [Memory Management](#memory-management)
- [Instructions](#instructions)
  - [Requirements](#requirements)
  - [Compilation](#compilation)
  - [Installation](#installation)
  - [Usage](#usage)
- [Resources](#resources)
  - [Documentation and References](#documentation-and-references)
  - [AI Usage](#ai-usage)

## Function Overview

### Prototype

```c
int	ft_printf(const char *format, ...);
```

### Parameters

The function takes two kinds of parameters:

- `const char *format` — a pointer to a format string whose characters cannot be modified through this pointer. It contains the text to print and the specifiers that determine how the additional arguments are interpreted.
- `...` — the variable arguments, whose number and types depend on the specifiers in `format`.

### Return Value

- **On success** — the total number of characters printed.
- **On error** — `-1`, in the following cases:
  - `format` is `NULL`.
  - A call to `write()` fails.

**Note:** Because the output is not buffered, a write error can occur after part of the output has already been printed. Those characters remain in the output, even though the function returns `-1`.

### Supported Conversions

`ft_printf()` supports the following conversion specifiers:

| Specifier | Description |
| --- | --- |
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in lowercase hexadecimal, prefixed with `0x`. |
| `%d` / `%i` | Prints a signed decimal integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned integer in lowercase hexadecimal. |
| `%X` | Prints an unsigned integer in uppercase hexadecimal. |
| `%%` | Prints a percent sign (`%`). |

### Special Cases

#### `NULL` String (`%s`)

When a `NULL` pointer is passed to `%s`, the implementation prints `(null)`.

**Example:**
```c
#include "ft_printf.h"

int	main(void)
{
	char	*name;

	name = NULL;
	ft_printf("Name: %s\n", name);
	return (0);
}
```

**Output:**
```
Name: (null)
```

#### `NULL` Pointer (`%p`)

When a `NULL` pointer is passed to `%p`, the implementation prints `(nil)`.

**Example:**
```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Address: %p\n", NULL);
	return (0);
}
```

**Output:**
```
Address: (nil)
```

**Note:** These behaviors for `NULL` strings and pointers follow the conventions of the glibc `printf()` used as the reference on the 42 campus. They are not necessarily the same in every C library.

### Limitations

The bonus part was not implemented, so the following features are not supported:

- Formatting flags (`-`, `0`, `#`, `+` and space).
- Minimum field width.
- Precision.

In addition, as required by the subject, the buffer management of the original `printf()` is not implemented.

## Algorithm and Data Structures

### Algorithm Overview

`ft_printf()` uses a **sequential traversal**: it reads the format string character by character, in a single pass.

The work is split among functions with specific responsibilities, so that parsing the string, identifying conversions and printing arguments are not concentrated in a single function:

| Function | Responsibility |
| --- | --- |
| `ft_printf()` | Traverses the string, manages the variable arguments and counts the characters printed. |
| `ft_is_valid_type()` | Checks whether the specifier belongs to `TYPESET`, which also includes `%`. |
| `ft_print_type()` | Retrieves the argument and calls the matching conversion function, or prints `%` for the `%%` sequence. |
| `ft_putchar()` | Writes a single character with `write()`. |

`ft_printf()` walks through `format` by advancing the pointer itself. At each iteration, it decides how to handle the current character:

1. **Regular character** — calls `ft_putchar()` to print it.
2. **Valid conversion** — when the character after `%` belongs to `TYPESET`, as checked by `ft_is_valid_type()`, `ft_printf()` moves the pointer to the specifier and calls `ft_print_type()` to process the matching argument. This includes the `%%` sequence: since `%` is in `TYPESET`, `ft_print_type()` prints a single `%` without reading any argument.
3. **Invalid conversion** — when the character after `%` is not a recognized specifier, the `%` is printed as a regular character, and the character after it is printed in the next iteration. As a result, the sequence is printed unchanged and no argument is consumed. This is an implementation choice, since the **ISO C standard** classifies invalid conversion specifications as undefined behavior.

**Example:**
```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("<%y>\n");
	return (0);
}
```

**Output:**
```
<%y>
```

The call returns `5`, the number of characters printed, including the newline. A `%` at the end of the format string is also printed as a regular character. For `<%y>`, this output is the same as that of the glibc `printf()`.

After each step, `ft_printf()` adds the number of characters printed to `count`, stopping as soon as an error is reported (see [Output and Error Handling](#output-and-error-handling)).

### Recursive Number Conversion

**Functions:** `ft_putnbr()`, `ft_putunbr()` and `ft_puthex()`.

To print integers in decimal or hexadecimal, I chose to use **recursion**.

The main challenge is printing the digits from left to right, starting with the most significant one.

The solution is to divide the number by the base repeatedly, stacking the calls on the call stack. As those calls return, the modulo operator (`%`) yields each digit, which is printed in the correct order.

- `ft_putnbr()` — converts signed integers to base 10. It uses `long` to handle negative values correctly, including `INT_MIN`, and prints the sign separately.
- `ft_putunbr()` — converts unsigned integers to base 10.
- `ft_puthex()` — converts values to base 16, using the character table it receives as an argument. It takes a `uintptr_t`, an unsigned integer type large enough to hold a pointer, so the same function handles both the 32-bit `unsigned int` of `%x` / `%X` and the 64-bit address of `%p`.

**Example with `1234` in base 10:**
```
Recursive calls:

1234 / 10 = 123
 123 / 10 = 12
  12 / 10 = 1

Returning from the calls:

   1 % 10 = 1
  12 % 10 = 2
 123 % 10 = 3
1234 % 10 = 4
```

**Output:**
```
1234
```

#### Why recursion?

- It reduces the code needed to print the digits in the correct order.
- It needs no temporary buffer to store the characters.
- It avoids dynamic allocation, unlike `ft_itoa()` from **libft**.
- It uses few local variables, which makes it easier to comply with the 42 **Norm**.

An alternative would be a local array such as `char	arr[11];`, large enough for the 10 digits and the sign of a 32-bit decimal integer, without a null terminator (`\0`). This approach would not need `malloc()` either, and could print all the characters with a single call to `write()`, but I preferred recursion for the reasons above.

#### Recursion Depth

The maximum depth depends on how many digits are needed to represent the number in the chosen base. Assuming 32-bit integers and 64-bit pointers:

| Conversion | Function | Maximum calls |
| --- | --- | --- |
| `%d` / `%i` | `ft_putnbr()` | 10 |
| `%u` | `ft_putunbr()` | 10 |
| `%x` / `%X` | `ft_puthex()` | 8 |
| `%p` | `ft_puthex()` | 16 |

For example, `INT_MIN` has 10 decimal digits and a minus sign, which `ft_putnbr()` handles separately. The recursion depth is therefore small and bounded by the numeric types used.

### Output and Error Handling

**Functions:** `ft_putchar()`, `ft_putstr()`, `ft_putnbr()`, `ft_putunbr()`, `ft_puthex()`, `ft_putptr()` and `ft_printf()`.

All output goes through `ft_putchar()`, the only function in the implementation that calls `write()` directly, writing one character to standard output. Centralizing the writes in a single function allows consistent error handling throughout the implementation.

```c
int	ft_putchar(char c)
{
	if (write(STDOUT_FILENO, &c, 1) != 1)
		return (-1);
	return (1);
}
```

The return value of `write()` is checked to detect failures:

- **Return value of `1`** — the character was written successfully.
- **Any other return value** — the write is treated as a failure.

Instead of the literal `1`, the call uses `STDOUT_FILENO`, a macro defined in `<unistd.h>` (the same header that declares `write()`) that represents the standard output file descriptor. This avoids a magic number and makes it explicit that the output goes to `stdout`.

`ft_putstr()`, `ft_putnbr()`, `ft_putunbr()` and `ft_puthex()` print through `ft_putchar()`, accumulating the number of characters written and checking each return value. `ft_putptr()` reuses `ft_putstr()` to print `(nil)` or the `0x` prefix, and `ft_puthex()` to print the address in hexadecimal.

If a failure occurs, the error is propagated up to `ft_printf()`, which stops processing, calls `va_end()` and returns `-1`.

#### Performance

Since every character goes through `ft_putchar()`, the implementation makes one `write()` call per character. Each system call has a cost, so this approach can be less efficient than the original `printf()`, which buffers its output. I chose to prioritize simplicity and centralized error handling.

### Variadic Arguments with `va_list`

**Functions:** `ft_printf()` and `ft_print_type()`.

The main data structure used to process the variable arguments is `va_list`, provided by the `<stdarg.h>` header. It gives access to the arguments of a variadic function through the following macros:

- `va_start()` — initializes access to the variable arguments.
- `va_arg()` — retrieves the next argument, as the specified type.
- `va_end()` — ends access to the arguments.

In `ft_printf()`, a `va_list` variable is initialized with `va_start(args, format)`. Its address (`&args`) is passed to `ft_print_type()`, where `va_arg(*args, type)` retrieves the argument matching the specifier found.

#### Why pass `va_list` by pointer?

So that the functions share and update the same reading state, keeping the current position after each call to `va_arg()`. This way, the arguments are consumed in the correct order, without restarting from the beginning.

Since the internal representation of `va_list` is platform-dependent, using a pointer also avoids relying on the details of that representation.

### Lookup Tables for Hexadecimal Conversion

**Functions:** `ft_print_type()`, `ft_putptr()` and `ft_puthex()`.

Hexadecimal conversion uses two macros defined in `ft_printf.h`:

- `HEX_LOWER` — `"0123456789abcdef"`
- `HEX_UPPER` — `"0123456789ABCDEF"`

These strings work as **lookup tables**: a value from 0 to 15 is converted directly into its hexadecimal character, using `% 16` as the table index. The table is chosen once, by the caller, and passed to `ft_puthex()`:

- `ft_print_type()` — passes `HEX_LOWER` for `%x` and `HEX_UPPER` for `%X`.
- `ft_putptr()` — passes `HEX_LOWER` for `%p`.

**Example with `3054` in base 16:**
```
Recursive calls:

3054 / 16 = 190
 190 / 16 = 11

Returning from the calls:

  11 % 16 = 11 -> b
 190 % 16 = 14 -> e
3054 % 16 = 14 -> e
```

**Output:**
```
bee
```

#### Why use these macros?

- They make the purpose of the characters explicit, which makes the code easier to read and maintain.
- They avoid repeating string literals in different parts of the code.
- They let `ft_puthex()` handle `%x`, `%X` and `%p`: printing uppercase letters only requires passing the other table, with no change to the conversion algorithm.
- Since the caller passes the table directly, the choice is made only once, instead of being repeated at every recursive call.

### String Traversal

**Functions:** `ft_printf()`, `ft_is_valid_type()` and `ft_putstr()`.

Strings are traversed in place, with a pointer or an index, without copying or modifying them, so no auxiliary structures are needed:

- `ft_printf()` — advances the `format` pointer itself (`format++`) and reads the character after a `%` with `*(format + 1)`. When that character is a valid specifier, the pointer is first moved to it, so the next iteration starts after the specifier.
- `ft_is_valid_type()` — uses its own index to walk through `TYPESET` and check whether a specifier is recognized.
- `ft_putstr()` — walks through the string with `len`, printing each character and counting the output length.

### Memory Management

**Functions:** `ft_printf()`, `ft_putnbr()`, `ft_putunbr()` and `ft_puthex()`.

The implementation does not use dynamic memory allocation. All processing relies on local variables, the variable arguments and the call stack of the recursive functions, whose depth is bounded (see [Recursion Depth](#recursion-depth)).

#### Why not use `malloc()`?

Since the conversions never need to store a variable amount of data, dynamic allocation would only add unnecessary complexity. Avoiding `malloc()` and `free()` removes the need to handle allocation failures, free memory and prevent leaks.

## Instructions

### Requirements

The following tools are required to compile the project:

- `cc` — a C compiler (e.g., Clang on macOS or GCC on Linux).
- `make` — automates the build.
- `ar` — creates the static library archive.

### Compilation

From the root directory of the repository, run:

```sh
make
```

This command compiles the source files with the `-Wall -Wextra -Werror` flags and creates the static library `libftprintf.a`.

The following `Makefile` targets are also available:

| Command | Description |
| --- | --- |
| `make` or `make all` | Compiles the library. |
| `make clean` | Removes the object files (`.o`). |
| `make fclean` | Removes the object files (`.o`) and `libftprintf.a`. |
| `make re` | Removes the generated files and recompiles the library from scratch. |

### Installation

No installation is required. `libftprintf.a` is a static library that is linked directly into a C program at compile time, as shown in [Usage](#usage) below.

### Usage

Include the `ft_printf.h` header in your C program. For example, a `main.c` file:

```c
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("Hi %s, you are %d years old\n", "Ana", 20);
	ft_printf("Hex: %x / %X | Unsigned: %u | Percent: %%\n", 3054, 3054, 4294967295u);
	ft_printf("Pointer: %p | NULL string: %s\n", NULL, NULL);
	ft_printf("The first line has %d characters.\n", len);
	return (0);
}
```

Assuming `main.c` is located in the root directory of the repository, compile and link it with the library:

```sh
cc -Wall -Wextra -Werror -I./includes/ main.c libftprintf.a -o example
```

Run the resulting executable:

```sh
./example
```

**Output:**
```
Hi Ana, you are 20 years old
Hex: bee / BEE | Unsigned: 4294967295 | Percent: %
Pointer: (nil) | NULL string: (null)
The first line has 29 characters.
```

**Notes:**

- `-I./includes/` — tells the compiler where to find `ft_printf.h`.
- `libftprintf.a` — the library linked into the executable. As a static library, it cannot be executed on its own.
- `-o example` — sets the name of the resulting executable.

## Resources

### Documentation and References

#### Official Documentation

- **Linux Manual Pages** — used to understand the behavior, return values and edge cases of the functions and features related to the project:
  - `man 3 printf` — behavior, conversion specifiers and return values of `printf()`.
  - `man 3p fprintf` — POSIX specification of the `printf()` family (`man 3p printf` refers to this page), which defers to the ISO C standard and defines invalid conversion specifications as undefined behavior.
  - `man 2 write` — how the `write()` system call works, its return values and error handling.
  - `man 3 stdarg` — use of variable arguments in C.
  - `man 3 fflush` — how output buffers are flushed, as a reference for understanding buffering in the C library.
- **42 Documentation** — the project subject was used to check the requirements, allowed functions and mandatory conversions. The Norm documentation was used as a reference for code style and organization rules.

#### Articles and Online References

- [Variadic Functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/) — GeeksforGeeks article used to understand how variadic functions are implemented and how they work in C.
- [Variadic functions](https://cppreference.com/c/variadic) — cppreference documentation on the `<stdarg.h>` features used to access variable arguments.

### AI Usage

I used Claude as a tutor, in a guided mode. It explained concepts, pointed out the kind of error in my code, gave hints and suggested how to test each part. It did not give me the code of the functions: I wrote it myself, and I can explain it.

**Topics covered:**

- **Defined, implementation-defined and undefined behavior** — applied to a lone `%` in the format string and to `NULL` passed to `%s` and `%p`.
- **Output buffering** — the difference between the buffered output of `printf()` and direct calls to `write()`.
- **Variadic functions** — how `va_start()`, `va_arg()` and `va_end()` work, with `va_list` acting as a cursor over the arguments.
- **Lookup tables** — what they are and how they work.
- **Recursion** — how the digits are printed in the correct order, traced step by step with a small number.
