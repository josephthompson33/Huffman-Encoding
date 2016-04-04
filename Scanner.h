/**
this class reads a text file charcacter by character
it will record the frequency of each of the ascii characters
Joseph Thompson
11/11/2015
**/




#include <iostream>
#include <string>
#include <vector>
#include <fstream>//for taking in text files

using namespace std;

#ifndef SCANNER_H
#define SCANNER_H
#define const int PSEUDOEOF = 256;

class Scanner{
public:
	vector<int> frequencyOfChars(string fileName){
		vector<int> ret(257,0);
		ifstream infile;
		infile.open(fileName.c_str());
		while(infile.peek()&& !infile.eof()){
			char ch = infile.get();
			ret[ch] = ret[ch]+1;
		}
		ret[256] = ret[256]+1;
		infile.close();
		return ret;
	}
	string encode(string codes[], string fileName){
		string ret = "";
		ifstream infile;
		infile.open(fileName.c_str());
		while(infile.peek()&&!infile.eof()){
			char ch = infile.get();
			ret = ret + codes[ch];
		}
		infile.close();
		return ret;
	}
private:
};
#endif