//
/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 2
 * Name: Wolf Zimmermann
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * Created on 11/10/16.
 * */

//

#ifndef ASSIGNMENT1_DIJSOLVER_H
#define ASSIGNMENT1_DIJSOLVER_H
#include "computePath.h"
#include <stack>
#include <vector>
#include <cmath>
#include "dijsolvermanhattan.h"
#include "dijSolvereuclidian.h"
class dijSolver:public computePath {

public:
	computePath * getDij(std::string);
	maze solve(maze) override;
	virtual cell calculateDist(cell *, std::queue<cell> *pQueue, maze *pMaze, std::vector<std::vector<int>> *pVector)= 0;
	maze m;
	std::queue<cell> q,n;
	cell current;
	std::queue<cell> toVisit;
	std::vector <std::vector<int> >visited;

};
#endif //ASSIGNMENT1_DIJSOLVER_H
