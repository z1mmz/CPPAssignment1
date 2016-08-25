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

int maze::saveToSVG(std::string file) {
    std::fstream fOut(file, std::fstream::out | std::fstream::trunc);


    if(fOut.is_open()){
        fOut << "<svg xmlns='http://www.w3.org/2000/svg' width='"<< (this->width + 1) * 10  <<"' ";
        fOut <<"height='"<<(this->height + 1) * 10 <<"'> \n";
        fOut << "<rect width='"<<(this->width+ 1)  * 10<<"' ";
        fOut << "height='"<<(this->height + 1) * 10<<"' ";
        fOut << "style='fill: black'/>\n";
//        edge p = this->edges_v[0];
//        std::cout << p.x1
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

int maze::saveToBin(std::string file) {
    std::fstream fOut(file,std::fstream::out | std::fstream::binary | std::fstream::trunc);

    if(fOut.is_open()){

        int h = this->height;
        int w = this->width;
        int numEdge = this->edges_v.size();
        fOut.write((char *)&w, sizeof(w));
        fOut.write((char *)&h, sizeof(h));
        fOut.write((char *)&numEdge , sizeof(numEdge));
        for (edge e : this->edges_v){
            fOut.write((char *)&e.x1, sizeof(e.x1));
            fOut.write((char *)&e.y1, sizeof(e.y1));
            fOut.write((char *)&e.x2, sizeof(e.x2));
            fOut.write((char *)&e.y2, sizeof(e.y2));
            std::cout << "x1: "<< e.x1 << " y1: " << e.y1 << " x2: " << e.x2 << " y2: "<< e.y2 << std::endl;
        }
        fOut.close();
    }
    return 0;
}


