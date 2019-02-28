//
// Created by a76 on 2/28/19.
//

#ifndef HASHCODE_GRAPH_BUILDER_H
#define HASHCODE_GRAPH_BUILDER_H

#include "photo.h"

int interestingness(int tags1_len, char** tags1, int tags2_len, char** tags2);

int** build_graph(size_t photos_len, t_photo * photos);

#endif //HASHCODE_GRAPH_BUILDER_H
