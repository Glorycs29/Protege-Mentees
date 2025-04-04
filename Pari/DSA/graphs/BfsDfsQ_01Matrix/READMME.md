##Intution
 brute force->  traversing through all blocks in the grid and checking the distance of the current block from each 1 in the grid, and assigning its minimum to ans[i][j]=>> min (ans[i][j]=min (ans[i,j] , abs(i- iter_i) + abs(iter_j))
TIME COMPLEXITY-> very huge and inefficient so thought of optimal one.



 optimal approach-> (Hint from striver vdo) 
 -MULTISOURCE BFS STARTING WITH ALL BLOCKS=1 AND THEN TRAVERSING THE BFS OF ALL THE QUEUE Elements until the queue becomes empty.
 
 -the no_of steps will increase( 2nd variable of the queue ) and then pushed in the queue each time
 - queue of form <pair<pair<int,int>,int>

 - important to keep a visited array as well( to not hamper data)

   ##COMPLEXITIES

###TIME-> O(n*m + n*m*4) =O(n*m)
###SPACE -> O(n*m) for (visited_array, queue, ans_to_be_returned) 
