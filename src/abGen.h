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

#ifndef CPPASSIGNMENT_ABGEN_H
#define CPPASSIGNMENT_ABGEN_H
#include "mazegen.h"
class abGen:public generator{
	maze genMaze(long seed, int w, int h);

};
#endif //CPPASSIGNMENT_ABGEN_H
