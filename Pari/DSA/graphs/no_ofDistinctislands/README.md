#INTUTION
 BASICALLY WE check the no of islands like the standard leetcode question but here we want to see the disinct islands and hence we check the differnce between base r and c and the current row and col;

_> DFS/BFS both can be used for traversing
# DIFFERENT THING ABOUT THIS QUESTION IS 
Store the shape as a set of relative coordinates (e.g., (x, y) - (start_x, start_y)) 

//time complexity 
O(N* M) As in worst case will do dfs of all matrix elements so basically traverse whole matrix 
