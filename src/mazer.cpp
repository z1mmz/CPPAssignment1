#include "mazer.h"


using namespace std;

int main(int argc, char *argv[]) {
    maze m = maze();
    std::string help = "./mazer --lb filename.maze --sv filename.svg"
            "# load binary file and save svg file \n"
            "./mazer --g seed --sb filename.maze # generate with seed value,"
            " save binary file \n./mazer --g seed --sv filename.svg # generate"
            " with seed value, save svg file \n./mazer --g seed --sb filename.maze"
            " --sv filename.svg # gen with seed, save binary, save svg";
    if (argc <= 1 || argc > 7) {
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
//            maze loadedMaze = loadMaze(argv[2]);
            if(m.loadFromBin(argv[2]) == 1){
                return 1;
            }
            argsexeced++;
            std::cout << "maze h: " << m.height << " maze w: " << m.width << std::endl;
            std::cout << "total edges: " << m.edges_v.size() << std::endl;
            std::cout << "Edge 1: " << m.edges_v.at(10).x1 << std::endl;
         if(strcmp(argv[argsexeced + 1],"--sv") == 0){
             argsexeced++;
             string file = argv[++argsexeced];
             m.saveToSVG(file);
             }else if (strcmp(argv[argsexeced + 1],"--sb") == 0){
             argsexeced++;
             string file = argv[++argsexeced];
             m.saveToBin(file);
         }
        }

        if(strcmp(argv[1],"--g") == 0){
          if (argc < 5){
            printf("%s\n","generator args not supplied" );
            return 1;
          }
            argsexeced++;
            int seed, h,w;
            seed = 0;
            seed = atoi(argv[2]);
            argsexeced++;
                w = atoi(argv[3]);
                argsexeced++;
                h = atoi(argv[4]);
                argsexeced++;
                maze loadedMaze = genABMaze(seed,w,h);

            std::cout << "maze h: " << loadedMaze.height << " maze w: " << loadedMaze.width << std::endl;
            std::cout << "total edges: " << loadedMaze.edges_v.size() << std::endl;
            std::cout << "Edge 1: " << loadedMaze.edges_v[19].x1 << std::endl;

            if(strcmp(argv[argsexeced + 1],"--sv") == 0){
                argsexeced++;
                string file = argv[++argsexeced];
                loadedMaze.saveToSVG(file);
            }else if(strcmp(argv[argsexeced + 1],"--sb") == 0){
                argsexeced++;
                string file = argv[++argsexeced];
                loadedMaze.saveToBin(file);
            }

        }


//        loadedMaze->saveToSVG("test.svg");
\

    }
    return 0;
}
