#pragma once
#include <stack>
#include <queue>
#include "Graph.h";

/**
* @file DSFIterator.h
* @class DFSIterator
*/

class DFSIterator
{
private:
	/**
	* @brief mark done vertexes 
	*/
	bool* discovered;
	/**
	* @brief It using stack
	*/
	stack<int>* currentStack;
	/**
	* @brief My graph from file
	*/
	Graph* graph;
public:
	/**
	* Konstruktor
	* @param Graph*
	*/
	DFSIterator(Graph* graph);
	/**
	* Reset - The iterator will start brom beginning
	*/
	void Reset();
	/**
	* Next - it send us to next vertex in stack, or to another component of graph
	*/
	void Next();
	/**
	* Checks if we are at the end (if we have gone trough all vertexes in graph)
	* @return bool
	*/
	bool IsEnd();
	/**
	* CurrentKey - It returns actual element in the stack
	* @return int
	*/
	int CurrentKey();
};