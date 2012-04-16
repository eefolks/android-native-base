LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	IHelloWorld.cpp \
	HelloWorld.cpp	

LOCAL_CFLAGS += -DPLATFORM_ANDROID


LOCAL_MODULE_TAGS := optional

# for now, until I do a full rebuild.
LOCAL_PRELINK_MODULE := false

# LOCAL_LDFLAGS += -llog

LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libutils libui
LOCAL_SHARED_LIBRARIES += libbinder

LOCAL_CFLAGS += -Idalvik/libnativehelper/include/nativehelper

LOCAL_MODULE := libhelloworldservice

include $(BUILD_SHARED_LIBRARY)
