#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

#define CONFIG_NAME "config.ini"

void myMenu(){
	printf("========================================\n");
	printf("1 测试写配置文件\n");
	printf("2 测试读配置文件\n");
	printf("0 其他退出\n");
	printf("========================================\n");	
}

//获取配置项
int testGetConfig(){	
	int 	ret = 0;
	char 	key[1024] = {0};
	char    value[1024] = {0};
	int 	valueLen = 0;


	printf("\n请键入key:");
	scanf("%s", key);
	
	ret = getConfigItem(CONFIG_NAME, key, value, &valueLen);
	if(ret != 0){
		printf("getConfigItem error\n");
	}

	printf("value:%s \n", value);

	return 0;
}

//写配置项
int testWriteConfig(){
	int ret = 0;
	char key[1024] = {0};
	char value[1024] = {0};

	printf("\n请键入key:");
	scanf("%s", key);
	
	printf("\n请键入value:");
	scanf("%s", value);
	 
	ret = writeConfigItem(CONFIG_NAME, key, value, strlen(value));
	if(ret != 0){
		printf("writeConfigItem error\n");
	}

	printf("你的输入时: %s = %s \n", key, value);
	return 0;
}

int main(int argc, char *argv[]){
	int choice;


	for(;;){
		//显示一个菜单
		myMenu();
		scanf("%d", &choice);
		switch(choice){
			case 1:	//写配置项
				testWriteConfig();
				break;
			case 2:	//读配置项
				testGetConfig();
				break;
			case 0:
				exit(0);
			default:
				exit(0);
		}			
	}	


	printf("hello...\n");
	return 0;
}
