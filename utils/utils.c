#include "utils.h"

char* util_substr(char* src, int start, int end) {
    int size = end - start;
    char* substr = (char*)malloc(sizeof(char) * size + 1);
    for (int i = 0; i < size; i++) {
        substr[i] = src[i + start];
    }
    substr[size] = '\0';
    return substr;
}