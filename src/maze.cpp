#include <iostream>
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

int maze::saveToSVG(void) {

    return 0;
}

maze::~maze() {

}
