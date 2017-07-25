/*
* Program:	lab7_lnr7605.c	 Due Date: 10-30-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:	Create basic C++ classes
*		Use public and private data members
*		Use public and private methods	
*		Use a constructor to initialize data members	
*
*		Student added: 	
*			print message class 		
*/
#include "Box.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv){
	Box	shippingBox;
	
	shippingBox.setLength(12);
	shippingBox.setWidth(6);
	shippingBox.setHeight(6);
	
	double v = shippingBox.getVolume();
	double sa = shippingBox.getSurfaceArea();
	
	shippingBox.printMessage(v, sa);
	
	return (0);
}
