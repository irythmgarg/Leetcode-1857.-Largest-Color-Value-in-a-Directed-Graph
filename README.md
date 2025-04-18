# Leetcode-1857.-Largest-Color-Value-in-a-Directed-Graph
# 🏔️ Highest Peak - Elevation Map Generator

This project solves the **Highest Peak problem** using a **Multi-Source Breadth-First Search (BFS)** approach.

Given a binary matrix where `1` represents **water** and `0` represents **land**, the goal is to generate a new grid where:
- Water cells have height `0`
- Land cells have heights representing their **shortest distance to the nearest water cell**

---

## 🌊 Problem Statement

**Input**: A `m x n` grid containing `0`s and `1`s  
**Output**: A `m x n` grid where each cell represents its "height" – the distance to the nearest water cell.

> This height map resembles a topographic elevation starting from water sources.

---

## 💡 Approach

- Use **multi-source BFS** starting from all water cells.
- Each step in BFS increases the height as we move away from the nearest water.
- Ensures that all land cells are assigned the shortest path (height) from water.

---

## 🧠 Algorithm

1. Add all water cells (`1`s) into the queue and mark them as visited.
2. Begin BFS traversal level-by-level.
3. For every unvisited neighbor, assign height = current height + 1.
4. Repeat until all land cells are processed.

---

## 🚀 Example

### Input

```cpp
grid = {
  {0, 1},
  {0, 0}
}
Output
cpp
Copy
Edit
{
  {1, 0},
  {2, 1}
}
🧪 Test It Out
vector<vector<int>> grid = {
  {0, 1},
  {0, 0}
};

Solution sol;
vector<vector<int>> result = sol.highestPeak(grid);

for (auto row : result) {
    for (auto val : row)
        cout << val << " ";
    cout << endl;
}
