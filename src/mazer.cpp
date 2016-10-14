/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 1
 * Name: Wolf Zimmermamnn
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * */

#include <unordered_map>
#include "mazer.h"


using namespace std;
std::unordered_map<std::string, std::vector<std::string>> args;
typedef void (*fp)(std::string , std::vector<std::string>);
std::unordered_map<std::string, fp > funcs;
bool isAFlag(std::string a){

	if(a[0] == '-'){
		return true;
	}
	return false;
}
maze m = maze();
int main(int argc, char *argv[]) {

//	heap_set<int> *a = new heap_set<int>();
//	a->insert(1);
//	a->insert(2);
//	std::cout << a << std::endl;
//	a->remove(2);
	m = maze();

	funcs.emplace("--ga",&genMaze);
	funcs.emplace("--ge",&genMaze);
	funcs.emplace("--pm",&solveMaze);
	funcs.emplace("--pe",&solveMaze);
	funcs.emplace("--pb",&solveMaze);
	funcs.emplace("--pd",&solveMaze);
	funcs.emplace("--sv",&saveMaze);
	funcs.emplace("--sb",&saveMaze);
	funcs.emplace("--lb",&loadMaze);

//	maze m = maze();
	computePath * e;
	e = new dfsSolver();
	std::string help = "./mazer --lb filename.maze --sv filename.svg"
			"# load binary file and save svg file \n"
			"./mazer --g seed --sb filename.maze # generate with seed value,"
			" save binary file \n./mazer --g seed --sv filename.svg # generate"
			" with seed value, save svg file \n./mazer --g seed --sb filename.maze"
			" --sv filename.svg # gen with seed, save binary, save svg";
	if (argc < 5) {
		std::cerr << "ERROR: incorrect usage p1ease use mazer --help for commands" << std::endl;
		std::cerr << help << std::endl;
	} else {

//		if(strcmp(argv[1], "--g") != 0 || strcmp(argv[1], "--lb") != 0){
//			std::cerr << help << std::endl;
//			return false ;
//		}
		std::string lastArg = "dasdasdasd";
		for(int i = 1 ; i < argc ; i++){
			std::string currentArg;
			std::vector<std::string> vars;
			currentArg = argv[i];
			i++;
			if(argv[1][2] != 'g' || strcmp(argv[1], "--lb") != 0){
				if(lastArg[2] != 'g' || lastArg == "--lb" ){
					std::cerr << "noot" << "ERROR: incorrect usage p1ease use mazer --help for commands" << std::endl;
				}
			}
			while(i < argc && isAFlag(argv[i]) == false ){
				vars.push_back(argv[i]);
				i++;
//				if(argv[i])

			}
			i--;
//			std::cout << currentArg <<  std::endl;
			if(funcs[currentArg] != nullptr) {
				funcs[currentArg](currentArg, vars);
			}

			lastArg = currentArg;

		}
//		// this will count how many arguments we have used
//		int argsexeced = 0;
//
//		if (strcmp(argv[1], "--help") == 0) {
//			argsexeced++;
//			std::cout << help << std::endl;
//		}
//
//		if (strcmp(argv[1], "--lb") == 0) {
//			argsexeced++;
//			std::cout << "LOADING BINARY" << std::endl;
//			if (m.loadFromBin(argv[2]) == 1) {
//				return 1;
//			}
//			argsexeced++;
//			std::cout << "maze h: " << m.height << " maze w: " << m.width << std::endl;
//			std::cout << "total edges: " << m.edges_v.size() << std::endl;
//			std::cout << "Seed: " << m.seed << std::endl;
//			if (argsexeced + 1 > argc) {
//				return 0;
//			}
//			if (strcmp(argv[argsexeced + 1], "--sv") == 0) {
//				argsexeced++;
//				argsexeced++;
//				m = e->solve(m);
//				// check if a file name has been passed
//				if (argv[argsexeced + 1] == NULL) {
//					std::cerr << "No out file" << std::endl;
//					return 1;
//				}
//				string file = argv[++argsexeced];
//				m.saveToSVG(file);
//			} else if (strcmp(argv[argsexeced + 1], "--sb") == 0) {
//				argsexeced++;
//				// check if a file name has been passed
//				if (argv[argsexeced + 1] == NULL) {
//					std::cerr << "No out file" << std::endl;
//					return 1;
//				}
//				string file = argv[++argsexeced];
//				m.saveToBin(file);
//			}
//		}
//
//		if (strcmp(argv[1], "--g") == 0) {
//			if (argc < 5) {
//				printf("%s\n", "generator args not supplied");
//				return 1;
//			}
//			argsexeced++;
//			int seed, h, w;
//
//			std::vector<int> genArgs;
//			for (int i = 2; i <= 4; i++) {
//				if (argv[i] != NULL) {
//					if (!(strcmp(argv[i], "--sv") == 0 || strcmp(argv[i], "--sb") == 0)) {
//						try {
//							genArgs.push_back(atoi(argv[i]));
//						} catch (std::invalid_argument) {
//							std::cerr << "Invalid generator flags" << std::endl;
//							return 1;
//						}
//
//
//					} else {
//						break;
//					}
//				}
//			}
//			if (genArgs.size() == 3) {
//				seed = genArgs[0];
//				argsexeced++;
//				w = genArgs[1];
//				argsexeced++;
//				h = genArgs[2];
//				argsexeced++;
//				m = genABMaze(seed, w, h);
//			} else if (genArgs.size() == 2) {
//				seed = 0;
//				w = genArgs[0];
//				argsexeced++;
//				h = genArgs[1];
//				argsexeced++;
//				m = genABMaze(seed, w, h);
//			} else {
//				std::cerr << "Please supply at least width and height" << std::endl;
//				return 1;
//			}
//
//
//			std::cout << "maze h: " << m.height << " maze w: " << m.width << std::endl;
//			std::cout << "total edges: " << m.edges_v.size() << std::endl;
//			std::cout << "Seed: " << m.seed << std::endl;
//
//
//			if (argsexeced + 1 > argc) {
//				return 0;
//			}
//			if (strcmp(argv[argsexeced + 1], "--sv") == 0) {
//				argsexeced++;
//				m = e->solve(m);
//				// check if a file name has been passed
//				if (argv[argsexeced + 1] == NULL) {
//					std::cerr << "No out file" << std::endl;
//					return 1;
//				}
//				string file = argv[++argsexeced];
//				m.saveToSVG(file);
//			} else if (strcmp(argv[argsexeced + 1], "--sb") == 0) {
//				argsexeced++;
//				// check if a file name has been passed
//				if (argv[argsexeced + 1] == NULL) {
//					std::cerr << "No out file" << std::endl;
//					return 1;
//				}
//				string file = argv[++argsexeced];
//				m.saveToBin(file);
//			}
//
//		}
//		int argsexeced;
//		if (argsexeced == 0) {
//			std::cerr << "ERROR: incorrect usage p1ease use mazer --help for commands" << std::endl;
//			return 1;
//
//		}

//        loadedMaze->saveToSVG("test.svg");


	}
	return 0;
}
void genMaze(std::string flag,std::vector<std::string> vars){

	generator * g;
	g = new abGen();
	int seed,w,h;
	if (vars.size() == 3) {
				seed = stoi(vars.at(0));
				w = stoi(vars[1]);
				h = stoi(vars[2]);

			} else if (vars.size() == 2) {
				seed = 0;
				w = stoi(vars[0]);
				h = stoi(vars[1]);
			} else {
				std::cerr << "Please supply at least width and height" << std::endl;
				return;
			}
	if(flag == "--ga") {
		m = g->genMaze(seed, w, h);
		std::cout << "maze h: " << m.height << " maze w: " << m.width << std::endl;
		std::cout << "total edges: " << m.edges_v.size() << std::endl;
		std::cout << "Seed: " << m.seed << std::endl;
	}
	if(flag == "--ge"){
		std::cout << "GE" << std::endl;
	}
}
void saveMaze(std::string flag,std::vector<std::string> vars){
	std::string file = vars[0];
	if(flag == "--sv"){
		std::cout << file << std::endl;
		m.saveToSVG(file);
	}
	if(flag == "--sb"){
		m.saveToBin(file);
	}

}
void solveMaze(std::string flag,std::vector<std::string> vars){
	computePath * e;
	if(flag == "--pb"){
		e = new bfsSolver();
	}
	if(flag == "--pd"){
		e = new dfsSolver();
	}
	if(flag == "--pm"){
		e = new dijSolver();
	}
	m = e->solve(m);

}
void loadMaze(std::string flag,std::vector<std::string> vars){
	std::string file = vars[0];
	m.loadFromBin(file);
}
