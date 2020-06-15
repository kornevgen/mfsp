#ifndef __MAP_H__
#define __MAP_H__

#include "maptypes.h"

Map *createMap(int size);

void deleteMap(Map *map);

int addElement(Map *map, Key *key, Value *value);

int removeElement(Map *map, Key *key, Value *value);

int getElement(Map *map, Key *key, Value *value);

#endif // __MAP_H__
