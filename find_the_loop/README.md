
# 0. Find the loop

Write a function that detects and returns the start of a loop in a singly
linked list.

- Prototype: `listint_t *find_listint_loop(listint_t *head);`
- Returns: The address of the node where the loop starts, or `NULL` if there
  is no loop.
- Constraints: do not use `malloc`, `free`, or arrays.
- Variable limit: you may declare at most two variables inside the function.

Local test and compilation:

```sh
cd holbertonschool-interview/find_the_loop
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-find_loop.c lib.c -o test_find_loop && ./test_find_loop
gcc -Wall -Werror -Wextra -pedantic test.c 0-find_loop.c -o test_custom && ./test_custom
```

This folder includes a minimal `lists.h` header declaring `listint_t` and the
necessary prototypes so the provided tests compile out of the box.
