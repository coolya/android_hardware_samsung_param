/******************************************************************************
 * param reader
 * reads bootloader parameters from samsung bootloaders
 *
 * Copyright 2011 - Kolja Dummann <k.dummann@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <param.h>


#define PARAM_FILE	"/dev/block/mmcblk0p14"

void usage() {
	printf("usage: sec_param [get|set] [variable]\n");
	printf("possible variables:\n");
	printf("booting_now, fota_mode, b, c, d \n");
	printf("efs_info, str2\n");
	printf("\n\n\n");
	printf("Without get|set it will print all params to stdout\n");
	}


status_t* load_params() {
	PARAM data;
	
	FILE* param = fopen(PARAM_FILE, "r");
	
	 if (param == NULL) {
		 printf("can not load param file\n");
		 return NULL;
	 }
	
	if (fread(&data, sizeof data, 1, param) != 1) {
		fclose(param);
		return NULL;
	}
	
	fclose(param);	
	return &data;
}

int main(int argc, char **argv)
{
	PARAM* param_data;
	param_data = load_params();

	if(param_data == NULL)
		return -EIO;

	if(argc > 1)
	{
		if (strstr(argv[1], "set") != NULL) {
			//todo
			printf("setting parameters not implemented\n");
			return -EINVAL;
		}
		if (strstr(argv[1], "get") != NULL) {

		}
		usage();
		return -EINVAL;

	} else {
		printf("-----------------------------------------------------\n");
		printf("	Information of Parameters\n");
		printf("-----------------------------------------------------\n");
		printf("booting_now	  : 0x%x\n", param_data->booting_now);
		printf("fota_mode	  : 0x%x\n", param_data->fota_mode);
		printf("b       	  : 0x%x\n", param_data->b);
		printf("c       	  : 0x%x\n", param_data->c);
		printf("d       	  : 0x%x\n", param_data->d);
		printf("efs_info	  : %s\n", param_data->efs_info);
		printf("str2     	  : %s\n", param_data->str2 );
		printf("-----------------------------------------------------\n");
	}

    return 0;
}
