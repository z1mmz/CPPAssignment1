#include "mazeloader.h"
maze loadMaze(std::string file){

  // TODO
  // Check file exists

  std::ifstream in(file, std::ios::binary);

  int x1 = 0;
  int x2 = 0;
  int y1 = 0;
  int y2 = 0;
  int h = 0;
  int w = 0;

// Read the width and height
  in.read((char*)&h,sizeof(h));
  in.read((char*)&w,sizeof(w));
  int totalEdges = 0;
  in.read((char*)&totalEdges,sizeof(totalEdges));
  maze loadedMaze(h,w);

  // Read in the edges
  while (in.read((char*)&x1,sizeof(x1))
        &&in.read((char*)&y1,sizeof(y1))
        &&in.read((char*)&x2,sizeof(x2))
        &&in.read((char*)&y2,sizeof(y2)) ){
    edge newEdge;
    newEdge.x1 = x1;
    newEdge.y1 = y1;
    newEdge.x2 = x2;
    newEdge.y2 = y2;
    loadedMaze.edges_v.push_back(newEdge);
  // std::cout << toresto << std::endl;
  }
  return loadedMaze;

  }
