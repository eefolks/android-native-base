/*
 * =====================================================================================
 *
 *       Filename:  HelloWorld.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/04/2012 01:18:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shanquan Wang (), eefolks@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef HELLOWORD_SERVICE_H
#define HELLOWORD_SERVICE_H

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
#include "IHelloWorld.h"
#include "utils/Log.h"
#include <unistd.h>
#include <utils/threads.h>
#include <utils/RefBase.h>
#include <binder/BinderService.h>

//------------------------------------------------------------------------'

namespace android {
//------------------------------------------------------------------
	
class HelloWorld :
		public BinderService<HelloWorld>,
		public BnHelloWorld,
		protected Thread
	{
		friend class BinderService<HelloWorld>;

		HelloWorld();
		virtual ~HelloWorld();

		//RefBase interface
		virtual void onFirstRef();

		//Thread interface
		virtual status_t readyToRun();
		virtual bool threadLoop();

		//IHelloWorld interface
		virtual void hellothere(const char *str);
		virtual int helloint(const char *str);

	
		public:
	   	static char const* getServiceName() { return HELLOWORLD_NAME ; }

	};

};//namespace android

#endif
