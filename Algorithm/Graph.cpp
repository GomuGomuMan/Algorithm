#include "Graph.h"

Graph::Graph()
{
	numVertices = 0;
}


Graph::Graph(int numVertices)
{
	this->numVertices = numVertices;
	adjList = new std::list<int>[numVertices];
}


int Graph::getNumVertices() const
{
	return numVertices;
}


void Graph::addEdge(int begin, int end)
{
	adjList[begin].push_back(end);
}

void Graph::printEdge() const
{
	for (int i = 0; i < numVertices; ++i)
	{
		std::list<int>::iterator it;
		for (it = adjList[i].begin(); it != adjList[i].end(); ++it)
		{
			std::cout << "Edge begins from: " << i << " and end in " << *it 
				<< std::endl;
		}
	}
}

void Graph::printBFS(int root) const
{
	//TODO: Maybe storing vertex as a node?
	//TODO: Recursive approach
	std::unordered_map<int, bool> visited;
	std::queue<int> stack;
	stack.push(root);
	visited.insert(std::make_pair(root, true));

	while (!stack.empty())
	{
		int currNode = stack.front();
		std::cout << currNode << " ";
		stack.pop();
		std::list<int>::iterator it;
		

		for (it = adjList[currNode].begin(); it != adjList[currNode].end(); ++it)
		{
			if (!visited[*it]) // also initialize an index oh hashmap
			{
				visited[*it] = true; // change to true
				stack.push(*it);
			}
		}
	}
	std::cout << std::endl;
}


Graph::~Graph() { }