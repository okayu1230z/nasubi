#include <stdio.h>
#include <string.h>

#define HASHSIZE 512
#define MAX_FILENAME_LEN 256

typedef enum {
    Occupied,
    Empty,
    Deleted
} Status;

struct hash_table {
    char keyword[MAX_FILENAME_LEN];
//    struct hash_table *next;
    Status status;
};

struct hash_table hash_tables[HASHSIZE];

static int hash(char *key);
static void init_hash();
static int find_hash(char *key);
static int push_hash(char *key);
static int delete_hash(char *key);
static int nothing_in_hashtable(char *str);
static struct hash_table get_hash(char *key);
static void print_hash(void);

static int hash(char *key) {
    int hashval = 0;
    while (*key != '\0'){
        hashval += *key++;
    }
    return (hashval % HASHSIZE);
}


static void init_hash() {
    for (int i = 0; i < HASHSIZE; i++) {
        hash_tables[i].status = Empty;
    }
    return;
}



static int find_hash(char *str) {
    int hashval = hash(str);
    for (int n = 0; n < HASHSIZE; n++) {
        int ix = (hashval + n) % HASHSIZE;
        if (strcmp(hash_tables[ix].keyword, "") == 0) {
            printf("LOG(find) : %s is nothing \n", str);
            return -1;
        } else if (strcmp(hash_tables[ix].keyword, str) == 0) {
            printf("LOG(find) : %s is existed, hash_value is %d , insert hash_tables[%d]\n", str, hashval, ix);
            strcpy(hash_tables[ix].keyword, str);
            return ix;
        }
    }
    printf("WARNING(find): Hash Table Full \n");
    return -2;
}


static int put_hash(char *str) {
    int hashval = hash(str);
    for (int n = 0; n < HASHSIZE; n++) {
        int ix = (hashval + n) % HASHSIZE;
        if (strcmp(hash_tables[ix].keyword, "") == 0) {
            printf("%s is new key , hash_value is %d , insert hash_tables[%d]\n", str, hashval, ix);
            strcpy(hash_tables[ix].keyword, str);
            return ix;
        } else if (strcmp(hash_tables[ix].keyword, str) == 0) {
            printf("ERROR(put): why collision %s \n", str);
            return ix;
        }
    }
    printf("WARNING(put): Hash Table Full \n");
    return -2;
}


static struct hash_table get_hash(char *str) {
      return hash_tables[1];
}

static int delete_hash(char *str) {
    int hashval = hash(str);
    for (int n = 0; n < HASHSIZE; n++) {
        int ix = (hashval + n) % HASHSIZE;
        if (strcmp(hash_tables[ix].keyword, str) == 0) {
            printf("delete key %s, hash_value is %d , delete from hash_tables[%d]\n", str, hashval, ix);
            strcpy(hash_tables[ix].keyword,"");
            return ix;
        }
    }
    printf("ERROR(delete): why key %s is nothing in Negative-cache\n", str);
}

static int nothing_in_hashtable(char *str) {
    int hashval = hash(str);
    if(strcmp(hash_tables[hashval].keyword, "") == 0) {
        return 1;
    }
    return 0;
}

static void print_detail_hash(void) {
    int i;
    printf("hash_tables: \n");
    for (i = 0; i < HASHSIZE; i++) {
        if(hash_tables[i].status == Occupied || hash_tables[i].status == Deleted )
            printf("\tindex:%03d keyword:%s Status:%d \n", i, hash_tables[i].keyword, hash_tables[i].status);
    }
}

static void print_hash(void) {
    int i;
    printf("hash_tables: \n");
    for (i = 0; i < HASHSIZE; i++) {
        if(strcmp(hash_tables[i].keyword, "") != 0)
            printf("\tindex:%03d keyword:%s \n", i, hash_tables[i].keyword);
    }
}


static char* split_path(char *str) {
    int slash_count = 0;
    char *s, *pre_s;
    char *p;
    int start = 0;
    int end;
    int length = strlen(str);
    printf("%d \n", length);

    for(int i = 0; i <= length; i++) {
        if(str[i] == '/') {
            slash_count++;
        }
    }

    printf("%d \n", slash_count);
    char a[slash_count][MAX_FILENAME_LEN];

    if(slash_count >= 1) {
        for(int i = 0; i <= slash_count; i++) {
            s = strchr(pre_s, '/');
            printf("%s \n", p);
        }
    }


}

//    char []

/*
    while(1){
        char p* = strchr(str, '/');
        printf("%s \n", p);
        str = p;
        if(p == NULL) break;
    }
*/

//    p = strchr(str, '/');
//    printf("%s \n", p);
/*
    p = strchr(p, '/');
    printf("%s \n", p);

    p = strchr(p, '/');
    printf("%s \n", p);
*/
//    while(p != NULL){
//        count_slash++;
//        printf("%d \n", count_slash);
//    }
    /*
    printf("%d \n", count_slash);
    for(int i = 0; i < count_slash; i++) {
        s = strtok(str, "/");
        printf("%s /n", str);
        printf("%s /n", s);
    }*/

    /*ptr = strtok(str, "/");
    while(ptr != NULL) {
        ptr = strtok(str, "/");
}
}*/

int main() {
    init_hash();

    put_hash("2019/05");
    put_hash("2018/06");
    put_hash("2018/07");
    put_hash("2018/07/07");

    if(nothing_in_hashtable("2018/06")) printf("2018/06 is nothing\n");
    if(nothing_in_hashtable("2019/12")) printf("2019/12 is nothing\n");

    print_detail_hash

    printf("---------------delete_hash test------------------------------------\n");

    find_hash("2018");
    find_hash("2018/05");
    find_hash("2018/06");
    find_hash("2018/07/07");

    split_path("2018/06/03/a.dat");


    printf("---------------find_hash test------------------------------------\n");

    find_hash("2018");
    find_hash("2018/05");
    find_hash("2018/06");
    find_hash("2018/07/07");

    split_path("2018/06/03/a.dat");

    printf("---------------split_path test------------------------------------\n");

    return 0;
}
