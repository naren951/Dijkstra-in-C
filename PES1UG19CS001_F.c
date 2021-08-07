#include"PES1UG19CS001_H.h"
void heapsort(struct heap *h,int a,int n){
    int  if_swap;
    do{
        if_swap = 0;
        for(int i = a; i < n-1; i++){
            if(h[i].dist > h[i + 1].dist){
                struct heap temp;
                temp = h[i];
                h[i] = h[i+1];
                h[i+1] = temp;
                if_swap = 1;
            }
        }

}while(if_swap);
}
void sort_v(struct heap *h,int a,int n){
    int  if_swap;
    do{
        if_swap = 0;
        for(int i = a; i < n-1; i++){
            if(h[i].vid > h[i + 1].vid){
                struct heap temp;
                temp = h[i];
                h[i] = h[i+1];
                h[i+1] = temp;
                if_swap = 1;
            }
        }
}while(if_swap);
}
void calculate(struct heap *cal,struct node **graph,int n,int a){
    for(int i=1;i<n-1;i++){
    struct node *curr=graph[cal[a].vid];
    while(curr!=NULL){
        if(curr->data==cal[i+1].vid)
        {
            if(cal[i+1].dist > (curr->weight+cal[a].dist)){
                cal[i+1].dist=(curr->weight+cal[a].dist);
                cal[i+1].prev=cal[a].vid;
            }
        }
        curr=curr->next;
    }
}
}
void create_graph(char *str,FILE *list,struct node **graph){
    while (fgets(str, MAXCHAR, list)!=NULL)
    {
      int data,weight,n;
      char *token = strtok(str, " ");
      data=atoi(token);
      struct node *curr;
      while(1) {
        token = strtok(NULL, " ");
        if(token==NULL)
            break;
        n=atoi(token);
        token = strtok(NULL, " ");
        weight=atoi(token);
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->weight=weight;
        newnode->next=NULL;
        curr=graph[n];
        if(graph[n]!=NULL){
            while(curr->next!=NULL){
                curr=curr->next;
            }
            curr->next=newnode;
        }
        else{
            graph[n]=newnode;
        }
   }
}
}