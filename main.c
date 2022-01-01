#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "algo.h"
typedef int bool;
#define True 1
#define False 0
#define GRAPH_
struct GRAPH_NODE_ * graph_node1;







// void duplicateDataE( struct edge_ ** h) {
//     struct edge_ ** h1 = h;
//     while(*h1){
//         h1 = &((*h1)->next);
//     }
// }






void scanfEx4(){
    char a;
    char b;
    // int i;
    // int j;
    char e;
    int first = 0;
    int firstE = 0;
    int sumNodes;
    int nodeId;
    int weight;
    int endpoint;
    if(scanf("%c", &a) == EOF){return;}
    if (a == ' '){if(scanf("%c", &a) == EOF){return;}}
    while ( (a == 'A') || (a == 'T') || (a == 'S') || (a == 'D') || (a == 'B') || (a == 'n'))
    {
        if (a == 'A')
        {
            scanf("%c", &e);
            if (e == ' '){scanf("%c", &e);}
            sumNodes = e -'0';
            first = 0;
            graph_node1=(struct GRAPH_NODE_*)malloc(sizeof(struct GRAPH_NODE_));
            if(graph_node1==NULL)
            {
                printf("Insufficient Memory, Exiting... \n");
                return;
            }
            if(scanf("%c", &a) == EOF){return;}
            if (a == ' '){if(scanf("%c", &a) == EOF){return;}}
            while ((a >= '0' && a <= '9') || (a == 'n') )
            {
                struct edge_ *p = (struct edge_*) malloc (sizeof(struct edge_));
                firstE = 0;
                if(p==NULL)
                {
                    printf("Insufficient Memory, Exiting... \n");
                    return;
                }
                if (a == 'n')
                {
                    if(scanf("%c", &a) == EOF){return;}
                    if (a == ' '){if(scanf("%c", &a) == EOF){return;}}
                    nodeId = a - '0';
                    if (first == 0)
                    {
                        (graph_node1) = newNode(nodeId,NULL,&p);
                    }else{
                        insertLast(nodeId,&graph_node1,&p);
                    }
                    first += 1;
                }

                if(scanf("%c", &a) == EOF){return;}
                if (a == ' '){if(scanf("%c", &a) == EOF){return;}}
                while ((a >= '0' && a <= '9'))
                {
                    if(scanf("%c", &b) == EOF){return;}
                    if (b == ' '){if(scanf("%c", &b) == EOF){return;}}
                    weight= b - '0';
                    endpoint = a - '0';
                    if (firstE == 0)
                    {
                        (p) = newEdge(weight,NULL,&graph_node1,endpoint);
                    }else{
                        insertLastEdge(weight,&graph_node1,endpoint,&p);
                    }
                    firstE += 1;
                    if(scanf("%c", &a) == EOF){return;}
                    if (a == ' '){if(scanf("%c", &a) == EOF){return;}}
                }
                insertLastP(&graph_node1,&p);
                duplicateData(&graph_node1);
            }
            add_conect_node(&graph_node1);
        }

        if (a == 'B')
        {
            if(scanf("%c", &b) == EOF){return;}
            if (b == ' '){if(scanf("%c", &b) == EOF){return;}}
            nodeId= b - '0';
            if(scanf("%c", &a) == EOF){return;}
            if (a == ' '){if(scanf("%c", &a) == EOF){return;}}
            deleteNode(&graph_node1,nodeId);
            if (first == 0)
            {
                graph_node1=(struct GRAPH_NODE_*)malloc(sizeof(struct GRAPH_NODE_));
                (graph_node1) = newNode(nodeId,NULL,NULL);
            }else{
                insertLast(nodeId,&graph_node1,NULL);
            }
            first += 1;
            struct edge_ *p = (struct edge_*) malloc (sizeof(struct edge_));
            firstE = 0;
            if(p==NULL){printf("Insufficient Memory, Exiting... \n");return; }
             while ((a >= '0' && a <= '9'))
            {
                if(scanf("%c", &b) == EOF){return;}
                if (b == ' '){if(scanf("%c", &b) == EOF){return;}}
                weight= b - '0';
                endpoint= a - '0';
                if (firstE == 0)
                {
                    p = newEdge(weight,NULL,&graph_node1,endpoint);
                }else{
                    insertLastEdge(weight,&graph_node1,endpoint,&p);
                }
                firstE += 1;
                if(scanf("%c", &a) == EOF){return;}
                if (a == ' '){if(scanf("%c", &a) == EOF){return;}}
                 insertLastP(&graph_node1,&p);
            }
            add_conect_node(&graph_node1);
        }
        if (a == 'D')
        {
            cmd_delete_node(&graph_node1);
            if(scanf("%c", &a) == EOF){return;}
            if (a == ' '){if(scanf("%c", &a) == EOF){return;}}
        }
        if (a == 'S')
        {
            cmd_shortest_path(&graph_node1,sumNodes);
            if(scanf("%c", &a) == EOF){return;}
            if (a == ' '){if(scanf("%c", &a) == EOF){return;}}
        }
        if (a == 'T')
        {
            cmd_TSP(&graph_node1,sumNodes);
            if(scanf("%c", &a) == EOF){return;}
            if (a == ' '){if(scanf("%c", &a) == EOF){return;}}
        } 
    }
} 

int main()
{
    scanfEx4();
    deleteAll(&graph_node1);
    printGraphNode(&graph_node1);
}