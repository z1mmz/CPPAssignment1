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
enum direction{
    north,
    south,
    east,
    west
};
struct cell {
    int y;
    int x;
    bool visited;

};

typedef std::vector<cell> cell_vec_t;
typedef std::vector<edge> edge_vec_t;


class maze {
public:
    int width;
    int height;
    long seed;
    edge_vec_t edges_v;
    cell_vec_t cell_v;
    std::vector<cell_vec_t> cells;

    maze(int w, int h);
    maze(long seed,int w,int h);

    int saveToSVG(std::string a);

//    virtual ~maze();

};

#endif