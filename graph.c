#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef int bool;
#define True 1
#define False 0

void cmd_delete_node(struct GRAPH_NODE_ **head1){
    int nodeId;
    char b;
    if(scanf("%c", &b) == EOF){return;}
    if (b == ' '){if(scanf("%c", &b) == EOF){return;}}
    nodeId= b - '0';
    deleteNodeAll(head1,nodeId);
}

void cmd_shortest_path(struct GRAPH_NODE_ **head1,int size){
    char b;
    char c;
    if(scanf("%c", &b) == EOF){return;}
    if (b == ' '){if(scanf("%c", &b) == EOF){return;}}
    if(scanf("%c", &c) == EOF){return;}
    if (c == ' '){if(scanf("%c", &c) == EOF){return;}}
    int dis = shortest_path(head1,b,c,size);
    printf("Dijsktra shortest path: %d \n",dis);
}

void cmd_TSP(struct GRAPH_NODE_ **head1,int size){
    char k;
    if(scanf("%c", &k) == EOF){return;}
    if (k == ' '){if(scanf("%c", &k) == EOF){return;}}
    int sizeTsp = k -'0';
    int path[sizeTsp];
    int *path2 = path;
    char r;
    for(int h=0;h<sizeTsp;h++){
        if(scanf("%c", &r) == EOF){return;}
        if (r == ' '){if(scanf("%c", &r) == EOF){return;}}
        path2[h] = r-'0';
    }
    int minTSPr = TSP(head1,path,sizeTsp,size);
    printf("TSP shortest path: %d \n",minTSPr);
}

void duplicateData( struct GRAPH_NODE_ ** h) {
    struct GRAPH_NODE_ ** h1 = h;
    pedge head = ((*h1)->edges);
    while(head){
        head = ((head)->next);
    }
}

void add_conect_node(struct GRAPH_NODE_ **head111) {
    struct GRAPH_NODE_ **head_node = head111;
    struct GRAPH_NODE_ ** h1 = head111;
    while (*h1)
    {
        if ((*h1)->edges != NULL)
        {
            pedge head_edge = ((*h1)->edges);
            if (head_edge != NULL)
            {
                if ((head_edge)->endpoint != NULL)
                {
                    while(head_edge){
                        while(*head_node){
                            if( (head_edge)->endpoint-> node_num == (*head_node)->node_num) {
                                (head_edge)->endpoint = (*head_node);
                            } 
                            head_node = &((*head_node)->next);
                        }
                        head_node = head111;
                        head_edge = ((head_edge)->next);
                    }
                }
            }
        }
        h1 = &((*h1)->next);
    }
}

void printGraphNode( struct GRAPH_NODE_ ** h) {
    struct GRAPH_NODE_ ** h1 = h;
    while (*h1)
    {
        printf("%d",(*h1)->node_num);
        pedge head = ((*h1)->edges);
        if (head->endpoint != NULL)
        {
            while(head){
                printf("%d",(head)->endpoint->node_num);
                printf("%d",(head)->weight);
                head = ((head)->next);
            }
        }
        printf("\n");
        h1 = &((*h1)->next);
    }
}

void deleteAll( struct GRAPH_NODE_ ** h) {
    struct GRAPH_NODE_ ** h2 = h;
    if(! *h2 ){
        return;
    }
    // struct GRAPH_NODE_ *p = *h2;
    // struct GRAPH_NODE_ **prev = h2;
    while (*h2)
    {
        pedge head_edge = (*h2)->edges;
        if ((head_edge)->endpoint != NULL)
        {
            edge *p = head_edge;
            edge **prev = &head_edge;
            while(p) {
                *prev = p->next;
                free(p);
                p = *prev;
                (*h2)->edges=p;
            }
        }
        h2 = &((*h2)->next);
    }
    struct GRAPH_NODE_ ** h11 = h;
    if(! *h11 ){
        return;
    }
    struct GRAPH_NODE_ *p1 = *h11;
    struct GRAPH_NODE_ **prev1 = h11;
    while(p1) {
        *prev1 = p1->next;
        free(p1);
        p1 = *prev1;
    }
}
