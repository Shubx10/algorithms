## Floyd Warshall Algorithm 🚀
- The Floyd Warshall algorithm is a multi-source shortest path algorithm and it helps to detect negative cycles as well.
- Dijkstra’s shortest path algorithm doesn’t work for negative weighted edges, and if we extend the Bellman Ford algorithm for all nodes, the time complexity becomes O($V^2 * E$) and since the maximum number of edges can be as high as $V * (V - 1)$ for a directed graph, so the overall complexity could be as high as O($V^4$). This makes the Floyd Warshall algorithm a more efficient choice. 
- Time Complexity - O($V^3$)
- Space Complexity - O($V^2$)
<br>

```cpp
class Solution{
public:
	void floydWarshall(vector<vector<int>> &matrix){
		int n = matrix.size();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] == -1){
					matrix[i][j] = 1e9;
				}
				if(i == j) matrix[i][j] = 0;
			}
		}
	
		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(matrix[i][k] != 1e9 && matrix[k][j] != 1e9){
						matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
					}
				}
			}
		}
	
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] == 1e9){
					matrix[i][j] = -1;
				}
			}
		}
	}
};
```
