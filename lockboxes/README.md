# 🔐 Lockboxes - Algorithm Challenge

![Python](https://img.shields.io/badge/language-Python-blue.svg)
![Algorithm](https://img.shields.io/badge/algorithm-graph_traversal-green.svg)
![Difficulty](https://img.shields.io/badge/difficulty-medium-orange.svg)

## 📋 Problem Description

You have `n` numbered boxes placed in front of you. Each box is locked and can only be opened with the correct key. Some boxes may contain keys that can unlock other boxes.

**The Challenge:** Determine if **all boxes** can be opened starting with the first box (box 0), which is always unlocked.

## 🎯 Algorithm Overview

This problem is essentially a **graph traversal** where:
- 📦 **Boxes** = Nodes
- 🔑 **Keys** = Edges  
- 🎯 **Goal** = Reach all nodes (boxes) starting from node 0

### Solution Approach: **Breadth-First Search (BFS)**

1. 🚀 **Start** with box 0 (always unlocked)
2. 🔍 **Explore** all keys in the current box
3. 🔓 **Unlock** new boxes with available keys
4. 🔄 **Repeat** until no more boxes can be opened
5. ✅ **Check** if all boxes have been opened

## 📁 Project Structure

```
lockboxes/
├── 📄 0-lockboxes.py    # Main algorithm implementation
├── 🧪 0-main.py         # Test cases
└── 📖 README.md         # This documentation
```

## 💻 Usage

### 🔧 Function Signature
```python
def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened using available keys
    
    Args:
        boxes (list): List of lists where boxes[i] contains keys
                     for other boxes
    
    Returns:
        bool: True if all boxes can be opened, False otherwise
    """
```

### 📝 Example Usage

```python
#!/usr/bin/python3
from lockboxes import canUnlockAll

# Example 1: All boxes can be opened
boxes = [[1], [2], [3], [4], []]
result = canUnlockAll(boxes)
print(result)  # Output: True

# Example 2: Complex key distribution
boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
result = canUnlockAll(boxes)
print(result)  # Output: True

# Example 3: Not all boxes can be opened
boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
result = canUnlockAll(boxes)
print(result)  # Output: False
```

## 🧪 Test Cases

### ✅ Test Case 1: Linear Chain
```python
boxes = [[1], [2], [3], [4], []]
# Box 0 → Box 1 → Box 2 → Box 3 → Box 4
# Result: True ✅
```

**Explanation:** Each box contains the key to the next box, forming a chain.

### ✅ Test Case 2: Complex Network
```python
boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
# Multiple keys per box, interconnected network
# Result: True ✅
```

**Explanation:** Multiple pathways exist to reach all boxes.

### ❌ Test Case 3: Unreachable Box
```python
boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
# Box 5 contains key to box 6, but box 5 is unreachable
# Result: False ❌
```

**Explanation:** No key exists to open box 5, making box 6 unreachable.

## 🔍 Algorithm Walkthrough

### Example: `boxes = [[1, 4], [2], [0, 4], [3], [], [4], [5]]`

```
Initial State:
📦 Box 0: [1, 4] (unlocked)
🔒 Box 1: [2] (locked)
🔒 Box 2: [0, 4] (locked)
🔒 Box 3: [3] (locked)
🔒 Box 4: [] (locked)
🔒 Box 5: [4] (locked)
🔒 Box 6: [5] (locked)

Step 1: Start with Box 0
🔑 Keys found: [1, 4]
📦 Unlock Box 1 and Box 4

Step 2: Process Box 1
🔑 Keys found: [2]
📦 Unlock Box 2

Step 3: Process Box 4
🔑 Keys found: []
📦 No new boxes to unlock

Step 4: Process Box 2
🔑 Keys found: [0, 4] (already have these)
📦 No new boxes to unlock

Final: Boxes 0,1,2,4 are unlocked
❌ Boxes 3,5,6 remain locked → Return False
```

## ⚡ Performance Analysis

| Aspect | Complexity |
|--------|------------|
| **Time** | `O(N + K)` |
| **Space** | `O(N)` |

Where:
- `N` = Number of boxes
- `K` = Total number of keys across all boxes

### **Why O(N + K)?**
- We visit each box at most once: `O(N)`
- We process each key at most once: `O(K)`
- BFS ensures optimal traversal

## 🎓 Key Concepts

### **Graph Theory**
- 🔗 **Directed Graph:** Keys point from one box to another
- 🚀 **Reachability:** Can we reach all nodes from node 0?
- 🌐 **Connected Component:** All reachable boxes form one component

### **Algorithm Design**
- 📊 **BFS Traversal:** Systematic exploration of boxes
- 📋 **State Tracking:** Remember which boxes are opened
- 🔄 **Queue Management:** Process boxes in discovery order

### **Problem-Solving Pattern**
This algorithm pattern applies to:
- 🗺️ **Network connectivity** problems
- 🧩 **Puzzle solving** (escape rooms, mazes)
- 🔐 **Access control** systems
- 🌐 **Web crawling** and link analysis

## 🚀 Running the Code

### **Execute Tests**
```bash
python3 0-main.py
```

### **Expected Output**
```
True
True
False
```

### **Import in Your Code**
```python
from lockboxes import canUnlockAll

# Your implementation here
```

## 🐛 Edge Cases Handled

✅ **Empty boxes list:** `[]` → `True` (vacuous truth)  
✅ **Single box:** `[[]]` → `True` (box 0 is unlocked)  
✅ **Invalid keys:** Keys pointing to non-existent boxes are ignored  
✅ **Duplicate keys:** Same key multiple times works correctly  
✅ **Self-referencing:** Box containing key to itself  

## 🎯 Learning Objectives

After completing this project, you'll understand:

- 🔍 **Graph Traversal** algorithms (BFS/DFS)
- 📊 **State Management** in algorithmic problems
- 🧠 **Problem Decomposition** from story to algorithm
- ⚡ **Efficiency Analysis** and optimization
- 🐛 **Edge Case Handling** in real-world scenarios

## 🤝 Contributing

This is an interview preparation project. Focus on:
- 📝 Clean, readable code
- 🧪 Comprehensive testing
- 📚 Clear documentation
- ⚡ Efficient algorithms

---

## 📜 License

This project is part of the Holberton School interview preparation curriculum.

## 👨‍💻 Author

**Your Name** - Holbertonschool Student

---

⭐ **Happy Coding!** ⭐