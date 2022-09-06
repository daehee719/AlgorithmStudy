#include <iostream>
#include <vector>
using namespace std;
#define MAX_VTXS 256
//연결리스트로 구현


//인접 행렬로 구현

/*

*/

class AdjMatGraph
{
protected:
	int size;
	vector<char> vertices;
	vector<vector<int>> adj;
public:
	AdjMatGraph(int num) { 
		vertices.reserve(num);
		adj.resize(num);
		size = 0;
		for (int i = 0; i < adj.size(); i++)
		{
			adj[i].resize(num);
		}


	}
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }
	void reset()
	{
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
		{
			for (int j = 0; j < MAX_VTXS; j++)
			{
				setEdge(i, j, 0);
			}
		}
	}
	void insertVertex(char name)
	{
		vertices.push_back(name);
		size++;
	}
	void insertEdge(int u, int v)
	{
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}
	void display()
	{
		cout << "정점의 개수 : " << size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << getVertex(i) << " ";
			for (int j = 0; j < size; j++)
			{
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	AdjMatGraph g(5);

	for (int i = 0; i < 4; i++)
	{
		g.insertVertex('A' + i);
	}

	g.insertEdge(0, 1);
	g.insertEdge(0, 3);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);

	cout << "인접 행렬로 구현한 그래프" << endl;
	g.display();
}