#ifndef __MAP_H__
#define __MAP_H__

typedef struct {
    int a;
    int b;
} Key;

typedef struct {
    int c;
    int d;
} Value;

typedef struct {
    Key key __attribute__((noembed));
    Value value;
    int existent;
} Item;

typedef struct {
    Item *items;
    int capacity;
    int count;
} Map;

Map *createMap(int size);

void deleteMap(Map *map);

int addElement(Map *map, Key *key, Value *value);

int removeElement(Map *map, Key *key, Value *value);

int getElement(Map *map, Key *key, Value *value);

#endif // __MAP_H__
