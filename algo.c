#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
static int min = 1111111111;
typedef int bool;
#define True 1
#define False 0
node_dis* newNodeDis(int data, int dis) {
    node_dis *p = (node_dis*) malloc (sizeof(node_dis));
    p->node_num = data;
    p->distance = dis;
    p->next = NULL;
    return p;
}
void insertLastDis2(int edge,int node_m, struct GRAPH_NODE_DISTANCE **head) {
    struct GRAPH_NODE_DISTANCE **p = head;
    while(*p){
        p = &((*p)->next);
    }
    *p = newNodeDis(edge,node_m);
}


void changeDis(int src, struct GRAPH_NODE_DISTANCE **head, int data){
    struct GRAPH_NODE_DISTANCE **p1 = head;
    while(*p1){
        if ((*p1)->node_num == src)
        {
            (*p1)->distance = data;
        } 
        p1 = &((*p1)->next);
    }
}
int disId(int id, struct GRAPH_NODE_DISTANCE **head){
    struct GRAPH_NODE_DISTANCE **p1 = head;
    if (id >=48){id = id -'0';}
    p1 = &((*p1)->next);
    while(*p1){
        if ((*p1)->node_num == id)
        {
            return (*p1)->distance;
        } 
        p1 = &((*p1)->next);
    }
    return -1;
}

void removeChar(char *str, char charto) {
    char*strpoi = str; 
    int i, j=0;
    char array[strlen(strpoi)];		
    memset(array, 0, strlen(strpoi));
	
	for(i = 0; strpoi[i] != '\0'; i++)	
	{	
	if(strpoi[i] != charto)		
        {
           if (j < strlen(strpoi))
           {
                if (strpoi[i] <='9' && strpoi[i] >= '0'){
                    array[j] = strpoi[i];
                    j++;	
                } 
           }
        }
	}
    array[j] = '\0';
    j++;
    array[j] = '\0';
    strcpy(strpoi, array);
}

int shortest_path(struct GRAPH_NODE_ **head1, int src, int dest,int size){
    struct GRAPH_NODE_DISTANCE* distance_path=(struct GRAPH_NODE_DISTANCE*)malloc(sizeof(struct GRAPH_NODE_DISTANCE));
    memset(distance_path, 0, sizeof(struct GRAPH_NODE_DISTANCE));
    struct GRAPH_NODE_ **p = head1;
    char* headCopy=(char*)malloc((size+1)*sizeof(char));
    memset(headCopy, 0, (size+1)*sizeof(char));
    char*index = headCopy;  
    headCopy = index; 
    int i = 0;
    struct GRAPH_NODE_ **p5 = head1;
    while (*p5)
    {
        int h = ((*p5)->node_num);
        char f= (h +'0');
        index[i] = f;
        i+=1;
        p5 = &((*p5)->next);
    }
    index[i] = '\0';
    while (*p)
    {
        insertLastDis2((*p)->node_num,1111111111,&distance_path);
        p = &((*p)->next);
    }
    changeDis(src,&distance_path,0);
    while (headCopy[1] != '\0')
    { 
        index = headCopy; 
        int node;
        int y = 0;
        int node_m = 1111111111;
        while (index[y] != 0)
        {               
            node =  index[y] - '0';
            if (node_m == 1111111111)
            {
                node_m = node;
            }else{
                if (disId(node,&distance_path) < disId(node_m,&distance_path))
                {
                    node_m = node;
                }
            }
            y++;
        }
        pedge out_edges = getEdge(node_m,head1);
        edge *p4 = out_edges;
        while(p4) {
            int edge = p4->endpoint->node_num;
            int distance = disId(node_m,&distance_path)+p4->weight;
            if (distance<disId(edge,&distance_path))
            {
                changeDis(edge,&distance_path,distance);
            }
            p4 = p4->next;
        }  
        removeChar(headCopy, node_m+'0');    
    }
    int shortPath = disId(dest,&distance_path);
    free(distance_path);
    free(headCopy);
    if (shortPath == 1111111111)
    {
        return getWeight(head1,src,dest);
    }
    return shortPath;
}
void deleteDISTANCE( struct GRAPH_NODE_DISTANCE ** h,int id) {
    struct GRAPH_NODE_DISTANCE ** h1 = h;
    if(! *h1 ){
        return;
    }
    struct GRAPH_NODE_DISTANCE *p = *h1;
    struct GRAPH_NODE_DISTANCE **prev = h1;
    while(p) {
        if(p->node_num == id) {
            *prev = p->next;
            free(p);
            p = *prev;
        } else {
            prev = &(p->next);
            p = p->next;
        }
    }
}

int sizePathTsp(struct GRAPH_NODE_DISTANCE **path){
    int size = 0;
    struct GRAPH_NODE_DISTANCE **p1 = path;
    while(*p1){
        size++;
        p1 = &((*p1)->next);
    }
    return size;
}

void tsp_shortest_route_i(struct GRAPH_NODE_ **head1,int* node_lst,struct GRAPH_NODE_DISTANCE **path, int size,int sizeH){
    int sum_w = 0;
    if (sizePathTsp(path) == size){
        struct GRAPH_NODE_DISTANCE **p1 = path;
        while(*p1){
            sum_w +=(*p1)->distance; 
            p1 = &((*p1)->next);
        }
        if (sum_w < min){
            min = sum_w;
        }
        return;
    }
    int* node_lst_p = node_lst;
    for (int i=0; i<size;i++){
        int w = node_lst_p[i];
        bool visited = False;
        struct GRAPH_NODE_DISTANCE **p1 = path;
        int src;
        while(*p1){
            if ((*p1)->node_num == w)
            {
                visited = True;
            } 
            src = (*p1)->node_num;
            p1 = &((*p1)->next);
        }
        if (visited == False)
        {
            int distance_path = shortest_path(head1,src, w,sizeH);
            if (distance_path > -1){
                insertLastDis2(w,distance_path,path);
                tsp_shortest_route_i(head1,node_lst, path,size,sizeH);
                deleteDISTANCE(path,src);
            }
        }
    }
}

int TSP(struct GRAPH_NODE_ **head1, int* node_lst,int size,int sizeH){
    
    min = 1111111;
    int* node_lst_p = node_lst;
    for (int i=0; i<size;i++){
        struct GRAPH_NODE_DISTANCE*  path=(struct GRAPH_NODE_DISTANCE*)malloc(size*sizeof(struct GRAPH_NODE_DISTANCE));
        memset(path, 0, size*sizeof(struct GRAPH_NODE_DISTANCE));

        struct GRAPH_NODE_DISTANCE** pathP = &path;
        while ((*pathP)){pathP = &((*pathP)->next);}
        path = *pathP;
        insertLastDis2(node_lst_p[i],0,&path);
        tsp_shortest_route_i(head1,node_lst, &path,size,sizeH);
        free(path);
    }
    if ((min == 1111111) || (min == 0))
    {
        return -1;
    }
    return min;
}