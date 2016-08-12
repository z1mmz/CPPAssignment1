#include "mazesaver.h"

int saveToBin(maze m,std::string out){
  std::ofstream saveFile (out, std::ios::out | std::ios::binary);
  if(saveFile.is_open()) {
    saveFile << m.width << std::endl;
    saveFile << m.height << std::endl;
    saveFile << m.edges_v.size() << std::endl;
    for (u_int i = 0 ; i < m.edges_v.size() ; i++){
      saveFile << m.edges_v[i].x1 << std::endl;
      saveFile << m.edges_v[i].y1 << std::endl;
      saveFile << m.edges_v[i].x2 << std::endl;
      saveFile << m.edges_v[i].y2 << std::endl;
    }
    saveFile.close();

  }else{
    std::cerr << "Failed to save file could not open file" << std::endl;
  }
  return 0 ;

}
int saveToSVG(maze m){
// save maze to svg
  return 0;
}
