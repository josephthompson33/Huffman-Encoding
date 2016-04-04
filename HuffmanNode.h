/**
this class will define a node object 
it will hold references to its children, among other things
11/11/15 - no procrastination this time
Joseph Thompson
**/

#include <iostream>
#include <string>

using namespace std;

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

class HuffmanNode{
private:
	string code;
	int weight;
	int value;
	HuffmanNode *leftChild;
	HuffmanNode *rightChild;
	bool visited;
public:
	HuffmanNode(int wayt, int valyoo){
		value = valyoo;
		weight = wayt;
		leftChild = NULL;
		rightChild = NULL;
		bool visited = false;
	}
	HuffmanNode(int leftval, int leftweight, int rightval, int rightweight){
		leftChild = new HuffmanNode(leftweight, leftval);
		rightChild = new HuffmanNode(rightweight, rightval);
		weight = leftweight + rightweight;
		value = -1;
		bool visited = false; 
	}
	HuffmanNode(HuffmanNode * left, HuffmanNode * right, int i){
		leftChild = left;
		rightChild = right;
		weight = left->Weight() + right->Weight();
		value = -1;
		bool visited = false;
	}
	void traverse(HuffmanNode * tree, string Code, string Codes[]){
		tree->visit();
		if(tree->Right() == NULL && tree->Left()==NULL){
			code = Code;
			char ch = tree->Value();
			Codes[ch] = code;
			cout<<"the Character "<<ch<<" occurs "<<tree->Weight()<<" times "<<" its code is:"<<code<<endl;
			return;
		}
		if(tree->Left() != NULL && !tree->Left()->Visited()){
			string cod;//cant increment Code here so i make a replacement for the left side called cod
			cod = Code;
			cod = cod + "0";
			tree->traverse(tree->Left(), cod, Codes);
		}
		if(tree->Right()!= NULL){
			Code = Code + "1";
			tree->traverse(tree->Right(), Code, Codes);
		}
	}
	string Code(){
		return code;
	}
	void setCode(string Code){
		code = Code;
	}
	bool Visited(){
		return visited;
	}
	void visit(){
		visited = true;
	}
	int Value(){
		return value;
	}
	int Weight(){
		return weight;
	}
	HuffmanNode* Left(){
		return leftChild;
	}
	HuffmanNode* Right(){
		return rightChild;
	}
};
#endif