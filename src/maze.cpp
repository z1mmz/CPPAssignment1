#include <iostream>
#include <fstream>
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
    std::cout << "GEN constructer";
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
            fOut << "<line stroke='white' stroke-width='1' ";
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
