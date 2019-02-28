//
// Created by a76 on 2/28/19.
//

#include <glob.h>
#include <malloc.h>
#include "graph_builder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myCompare (const void * a, const void * b ) {
    const char *pa = *(const char**)a;
    const char *pb = *(const char**)b;

    return strcmp(pa,pb);
}

int** build_graph(size_t photos_len, t_photo * photos)
{
    int** matrix = (int**) malloc(sizeof(int*) * photos_len);
    for(size_t i = 0; i < photos_len; i++)
    {
        matrix[i] = (int*) malloc(sizeof(int) * photos_len);
        for (size_t j = 0; j < photos_len; j++)
        {
            matrix[i][j] = interestingness(photos[i].tags_len, photos[i].tags, photos[j].tags_len, photos[j].tags);
        }
    }

    return matrix;
}

int interestingness(int tags1_len, char** tags1, int tags2_len, char** tags2)
{
    qsort(tags1, tags1_len, sizeof(char*), myCompare);
    qsort(tags2, tags2_len, sizeof(char*), myCompare);

    int in_1_not_2 = 0;
    int in_2_not_1 = 0;
    int common = 0;

    int i = 0;
    int j = 0;
    while(i < tags1_len && j < tags2_len)
    {
        int diff = strcmp(tags1[i], tags2[j]);
        if (diff == 0)
        {
            common++;
            i++;
            j++;
        }
        else if (diff < 0)
        {
            in_1_not_2++;
            i++;
        }
        else
        {
            in_2_not_1++;
            j++;
        }
    }
    in_2_not_1 += tags2_len - j;

    return common < in_1_not_2 ? common : in_1_not_2 < in_2_not_1 ? in_1_not_2 : in_2_not_1;
}
