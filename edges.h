#include "graph.h"

// Creates a new node
node* newNode(int data, node *next, pedge edges) ;

// Creates a new Edge
edge* newEdge(int weight, edge *next, struct GRAPH_NODE_ **head1,int nodeId,pnode point);

// insert in Last the head Edge
void insertLastP(struct GRAPH_NODE_ **head,struct edge_ **head_edge) ;

// insert in Last the new Edge
void insertLastEdge(int weight, struct GRAPH_NODE_ **headNode,int nodeId, struct edge_ **head) ;

// remove Edge
void removeEdge(pedge head_edge) ;

// get Edge
pedge getEdge(int id, struct GRAPH_NODE_ **head);

// get weight between src and dest
int getWeight(struct GRAPH_NODE_ **head1,int src,int dest);