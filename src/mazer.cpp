#include "mazer.h"

using namespace std;

int main(int argc, char *argv[]) {
    std::string help = "./mazer --lb filename.maze --sv filename.svg"
            "# load binary file and save svg file \n "
            "./mazer --g seed --sb filename.maze # generate with seed value,"
            " save binary file \n./mazer --g seed --sv filename.svg # generate"
            " with seed value, save svg file \n ./mazer --g seed --sb filename.maze"
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
            loadedMaze.saveToSVG("a.svg");

        }
        if(strcmp(argv[1],"-g") ==0){
            argsexeced++;
            int seed, h,w;
            seed = (int) argv[2];
            if(isdigit((int) argv[3]) && isdigit((int) argv[4]) ){
                w = (int) argv[3];
                argsexeced++;
                h = (int) argv[4];
                argsexeced++;
                maze a = genABMaze(seed,w,h);
            }else{
                maze a = genABMaze(seed,10,10);
            }
            std::cout << "Ate: " << argsexeced << std::endl;

        }
    }
    return 0;
}
