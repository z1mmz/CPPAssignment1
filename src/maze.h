class maze
{
public:
  int width;
  int height;
  int *edges;
  maze(int w , int h);
};
struct edge{
  int n;
  int s;
  int e;
  int w;
};
