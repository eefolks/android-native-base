/*
 * =====================================================================================
 *
 *       Filename:  IHelloWorld.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/04/2012 01:03:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shanquan Wang (), eefolks@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <string.h>
#include <cutils/atomic.h>
#include <utils/Errors.h>
#include <binder/IServiceManager.h>
#include <utils/String16.h>
#include <utils/String8.h>
#
#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <utils/threads.h>
#include <string.h>
#include <utils/Log.h>
#include "IHelloWorld.h"

namespace android {

/**
 * This is the implementation of the client side of the IHelloWorld interface
 * Typical usage of this class is to first get a binder object from the service manager
 * then use the interface_cast<IHelloWorld>(binder) method to convert the binder into
 * a IHelloWorld smart pointer and invoke methods on this
 *
 * This code is not needed if your interface is only exposed to the Java world.
 * but similar code can be created to access "Java only" AIDL interfaces.
 *
 * Because we extend from BpInterface we have the remote() method
 * to get access back to the binder when needed
 *
 *  class BpInterface<INTERFACE> extends BpRefBase
 *   + onAsBinder();
 *
 * BpRefBase defines a ref counted class having a method to get
 * a binder object
 *
 * class BpRefBase extends RefBase
 *   + remote() IBinder
 *
 **/
class BpHelloWorld: public BpInterface<IHelloWorld>
{
public:
        BpHelloWorld(const sp<IBinder>& impl)
                : BpInterface<IHelloWorld>(impl) {}

        virtual void hellothere(const char *str) {
                /**
                 * most remote implementation method will look like this
                 * two objects are created "data and reply" to serve as and reply
                 * A parcel is "filled with data" and the transact method is called
                 */
                Parcel data, reply;
                data.writeInterfaceToken(getInterfaceDescriptor());
                data.writeString16(String16(str));
                remote()->transact(HW_HELLOTHERE, data, &reply, IBinder::FLAG_ONEWAY);
        }

		/* 
		 * ===  FUNCTION  ======================================================================
		 *         Name: helloint 
		 *  Description:  eefolks@gmail.com add for test binder
		 * =====================================================================================
		 */
		virtual int helloint(const char *str) {
                /**
                 * most remote implementation method will look like this
                 * two objects are created "data and reply" to serve as and reply
                 * A parcel is "filled with data" and the transact method is called
                 */
				status_t status;
                Parcel data, reply;
                data.writeInterfaceToken(getInterfaceDescriptor());
                data.writeString16(String16(str));
                //status = remote()->transact(RETURN_INT_SHANQUAN, data, &reply, IBinder::FLAG_ONEWAY);
                status = remote()->transact(RETURN_INT_SHANQUAN, data, &reply);
				if(status == NO_ERROR)
					printf("client no error ###\n");
				else
					printf("client error ###\n");

				//Mon 30 Jan 2012 04:11:40 PM CST
				int tmp = reply.readInt32();
				printf("tmp reply:%d\n",tmp);
				return tmp;
        }
					/* -----  end of function helloint  ----- */
};

/**
 * Implementation of the cast from a IBinder back to an interface.
 */
IMPLEMENT_META_INTERFACE(HelloWorld, HELLOWORLD_NAME);

/* BnHelloWorld */
status_t BnHelloWorld::onTransact(uint32_t code,
                                                const Parcel &data,
                                                Parcel *reply,
                                                uint32_t flags)
{
        LOGE("OnTransact(%u,%u)", code, flags);
        CHECK_INTERFACE(IHelloWorld, data, reply);
        switch(code) {
        case HW_HELLOTHERE: {
                /**
                 * Checking permissions is always a good idea.
                 *
                 * Note that the native client will also be granted these permissions in two cases
                 * 1) you run the client code as root or system user.
                 * 2) you run the client code as user who was granted this permission.
                 * @see http://github.com/keesj/gomo/wiki/AndroidSecurity for more information
                 **/
                if (checkCallingPermission(String16("org.credil.helloworldservice.permissions.CALL_HELLOTHERE")) == false){
                    return   PERMISSION_DENIED;
                }
                String16 str = data.readString16();
                hellothere(String8(str).string());
                ///reply->writeString16(str);
                return NO_ERROR;
        } break;
		case RETURN_INT_SHANQUAN:{
                if (checkCallingPermission(String16("org.credil.helloworldservice.permissions.CALL_HELLOTHERE")) == false){
                    return   PERMISSION_DENIED;
                }
                String16 str = data.readString16();
                helloint(String8(str).string());
				int tmp= str.size();
				printf("servie str.size():%i\n",tmp);
				status_t status = reply->writeInt32(tmp);
				if( status == NO_ERROR)
					printf("file:%s,line:%i,no error\n",__FILE__,__LINE__);
				else
					printf("file:%s,line:%i, error\n",__FILE__,__LINE__);
                return NO_ERROR;
		} break;
        default:
                return BBinder::onTransact(code, data, reply, flags);
        }
        return NO_ERROR;
}


};

