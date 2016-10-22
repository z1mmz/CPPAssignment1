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

	// create a 2d vector for checking if a cell has been visited
	std::queue<cell> toVisit;
	vector<vector<int>> visited;
	for (int i = 0; i <= m.width; i++) {
		std::vector<int> col;
		for (int x = 0; x <= m.height; x++) {
			col.push_back(0);
		}
		visited.push_back(col);
	}
	std::cout << "BFS" << std::endl;
	toVisit.push(current);


	int z = 0;// counter for how many times we have looped


	while (!toVisit.empty()) {

		// if the node is already visited get a new one
		while (visited[current.x][current.y] == 1) {
			current = toVisit.front();

			toVisit.pop();

		}


		if (current.y == m.end.y && current.x == m.end.x) {
			cell temp = m.cells[m.end.x][m.end.y];
			m.solved = true;
			return m;
		}

		// mark the current node as visited
		visited[current.x][current.y] = 1;
		z++;

		// add all the neighbors to visit and set their parents
		for (int i = 0; i < (int)current.connected.size(); i++) {
			edge e = current.connected[i];
			if (e.x1 == current.x && e.y1 == current.y) {
				if (visited[e.x2][e.y2] == 0) {
					m.cells[e.x2][e.y2].parent_y = e.y1;
					m.cells[e.x2][e.y2].parent_x = e.x1;
					toVisit.push(m.cells[e.x2][e.y2]);
				}
			} else {
				if (visited[e.x1][e.y1] == 0) {
					m.cells[e.x1][e.y1].parent_y = e.y2;
					m.cells[e.x1][e.y1].parent_x = e.x2;
					toVisit.push(m.cells[e.x1][e.y1]);
				}
			}
		}
		// get the next node
		current = toVisit.front();

	}

	return m;

}
