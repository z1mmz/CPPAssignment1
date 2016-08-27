
#include <iostream>
#include <random>
#include <chrono>
#include "maze.h"

maze genABMaze(long seed, int w, int h) {

    if(seed == 0){
        seed = std::chrono::system_clock::now().time_since_epoch().count();
    }
//    std::cout << "Seed: " << seed << std::endl;
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distr(0, 4);
    std::uniform_int_distribution<int> rH(0, h-1);
    std::uniform_int_distribution<int> rW(0, w-1);
    maze ABMaze(w,h);
    cell s = ABMaze.cells[rW(generator)][rH(generator)];
    std::cout << "Starting maze generation loop" << std::endl;
    long unvisted = w*h;
    auto start_t = std::chrono::high_resolution_clock::now();
    ABMaze.seed = seed;
    while(unvisted > 1){

        direction d = (direction) distr(generator);

        switch (d){
            case north:
                if (s.y > 0 ){
                    if (!ABMaze.cells[s.x][s.y - 1].visited){
                        edge e;
                        e.x1 = s.x;
                        e.y1 = s.y;
                        e.x2 = s.x;
                        e.y2 = s.y - 1;
                        ABMaze.edges_v.push_back(e);
                        ABMaze.cells[s.x][s.y - 1].visited = true;
                        s = ABMaze.cells[s.x][s.y - 1];
                        unvisted--;
                    }else
                    {
                        s = ABMaze.cells[s.x][s.y - 1];
                    }

                }
                break;
            case south:
                if (s.y < ABMaze.height -1 ){
                    if (!ABMaze.cells[s.x][s.y + 1].visited){
                        edge e;
                        e.x1 = s.x;
                        e.y1 = s.y;
                        e.x2 = s.x;
                        e.y2 = s.y + 1;
                        ABMaze.edges_v.push_back(e);
                        ABMaze.cells[s.x][s.y + 1].visited = true;
                        s = ABMaze.cells[s.x][s.y + 1];
                        unvisted--;
                    }else
                    {
                        s = ABMaze.cells[s.x][s.y + 1];
                    }

                }
                break;
            case west:

                if (s.x > 0 ){
                    if (!ABMaze.cells[s.x - 1][s.y].visited){
                        edge e;
                        e.x1 = s.x;
                        e.y1 = s.y;
                        e.x2 = s.x - 1;
                        e.y2 = s.y;
                        ABMaze.edges_v.push_back(e);
                        ABMaze.cells[s.x -1][s.y].visited = true;
                        s = ABMaze.cells[s.x -1][s.y];
                        unvisted--;
                    }else
                    {
                        s = ABMaze.cells[s.x - 1][s.y];
                    }

                }
                break;
            case east:
                if (s.x < ABMaze.width - 1 ){
                    if (!ABMaze.cells[s.x + 1][s.y].visited){
                        edge e;
                        e.x1 = s.x;
                        e.y1 = s.y;
                        e.x2 = s.x + 1;
                        e.y2 = s.y;
                        ABMaze.edges_v.push_back(e);
                        ABMaze.cells[s.x+1][s.y].visited = true;
                        s = ABMaze.cells[s.x+1][s.y];
                        unvisted--;
                    }else
                    {
                        s = ABMaze.cells[s.x+1][s.y];
                    }

                }
                break;
        }

    }
    auto end_t = std::chrono::high_resolution_clock::now();


    std::cout << "Generated maze in: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end_t - start_t).count()
              << " milliseconds"
              << std::endl;
    return ABMaze;

}
