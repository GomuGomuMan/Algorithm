#include <list>
#include <iostream>
#include <queue>
#include <unordered_map>

class Graph 
{
	public:
		// Default Constructor
		Graph();

		/*
			Overloaded Constructor
			@param: number of vertices
		*/
		Graph(int v);

		/*
			@return: the number of vertices
		*/
		int getNumVertices() const;

		/*
			Add edge to adjacency list
			@param: edge's begin, edge's end
		*/
		void addEdge(int begin, int end);

		/*
			Print all edges of the graph
		*/
		void printEdge() const;

		// BFS
		void printBFS(int root) const;

		// Destructor
		~Graph();

	private:
		int numVertices;
		std::list<int> * adjList;
};