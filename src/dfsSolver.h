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

#ifndef ASSIGNMENT1_DFSSOLVER_H
#define ASSIGNMENT1_DFSSOLVER_H

#include "computePath.h"
#include <stack>
class dfsSolver:public computePath{
public:
	maze solve(maze) override;
};

#endif //ASSIGNMENT1_DFSSOLVER_H
