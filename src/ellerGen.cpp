//
/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 2
 * Name: Wolf Zimmermann
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * Created on 13/10/16.
 * */

//

#include <set>
#include "ellerGen.h"



maze ellerGen::genMaze(long seed, int w, int h) {
maze m(w,h);
	if (seed == 0) {
		seed = std::chrono::system_clock::now().time_since_epoch().count();
	}
//    std::cout << "Seed: " << seed << std::endl;
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distr(0, 1);
	for(int i = 0 ; i < m.cells.size() ; i++){
		std::vector<std::set<std::string>> set;
		for(int c = 0; c < m.cells[i].size() ;c++){
			set[c].insert(cellToS(m.cells[i][c]));

		}
		for(int c = 0; c < m.cells[i].size() ;c++){
			if(isDisjoint(set ,m.cells[i][c] , m.cells[i][c+1] ) && distr(generator) == 1){
				edge t;
				t.x1 = m.cells[i][c].x;
				t.y1 = m.cells[i][c].y;
				t.x2 = m.cells[i][c+1].x;
				t.y2 = m.cells[i][c+1].y;
				m.cells[i][c].connected.push_back(t);
				m.cells[i][c+1].connected.push_back(t);
				// merge the sets here
			}

		}


	}
	m.cells[0];
	
}

std::string ellerGen::cellToS(cell c) {

	return std::to_string(c.x)+ std::to_string(c.y);
}
bool ellerGen::isDisjoint(std::vector<std::set<std::string>> sets , cell c1, cell c2 ){

	return false;
}
