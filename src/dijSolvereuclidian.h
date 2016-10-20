//
/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 2
 * Name: Wolf Zimmermann
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * Created on 18/10/16.
 * */

#ifndef CPPASSIGNMENT_DIJSOLVEREUCLIDIAN_H
#define CPPASSIGNMENT_DIJSOLVEREUCLIDIAN_H

#include "dijSolver.h"

class dijSolvereu:public computePath {
public:
	maze solve(maze) override;
//	virtual cell calculateDist(cell *, std::queue<cell> *pQueue, maze *pMaze, std::vector<std::vector<int>> *pVector)= 0;
private:
	maze m;
	std::queue<cell> q,n;
	cell current;
	std::priority_queue<cell> toVisit;
	std::vector <std::vector<int> >visited;



};

#endif //CPPASSIGNMENT_DIJSOLVEREUCLIDIAN_H
