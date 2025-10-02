# 🔄 Linked List Cycle

## 📝 Description

This project is part of the technical interview preparation exercises at Holberton School. The objective is to implement a C function that detects if a singly linked list contains a cycle.

## 🧠 Concept

A cycle in a linked list occurs when a node points to a previous node in the list, creating an infinite loop when traversing the list.

## 🔍 Algorithm Used

The implementation uses **Floyd's Cycle-Finding Algorithm**, also known as the "Tortoise and Hare" algorithm. This algorithm uses two pointers moving at different speeds:
- A slow pointer (tortoise) that advances one node at a time
- A fast pointer (hare) that advances two nodes at a time

If the list contains a cycle, the fast pointer will eventually catch up to the slow pointer.

## 📋 Prototype

```c
int check_cycle(listint_t *list);
```

## 📤 Return Value

- `0` if there is no cycle in the list
- `1` if there is a cycle in the list

## 📚 Data Structure

```c
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

## ⚙️ Complexity

- **Time complexity**: O(n) where n is the number of nodes in the list
- **Space complexity**: O(1) as only two pointers are used, regardless of the list size

## 🚫 Restrictions

Only the following functions are allowed:
- write
- printf
- putchar
- puts
- malloc
- free

## 🧪 Compilation and Execution

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
./cycle
```

## 📝 Example Output

```
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
```

## 👨‍💻 Author

Patrick Michel