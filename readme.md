README

# C++ COSC1254 2016 Assignment 2

- Student ID : S3495671
- Student Name : Wolf Zimmermann

#### Make
To make use the default make target

#### Usage
- arg 1
  - --ga seed width height
    - Generates maze using aldus-broder
    - Seed is optional if left empty will use time since epoch
    - --ge seed width height
      - Generates maze using Ellers
      - Seed is optional if left empty will use time since epoch
  - --lb filename
    - loads maze from binary
- other args
  - --pe
    - solve maze using Dijkstra's and euclidian distance
  - --pm
    - solve maze using Dijkstra's and manhattan distance
  - --pb
    - solve maze using breadth first search
  - --pd
    - solver maze using depth first search
  - --sv filename
    - save maze as SVG
  - --sb
    - save file a binary
    - does not save solved path's

- you need to specify a solver or loader first then you can do any combonation
of commands



#### Design of program
#### from Assignment 1
1. Created functions for loading binary
2. Created Maze class
3. Created Vector of vectors to store cells and created a vector of edges also created stucts for cell and edges
4. Created SVG saving function
5. Moved Saving and loading operations inside of Maze class
6. Created Maze generation inside of maze class
7. Moved the function to a module so if more algorithims where to be used it would better to have this seperate from the maze
8. Implemented binary saving
9. handling of input flags
10. Clean up and finish

# Assignment 2
1. Fixed errors with seed segfualt
2. created Design diagram
3. changed how the arguments are handled
4. Implemented dfs
5. Implemented bfs
6. Attempted to Implement the heap set
7. Implemented Ellers
8. Implemented Dijkstra with euclidian
9. Implemented Dijkstra with manhattan
10. Ran profiling and optimised program
11. cleanup and finish
