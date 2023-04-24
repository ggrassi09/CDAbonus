//Name: Gabriel Grassi
//Neslisah Torosdagli
//Computer Logic & Design
//Bonus Assignment

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE 32
#define BLOCK 4
;
typedef struct cache {
    int size;
    int assoc;
    int num_sets;
    int block;
    int rp;     //1 for random case
    int hit;    // Number of hits
    int miss;   // Number of misses
    int** tag;
    int** valid;
    char** data;
    int* lru;   // array used for replacement policy
} Cache;

//hexadecimal to ints
int hex_to_int(char* hex) {
    return (int)strtol(hex, NULL, 16);
}

//initialize the cache
void init_cache(Cache* cache, int assoc, int rp) {
    int i, j;
    cache->assoc = assoc;
    cache->num_sets = cache->size / (assoc * cache->block);
    cache->rp = rp;
    cache->hit = 0;
    cache->miss = 0;
    cache->tag = (int**)malloc(cache->num_sets * sizeof(int*));
    cache->valid = (int**)malloc(cache->num_sets * sizeof(int*));
    cache->data = (char**)malloc(cache->num_sets * sizeof(char*));
    if (rp == 0) {
        cache->lru = (int*)malloc(cache->num_sets * sizeof(int));
        memset(cache->lru, 0, cache->num_sets * sizeof(int));
    }
    for (i = 0; i < cache->num_sets; i++) {
        cache->tag[i] = (int*)malloc(assoc * sizeof(int));
        cache->valid[i] = (int*)malloc(assoc * sizeof(int));
        cache->data[i] = (char*)malloc(cache->block * assoc * sizeof(char));
        for (j = 0; j < assoc; j++) {
            cache->tag[i][j] = -1;
            cache->valid[i][j] = 0;
            memset(&cache->data[i][j * cache->block], 0, cache->block * sizeof(char));
        }
    }
}

//access the cache
void Cacheaccess(Cache* cache, int addr) {
    
}

int main() {
    Cache cache; //create case structure
    char hex[9]; //holder variable for the hex value being read
    int addr;
    int i;
    // Initialize cache
    cache.size = CACHE;
    cache.block = 32;
    init_cache(&cache, 1, 0); //calling function to initialize the the cache
    
    for (i = 0; i < 16; i++) {
        // Read hexadecimal from text file
        scanf("%s", hex);
        // Convert hexadecimal 
        addr = hex_to_int(hex);
        // When completed this funcion should return informations about the cache
        Cacheaccess(&cache, addr);
    }

    
    printf(" Number of Hits: %d\n", cache.hit);
    printf("Number of Misses: %d\n", cache.miss);
    //The values we are interested in observing ^^

    return 0;
}