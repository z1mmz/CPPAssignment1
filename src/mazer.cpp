#include "mazer.h"
using namespace std;
int main(int argc, char *argv[]) {
std::string help = "./mazer --lb filename.maze --sv filename.svg # load binary file and save svg file \n ./mazer --g seed --sb filename.maze # generate with seed value, save binary file \n./mazer --g seed --sv filename.svg # generate with seed value, save svg file \n ./mazer --g seed --sb filename.maze --sv filename.svg # gen with seed, save binary, save svg";
if (argc  <= 1 || argc > 6){
  std::cerr << "ERROR: incorrect usage pleas1e use mazer --help for commands" << std::endl;
  std::cerr << help << std::endl;
}else{

  if(strcmp(argv[1],"--help") == 0){
    std::cout << help << std::endl;
  }
  if(strcmp(argv[1],"--lb") == 0){
    std::cout << "LOADING BINARY" << std::endl;
    maze loadedMaze = loadMaze("maze.g");
;
    std::cout << "maze h: "<< loadedMaze.height << " maze w: " << loadedMaze.width << std::endl;
    std::cout << "total edges: " << loadedMaze.edges_v.size() << std::endl;
    std::cout << "Edge 1" << loadedMaze.edges_v[0].x1 << std::endl;



  }
}
  return 0;
}
