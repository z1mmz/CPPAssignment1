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
#include <algorithm>
#include <unordered_map>
#include "ellerGen.h"


std::unordered_map<std::string , int > cells;
std::unordered_map<int, std::vector<cell>> sets;


maze ellerGen::genMaze(long seed, int w, int h) {
	std::mt19937 generator(seed);

maze m(w,h);
	if (seed == 0) {
		seed = std::chrono::system_clock::now().time_since_epoch().count();
	}
    //std::cout << "width: " << m.width << "Height: " << m.height<< std::endl;
	//std::cout << "width real: " << m.cells.size() << "Height: " << m.cells[1].size()<< std::endl;

	std::uniform_int_distribution<int> distr(0, 1);
//	std::vector<std::set<std::string>> set;
	int next_set = 1;
	for(int i = 0 ; i < m.cells.size() ; i++) {
		//std::cout << "Sets in new " << std::endl;
		for(int c = 0 ; c < m.cells[i].size() ; c++){
			// do a row here
			// fill in cells that do no have a set
		//std::cout << cells[cellToS(m.cells[i][c])] << " ";
			if(cells[cellToS(m.cells[i][c])] == 0){
				cells[cellToS(m.cells[i][c])] = next_set++;
				add(m.cells[i][c] ,cells[cellToS(m.cells[i][c])]);
//				sets[cells[cellToS(m.cells[i][c])]].push_back(m.cells[i][c]);
			}
		}
		//std::cout << "sets this cycle =" << sets.size() << std::endl;
		for(int c = 0 ; c < m.cells[i].size() - 1 ; c++){
			if(i == m.width - 1){
				// do final row
				if(!same(m.cells[i][c],m.cells[i][c+1])){
					edge t;
					t.x1 = m.cells[i][c].x;
					t.y1 = m.cells[i][c].y;
					t.x2 = m.cells[i][c+1].x;
					t.y2 = m.cells[i][c+1].y;
					m.edges_v.push_back(t);
					m.cells[i][c].connected.push_back(t);
					m.cells[i][c+1].connected.push_back(t);
					// merge the sets here
					merge(m.cells[i][c] , m.cells[i][c+1]);

				}
			}
			// do horizontal joins
			if(!same(m.cells[i][c],m.cells[i][c+1]) && distr(generator) == 0){
				edge t;
				t.x1 = m.cells[i][c].x;
				t.y1 = m.cells[i][c].y;
				t.x2 = m.cells[i][c+1].x;
				t.y2 = m.cells[i][c+1].y;
				m.edges_v.push_back(t);
				m.cells[i][c].connected.push_back(t);
				m.cells[i][c+1].connected.push_back(t);
				// merge the sets here
				merge(m.cells[i][c] , m.cells[i][c+1]);
			}
			if( i+1 < m.height && !same(m.cells[i][c],m.cells[i+1][c]) && distr(generator) == 1){
				edge t;

				t.x1 = m.cells[i][c].x;
				t.y1 = m.cells[i][c].y;
				t.x2 = m.cells[i+1][c].x;
				t.y2 = m.cells[i+1][c].y;
			m.edges_v.push_back(t);
				m.cells[i][c].connected.push_back(t);
				m.cells[i+1][c].connected.push_back(t);
				// merge the sets here
				merge(m.cells[i][c] , m.cells[i+1][c]);
			}

		}
		//std::cout << "sets after horizontal joins =" << sets.size() << std::endl;
		// do joins to next set
		std::unordered_map<int, std::vector<cell>> next_sets;
		for(int s = 1 ; s <= sets.size() ;s++){
//			std::uniform_int_distribution<int> dist(0, sets[s].size() -1 );
			if(sets[s].size() > 0 ) {
				int key = (rand() % (int) (sets[s].size()));
//				//std::cout << key << std::endl;
				int x = sets[s][key].x;
				int y = sets[s][key].y;
//				while(x > m.height - 2|| y > m.width - 2) {
//					key = (rand() % (int) (sets[s].size()));
//
//					x = sets[s][key].x;
//					y = sets[s][key].y;
//					//std::cout << "X = "<<  x << "Y = " << y<< std::endl;
//				}
				if(x < m.width - 1) {
					edge t;
					//
					t.x1 = x;
					t.y1 = y;
					t.x2 = x + 1;
					t.y2 = y;
					m.edges_v.push_back(t);
					m.cells[x][y].connected.push_back(t);
					m.cells[x + 1][y].connected.push_back(t);
					cells[cellToS(m.cells[x + 1][y])] =  cells[cellToS(m.cells[x][y])];
					//std::cout << "set " << cells[cellToS(m.cells[x + 1][y])] << std::endl;
					next_sets[cells[cellToS(m.cells[x + 1][y])]].push_back(m.cells[x + 1][y]);
					// merge the sets here
				}
			}
		}
		//std::cout << "sets in next =" << next_sets.size() << std::endl;

		sets = next_sets;

	}
	m.start = m.cells[0][0];
	m.end = m.cells[w-1][h-1];
	return m;
	
}


std::string ellerGen::cellToS(cell c) {

	return std::to_string(c.x)+ std::to_string(c.y);
}


bool ellerGen::same(cell c1, cell c2) {
////std::cout<<cells[cellToS(c1)]<< " < C1 C2 >" << cells[cellToS(c2)] << std::endl;
	return cells[cellToS(c1)] == cells[cellToS(c2)];
}

void ellerGen::add(cell c, int s) {
	cells[cellToS(c)] = s;
//	//std::cout << "X = "<<  c.x << "Y = " << c.y<< std::endl;
	sets[s].push_back(c);

}

void ellerGen::merge(cell s, cell t) {
	int sink = cells[cellToS(s)];
	int target = cells[cellToS(t)];
	sets[sink].reserve(sets[target].size() + sets[sink].size());
	sets[sink].insert(sets[sink].end(),sets[target].begin(),sets[target].end());
	for(int i = 0 ; i < sets[target].size() ; i++ ){
		cells[cellToS(sets[target][i])] = sink;
	}
	sets.erase(target);
}
