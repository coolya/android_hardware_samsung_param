LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := param.c
LOCAL_MODULE := sec_param
LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_LIBRARIES := libstdc++ libc
LOCAL_FORCE_STATIC_EXECUTABLE := true
include $(BUILD_EXECUTABLE)
