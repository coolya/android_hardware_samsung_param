ifeq ($(BOARD_USES_SAMSUNG_PARAM),true)
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := param.c
LOCAL_MODULE := sec_param
LOCAL_MODULE_TAGS := eng
LOCAL_SHARED_LIBRARIES := libcutils libc
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := param.c
LOCAL_MODULE := recovery_sec_param
LOCAL_MODULE_TAGS := eng
LOCAL_MODULE_PATH := $(TARGET_ROOT_OUT_SBIN)
LOCAL_UNSTRIPPED_PATH := $(TARGET_ROOT_OUT_SBIN_UNSTRIPPED)
LOCAL_MODULE_STEM := sec_param
LOCAL_STATIC_LIBRARIES := libcutils libc
LOCAL_FORCE_STATIC_EXECUTABLE := true
include $(BUILD_EXECUTABLE)

endif # BOARD_USES_SAMSUNG_PARAM
