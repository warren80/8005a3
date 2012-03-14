#include "mapHash.h"
#include <pthread.h>

PMAP hashMap = NULL;

void mapAdd(PMAP pmap);
PMAP mapFind(int port);
void mapDelete(PMAP pmap);
void mapDeleteAll();
void mapPrint();
int mapSort(PMAP a, PMAP b);
void mapSortById();

void mapAdd(PMAP map) {
    HASH_ADD_INT(hashMap, port, map);
}

PMAP mapFind(int ip) {
    PMAP map;

    HASH_FIND_INT(hashMap, &port, map);  /* s: output pointer */
    return map;
}

void mapDelete(PMAP map) {
    HASH_DEL(hashMap, map);  /* user: pointer to deletee */
    free(map);
}

void mapDeleteAll() {
  PMAP current_map, tmp;

  HASH_ITER(hh, hashMap, current_map, tmp) {
    HASH_DEL(hashMap, current_map);  /* delete it (metrics advances to next) */
    free(current_map);            /* free it */
  }
}

void mapPrint() {
    PMAP s;
    int i = 0;
    for(s=mapHash; s != NULL; s=s->hh.next) {
        //print ipetId, addr in and addr out maybe more.
        //printf("user id %d: name %s\n", s->id, s->name);
        printf("map num: %d\n",i++);
    }
}

int mapSort(PMAP a, PMAP b) {
    return (a->ip - b->ip);
}

void mapSortById() {
    HASH_SORT(mapHash, mapSort);
}


