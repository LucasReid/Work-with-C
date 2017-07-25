#include "Box.h"
#include <iostream>
using namespace std;

Box::Box(){
	length= 0;
	width =0;
	height =0;	
}

Box::~Box(){
}


void Box::setLength(double newLength){
//set the Length
	length = newLength;
	return;
}

double Box::getLength(){
//return length
	return(length);
}

void Box::setWidth(double newWidth){
	width = newWidth;
	return;
}
double Box::getWidth(){
	return(width);
}

void Box::setHeight(double newHeight){
	height = newHeight;
	return;
}
double Box::getHeight(){
	return(height);
}

double Box::getVolume(){
	double volume;
	volume = length*width*height;
	return (volume);
}

double Box::getSurfaceArea(){
	double sArea;
	sArea = (2*length*width)+(2*length*height)+(2*height*width);
	return (sArea);
}

void Box::printMessage(double volume, double sArea){
	cout<<"Storage Box\n  Volume: "<<volume<<"\n  Surface Area: "<<sArea<<"\n"<<endl;
}

















