#include <stdio.h>
#include <string.h>

#define HASHSIZE 512
#define MAX_FILENAME_LEN 256

typedef enum {
    Occupied,   // 0
    Empty,    // 1
    Deleted   // 2
} Status;

struct hash_table {
    char keyword[MAX_FILENAME_LEN];
//    struct hash_table *next;
    Status status;
};

struct hash_table hash_tables[HASHSIZE];

static int hash(char *key);
static void init_hash(void);
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
        if (strcmp(hash_tables[ix].keyword, "") == 0 && hash_tables[ix].status == Empty) {
            printf("LOG(find) : %s is nothing \n", str);
            return -1;
        } else if (strcmp(hash_tables[ix].keyword, str) == 0 && hash_tables[ix].status == Occupied) {
            printf("LOG(find) : %s is existed, hash_value is %d , inserted hash_tables[%d]\n", str, hashval, ix);
            strcpy(hash_tables[ix].keyword, str);
            return ix;
        }
    }
    printf("WARNING(find): Hash Table Full Searched\n");
    return -2;
}


static int put_hash(char *str) {
    int hashval = hash(str);
    for (int n = 0; n < HASHSIZE; n++) {
        int ix = (hashval + n) % HASHSIZE;
        if (strcmp(hash_tables[ix].keyword, "") == 0) {
            printf("LOG(put) : %s is new key , hash_value is %d , insert hash_tables[%d]\n", str, hashval, ix);
            strcpy(hash_tables[ix].keyword, str);
            hash_tables[ix].status = Occupied;
            return ix;
        } else if (strcmp(hash_tables[ix].keyword, str) == 0) {
            printf("WARNING(put): why collision %s \n", str);
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
        if (strcmp(hash_tables[ix].keyword, str) == 0 && hash_tables[ix].status != Empty) {
            printf("delete key %s, hash_value is %d , delete from hash_tables[%d]\n", str, hashval, ix);
            strcpy(hash_tables[ix].keyword, "");
            hash_tables[ix].status = Deleted;
            return ix;
        }
    }
    printf("ERROR(delete): why key %s is nothing in Negative-cache\n", str);
}

static int nothing_in_hashtable(char *str) {
    int hashval = hash(str);
    for (int n = 0; n < HASHSIZE; n++) {
        int ix = (hashval + n) % HASHSIZE;
        if(hash_tables[ix].status == Empty) return 1;
        if(strcmp(hash_tables[ix].keyword, str) == 0) return 0;
    }
    return 0;
}

static void print_detail_hash(void) {
    int i;
    printf("hash_tables: \n");
    for (i = 0; i < HASHSIZE; i++) {
        if(hash_tables[i].status == Occupied || hash_tables[i].status == Deleted)
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

int mysubstr( char *t, const char *s, int pos, int len )
{
    if( pos < 0 || len < 0 || len > strlen(s) )
        return -1;
    for( s += pos; *s != '\0' && len > 0; len-- )
        *t++ = *s++;
    *t = '\0';
    return 0;
}

static char* split_path(int length, char s[length][MAX_FILENAME_LEN], char *str) {
    char *str = "/a/b/cde";
    int slash_count = 0;

    for(int i = 0; i <= strlen(str); i++) {
        if(str[i] == '/') {
            slash_count++;
        }
    }

    char s_temp[MAX_FILENAME_LEN];

    strcpy(s_temp, str);

    for(int i = 0; i < length; i++) {
          strncpy(s_temp, s_temp + 1 ,strlen(s_temp));
          printf("%s \n", s_temp);
          char *t_temp = strchr(s_temp, '/');
          strcpy(s_temp, t_temp);
          printf("%s \n", s_temp);
      }

    return *s;
}


int main() {
    init_hash();

    put_hash("/2019/05");
    put_hash("/2018/06");
    put_hash("/2018/07");
    put_hash("/2018/07/07");

    printf("---------------split_path test------------------------------------\n");

    char *str = "/2018/07/07";

    int length = strlen(str);
    int slash_count = 0;

    for(int i = 0; i <= length; i++) {
        if(str[i] == '/') {
            slash_count++;
        }
    }

    printf("%d \n", slash_count);

    char s[slash_count][MAX_FILENAME_LEN];

    split_path( slash_count, s, str);

    return 0;
}
