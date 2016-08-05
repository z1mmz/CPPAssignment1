
#include <vector>
struct edge{
  int x1;
  int x2;
  int y1;
  int y2;
};
typedef std::vector<edge> edge_vec_t;
class maze
{
public:
  int width;
  int height;
  int *edges;
  edge_vec_t edges_v;
  maze(int w , int h);
};
