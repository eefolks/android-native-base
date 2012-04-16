/*
 * =====================================================================================
 *
 *       Filename:  dd.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/27/2011 05:40:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Wang (), eefolks@jrdcom.com
 *
 * =====================================================================================
 */

#include	<stdlib.h>
#include<stdio.h>
#include "RefBase.h"
#include <iostream>
using namespace std;

class A : public android::RefBase 
{
public:
	A(){
		cout << "kkj" << endl;	
	}
	~A(){
		cout << "#### deconstructor #####" << endl;	
	}
	void onFirstRef(){
		cout << "#### a class onFirstRef #####:%p" << this <<  endl;	
	}

};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	A *pa = new A();
	cout << "after constructor" << endl;
	android::sp<A> spA(pa);
	android::wp<A> wpA(pa);	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
