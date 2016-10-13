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

//	test.y;
	int z = 0;
	while (!toVisit.empty()) {

//	current->connected[1];

//
		if (current.y == m.end.y && current.x == m.end.x){
			std::cout << "SOLVED" << std::endl;
			cell temp = m.cells[m.end.x][m.end.y];


			while(temp.x != 0 || temp.y != 0){

				temp = m.cells[temp.parent_x][temp.parent_y];
				std::cout << temp.x << " " << temp.y << std::endl;

			}
			m.solved = true;
			return m ;
		}
	visited[current.x][current.y] = 1;
		z++;
		std::cout << "to visit  "<< toVisit.size() << std::endl;
	std::cout << "visited ?  "<< z << std::endl;
		for (int i = 0; i < current.connected.size() ; i++) {
			edge e = current.connected[i];
			if (e.x1 == current.x && e.y1 == current.y){
				if(visited[e.x2][e.y2] == 0) {

					m.cells[e.x2][e.y2].parent_y = e.y1;
					m.cells[e.x2][e.y2].parent_x = e.x1;
					std::cout << "Current: "<< current.x << " " << current.y << std::endl ;
					std::cout << "Parents: "<< m.cells[e.x2][e.y2].parent_x << " " << m.cells[e.x2][e.y2].parent_y << std::endl;
					toVisit.push(m.cells[e.x2][e.y2]);
				}
			} else{
				if(visited[e.x1][e.y1] == 0) {
					m.cells[e.x1][e.y1].parent_y = e.y2;
					m.cells[e.x1][e.y1].parent_x = e.x2;
					std::cout << "Current: "<< current.x << " " << current.y << std::endl ;
					std::cout << "Parents: "<< m.cells[e.x1][e.y1].parent_x << " " << m.cells[e.x1][e.y1].parent_y << std::endl;
//					std::cout << m.cells[e.x1][e.y1].parent_x << " " << m.cells[e.x1][e.y1].parent_y << std::endl;
					toVisit.push(m.cells[e.x1][e.y1]);
				}
			}
		}
		current = toVisit.front();

		toVisit.pop();
//		std::cout << "POP" << std::endl;
	}



	std::cout << "visited: " << z;


	return m;

}
