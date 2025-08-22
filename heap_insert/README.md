# 🌳 Max Heap Insert - Binary Tree Data Structure

![C](https://img.shields.io/badge/language-C-blue.svg)
![Algorithm](https://img.shields.io/badge/algorithm-heap-green.svg)
![License](https://img.shields.io/badge/license-MIT-orange.svg)

## 📋 Overview

This project implements **element insertion** into a **maximum heap** (max heap), a tree data structure where:
- 🔺 Each parent node has a value **greater than or equal** to its children
- 📦 The tree is **complete** (all levels filled except the last, filled left to right)

## 🎯 Algorithm Overview

The insertion process follows **3 key steps**:

### 1️⃣ Create New Node
```c
new_node = binary_tree_node(NULL, value);
```
🎯 **Purpose:** Create an isolated node with the target value

### 2️⃣ Find Correct Position  
```c
size = node_count(*root) + 1;
*root = ins_max_heap(*root, new_node, 0, size - 1);
```
🎯 **Purpose:** Maintain complete tree structure using indexing:
- Parent: `(i-1)/2`
- Left child: `2*i+1`
- Right child: `2*i+2`

### 3️⃣ Heapify (Bubble Up)
```c
return (bottom_up_heapify(new_node));
```
🎯 **Purpose:** Restore max heap property by moving node upward if needed

## 📁 Project Structure

```
heap_insert/
├── 📄 binary_trees.h          # Header with structures and prototypes
├── 🔧 0-binary_tree_node.c    # Function to create a new node
├── 🚀 1-heap_insert.c         # Main heap insertion function
├── 🎨 binary_tree_print.c     # Tree visualization utility
├── ⚡ 1-main.c                # Test program
├── 🛠️  Makefile               # Build script
├── 🧪 test.sh                 # Automated test script
└── 📖 README.md               # This file
```

## 🚀 Quick Start

### 🔨 Build the Project
```bash
make
```

### 🧪 Run Tests
```bash
make test
# or
./test.sh
```

### 🧹 Clean Up
```bash
make clean
```

## 💻 Usage Example

```c
#include "binary_trees.h"

int main(void)
{
    heap_t *root = NULL;
    heap_t *node;

    // Insert values into the heap
    node = heap_insert(&root, 98);   // 🌱 Insert 98
    node = heap_insert(&root, 402);  // 🌿 Insert 402
    node = heap_insert(&root, 12);   // 🍃 Insert 12
    
    binary_tree_print(root);         // 🎨 Visualize the tree
    return (0);
}
```

## 📊 Visual Example

**Step-by-step insertion of values: 98 → 402 → 12**

```
Insert 98:                Insert 402:              Insert 12:
                         
(098)                     .--(402)                .--(402)--.
                        (098)                   (098)     (012)
```

## ⚡ Performance

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| **Insert** | `O(log n)` | `O(1)` |
| **Find Position** | `O(log n)` | `O(log n)` |
| **Heapify** | `O(log n)` | `O(1)` |

## 🔧 Core Functions

| Function | 📝 Description | ⚡ Complexity |
|----------|---------------|--------------|
| `heap_insert()` | 🎯 Main insertion function | O(log n) |
| `binary_tree_node()` | 🆕 Create new node | O(1) |
| `node_count()` | 📊 Count nodes in tree | O(n) |
| `ins_max_heap()` | 📍 Find correct position | O(log n) |
| `bottom_up_heapify()` | 📈 Restore heap property | O(log n) |

## 🛡️ Properties Maintained

✅ **Complete Structure:** All levels filled except the last  
✅ **Max Heap Property:** parent ≥ children (≥ allows duplicates)  
✅ **Parent-Child Links:** Correctly established  
✅ **Left-to-Right Filling:** Maintains complete tree structure  

## 🧪 Test Suite

The program tests sequential insertion of values:
```
🔢 Test Values: 98, 402, 12, 46, 128, 256, 512, 50
```

Each insertion displays the resulting tree for visual verification.

### 🎨 Sample Output
```bash
$ ./heap_insert
Inserted: 98
(098)

Inserted: 402
  .--(402)
(098)

Inserted: 12
  .--(402)--.
(098)     (012)

...
```

## 🎓 Learning Objectives

After completing this project, you will understand:

- 🌳 **Binary Tree Structures** and their properties
- 📦 **Complete Binary Trees** and indexing systems
- 🔺 **Heap Data Structures** and their applications
- 🔄 **Tree Traversal** and navigation algorithms
- 📈 **Heapify Operations** and property maintenance

## 🔢 Binary Indexing Magic

Understanding the binary representation of indices reveals the navigation pattern:

| Index | Binary | Navigation Path |
|-------|--------|-----------------|
| 0 | `0` | Root |
| 1 | `1` | Left |
| 2 | `10` | Right |
| 3 | `11` | Left → Left |
| 4 | `100` | Left → Right |
| 5 | `101` | Right → Left |
| 6 | `110` | Right → Right |

🎯 **Navigation Rule:** Ignore the first bit (always 1), then read remaining bits:
- `0` = go Right
- `1` = go Left

## 🐛 Debugging Tips

### Common Issues:
- 🚨 **Segmentation Fault:** Check for NULL pointer dereferences
- 🔍 **Wrong Position:** Verify indexing calculations
- ⚖️ **Heap Property Violated:** Ensure heapify runs after placement

### Debugging Tools:
```bash
# Memory checking
valgrind --leak-check=full ./heap_insert

# Debug compilation
gcc -g -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o heap_insert_debug
```

## 🎯 Real-World Applications

Max heaps are used in:
- 📊 **Priority Queues** (operating system scheduling)
- 📈 **Heap Sort Algorithm** (O(n log n) sorting)
- 🗺️ **Graph Algorithms** (Dijkstra's shortest path)
- 🗜️ **Data Compression** (Huffman coding)

## 🤝 Contributing

1. Fork the project
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📜 License

This project is part of the Holberton School curriculum.

## 👨‍💻 Author

**Pmichel74** - Holberton School Student

---

⭐ **Star this repo if you found it helpful!** ⭐
