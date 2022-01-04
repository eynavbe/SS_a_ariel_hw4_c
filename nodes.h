#include "edges.h"

// insert in Last the new node
void insertLast(int data, struct GRAPH_NODE_ **head,struct edge_ **head_edge) ;

// remove node
void deleteNode( struct GRAPH_NODE_ ** h,int id) ;

// remove node and everything connected to it
void deleteNodeAll( struct GRAPH_NODE_ ** h,int id);