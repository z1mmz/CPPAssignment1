
#include <iostream>
#include <random>
#include "maze.h"

maze genABMaze(long seed, int w, int h) {


    std::cout << "getting random" << std::endl;
    std::random_device rand_dev;
    std::cout << "getting gen" << std::endl;
    std::mt19937 generator(rand_dev());
    std::cout << "do dist" << std::endl;
    std::uniform_int_distribution<int> distr(0, 4);
//    std::cout << "cell 0 0 : " <<this->cells[0][0].x;

    maze ABMaze(w,h);
    maze * mazeponter;
    std::cout << "getting cell" << std::endl;
    cell s = ABMaze.cells[0][0];
    std::cout << "starting loop" << std::endl;
    long unvisted = w*h;




    while(unvisted > 1){
//        std::cout << unvisted << std::endl;
        direction d = (direction) distr(generator);

        switch (d){
            case north:
                if (s.y > 0 ){
                    if (!ABMaze.cells[s.x][s.y - 1].visited){
                        std::cout << "Going North x = " << s.x << "y = " << s.y -1 << std::endl;
                        edge e;
                        e.x1 = s.x;
                        e.y1 = s.y;
                        e.x2 = s.x;
                        e.y2 = s.y - 1;
                        ABMaze.edges_v.push_back(e);
                        std::cout << e.y1 << "= y1 " << e.x1 << " = x1" << std::endl;
                        std::cout << e.y2 << "= y2 " << e.x2 << " = x2" << std::endl;
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
                        std::cout << "Going South" << std::endl;
                        edge e;
                        e.x1 = s.x;
                        e.y1 = s.y;
                        e.x2 = s.x;
                        e.y2 = s.y + 1;
                        ABMaze.edges_v.push_back(e);
                        ABMaze.cells[s.x][s.y + 1].visited = true;
                        s = ABMaze.cells[s.x][s.y + 1];
                        std::cout << e.y1 << "= y1 " << e.x1 << " = x1" << std::endl;
                        std::cout << e.y2 << "= y2 " << e.x2 << " = x2" << std::endl;
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
                        std::cout << "Going West" << std::endl;
                        edge e;
                        e.x1 = s.x;
                        e.y1 = s.y;
                        e.x2 = s.x - 1;
                        e.y2 = s.y;
                        ABMaze.edges_v.push_back(e);
                        ABMaze.cells[s.x -1][s.y].visited = true;
                        s = ABMaze.cells[s.x -1][s.y];
                        std::cout << e.y1 << "= y1 " << e.x1 << " = x1" << std::endl;
                        std::cout << e.y2 << "= y2 " << e.x2 << " = x2" << std::endl;
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
                        std::cout << "Going East" << std::endl;
                        edge e;
                        e.x1 = s.x;
                        e.y1 = s.y;
                        e.x2 = s.x + 1;
                        e.y2 = s.y;
                        ABMaze.edges_v.push_back(e);
                        ABMaze.cells[s.x+1][s.y].visited = true;
                        s = ABMaze.cells[s.x+1][s.y];
                        std::cout << e.y1 << "= y1 " << e.x1 << " = x1" << std::endl;
                        std::cout << e.y2 << "= y2 " << e.x2 << " = x2" << std::endl;
                        unvisted--;
                    }else
                    {
                        s = ABMaze.cells[s.x+1][s.y];
                    }

                }
                break;
        }

    }

    std::cout << "Generated maze " << std::endl;

    mazeponter = &ABMaze;
    std::cout << "Edge size: " << (*(mazeponter)).edges_v[0].x1<< std::endl;
    return ABMaze;

}
