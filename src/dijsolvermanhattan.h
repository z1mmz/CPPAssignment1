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

#ifndef CPPASSIGNMENT_DIJSOLVERMANHATTAN_H
#define CPPASSIGNMENT_DIJSOLVERMANHATTAN_H

#include "dijSolver.h"

class dijSolvermanhattan:public computePath {
public:
	maze solve(maze) override;
//	virtual cell calculateDist(cell *, std::queue<cell> *pQueue, maze *pMaze, std::vector<std::vector<int>> *pVector)= 0;
private:
	maze m;
	cell current;
	std::priority_queue<cell> toVisit;
	std::vector <std::vector<int> >visited;



};
#endif //CPPASSIGNMENT_DIJSOLVERMANHATTAN_H
