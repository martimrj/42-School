*This project has been created as part of the 42 curriculum by majesus.*

# Libft

## Description

Libft is the first project of the 42 Common Core. The goal is to build our own small C library, `libft.a`, by re-implementing a selection of standard C functions and adding a few extra utilities. The library is then reused in later projects, so every function has to be correct, norm-compliant, and safe with memory.

The project has three parts:

1. **Libc re-implementations**: the same behaviour as the originals, but with an `ft_` prefix.
2. **Additional functions**: string and output helpers that are not in the libc.
3. **Bonus**: a minimal singly linked list API.

Everything is compiled with `-Wall -Wextra -Werror` and archived with `ar` into a static library.

### Part 1: libc functions

#### Character checks and conversion

| Function | Prototype | What it does |
|---|---|---|
| `ft_isalpha` | `int ft_isalpha(int c)` | Returns 1 if `c` is a letter (`A-Z`, `a-z`), 0 otherwise. |
| `ft_isdigit` | `int ft_isdigit(int c)` | Returns 1 if `c` is a decimal digit. |
| `ft_isalnum` | `int ft_isalnum(int c)` | Returns 1 if `c` is a letter or a digit. |
| `ft_isascii` | `int ft_isascii(int c)` | Returns 1 if `c` fits in the ASCII table (0 to 127). |
| `ft_isprint` | `int ft_isprint(int c)` | Returns 1 if `c` is printable (32 to 126, space included). |
| `ft_toupper` | `int ft_toupper(int c)` | Converts a lowercase letter to uppercase; anything else is returned unchanged. |
| `ft_tolower` | `int ft_tolower(int c)` | Converts an uppercase letter to lowercase; anything else is returned unchanged. |

#### Memory functions

These work on raw bytes, so they take `void *` and treat the data as `unsigned char`.

| Function | Prototype | What it does |
|---|---|---|
| `ft_memset` | `void *ft_memset(void *s, int c, size_t n)` | Fills the first `n` bytes of `s` with the byte `c` and returns `s`. |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Sets `n` bytes to zero. |
| `ft_memcpy` | `void *ft_memcpy(void *dest, const void *src, size_t n)` | Copies `n` bytes from `src` to `dest`. The areas must not overlap. |
| `ft_memmove` | `void *ft_memmove(void *dest, const void *src, size_t n)` | Same as `ft_memcpy`, but correct even when the areas overlap. |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | Returns a pointer to the first byte equal to `c` within `n` bytes, or `NULL`. A zero byte is not treated as an end marker. |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares `n` bytes and returns the difference of the first pair that differs (0 if equal). |
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size)` | Allocates `nmemb * size` bytes set to zero. Returns `NULL` if the multiplication would overflow or if `malloc` fails. |

#### String functions

| Function | Prototype | What it does |
|---|---|---|
| `ft_strlen` | `size_t ft_strlen(const char *s)` | Returns the length of `s`, not counting the terminating `'\0'`. |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | Copies at most `size - 1` characters and always terminates the result (if `size > 0`). Returns the length of `src`. |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size)` | Appends `src` to `dst` without exceeding `size` bytes in total. Returns the length it tried to create, so truncation can be detected. |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | Returns a pointer to the first occurrence of `c` in `s`, or `NULL`. Searching for `'\0'` returns a pointer to the terminator. |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | Same as `ft_strchr`, but returns the last occurrence. |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares at most `n` characters, stopping at the first difference or at `'\0'`. Characters are compared as `unsigned char`. |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len)` | Looks for `little` inside the first `len` characters of `big`. Returns `big` if `little` is empty, `NULL` if there is no match. |
| `ft_atoi` | `int ft_atoi(const char *nptr)` | Skips leading whitespace, reads one optional sign, then converts consecutive digits to an `int`. |
| `ft_strdup` | `char *ft_strdup(const char *s)` | Returns a freshly allocated copy of `s`. The caller must free it. |

### Part 2: additional functions

| Function | Prototype | What it does |
|---|---|---|
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Allocates and returns a substring of at most `len` characters starting at index `start`. If `start` is past the end, the result is an empty string. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Allocates a new string that is `s1` followed by `s2`. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Returns a copy of `s1` without any leading or trailing characters that belong to `set`. |
| `ft_split` | `char **ft_split(char const *s, char c)` | Splits `s` on the delimiter `c` and returns a `NULL`-terminated array of new strings. Consecutive delimiters do not produce empty words. If any allocation fails, everything already allocated is freed and `NULL` is returned. |
| `ft_itoa` | `char *ft_itoa(int n)` | Converts an integer to a newly allocated string, including negative numbers and `INT_MIN`. |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Builds a new string where each character is the result of `f(index, character)`. The original string is untouched. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | Calls `f(index, &character)` on every character, so `f` can modify the string in place. |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Writes one character to the file descriptor `fd`. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Writes a string to `fd`. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Writes a string to `fd`, followed by a newline. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Writes an integer to `fd`, including `INT_MIN`. |

The usual values for `fd` are `1` (standard output) and `2` (standard error), but any open file descriptor works.

### Bonus: linked lists

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

Each node stores a generic pointer (`content`) and the address of the next node. The last node points to `NULL`. A list is represented by a pointer to its first node. Functions that may change which node is first take a `t_list **`.

| Function | Prototype | What it does |
|---|---|---|
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Allocates a node holding `content`, with `next` set to `NULL`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Inserts `new` at the beginning of the list. |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | Counts the nodes. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Returns the last node. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Appends `new` at the end. An empty list becomes just `new`. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees a node's content using `del`, then frees the node itself. |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Deletes a node and all the ones after it, then sets `*lst` to `NULL`. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Applies `f` to the content of every node. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Builds a new list from the results of `f`. If an allocation fails, the partial new list is cleaned with `del` and `NULL` is returned. |

## Implementation notes

A few decisions worth knowing about:

- **`ft_memmove`** compares the two addresses to choose the copy direction. If `dest` is before `src` it copies forwards; otherwise it copies backwards, so no source byte is overwritten before it is read.
- **`ft_strlcat`** measures `dst` only up to `size` bytes. A buffer that has no `'\0'` inside `size` is therefore never read past its limit.
- **`ft_calloc`** checks `nmemb > SIZE_MAX / size` before multiplying, so an overflow can never produce a block smaller than the caller expects.
- **`ft_itoa`** converts through a `long`, because the absolute value of `INT_MIN` does not fit in an `int`.
- **`ft_split`** and **`ft_lstmap`** release every partially built result when an allocation fails. In `ft_lstmap`, the value returned by `f` is stored before the node is created, so it can be freed if node allocation fails.
- Pointer parameters that must not be modified are declared `const`, and the casts back to a non-const return type are explicit.

## Instructions

### Requirements

- A C compiler (`cc`) and `make`
- `ar` (part of the usual build tools)

### Build

From the project folder:

```bash
make          # builds libft.a (mandatory part)
make bonus    # also adds the linked list functions
make clean    # removes the object files
make fclean   # removes object files and libft.a
make re       # fclean followed by a full rebuild
```

### Use it in your own program

Include the header and link against the library:

```c
#include "libft.h"

int	main(void)
{
	ft_putendl_fd("hello, libft", 1);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o demo
./demo
```

If the header lives in another directory, add `-I<path to libft.h>`.

### Testing

Each function was checked against the real libc version (or against the expected output when no libc version exists) and run with AddressSanitizer (`-fsanitize=address`) to catch out-of-bounds accesses and memory leaks. Edge cases include empty strings, `n = 0`, `NULL` arguments where the original tolerates them, and simulated allocation failures.

## Resources

- Linux manual pages: `man 3 <function>` for each re-implemented function.
- The 42 Libft subject.
- Documentation for AddressSanitizer and Valgrind.
- Articles and tutorials on pointers, function pointers, and singly linked lists in C.

**AI usage:** Claude (Anthropic) was used as a study aid: to explain concepts (pointers, `size_t`, function pointers, linked lists, memory ownership), to review my code and point out bugs, to help read compiler, sanitizer, and tester output, and to help draft this README. Some corrected snippets suggested during review were used or adapted. I read, tested, and understood every function before including it.
