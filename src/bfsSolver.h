//
/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 2
 * Name: Wolf Zimmermamnn
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * Created on 9/09/16.
 * */

//

#ifndef ASSIGNMENT1_BFSSOLVER_H
#define ASSIGNMENT1_BFSSOLVER_H
#include "maze.h"
#include "computePath.h"
class bfsSolver:public computePath{
public:
	maze solve(maze) override;

};
#endif //ASSIGNMENT1_BFSSOLVER_H
