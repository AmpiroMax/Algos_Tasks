// ДЗ: на 12.09.20
// реализовать орграф на матрице смежности

#include <iostream>
#include <vector>

using Vertex = size_t;
using AdjList = std::vector<std::vector<Vertex>>;

class IGraph
{
  public:
    virtual size_t size() const;
    virtual void AddEdge(Vertex v1, Vertex v2) = 0;
    virtual std::vector<Vertex> &GetAdj(Vertex v) = 0;
    virtual const std::vector<Vertex> &GetAdj(const Vertex &v) = 0;
    virtual ~IGraph(){};
};

class OrGraph : public IGraph
{
  private:
    AdjList matrix;
    size_t vCount;
    size_t AdjNum;
    std::vector<Vertex> retAdj;

  public:
    OrGraph(size_t count) : vCount{count}
    {
        matrix = std::vector<std::vector<Vertex>>(vCount, std::vector<Vertex>(vCount, 0));
        AdjNum = 0;
    }

    size_t size() const override { return AdjNum; }

    void AddEdge(Vertex v1, Vertex v2) override { matrix.at(v1).at(v2) = 1; }

    std::vector<Vertex> &GetAdj(Vertex v) override
    {
        retAdj = std::vector<Vertex>(0);
        for (auto adj : matrix.at(v))
            if (adj == 1)
                retAdj.push_back(adj);
        return retAdj;
    }
};
