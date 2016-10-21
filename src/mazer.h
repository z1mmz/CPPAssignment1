/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 1
 * Name: Wolf Zimmermamnn
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * */
#ifndef MAZER
#define MAZER
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <fstream>
#include <bitset>
#include <sstream>
#include "computePath.h"
#include "bfsSolver.h"
#include "dfsSolver.h"
#include "abGen.h"
#include "heap_set.h"
#include "dijSolver.h"
#include "ellerGen.h"


// #include "maze.h"
void genMaze(std::string flag,std::vector<std::string> vars);
void saveMaze(std::string flag,std::vector<std::string> vars);
void loadMaze(std::string flag,std::vector<std::string> vars);
void solveMaze(std::string flag,std::vector<std::string> vars);

#endif
// #include "mazesaver.h"

// std::vector<std::vector<std::string>> arguments;
