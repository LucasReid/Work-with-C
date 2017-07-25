//stuff
//sudoCode
#ifndef WORDCOUNT_H_
#define WORDCOUNT_H_
#include <cctype>
#include <fstream>
#include <map>
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

class wordCount{
	private:
		map<string, int> words;
	
	public:
		wordCount(string fileName);
		virtual ~wordCount();
	
		void outputMap();
	
	private:
		void buildMap(istream &InFile);//done as a pointer
	
		string removePunctuation(string noPunctWrd);
		
		string makeLowerCase(string lowerCaseWrd);
};
#endif	
