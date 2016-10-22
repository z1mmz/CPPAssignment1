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


	std::string help = "First command must be a loader or generator\n"
			"eg. ./mazer --ge 100 100 --pd --sv test.svg # "
			"generate a maze using ellers that is 100x100 \nsolve it using dfs "
			"and save as svg\n"
			"----------------------------------------------------------------\n"
			"Commands\n"
			"----------------------------------------------------------------\n"
			"--lb <filename> # load from a binary file\n"
			"--ga seed(optional) width height # generate maze using "
			"Aldous-Broder\n"
			"--ge seed(optional) width height # generate maze using ellers\n"
			"--pe # solve maze using Dijkstra's with euclidean distance\n"
			"--pm # Solve Maze using Dijkstra's with manhattan distance\n"
			"--pb # Solve maze using breadth first search\n"
			"--pd # Solve mazae using Depth first Search\n"
			"--sv # Save to svg";
	if (argc < 2) {
		std::cerr << help << std::endl;
	} else {

		if(argv[1][2] != 'g' && strcmp(argv[1], "--lb") != 0){
			std::cout << argv[1][2] << std::endl;
			std::cerr << help << std::endl;
			return false ;
		}
		std::string lastArg = "";
		for(int i = 1 ; i < argc ; i++){
			std::string currentArg;
			std::vector<std::string> vars;
			currentArg = argv[i];
			i++;
			while(i < argc && !isAFlag(argv[i])){
				vars.push_back(argv[i]);
				i++;

			}
			i--;
			if(funcs[currentArg] != nullptr) {
				funcs[currentArg](currentArg, vars);
			}else{
				std::cerr<< currentArg << " Not implemented" << std::endl;
				std::cerr<< help <<std::endl;
				return EXIT_FAILURE;
			}

			lastArg = currentArg;

		}


	}
	return 0;
}
void genMaze(std::string flag,std::vector<std::string> vars){

	generator * g;

	int w,h;
	long seed;
	if (vars.size() == 3) {
				seed = stol(vars.at(0));
				w = stoi(vars[1]);
				h = stoi(vars[2]);

			} else if (vars.size() == 2) {
				seed = 0;
				w = stoi(vars[0]);
				h = stoi(vars[1]);
			} else {
				std::cerr << "Please supply at least width and height"
						  << std::endl;
				return;
			}
	if(flag == "--ga") {
		g = new abGen();

	}
	if(flag == "--ge"){
		g = new ellerGen();
		std::cout << "ELLERS" << std::endl;
	}
	auto start_t = std::chrono::high_resolution_clock::now();
	m = g->genMaze(seed, w, h);
	auto end_t = std::chrono::high_resolution_clock::now();
	std::cout << "Generated maze in: "
			  << std::chrono::duration_cast<std::chrono::milliseconds>(end_t - start_t).count()
			  << " milliseconds"
			  << std::endl;
	std::cout << "maze h: " << m.height << " maze w: " << m.width << std::endl;
	std::cout << "total edges: " << m.edges_v.size() << std::endl;
	std::cout << "Seed: " << m.seed << std::endl;
}
void saveMaze(std::string flag,std::vector<std::string> vars){
	std::string file = vars[0];
	auto start_t = std::chrono::high_resolution_clock::now();
	if(flag == "--sv"){
		std::cout << file << std::endl;

		m.saveToSVG(file);
	}
	if(flag == "--sb"){
		m.saveToBin(file);
	}
	auto end_t = std::chrono::high_resolution_clock::now();
	std::cout << "Saved maze in: "
			  << std::chrono::duration_cast<std::chrono::milliseconds>(end_t - start_t).count()
			  << " milliseconds"
			  << std::endl;

}
void solveMaze(std::string flag,std::vector<std::string> vars){
	computePath  * e;

	e = solverFactory::makeSolver(flag);
	auto start_t = std::chrono::high_resolution_clock::now();
	m = e->solve(m);
	auto end_t = std::chrono::high_resolution_clock::now();
	std::cout << "Solved maze in: "
			  << std::chrono::duration_cast<std::chrono::milliseconds>(end_t - start_t).count()
			  << " milliseconds"
			  << std::endl;
}
void loadMaze(std::string flag,std::vector<std::string> vars){
	std::string file = vars[0];
	m.loadFromBin(file);
}
