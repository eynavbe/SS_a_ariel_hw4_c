typedef struct GRAPH_NODE_ *pnode;
typedef int bool;
#define True 1
#define False 0

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct GRAPH_NODE_DISTANCE {
    int node_num;
    int distance;
    struct GRAPH_NODE_DISTANCE *next;
} node_dis, *pnode_dis;

// Get parameters from cmd to delete node
bool cmd_delete_node(struct GRAPH_NODE_ **head1);

// Get parameters from cmd to get the shortest path between src and dest
bool cmd_shortest_path(struct GRAPH_NODE_ **head1,int size);

// Get parameters from cmd to get the length route is the shortest (with the least weight).
// Which passes through all the points
bool cmd_TSP(struct GRAPH_NODE_ **head1,int size);

void duplicateData( struct GRAPH_NODE_ ** h) ;

// conect all nodes and sides according to data structures
void add_conect_node(struct GRAPH_NODE_ **head111);

// prints the graph
void printGraphNode( struct GRAPH_NODE_ ** h) ;

// Deletes the all graph
void deleteAll( struct GRAPH_NODE_ ** h) ;

//remove node
void removeNode(pnode head_edge) ;