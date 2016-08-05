class maze
{
public:
  int width;
  int height;
  int *edges;
  maze(int w , int h);
};
struct edge{
  int x1;
  int x2;
  int y1;
  int y2;
};
