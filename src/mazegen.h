/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 1
 * Name: Wolf Zimmermamnn
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * */
#include "maze.h"
#ifndef CPPASSIGNMENT_GEN_H
#define CPPASSIGNMENT_GEN_H
#include <iostream>
#include <random>

#include <chrono>
class generator{
public:
	generator();
	virtual maze genMaze(long seed, int w, int h);

};

#endif