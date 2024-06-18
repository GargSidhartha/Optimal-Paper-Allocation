<div align="center">

  <h1 style="font-family: 'Helvetica', sans-serif;"><span style="color:#00FFFF;">Exam Paper Distribution Simulation for Fairness📝</span></h1>

</div>

  

<div align="center">

  <h6 style="font-family: 'Helvetica', sans-serif;"> © Sarthak Gupta, Sidhartha Garg and Tanishk Singh 🎓</h6>

</div>

  

---

  

> 📄 **Paper Link:** [Paper Distribution Simulation Slides](https://docs.google.com/presentation/d/1q7nXEGrO687Rii2Zthmp4VpEUUrOY9S9EIlYOgRD5y0/edit?usp=sharing)

  

## BFS Function 🚀

  

This C++ program simulates the distribution of papers by students in a grid, represented as blocks using a 2D vector. The simulation employs a breadth-first search (BFS) algorithm, where students distribute papers in different directions (4 and 8 directional) until reaching the boundary.

  

### BFS Loop 🔍

  

- The function enters a while loop, which continues until the queue is empty.

- Within the loop, the front element of the queue (current) is popped.

- The current time is updated based on the time taken to reach the current cell.

  

### Neighbouring Cells Exploration 🌐

  

- The function explores the neighbouring cells of the current cell in eight possible directions.

- For each neighbour, it checks conditions such as movement within grid boundaries, the absence of blockage (`graph[nx][ny] == 1`), and unvisited status (`!visited[nx][ny]`).

- If conditions are met, the neighbour is pushed onto the queue with an updated time (`currentTime + 1`), and the neighbour cell is marked as visited.

  

### Time Tracking ⏱️

- The `totalTime` is updated to keep track of the maximum time encountered during the BFS traversal.

  

### Time taken if movement in Diagonal Directions is allowed 🔄

  

- To calculate time with diagonal movement, modify the for loop in the BFS function by replacing `4` with `8`. This ensures the updated time is calculated using all eight directions.

  

## INT MAIN 📊

This section implements the BFS function for critical points in the six blocks, representing specific starting positions for each block.

