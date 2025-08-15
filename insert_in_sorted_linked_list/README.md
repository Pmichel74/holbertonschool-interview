# 📝 Insert in Sorted Linked List

> 🎯 **Mission**: Smartly insert a number into an already sorted linked list!

## 🤔 What is this?

Imagine you have a list of numbers arranged in order: `[1, 3, 5, 8, 10]`
You want to add the number `7` without breaking the order. It should go between `5` and `8`!

That's exactly what this project does 🚀

## 🗂️ The files

| File | Role | Emoji |
|------|------|-------|
| `0-insert_number.c` | The star of the show! Contains the magic function | ⭐ |
| `linked_lists.c` | The helpful assistants (print, add, clean) | 🔧 |
| `lists.h` | The blueprint (structures and declarations) | 📋 |
| `main.c` | The playground for testing | 🎮 |
| `test_insert` | The ready-to-use executable | ⚡ |

## 🚀 Quick start

### 1️⃣ Compile
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o test_insert
```

### 2️⃣ Run
```bash
./test_insert
```

### 3️⃣ Magic result
```
Before insertion:
0 → 1 → 2 → 3 → 4 → 98 → 402 → 1024

After inserting 27:
0 → 1 → 2 → 3 → 4 → 27 → 98 → 402 → 1024
```

## 🎯 The star function: `insert_node`

```c
listint_t *insert_node(listint_t **head, int number);
```

**What it does:**
- 🧠 Thinks: "Where should I place this number?"
- 🔍 Searches for the right position in the sorted list
- ✨ Inserts the number without breaking the order
- 💾 Returns the address of the new node

## 🕵️ How does it work?

The function is clever! It handles **4 cases**:

### Case 1: Empty list 📭
```
Before: (nothing)
Insert 5: [5]
```

### Case 2: Insert at beginning 🥇
```
Before: [5, 8, 10]
Insert 3: [3, 5, 8, 10]
```

### Case 3: Insert in middle 🎯
```
Before: [3, 5, 10]
Insert 8: [3, 5, 8, 10]
```

### Case 4: Insert at end 🏁
```
Before: [3, 5, 8]
Insert 12: [3, 5, 8, 12]
```

## 🛠️ The tools in `linked_lists.c`

### `print_listint()` 🖨️
Nicely displays your list (like shown above)

### `add_nodeint_end()` ➕
Adds an element at the end (to build the test list)

### `free_listint()` 🧹
Cleans up memory (very important!)

## 🎪 Concrete example

The `main.c` does a little demo:

1. 🏗️ Builds a list: `[0, 1, 2, 3, 4, 98, 402, 1024]`
2. 📸 Shows the list
3. ✨ Inserts `27` in the right place
4. 📸 Shows the result: `27` is now between `4` and `98`
5. 🧹 Cleans everything up

## 💡 Why is this cool?

- ⚡ **Efficient**: Finds the position in one pass
- 🛡️ **Robust**: Handles all edge cases (empty list, out of memory...)
- 🧼 **Clean**: No memory leaks, well-commented code
- 🎯 **Precise**: Always maintains list order

## 🔥 Challenges to go further

- Try inserting negative numbers
- What happens with duplicates?
- Can you modify it to sort in descending order?

---
