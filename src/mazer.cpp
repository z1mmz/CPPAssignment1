#include "mazer.h"

using namespace std;

int main(int argc, char *argv[]) {
    std::string help = "./mazer --lb filename.maze --sv filename.svg"
            "# load binary file and save svg file \n"
            "./mazer --g seed --sb filename.maze # generate with seed value,"
            " save binary file \n./mazer --g seed --sv filename.svg # generate"
            " with seed value, save svg file \n./mazer --g seed --sb filename.maze"
            " --sv filename.svg # gen with seed, save binary, save svg";
    if (argc <= 1 || argc > 6) {
        std::cerr << "ERROR: incorrect usage p1ease use mazer --help for commands" << std::endl;
        std::cerr << help << std::endl;
    } else {
        int argsexeced = 0;

        if (strcmp(argv[1], "--help") == 0) {
            argsexeced++;
            std::cout << help << std::endl;
        }
        if (strcmp(argv[1], "--lb") == 0) {
            argsexeced++;
            std::cout << "LOADING BINARY" << std::endl;
            maze loadedMaze = loadMaze(argv[2]);

            std::cout << "maze h: " << loadedMaze.height << " maze w: " << loadedMaze.width << std::endl;
            std::cout << "total edges: " << loadedMaze.edges_v.size() << std::endl;
            std::cout << "Edge 1: " << loadedMaze.edges_v[0].x1 << std::endl;
//            loadedMaze.saveToSVG("a.svg");

        }
        if(strcmp(argv[1],"-g") == 0){
          if (argc < 5){
            printf("%s\n","generator args not supplied" );
            return 1;
          }
            argsexeced++;
            int seed, h,w;
            seed = 0;
//            if(isdigit(atoi(argv[3])) && isdigit(atoi(argv[4])) ){
              seed = atoi(argv[2]);
                w = atoi(argv[3]);
                argsexeced++;
                h = atoi(argv[4]);
                argsexeced++;
                maze a = genABMaze(seed,w,h);
//            }else{
//                maze a = genABMaze(seed,10,10);
//            }
            std::cout << "Ate: " << argsexeced << std::endl;

        }

    }
    return 0;
}
