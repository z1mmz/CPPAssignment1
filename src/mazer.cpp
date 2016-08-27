/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 1
 * Name: Wolf Zimmermamnn
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * */
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
	if (argc < 5 || argc > 7) {
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
			if (m.loadFromBin(argv[2]) == 1) {
				return 1;
			}
			argsexeced++;
			std::cout << "maze h: " << m.height << " maze w: " << m.width << std::endl;
			std::cout << "total edges: " << m.edges_v.size() << std::endl;
			std::cout << "Seed: " << m.seed << std::endl;
			if (argsexeced + 1 > argc) {
				return 0;
			}
			if (strcmp(argv[argsexeced + 1], "--sv") == 0) {
				argsexeced++;
				if (argv[argsexeced + 1] == NULL) {
					std::cerr << "No out file" << std::endl;
					return 1;
				}
				string file = argv[++argsexeced];
				m.saveToSVG(file);
			} else if (strcmp(argv[argsexeced + 1], "--sb") == 0) {
				argsexeced++;
				if (argv[argsexeced + 1] == NULL) {
					std::cerr << "No out file" << std::endl;
					return 1;
				}
				string file = argv[++argsexeced];
				m.saveToBin(file);
			}
		}

		if (strcmp(argv[1], "--g") == 0) {
			if (argc < 5) {
				printf("%s\n", "generator args not supplied");
				return 1;
			}
			argsexeced++;
			int seed, h, w;

			std::vector<int> genArgs;
			for (int i = 2; i <= 4; i++) {
				if (argv[i] != NULL) {
					if (!(strcmp(argv[i], "--sv") == 0 || strcmp(argv[i], "--sb") == 0)) {
						try {
							genArgs.push_back(atoi(argv[i]));
						} catch (std::invalid_argument) {
							std::cerr << "Invalid generator flags" << std::endl;
							return 1;
						}


					} else {
						break;
					}
				}
			}
			if (genArgs.size() == 3) {
				seed = genArgs[0];
				argsexeced++;
				w = genArgs[1];
				argsexeced++;
				h = genArgs[2];
				argsexeced++;
				m = genABMaze(seed, w, h);
			} else if (genArgs.size() == 2) {
				seed = 0;
				w = genArgs[0];
				argsexeced++;
				h = genArgs[1];
				argsexeced++;
				m = genABMaze(seed, w, h);
			} else {
				std::cerr << "Please supply at least width and height" << std::endl;
				return 1;
			}


			std::cout << "maze h: " << m.height << " maze w: " << m.width << std::endl;
			std::cout << "total edges: " << m.edges_v.size() << std::endl;
			std::cout << "Seed: " << m.seed << std::endl;
			if (argsexeced + 1 > argc) {
				return 0;
			}
			if (strcmp(argv[argsexeced + 1], "--sv") == 0) {
				argsexeced++;
				if (argv[argsexeced + 1] == NULL) {
					std::cerr << "No out file" << std::endl;
					return 1;
				}
				string file = argv[++argsexeced];
				m.saveToSVG(file);
			} else if (strcmp(argv[argsexeced + 1], "--sb") == 0) {
				argsexeced++;
				if (argv[argsexeced + 1] == NULL) {
					std::cerr << "No out file" << std::endl;
					return 1;
				}
				string file = argv[++argsexeced];
				m.saveToBin(file);
			}

		}
		if (argsexeced == 0) {
			std::cerr << "ERROR: incorrect usage p1ease use mazer --help for commands" << std::endl;
			return 1;

		}

//        loadedMaze->saveToSVG("test.svg");
				\

	}
	return 0;
}
