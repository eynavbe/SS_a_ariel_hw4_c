#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
// #include "algo.h"

typedef int bool;
#define True 1
#define False 0

// node* newNode(int data, node *next, struct edge_ ** edges) {
//     node *p = (node*) malloc (sizeof(node));
//     p->node_num = data;
//     p->edges = NULL;
//     p->next = next;
//     return p;
// }
void insertLast(int data, struct GRAPH_NODE_ **head,struct edge_ **head_edge) {
    struct GRAPH_NODE_ **p = head;
    while(*p){
        p = &((*p)->next);
    }
    *p = newNode(data,NULL,head_edge);
}

void deleteNode( struct GRAPH_NODE_ ** h,int id) {
    struct GRAPH_NODE_ ** h1 = h;
    if(! *h1 ){
        return;
    }
    struct GRAPH_NODE_ *p = *h1;
    struct GRAPH_NODE_ **prev = h1;
    while(p) {
        if(p->node_num == id) {
            *prev = p->next;
            pedge head = (p->edges);
            if ((head)->endpoint != NULL)
            {
                removeEdge(head);
            }
            free(p);
            p = *prev;
        } else {
            prev = &(p->next);
            p = p->next;
        }
    }
}

void deleteNodeAll( struct GRAPH_NODE_ ** h,int id) {
    struct GRAPH_NODE_ ** h2 = h;
    if(! *h2 ){
        return;
    }
    // struct GRAPH_NODE_ *p = *h2;
    // struct GRAPH_NODE_ **prev = h2;
    while (*h2)
    {
        pedge head_edge = (*h2)->edges;
        bool first = True;
        if ((head_edge)->endpoint != NULL)
        {
            edge *p = head_edge;
            edge **prev = &head_edge;
            while(p) {
                if(p->endpoint->node_num == id) {
                    *prev = p->next;
                    free(p);
                    p = *prev;
                    if (first)
                    {
                        (*h2)->edges=p;
                    }
                } else {
                    first = False;
                    prev = &(p->next);
                    p = p->next;
                }
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
        if(p1->node_num == id) {
            *prev1 = p1->next;
            free(p1);
            p1 = *prev1;
        } else {
            prev1 = &(p1->next);
            p1 = p1->next;
        }
    }
}