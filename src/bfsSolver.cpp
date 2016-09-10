//
/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 2
 * Name: Wolf Zimmermann
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * Created on 9/09/16.
 * */

//

#include "bfsSolver.h"

using namespace std;

maze bfsSolver::solve(maze m) {
	cell current = m.start;
	m.start.y;
//	std::set<cell> visited;
	std::queue <cell> toVisit;
	vector <vector<int>> visited;
	for(int i = 0 ; i <= m.width; i++){
		std::vector<int> col;
		for(int x = 0 ; x <= m.height; x++){
			col.push_back(0);
		}
		visited.push_back(col);
	}
	std::cout << "BFS" << std::endl;
	toVisit.push(current);
	cell * test = m.start.connected[0];
	test->y;
	while (!toVisit.empty()) {
		std::cout << "POP" << std::endl;
//	current->connected[1];

	visited[current.x][current.y] = 1;
	std::cout << "visited ?  "<< visited[current.x][current.y]  << std::endl;;
		for (cell *cellTemp : current.connected) {

//		std::cout << "Count: " << visited.count(*cellTemp) << std::endl;


			if (visited[cellTemp->x][cellTemp->y] == 0) {
				toVisit.push(*cellTemp);
				std::cout << "Push: " << cellTemp->y << std::endl;
			}
		}
		current = toVisit.front();
		toVisit.pop();


	}
	return m;

}
