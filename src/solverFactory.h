//
/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 2
 * Name: Wolf Zimmermann
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * Created on 22/10/16.
 * */

//

#ifndef CPPASSIGNMENT_SOLVERFACTORY_H
#define CPPASSIGNMENT_SOLVERFACTORY_H

#include "dijSolver.h"
#include "computePath.h"
#include "dfsSolver.h"
#include "bfsSolver.h"

class solverFactory {
public:
	solverFactory();
	static computePath * makeSolver(std::string);

};


#endif //CPPASSIGNMENT_SOLVERFACTORY_H
