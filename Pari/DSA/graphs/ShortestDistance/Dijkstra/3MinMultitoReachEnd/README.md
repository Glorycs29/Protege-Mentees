# 🚀 Minimum Multiplications to Reach End
- [Problem Statement](https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1)
## ✨ Intuition

- Since the problem was about finding **minimum steps**, **Dijkstra's Algorithm** naturally came to mind because Dijkstra is used for **minimum cost path** problems.
- **Initially**, I thought of **using a Priority Queue** to maintain minimum steps as priority.
- **While dry-running the example**, I realized:
  - Every operation just **increased steps by 1** (uniform cost).
  - Hence, **no need for a Priority Queue**, as the steps were not varying.
- So I **optimized** it:
  - Instead of a **Priority Queue** (which has `log(V)` overhead per operation),
  - I used a simple **Queue** (like BFS) which is faster (`O(1)` enqueue and dequeue).
  
> **Summary**:  
> At first, you might think of using Dijkstra with Priority Queue, but after dry-running, you realize **simple BFS with a normal queue** is faster and sufficient here.

---


## 🛠️ Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> q; // {steps, node}
        vector<int> dist(100000, 1e9);

        dist[start] = 0;
        q.push({0, start});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second;

            if (node == end) return steps;

            for (auto it : arr) {
                int to = (node * it) % 100000;
                if (steps + 1 < dist[to]) {
                    dist[to] = steps + 1;
                    q.push({steps + 1, to});
                }
            }
        }
        return -1;
    }
};
