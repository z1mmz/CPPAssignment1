#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <fstream>
#include <bitset>
#include <sstream>
#include "mazegen.h"
#include "maze.h"
using namespace std;
int main(int argc, char *argv[]) {
std::string help = "./mazer --lb filename.maze --sv filename.svg # load binary file and save svg file \n ./mazer --g seed --sb filename.maze # generate with seed value, save binary file \n./mazer --g seed --sv filename.svg # generate with seed value, save svg file \n ./mazer --g seed --sb filename.maze --sv filename.svg # gen with seed, save binary, save svg";
if (argc  <= 1 || argc > 6){
  std::cerr << "ERROR: incorrect usage please use mazer --help for commands" << std::endl;
  std::cerr << help << std::endl;
}else{

  if(strcmp(argv[1],"--help") == 0){
    std::cout << help << std::endl;
  }
  if(strcmp(argv[1],"--lb") == 0){
    std::cout << "LOADING BINARY" << std::endl;
    std::ifstream in("maze.g", std::ios::binary);
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    int h = 0;
    int w = 0;
    // int e = 0;
    in.read((char*)&h,sizeof(h));
    in.read((char*)&w,sizeof(w));
    int totalEdges = 0;
    in.read((char*)&totalEdges,sizeof(totalEdges));
    maze loadedMaze(h,w);
    int edges[totalEdges];
    loadedMaze.edges = edges;
    while (in.read((char*)&x1,sizeof(x1))&&in.read((char*)&y1,sizeof(y1))&&in.read((char*)&x2,sizeof(x2))&&in.read((char*)&y2,sizeof(y2)) ){
      edge newEdge;
      newEdge.x1 = x1;
      newEdge.y1 = y1;
      newEdge.x2 = x2;
      newEdge.y2 = y2;
    // std::cout << toresto << std::endl;
  }

  std::cout << "maze h: "<< loadedMaze.height << " maze w: " << loadedMaze.width << std::endl;
  std::cout << "total edges: " << totalEdges << std::endl;
  }
}
  return 0;
}
