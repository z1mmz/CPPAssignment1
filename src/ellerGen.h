//
/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 2
 * Name: Wolf Zimmermann
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * Created on 13/10/16.
 * */

//

#ifndef CPPASSIGNMENT_ELLERGEN_H
#define CPPASSIGNMENT_ELLERGEN_H
#include "mazegen.h"
class ellerGen:public generator{
	maze genMaze(long seed, int w, int h);

private:
	std::string cellToS(cell);
	bool isDisjoint(std::vector<std::set<std::string>> , cell, cell);
};
#endif //CPPASSIGNMENT_ELLERGEN_H
