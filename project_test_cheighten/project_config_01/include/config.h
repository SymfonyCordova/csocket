
#ifndef __CONFIG_H__
#define __CONFIG_H__

//获取配置项
int getConfigItem(char *path/*in*/, char *key/*in*/, char *value/*in out*/, int *valueLen/*out*/);

//写配置项
int writeConfigItem(char *path/*in*/, char *itemName/*in*/, char *itemValue/*in*/, int itemValueLen/*in*/);

#endif
