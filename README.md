*This project has been created as part of the 42 curriculum by isousman.*

# Libft

## Description

**Libft** is the first project of the 42 / 1337 common core. The goal is to build
your own C library (`libft.a`): a collection of general-purpose functions that
will be reused in all the following projects of the curriculum.

The project strengthens the understanding of pointers, dynamic memory
allocation, string and memory manipulation, and linked lists. Everything is
written in C, follows the 42 Norm, compiles with `-Wall -Wextra -Werror`, and
the archive is built with `ar` (no `libtool`).

### Library overview

The library is split into three parts, all compiled by a plain `make`.

**Part 1 - Libc functions** (same prototypes and behaviors as the originals,
prefixed with `ft_`):

| Category | Functions |
|---|---|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` (return `1` or `0`) |
| Character conversion | `ft_toupper`, `ft_tolower` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_atoi` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| Allocation (`malloc`) | `ft_calloc`, `ft_strdup` |

Notes: `ft_calloc` returns a unique pointer that can be passed to `free()` when
`nmemb` or `size` is `0`. `ft_atoi` mimics the libc behavior on overflow.

**Part 2 - Additional functions** (not in the libc, or in a different form):

| Function | Description |
|---|---|
| `ft_substr` | Allocates and returns a substring of `s` starting at `start`, with a maximum length `len`. |
| `ft_strjoin` | Allocates and returns the concatenation of `s1` and `s2`. |
| `ft_strtrim` | Allocates and returns a copy of `s1` without the characters of `set` at the beginning and at the end. |
| `ft_split` | Allocates and returns a `NULL`-terminated array of strings obtained by splitting `s` with the delimiter `c`. |
| `ft_itoa` | Allocates and returns the string representation of an integer (negative numbers and `INT_MIN` handled). |
| `ft_strmapi` | Applies `f(index, char)` to each character of `s` and returns a new string of the results. |
| `ft_striteri` | Applies `f(index, &char)` to each character of `s` in place. |
| `ft_putchar_fd` | Writes a character on a file descriptor. |
| `ft_putstr_fd` | Writes a string on a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline on a file descriptor. |
| `ft_putnbr_fd` | Writes an integer on a file descriptor. |

**Part 3 - Linked list** (part of the mandatory work in version 19.3):

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node holding `content`, with `next` set to `NULL`. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Returns the number of nodes (`unsigned int`). |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Frees one node and its content using `del` (does not free the next node). |
| `ft_lstclear` | Frees a node and all its successors, then sets the list pointer to `NULL`. |
| `ft_lstiter` | Applies `f` to the content of each node. |
| `ft_lstmap` | Builds a new list by applying `f` to each content; frees everything with `del` if an allocation fails. |

### Technical choices

* No global variables.
* Helper functions are declared `static` to limit their scope to their file.
* Every allocating function checks the result of `malloc` and, on failure,
  frees everything that was previously allocated (`ft_split`, `ft_lstmap`).
* The `restrict` qualifier is not used and `-std=c99` is not passed.

## Instructions

### Requirements

A C compiler (`cc`), `make` and `ar`.

### Compilation

```bash
git clone <repository_url> libft
cd libft
make
```

| Rule | Effect |
|---|---|
| `make` / `make all` | Builds `libft.a` at the root of the repository (no unnecessary relinking). |
| `make clean` | Removes the object files. |
| `make fclean` | Removes the object files and `libft.a`. |
| `make re` | Rebuilds everything from scratch. |

### Usage

Include the header in your code:

```c
#include "libft.h"

int	main(void)
{
	char	*str;

	str = ft_strdup("Hello, 42!");
	if (!str)
		return (1);
	ft_putendl_fd(str, 1);
	free(str);
	return (0);
}
```

Compile it and link it with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -I.
```

## Resources

### References

* Linux man pages (`man 3 strlen`, `man 3 memmove`, `man 3 strlcpy`, `man 3 calloc`, `man 3 atoi`, `man 2 write`)
* [The 42 Norm](https://github.com/42School/norminette)
* [Tripouille/libftTester](https://github.com/Tripouille/libftTester) - community test suite
* [alelievr/libft-unit-test](https://github.com/alelievr/libft-unit-test) - community test suite
* *The C Programming Language*, B. Kernighan and D. Ritchie

### Use of AI

AI was used as a learning and review tool, not to write the solutions.

* **Tasks:** code review of finished functions, discussion of edge cases and
  overflow handling (`ft_atoi`, `ft_itoa`, `ft_putnbr_fd`), and checking the
  memory-cleanup paths on allocation failure (`ft_split`, `ft_lstmap`).
* **Parts of the project concerned:** `ft_atoi`, `ft_itoa`, `ft_putnbr_fd`,
  `ft_split`, `ft_lstmap`, `ft_lstclear`, the `Makefile` and this README.
* **Control practices:** the code was written by me first. Suggestions were
  never copied blindly: each one was tested (community testers,
  `norminette`) and understood well enough to be explained and modified
  during the peer evaluation.
