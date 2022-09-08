#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VTXS 256





class AdjMatGraph
{
protected:
    int        size;                        // ������ ����
    char    vertices[MAX_VTXS];            // ������ �̸�
    int        adj[MAX_VTXS][MAX_VTXS];    // ���� ���

public:
    AdjMatGraph() { reset(); }

    char getVertex(int i) { return vertices[i]; }
    int     getEdge(int i, int j) { return adj[i][j]; }
    void setEdge(int i, int j, int val) { adj[i][j] = val; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= MAX_VTXS; }
    void reset() {
        size = 0;
        for (int i = 0; i < MAX_VTXS; i++)
            for (int j = 0; j < MAX_VTXS; j++)
                setEdge(i, j, 0);
    }
    void insertVertex(char name) {
        if (!isFull()) vertices[size++] = name;
        else cout << "Error: �׷��� ������ ���� �ʰ�" << endl;
    }

    void insertEdge(int u, int v) {
        setEdge(u, v, 1);
        setEdge(v, u, 1);
    }

    void display() {
        cout << "������ ���� : " << size << endl;
        for (int i = 0; i < size; i++) {
            cout << getVertex(i) << " ";
            for (int j = 0; j < size; j++)
                cout << " " << getEdge(i, j);
            cout << endl;
        }
    }
};

class SearchGraph : public AdjMatGraph
{
    bool visited[MAX_VTXS];
public:
    void resetVisit()
    {
        for (int i = 0; i < size; i++)
        {
            visited[i] = false;
        }
    }
    bool isLinked(int u, int v) { return getEdge(u, v) != 0; }
    void DFS(int v)
    {
        visited[v] = true;
        cout << vertices[v] << " ";
        for (int i = 0; i < size; i++)
        {
            if (isLinked(v, i) && visited[i] == false)
            {
                DFS(i);
            }
        }
    }

    void BFS(int v)
    {
        visited[v] = true;
        queue<char> q;
        q.push(v);
        while (!q.empty())
        {
            int i = q.front();
            cout << getVertex(i) << " ";
            q.pop();
            for (int i = 0; i < size; i++)
            {
                if (isLinked(v, i) && visited[i] == false)
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};


int main()
{
    SearchGraph g;

    for (int i = 0; i < 4; i++)
        g.insertVertex('A' + i);

    g.insertEdge(0, 1);
    g.insertEdge(0, 3);
    g.insertEdge(1, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);

    cout << "���� ��ķ� ǥ���� �׷���" << endl;
    g.display();
    cout << "DFS" << endl;
    g.resetVisit();
    g.DFS(0);
    cout << endl;

    g.resetVisit();
    cout << "BFS" << endl;
    g.BFS(0);
}
