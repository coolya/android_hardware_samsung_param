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


#define PARAM_FILE	"/mnt/.lfs/param.blk"

void usage() {
	printf("usage: sec_param [get|set] [variable]\n");
	printf("possible variables:\n");
	printf("serial_speed, load_ramdisc, boot_delay, lcd_level\n");
	printf("switch_sel, phone_debug_on, lcd_dim_level, lcd_dim_time\n");
	printf("melody_level, reboot_mode, nation_sel, language_sel\n");
	printf("set_default_param, version, cmdline\n");
	printf("\n\n\n");
	printf("Without get|set it will print all params to stdout\n");
	}


status_t* load_params() {
	status_t data;
	
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
	status_t* param_data;
	param_data = load_params();

	if(param_data == NULL)
		return -EIO;

	if(param_data->param_magic != PARAM_MAGIC)
	{
		printf("parameter magic 0x%x expected 0x%x\n",
			param_data->param_magic, PARAM_MAGIC);
		return -EIO;
	}

	if(param_data->param_version != PARAM_VERSION)
	{
		printf("parameter version 0x%x expected 0x%x\n",
			param_data->param_version, PARAM_VERSION);
		return -EIO;
	}

	if(argc > 1)
	{
		if (strstr(argv[1], "set") != NULL) {
			//todo
			printf("setting parameters not implemented\n");
			return -EINVAL;
		}
		if (strstr(argv[1], "get") != NULL) {
			//if we don't set we assume we want to read
			if (strstr(argv[2], "serial_speed") != NULL)
				return param_data->param_list[0].value;
			if (strstr(argv[2], "load_ramdisc") != NULL)
				return param_data->param_list[1].value;
			if (strstr(argv[2], "boot_delay") != NULL)
				return param_data->param_list[2].value;
			if (strstr(argv[2], "lcd_level") != NULL)
				return param_data->param_list[3].value;
			if (strstr(argv[2], "switch_sel") != NULL)
				return param_data->param_list[4].value;
			if (strstr(argv[2], "phone_debug_on") != NULL)
				return param_data->param_list[5].value;
			if (strstr(argv[2], "lcd_dim_level") != NULL)
				return param_data->param_list[6].value;
			if (strstr(argv[2], "lcd_dim_time") != NULL)
				return param_data->param_list[7].value;
			if (strstr(argv[2], "melody_level") != NULL)
				return param_data->param_list[8].value;
			if (strstr(argv[2], "reboot_mode") != NULL)
				return param_data->param_list[9].value;
			if (strstr(argv[2], "nation_sel") != NULL)
				return param_data->param_list[10].value;
			if (strstr(argv[2], "language_sel") != NULL)
				return param_data->param_list[11].value;
			if (strstr(argv[2], "set_default_param") != NULL)
				return param_data->param_list[12].value;
			if (strstr(argv[2], "version") != NULL)
				return -EINVAL;
			if (strstr(argv[2], "cmdline") != NULL)
				return -EINVAL;
		}
		usage();
		return -EINVAL;

	} else {
		printf("-----------------------------------------------------\n");
		printf("	Information of Parameters\n");
		printf("-----------------------------------------------------\n");
		printf("param_magic	  : 0x%x\n", param_data->param_magic);
		printf("param_version	  : 0x%x\n", param_data->param_version);
		printf("SERIAL_SPEED	  : %d\n", param_data->param_list[0].value);
		printf("LOAD_RAMDISK	  : %d\n", param_data->param_list[1].value);
		printf("BOOT_DELAY	  : %d\n", param_data->param_list[2].value);
		printf("LCD_LEVEL	  : %d\n", param_data->param_list[3].value);
		printf("SWITCH_SEL	  : %d\n", param_data->param_list[4].value);
		printf("PHONE_DEBUG_ON	  : %d\n", param_data->param_list[5].value);
		printf("LCD_DIM_LEVEL	  : %d\n", param_data->param_list[6].value);
		printf("LCD_DIM_TIME	  : %d\n", param_data->param_list[7].value);
		printf("MELODY_LEVEL	  : %d\n", param_data->param_list[8].value);
		printf("REBOOT_MODE	  : %d\n", param_data->param_list[9].value);
		printf("NATION_SEL	  : %d\n", param_data->param_list[10].value);
		printf("LANGUAGE_SEL	  : %d\n", param_data->param_list[11].value);
		printf("SET_DEFAULT_PARAM : %d\n", param_data->param_list[12].value);
		printf("VERSION(STR)	  : %s\n", param_data->param_str_list[0].value);
		printf("CMDLINE(STR)	  : %s\n", param_data->param_str_list[1].value);
		printf("-----------------------------------------------------\n");
	}

    return 0;
}
