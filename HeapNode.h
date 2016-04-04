/**
this class will help me implement a heap of huffman nodes
11/11/2015
Joseph Thompson
**/

#include <iostream>
#include <queue>
#include "HuffmanNode.h"

using namespace std;

#ifndef HEAPNODE_H
#define HEAPNODE_H
 
 class HeapNode{
public:
	HuffmanNode * node;

	bool operator <(const HeapNode &rightArgument) const
	{
		HuffmanNode* temp = rightArgument.getNode();
		int rightWeight = temp->Weight();
		int leftWeight = node->Weight();
		return(rightWeight < leftWeight);
	}
	HuffmanNode* getNode() const{
		return node;
	}
	HuffmanNode* Value(){
		return node;
	}
	void BuildLeaf(int weight, int value){
		node = new HuffmanNode(weight,value);
	}
	void BuildNode(HuffmanNode* left, HuffmanNode* right){
		node = new HuffmanNode(left, right,0);
	}	
 };
 #endif