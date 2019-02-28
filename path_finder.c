//
// Created by a76 on 2/28/19.
//

#include <malloc.h>
#include <stdbool.h>
#include "path_finder.h"

typedef struct s_coord
{
    size_t x;
    size_t y;
} t_coord;

int* init_path(size_t len);
t_coord find_max_edge(size_t len, int** graph);
bool noway(size_t len, bool* cycle_points);
int* transform_path(size_t len, int* path);

int* find_path(size_t len, int **graph)
{
    int* path = init_path(len);
    t_coord start = find_max_edge(len, graph);

    path[start.x] = 0;
    path[start.y] = 1;

    int progress = 2;
    size_t current = start.y;

    bool* cycle_points = (bool*)malloc(sizeof(bool) * len);
    for (size_t i = 0; i < len; i++)
    {
        cycle_points[i] = false;
    }

    while(true)
    {
        int max = -1;
        int max_i = -1;

        for(size_t i = 1; i < len; i++)
        {
            if(!cycle_points[i] && graph[current][i] > max)
            {
                max_i = i;
            }
        }

        if(max_i == -1)
        {
            break;
        }

        if (path[max_i] == -1)
        {
            current = max_i;
            path[current] = progress++;
            for (size_t i = 0; i < len; i++)
            {
                cycle_points[i] = false;
            }
        } else {
            cycle_points[max_i] = true;
//            if (noway(len, cycle_points)) {
//                break;
//            }
        }
    }

    return transform_path(len, path);
}

t_coord find_max_edge(size_t len, int** graph)
{
    int max = -1;
    t_coord max_i;

    for (size_t i = 0; i < len; i++)
    {
        for(size_t j = 0; j < len; j++)
        {
            if(graph[i][j] > max)
            {
                max = graph[i][j];
                max_i.x = i;
                max_i.y = j;
            }
        }
    }

    return max_i;
}

int* init_path(size_t len)
{
    int* path = (int*)malloc(sizeof(int) * len);
    for(size_t i = 0; i < len; i++)
    {
        path[i] = -1;
    }
    return path;
}

bool noway(size_t len, bool* cycle_points)
{
    for(size_t i = 0; i < len; i++)
    {
        if(!cycle_points[i])
        {
            return false;
        }
    }

    return true;
}

int* transform_path(size_t len, int* path)
{
    int* res = (int*)malloc(sizeof(int)*len);
    for(int i = 0; i < len; i++)
    {
       res[i] = -1;
    }
    for(int i = 0; i < len; i++)
    {
        if(path[i] != -1)
        {
            res[path[i]] = i;
        }
    }
    return res;
}
