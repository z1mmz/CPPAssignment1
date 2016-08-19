#include <iostream>
#include <fstream>
#include <random>
#include "maze.h"

maze::maze(int w , int h){
    width = w;
    height = h;

    for (int x = 0 ; x < h ; x++){
      cell_vec_t coll;
      for (int i = 0 ; i < w ; i++){
          cell a;
          a.x = x;
          a.y = i;
          coll.push_back(a);
      }
      cells.push_back(coll);
    }
//    cells[x][y]
//    std::cout << cells[0][1].y; should = 1


  }

maze::maze(long seed, int w, int h) {
    // constructed to generate maze
    width = w;
    height = h;

    for (int x = 0 ; x < h ; x++){
        cell_vec_t coll;
        for (int i = 0 ; i < w ; i++){
            cell a;
            a.x = x;
            a.y = i;
            coll.push_back(a);
        }
        cells.push_back(coll);
    }

    std::cout << "getting random" << std::endl;
    std::random_device rand_dev;
    std::cout << "getting gen" << std::endl;
    std::mt19937 generator(rand_dev());
    std::cout << "do dist" << std::endl;
    std::uniform_int_distribution<int> distr(0, 4);
//    std::cout << "cell 0 0 : " <<this->cells[0][0].x;
    std::cout << "getting cell" << std::endl;
    cell s = this->cells[0][0];
    std::cout << "starting loop" << std::endl;
    long unvisted = w*h;



    while(unvisted > 1){
        std::cout << unvisted << std::endl;
        direction d = (direction) distr(generator);

        switch (d){
            case north:
                if (s.y > 0 ){
                    if (!this->cells[s.x][s.y - 1].visited){
                        edge e;
                        e.x1 = s.x;
                        e.y1 = s.y;
                        e.x2 = s.x;
                        e.y2 = s.y - 1;
                        this->edges_v.push_back(e);
                        this->cells[s.x][s.y - 1].visited = true;
                        s = this->cells[s.x][s.y - 1];
                        unvisted--;
                    }else
                    {
                        s = this->cells[s.x][s.y - 1];
                    }

                }
                break;
            case south:
                if (s.y < this->height -1 ){
                    if (!this->cells[s.x][s.y + 1].visited){
                        edge e;
                        e.x1 = s.x;
                        e.y1 = s.y;
                        e.x2 = s.x;
                        e.y2 = s.y + 1;
                        this->edges_v.push_back(e);
                        this->cells[s.x][s.y + 1].visited = true;
                        s = this->cells[s.x][s.y + 1];
                        unvisted--;
                    }else
                    {
                        s = this->cells[s.x][s.y + 1];
                    }

                }
                break;
            case west:

                if (s.x > 0 ){
                    if (!this->cells[s.x - 1][s.y].visited){
                        edge e;
                        e.x1 = s.x;
                        e.y1 = s.y;
                        e.x2 = s.x - 1;
                        e.y2 = s.y;
                        this->edges_v.push_back(e);
                        this->cells[s.x -1][s.y].visited = true;
                        s = this->cells[s.x -1][s.y];
                        unvisted--;
                    }else
                    {
                        s = this->cells[s.x - 1][s.y];
                    }

                }
                break;
            case east:
                if (s.x < this->width - 1 ){
                    if (!this->cells[s.x + 1][s.y].visited){
                        edge e;
                        e.x1 = s.x;
                        e.y1 = s.y;
                        e.x2 = s.x + 1;
                        e.y2 = s.y;
                        this->edges_v.push_back(e);
                        this->cells[s.x+1][s.y].visited = true;
                        s = this->cells[s.x+1][s.y];
                        unvisted--;
                    }else
                    {
                        s = this->cells[s.x+1][s.y];
                    }

                }
                break;
        }

    }

}


int maze::saveToSVG(std::string file) {
    std::fstream fOut(file, std::fstream::out | std::fstream::trunc);


    if(fOut.is_open()){
        fOut << "<svg xmlns='http://www.w3.org/2000/svg' width='"<< (this->width + 1) * 10  <<"' ";
        fOut <<"height='"<<(this->height + 1) * 10 <<"'> \n";
        fOut << "<rect width='"<<(this->width+ 1)  * 10<<"' ";
        fOut << "height='"<<(this->height + 1) * 10<<"' ";
        fOut << "style='fill: black'/>\n";
        for (edge e : this->edges_v){
            fOut << "<line stroke='white' stroke-width='4' ";
            fOut << "x1='" <<( e.x1 + 1) * 10 <<"' ";
            fOut << "y1='" << (e.y1 + 1 )* 10 << "' ";
            fOut << "x2='" << (e.x2 + 1) * 10 << "' ";
            fOut << "y2='" << (e.y2 + 1) * 10 << "' /> \n";

        }
        fOut << "</svg>";

    }else{
        std::cerr << "Could not save maze to SVG" << std::endl;

    }


//    /* header */
//    unsigned offset = WALL_WIDTH * 2; /* Both sides */
//    unsigned box_width = CELL_SIZE_PIXELS * maze->get_width() + offset;
//    unsigned box_height = CELL_SIZE_PIXELS * maze->get_height() + offset;
//    output << "<svg width='" << box_width << "' ";
//    output << "height='" << box_height << "' ";
//    output << "xmlns='http://www.w3.org/2000/svg'>" << "\n";
//
//    /* box */
//    output << "<rect width='" << box_width << "' height='" << box_height;
//    output << "' style='fill: black' />" << "\n";
    return 0;
}

maze::~maze() {

}
