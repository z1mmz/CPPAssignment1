#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <fstream>
#include <bitset>
#include <sstream>
#include "mazegen.h"
using namespace std;
int main(int argc, char *argv[]) {
  int binlen;
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
    std::ifstream in("a", std::ios::binary);
    // in.seekg(0,ios::end);
    // binlen = in.tellg();
    // in.seekg(0,ios::end);
    char* buff[binlen];
    int toresto = 0;
    while (in.read((char*)&toresto,sizeof(toresto))){
    std::cout << toresto << std::endl;
  }
    // std::istringstream s(in.rdbuf());
    // std::bitset<8> bs;
  }
}
  return 0;
}
