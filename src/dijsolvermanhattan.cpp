//
/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 2
 * Name: Wolf Zimmermann
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * Created on 16/10/16.
 * */

//

#include "dijsolvermanhattan.h"
maze dijSolvermanhattan::solve(maze maz) {

	m = maz;
	current = m.start;

	// 2d array for checking visited
	for (int i = 0; i <= m.width; i++) {
		std::vector<int> col;
		for (int x = 0; x <= m.height; x++) {
			col.push_back(0);
		}
		visited.push_back(col);
	}
	std::cout << "Dij" << std::endl;
	current.cost = 0;
	toVisit.push(current);

	while (!toVisit.empty()) {

		current = toVisit.top();
		toVisit.pop();
		visited[current.x][current.y] = 1;
		// add all neighbors to visit that we have a better cost to or
		// are not visited
		for(edge e : current.connected){
			int x,y;
			//We check which co-ordinates to use as we are reusing the edges
			if (e.x1 == current.x && e.y1 == current.y){
				x = e.x2;
				y = e.y2;
			}else{
				x = e.x1;
				y = e.y1;
			}
			//manhattan calc
			 if(!visited[x][y]){
			 	m.cells[x][y].cost = abs(x - m.start.x) + abs( y - m.start.y);
			 	m.cells[x][y].parent_x = current.x;
			 	m.cells[x][y].parent_y = current.y;
				 visited[x][y] = 1;
			 	toVisit.push(m.cells[x][y]);
			 } else if (m.cells[x][y].cost < (abs(x - m.start.x) + abs( y - m.start.y))){
			 	m.cells[x][y].cost = abs(x - m.start.x) + abs( y - m.start.y);
			 	m.cells[x][y].parent_x = current.x;
			 	m.cells[x][y].parent_y = current.y;
			 	toVisit.push(m.cells[x][y]);
			 }

		}


	}
	cell temp = m.cells[m.end.x][m.end.y];
	int cost = temp.cost;
	std::cout << "cost: "<< cost << std::endl;
	m.solved = true;
	return m ;

}
