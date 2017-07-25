//sudoCode
//things you will need
#include "wordCount.h"
#include <cctype>
#include <fstream>
#include <map>
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

wordCount::wordCount(string fileName){
	ifstream 	InFile(fileName.c_str());
	
	if(!InFile){		
		runtime_error myException("error opening file!"+ fileName);
		throw(myException);
	}
	buildMap(InFile);
	
}
wordCount::~wordCount(){}


void wordCount::buildMap(istream &InFile){
	while(!InFile.eof())// .eof();
	{
		string tmpWord;
		//read in a word;
		if(tmpWord.empty())//.empty()
		continue;
		
	tmpWord= removePunctuation(tmpWord);
		if(tmpWord.empty())
		continue;
	//tmpWord = makeLowerCase(tmpWord);
	 
	map<string/*first*/, int/*second*/>:: iterator 	currentWord = words.find(tmpWord);	
	
	if(words.find(tmpWord)!=words.end())//.find(), .end(), .insert()
		currentWord -> second++;
	else
		words.insert(pair<string, int>(tmpWord, 1));
	}
}	
string wordCount::removePunctuation(string noPunctWord){
	string punctuationList=".,:;[]()-?\"!";
		for(unsigned int i; punctuationList.length(); i++){
		
			while(true){
			
				unsigned long position = noPunctWord.find(punctuationList[i]);
				if(position != string::npos){
					//erase it
				}
				else 
					break;	
				
				if(noPunctWord.find("'") ==0){
					//erase it
				}
				return(noPunctWord);	
			}
		}					
	return(noPunctWord);
}

string wordCount::makeLowerCase(string lowerCaseWrd){

	for(int i = 0; i<words.length() ;i++)
	lowerCaseWrd[i] = tolower(lowerCaseWrd[i]);

	return( lowerCaseWrd );
}
/*
void wordCount::outPutMap(){
	map<string, int>::iterator current; 
	start = words.begin();
	end = 
	
}
*/




















