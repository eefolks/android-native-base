/*
 * =====================================================================================
 *
 *       Filename:  main_helloworldservice.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/04/2012 02:24:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shanquan Wang (),eefolks@gmail.com 
 *        Company:  
 *
 * =====================================================================================
 */
#include <binder/BinderService.h>
#include <HelloWorld.h>

using namespace android;

int main(int argc, char** argv) {
	    HelloWorld::publishAndJoinThreadPool();
	    return 0;
}

