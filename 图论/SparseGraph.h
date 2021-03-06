#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
/**
 * 稀疏图
 * 邻接表表示
 */
class SparseGraph
{
private:
  int spotNum;           //点数
  int edgeNum;           //边数
  bool directed;         //是否为有向图
  vector<vector<int>> g; //邻接表
public:
  SparseGraph(int n, bool directed)
  {
    this->spotNum = n;
    this->edgeNum = 0;
    this->directed = directed;
    for (int i = 0; i < n; i++)
    {
      g.push_back(vector<int>());
    }
  }
  //返回点的个数
  int V() { return spotNum; }
  //返回边的个数
  int E() { return edgeNum; }
  /**
   * 添加一条边
   */
  void addEdge(int v, int w)
  {
    assert(v >= 0 && v < spotNum);
    assert(w >= 0 && w < spotNum);
    g[v].push_back(w);
    if (v != w && !directed)
    {
      g[w].push_back(v);
    }
    edgeNum++;
  }
  // v和w直接是否有边
  bool hasEdge(int v, int w)
  {
    assert(v >= 0 && v < spotNum);
    assert(w >= 0 && w < spotNum);
    for (int i = 0; i < g[v].size(); i++)
    {
      if (g[v][i] == w)
      {
        return true;
      }
    }
    return false;
  }

  void show()
  {
    for (int i = 0; i < spotNum; i++)
    {
      cout << "vertex " << i << ":\t";
      for (int j = 0; j < g[i].size(); j++)
        cout << g[i][j] << "\t";
      cout << endl;
    }
  }

  class adjIterator
  {
  private:
    SparseGraph &G;
    int v;
    int index;

  public:
    adjIterator(SparseGraph &graph, int v) : G(graph)
    {
      this->v = v;
      this->index = 0;
    }

    int begin()
    {
      index = 0;
      if (G.g[v].size())
        return G.g[v][index];
      return -1;
    }

    int next()
    {
      index += 1;
      if (G.g[v].size())
        return G.g[v][index];
      return -1;
    }

    bool end()
    {
      return index >= G.g[v].size();
    }
  };
};