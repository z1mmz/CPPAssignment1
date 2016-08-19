
#include <vector>
struct edge{
  int x1;
  int x2;
  int y1;
  int y2;
};

struct cell{
  int y;
  int x;
};

typedef std::vector<cell> cell_vec_t;
typedef std::vector<edge> edge_vec_t;


class maze
{
public:
  int width;
  int height;
  int seed;
  edge_vec_t edges_v;
  cell_vec_t cell_v;
  std::vector<cell_vec_t> cells;
  maze(int w , int h);
};
