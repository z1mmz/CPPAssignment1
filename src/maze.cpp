/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 1
 * Name: Wolf Zimmermamnn
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * */
#include <iostream>
#include <fstream>
#include <random>
#include "maze.h"

maze::maze(int w, int h) {
	width = w;
	height = h;
	solved = false;

	for (int x = 0; x < w; x++) {
		cell_vec_t coll;
		for (int i = 0; i < h; i++) {
			cell a;
			a.x = x;
			a.y = i;
			a.visited = false;
			coll.push_back(a);
		}
		cells.push_back(coll);
	}
	start = cells[0][0];
	end = cells[w-1][h-1];

}

maze::maze(void) {}

int maze::initMaze(int w, int h) {
	width = w;
	height = h;
	solved = false;
	for (int x = 0; x < w; x++) {
		cell_vec_t coll;
		for (int i = 0; i < h; i++) {
			cell a;
			a.x = x;
			a.y = i;
			a.visited = false;
			coll.push_back(a);
		}
		cells.push_back(coll);
	}
	start = cells[0][0];
	end = cells[w-1][h-1];
	return 0;
}

int maze::saveToSVG(std::string file) {
	std::fstream fOut(file, std::fstream::out);


	if (fOut.is_open()) {
		// adding + 1 to width and height to give the maze a boarder
		// * 10 scales the maze to level where it is nice to look at
		fOut << "<svg xmlns='http://www.w3.org/2000/svg' width='" << (this->width + 1) * 10 << "' ";
		fOut << "height='" << (this->height + 1) * 10 << "'> \n";
		fOut << "<rect width='" << (this->width + 1) * 10 << "' ";
		fOut << "height='" << (this->height + 1) * 10 << "' ";
		fOut << "style='fill: black'/>\n";

		for (edge e : this->edges_v) {
			fOut << "<line stroke='white' stroke-width='4' ";
			fOut << "x1='" << (e.x1 + 1) * 10 << "' ";
			fOut << "y1='" << (e.y1 + 1) * 10 << "' ";
			fOut << "x2='" << (e.x2 + 1) * 10 << "' ";
			fOut << "y2='" << (e.y2 + 1) * 10 << "' /> \n";

		}
		cell temp = cells[end.x][end.y];
//			std::cout << temp.x << " " << temp.y << std::endl;
//			std::cout << temp.parent_x << " parararar " << temp.parent_x << std::endl;
if(solved == true) {
	while (temp.x != start.x || temp.y != start.y) {
//			std::cout << temp.x << " " << temp.y << std::endl;
//				std::cout << temp.parent_x << " " << temp.parent_x << std::endl;

//				std::cout << "got a new cell" << std::endl;
//				std::cout << temp.x << " " << temp.y << std::endl;
		fOut << "<line stroke='red' stroke-width='4' ";
		fOut << "x1='" << (temp.x + 1) * 10 << "' ";
		fOut << "y1='" << (temp.y + 1) * 10 << "' ";
		fOut << "x2='" << (temp.parent_x + 1) * 10 << "' ";
		fOut << "y2='" << (temp.parent_y + 1) * 10 << "' /> \n";
		temp = cells[temp.parent_x][temp.parent_y];
	}
}
		fOut << "</svg>";

	} else {
		std::cerr << "Could not save maze to SVG" << std::endl;

	}

	fOut.close();

	return 0;
}

int maze::saveToBin(std::string file) {
	std::fstream fOut(file, std::fstream::out | std::ios::binary );

	if (fOut.is_open()) {

		int h = this->height;
		int w = this->width;
		int numEdge = this->edges_v.size();
		fOut.write((char *) &h, sizeof(h));
		fOut.write((char *) &w, sizeof(w));
		fOut.write((char *) &numEdge, sizeof(numEdge));
		for (edge e : this->edges_v) {
			fOut.write((char *) &e.x1, sizeof(e.x1));
			fOut.write((char *) &e.y1, sizeof(e.y1));
			fOut.write((char *) &e.x2, sizeof(e.x2));
			fOut.write((char *) &e.y2, sizeof(e.y2));
		}
		fOut.close();
	}
	return 0;
}

int maze::loadFromBin(std::string file) {

	std::ifstream in(file, std::ios::binary);

	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	int h = 0;
	int w = 0;

// Read the width and height
	in.read((char *) &h, sizeof(h));
	in.read((char *) &w, sizeof(w));
	std::cout << h << std::endl;
	int totalEdges = 0;
	in.read((char *) &totalEdges, sizeof(totalEdges));
	initMaze(h, w);

	// Read in the edges
	while (in.read((char *) &x1, sizeof(x1))
		   && in.read((char *) &y1, sizeof(y1))
		   && in.read((char *) &x2, sizeof(x2))
		   && in.read((char *) &y2, sizeof(y2))) {
		edge newEdge;
		newEdge.x1 = x1;
		newEdge.y1 = y1;
		newEdge.x2 = x2;
		newEdge.y2 = y2;
		// create connected vectors
		cells[x1][y1].connected.push_back(newEdge);
		cells[x2][y2].connected.push_back(newEdge);
		cells[x1][y1].visited = true;
		cells[x2][y2].visited = true;
		edges_v.push_back(newEdge);

	}
	if (edges_v.size() != (unsigned) totalEdges) {
		std::cerr << "Error: Did not load all edges" << std::endl;
		return 1;

	}
	in.close();

	return 0;
}

maze::~maze() {

}
