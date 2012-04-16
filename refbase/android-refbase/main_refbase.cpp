/*
 * =====================================================================================
 *
 *       Filename:  main_refbase.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/07/2012 02:18:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Wang (),eefolks@gmail.com 
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <utils/RefBase.h>
#include <utils/Log.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#define LOG_TAG "shanquan.refbase"

//using namespace std;

class A : public android::RefBase 
{
public:
	A(){
		LOGE("A constructor");
		printf("#### A constructor ####\n");
	}
	~A(){
		LOGE("#### deconstructor #####");	
		printf("#### deconstructor #####\n");	
	}
	void onFirstRef(){
		LOGE("#### a class onFirstRef #####:%p", this) ;	
		printf("#### a class onFirstRef #####:%p\n", this) ;	
	}
	void printMe(){
		printf("ye!,it is me \n");	
	}

};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  shanquanSP
 *  Description:  
 * =====================================================================================
 */

int	
shanquanSP(android::sp<A> base)
{
	base->printMe();
	return 0;
}		/* -----  end of function shanquanSP  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	LOGI("before new constructor");
	//printf("before new constructor\n");
	A *pa = new A();
	LOGE("after constructor");
	//printf("after constructor\n");
	/*  
	android::sp<A> spA(pa);
	android::wp<A> wpA(pa);	
	*/
    //android::sp<android::IServiceManager> sm = android::defaultServiceManager();
	shanquanSP(pa);
	return (0);
}				/* ----------  end of function main  ---------- */


