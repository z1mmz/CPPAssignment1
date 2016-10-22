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

#include "solverFactory.h"
computePath * solverFactory::makeSolver(std::string flag){
	computePath * e;

	if(flag == "--pb"){
		e = new bfsSolver();
	}
	if(flag == "--pd"){
		e = new dfsSolver();
	}
	if(flag == "--pm"){
		e = new dijSolvermanhattan();
	}
	if(flag == "--pe"){
		e = new dijSolvereu();
	}
	return e;


}