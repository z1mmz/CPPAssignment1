//
/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 2
 * Name: Wolf Zimmermann
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * Created on 26/09/16.
 * */

//

#include "dfsSolver.h"

using namespace std;

maze dfsSolver::solve(maze m) {
	cell current = m.start;
	std::stack<cell> toVisit;

	vector<vector<int>> visited;
	// create 2d vector to mark visited cells
	for (int i = 0; i <= m.width; i++) {
		std::vector<int> col;
		for (int x = 0; x <= m.height; x++) {
			col.push_back(0);
		}
		visited.push_back(col);
	}

	toVisit.push(current);

	int z = 0;
	while (!toVisit.empty()) {


		if (current.y == m.end.y && current.x == m.end.x) {

			m.solved = true;
			return m;
		}
		// mark current as visited
		visited[current.x][current.y] = 1;
		z++;

		// add the neighbors to visit and set parents
		for (unsigned i = 0; i < current.connected.size(); i++) {
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
		current = toVisit.top();

		toVisit.pop();

	}

	return m;

}