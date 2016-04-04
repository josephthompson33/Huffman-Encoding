#include <iostream>
#include <queue>
#include <string>
#include "HeapNode.h"
#include "HuffmanNode.h"
#include "Scanner.h"

using namespace std;

int main(int argc, char *argv[]){
	if(argv[1]==NULL){
		cout<<"give a text file on the command line pls"<<endl;
		return 0;
	}
		Scanner object;
		vector<int> output = object.frequencyOfChars(argv[1]);
		//cout<<"output is made"<<endl;
		priority_queue<HeapNode> theQueue;//this will be a heap of heapnodes
		//cout<<"the q is made"<<endl;
		for(int i = 0;i<output.size();i++){
			if(output[i]!=0){
				HeapNode theNode;
				theNode.BuildLeaf(output[i], i);
				theQueue.push(theNode);
			}
		}
		/**while(!theQueue.empty()){
			HeapNode heapNode = theQueue.top();
			theQueue.pop();
			cout<<heapNode.Value()->Value()<<" "<<heapNode.Value()->Weight()<<endl;
		}**/
		HuffmanNode * theTree;
		while(!theQueue.empty()){
			HeapNode  node1 = theQueue.top();
			HuffmanNode * huffNode1 = node1.Value();
			theQueue.pop();
			if(!theQueue.empty()){
				HeapNode  node2 = theQueue.top();
				HuffmanNode * huffNode2 = node2.Value();
				theQueue.pop();
				node2.BuildNode(huffNode1,huffNode2);
				//cout<<"weight "<<huffNode1->Weight()<<" and weight "<<huffNode2->Weight()<<" were combined to make weight "<<node2.Value()->Weight()<<endl;
				//cout<<"children of "<<node2.Value()->Weight()<<" are "<<huffNode1->Weight()<<" "<<huffNode2->Weight()<<endl;
				theQueue.push(node2);
			}
			else{
				theTree = node1.Value();//this means there was one node left at
				//the top of the loop, so parent must be set to the final
				//node in the Queue, which is the huffmantree
			}
		}
		while(theTree!=NULL){
			cout<<theTree->Weight()<<" "<<theTree->Value()<<endl;
			theTree = theTree->Right();
		}
	}