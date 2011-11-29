#define NORMAL_MODE         0
#define FOTA_MODE           1

#define CHARGING_MODE   0
#define DIRECT_BOOTING_MODE 1
#define RECOVERY_ENTER_MODE 2
#define RECOVERY_END_MODE   3
#define DOWNLOAD_FAIL       4

// must be same as bootable/bootloader/lk/app/aboot/common.h
typedef struct _param {
	int booting_now;    
	int fota_mode;  
	int b;
	int c;
	int d;
	char efs_info[32];
	char str2[32];
} PARAM;

#define PARAM_SIZE        	84s
