/*
 * =====================================================================================
 *
 *       Filename:  HelloWorld.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/04/2012 01:38:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shanquan Wang (), eefolks@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#define LOG_TAG "HelloWorld"

#include <utils/Log.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#include <string.h>
#include <cutils/atomic.h>
#include <utils/Errors.h>
#include <binder/IServiceManager.h>
#include <utils/String16.h>
#include <utils/String8.h>
#include "utils/Log.h"
#include <unistd.h>

#include "HelloWorld.h"
#include "IHelloWorld.h"
//--------------------------------------------------------------------
namespace android {

HelloWorld::HelloWorld()
{
	
}

HelloWorld :: ~HelloWorld()
{

}

void HelloWorld::onFirstRef()
{
	LOGE("helloworld service start");
	printf("file:%s,line:%i, helloworld service start \n",__FILE__,__LINE__);
	run("HelloWorld",PRIORITY_URGENT_DISPLAY);
}

status_t HelloWorld::readyToRun()
{
	printf("file:%s,line:%i, readyToRun \n",__FILE__,__LINE__);
	return NO_ERROR;
}

bool HelloWorld::threadLoop()
{
	do{
		printf("file:%s,line:%i, threadLoop\n",__FILE__,__LINE__);
		sleep(5);
	}while(true || Thread::exitPending());

	LOGE("helloworld :: threadLoop exsiting");
	return false;

}

void HelloWorld::hellothere(const char *str){
    LOGE("hello: %s\n", str);
    printf("hello: %s\n", str);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  HelloWorldService::helloint
 *  Description: eefolks@gmail.com for binder test
 * =====================================================================================
 */
int HelloWorld::helloint(const char *str){
    printf("hello: %s\n", str);
	return 101;
}
		/* -----  end of function helloint  ----- */

};//namespace android
