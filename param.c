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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <param.h>


#define PARAM_FILE	"/mnt/.lfs/param.blk"

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

    return 0;
}
