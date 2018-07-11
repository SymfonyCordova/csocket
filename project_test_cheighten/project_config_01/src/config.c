#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "config.h"

#define MAX_LINE 2048

//获取配置项
int getConfigItem(char *path/*in*/, char *key/*in*/, char *value/*in out*/, int *valueLen/*out*/){	
	int 	ret = 0;
	FILE 	*fp = NULL;
	char 	lineBuf[MAX_LINE];
	char 	*pTem = NULL;
	char 	*pBegin = NULL;
	char 	*pEnd = NULL;

	fp = fopen(path, "r");
	if(fp == NULL){
		ret = -1;
		return ret;
	}

	while(!feof(fp)){
		memset(lineBuf, 0, sizeof(lineBuf));

		fgets(lineBuf, MAX_LINE, fp);

		pTem = strchr(lineBuf, '=');
		if(pTem == NULL){ //如果没有=号
			continue;	
		}

		pTem = strstr(lineBuf, key);
		if(pTem == NULL){ //所在行是不是有key
			continue;
		}
		
		pTem = pTem + strlen(key); //mykey1 = myvaluede1111 ==> "= myvalue111111"
		
		pTem = strchr(pTem, '=');
		if(pTem == NULL){
			continue;
		}
	
		pTem = pTem + 1;
	
		//=过后就要取出前后空格和\n
		//获取value起点
		while(1){
			if(*pTem == ' '){
				pTem++;
			}else{
				pBegin = pTem;
				if(*pBegin == '\n'){
					//没有配置value
					printf("配置项:%s 没有配置value \n", key);
					goto End;
				}
				break;
			}
		}

		//获取value结束点
		while(1){
			if((*pTem == ' ' || *pTem == '\n')){
				break;
			}else{
				pTem++;
			}
		}
		pEnd = pTem;
		
		//赋值
		*valueLen = pEnd - pBegin;
		memcpy(value, pBegin, pEnd - pBegin);
		break;
	}

End:
	if(fp != NULL){
		fclose(fp);
	}

	return ret;
}

//写配置项
int writeConfigItem(char *path/*in*/, char *itemName/*in*/, char *itemValue/*in*/, int itemValueLen/*in*/){
	
	return 0;
}

