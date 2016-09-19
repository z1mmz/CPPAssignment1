/*
 * COSC1254 Programming Using c++ 2016
 * Assignment 1
 * Name: Wolf Zimmermamnn
 * Student ID: s3495671
 * Course Code: COSC1254
 * Program Code: BP094
 * */
#ifndef maze_h_
#define maze_h_

#include <vector>
#include <string>

struct edge {
	int x1;
	int x2;
	int y1;
	int y2;
};
enum direction {
	north,
	south,
	east,
	west
};
struct cell {
	int y;
	int x;
	std::vector<edge> connected;
	bool visited;

};

typedef std::vector<cell> cell_vec_t;

typedef std::vector<edge> edge_vec_t;

class maze {
public:
	int width;
	int height;
	cell start;
	cell end;
	long seed;
	edge_vec_t edges_v;
	cell_vec_t cell_v;
	std::vector<cell_vec_t> cells;

	maze(int w, int h);

	maze(void);

	int saveToSVG(std::string file);

	int saveToBin(std::string file);

	virtual ~maze();

	int loadFromBin(std::string file);

	int initMaze(int w, int h);
};

#endif