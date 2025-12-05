# Rain Water Trapping

## 📋 Description

This project contains a Python function that calculates how many square units of water will be retained after it rains, given a list of non-negative integers representing wall heights. This is a classic algorithmic problem often asked in technical interviews.

## 🎯 Problem Statement

Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, calculate how many square units of water will be retained after it rains.

**Visual Example:**

```
Walls: [0, 1, 0, 2, 0, 3, 0, 4]

Height
4              ┃
3           ┃≈≈┃
2        ┃≈≈┃≈≈┃
1     ┃≈≈┃≈≈┃≈≈┃
0  ┃  ┃  ┃  ┃  ┃  ┃
   0  1  0  2  0  3  0  4

Water retained (≈) = 6 square units
```

## 🔧 Function Prototype

```python
def rain(walls)
```

### Parameters

- **walls** (list): A list of non-negative integers representing wall heights

### Returns

- **int**: Total amount of rainwater retained

### Constraints

- The ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water
- If the list is empty, return 0
- All values are non-negative integers

## 💡 Algorithm Logic

For each position in the array, the water level depends on:

1. **Maximum wall height to the left**
2. **Maximum wall height to the right**
3. **Current wall height**

### Formula

```
water[i] = min(max_left[i], max_right[i]) - height[i]
```

Water can only be retained if the result is **positive**.

## 📊 Examples

### Example 1

```python
walls = [0, 1, 0, 2, 0, 3, 0, 4]
rain(walls)  # Returns: 6
```

**Visual representation:**

```
Height
4              ┃
3           ┃≈≈┃
2        ┃≈≈┃≈≈┃
1     ┃≈≈┃≈≈┃≈≈┃
0  ┃  ┃  ┃  ┃  ┃  ┃
   0  1  0  2  0  3  0  4
```

**Calculation:**

| Index | Wall | Max Left | Max Right | Min(L,R) | Water |
|-------|------|----------|-----------|----------|-------|
| 0     | 0    | 0        | 4         | 0        | 0     |
| 1     | 1    | 0        | 4         | 0        | 0     |
| 2     | 0    | 1        | 4         | 1        | 1     |
| 3     | 2    | 1        | 4         | 1        | 0     |
| 4     | 0    | 2        | 4         | 2        | 2     |
| 5     | 3    | 2        | 4         | 2        | 0     |
| 6     | 0    | 3        | 4         | 3        | 3     |
| 7     | 4    | 3        | 0         | 0        | 0     |

**Total: 0 + 0 + 1 + 0 + 2 + 0 + 3 + 0 = 6**

### Example 2

```python
walls = [2, 0, 0, 4, 0, 0, 1, 0]
rain(walls)  # Returns: 6
```

**Visual representation:**

```
Height
4        ┃
3        ┃
2  ┃≈≈≈≈≈┃
1  ┃≈≈≈≈≈┃≈≈≈≈≈┃
0  ┃     ┃        ┃
   2  0  0  4  0  0  1  0
```

**Calculation:**

| Index | Wall | Max Left | Max Right | Min(L,R) | Water |
|-------|------|----------|-----------|----------|-------|
| 0     | 2    | 0        | 4         | 0        | 0     |
| 1     | 0    | 2        | 4         | 2        | 2     |
| 2     | 0    | 2        | 4         | 2        | 2     |
| 3     | 4    | 2        | 1         | 1        | 0     |
| 4     | 0    | 4        | 1         | 1        | 1     |
| 5     | 0    | 4        | 1         | 1        | 1     |
| 6     | 1    | 4        | 0         | 0        | 0     |
| 7     | 0    | 4        | 0         | 0        | 0     |

**Total: 0 + 2 + 2 + 0 + 1 + 1 + 0 + 0 = 6**

## 🚀 Usage

### Running the main file

```bash
./0_main.py
```

### Expected output

```
6
6
```

### Test file example (0_main.py)

```python
#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))
    walls = [2, 0, 0, 4, 0, 0, 1, 0]
    print(rain(walls))
```

## 🏗️ Solution Approaches

### 1. Brute Force Approach
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- For each element, find the maximum height on both left and right sides

### 2. Dynamic Programming Approach
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- Pre-compute maximum heights to the left and right for each position
- Store in two arrays

### 3. Two Pointers Approach
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- Use two pointers moving from both ends
- Keep track of maximum heights seen so far

## 🧮 Step-by-Step Algorithm (Dynamic Programming)

1. Create two arrays: `left_max` and `right_max`
2. Fill `left_max` array by scanning from left to right
3. Fill `right_max` array by scanning from right to left
4. For each position, calculate water trapped:
   ```python
   water = min(left_max[i], right_max[i]) - walls[i]
   ```
5. Sum all water values

## 🔍 Key Concepts

- **Water level**: Determined by the minimum of the two surrounding maximum walls
- **Boundaries**: No water can be retained at the edges
- **Accumulation**: Water fills all valleys between peaks

## 📚 Edge Cases

1. **Empty list**: `[]` → Returns `0`
2. **Single element**: `[5]` → Returns `0`
3. **Flat surface**: `[3, 3, 3, 3]` → Returns `0`
4. **Descending**: `[5, 4, 3, 2, 1]` → Returns `0`
5. **Ascending**: `[1, 2, 3, 4, 5]` → Returns `0`
6. **All zeros**: `[0, 0, 0, 0]` → Returns `0`

## 🎓 Learning Objectives

This exercise helps develop:
- Understanding of dynamic programming concepts
- Array manipulation and traversal
- Spatial reasoning and visualization
- Algorithm optimization techniques
- Problem-solving skills for technical interviews

## 💼 Real-World Applications

This problem pattern applies to:
- Water resource management and reservoir design
- Terrain analysis in GIS systems
- Memory allocation in operating systems
- Stock market buy/sell optimization (similar pattern)

## 🧪 Testing

Test your solution with various cases:

```python
# Test empty list
assert rain([]) == 0

# Test single element
assert rain([1]) == 0

# Test no water retention
assert rain([1, 2, 3, 4, 5]) == 0

# Test standard cases
assert rain([0, 1, 0, 2, 0, 3, 0, 4]) == 6
assert rain([2, 0, 0, 4, 0, 0, 1, 0]) == 6
assert rain([3, 0, 2, 0, 4]) == 7
```

## 👥 Author

Project completed as part of the Holberton School program.

## 📝 License

This project is for educational purposes.


---

**Holberton School - Interview Preparation**
