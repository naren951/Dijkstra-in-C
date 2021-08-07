#include"PES1UG19CS001_H.h"
int main(){
    FILE *list = (FILE *)fopen("list.txt","r");
    char str[MAXCHAR];
    fgets(str, MAXCHAR, list);
    int n=atoi(str)+1;
    struct node *graph[n]; 
    for(int i=0;i<n;i++){
        graph[i]=NULL;
    }
    create_graph(str,list,graph);
struct heap cal[n];
for(int i=1;i<n;i++){
    cal[i].vid=i;
    cal[i].dist=INT_MAX;
    cal[i].prev=-1;
}
//dijkstra
cal[n-1].dist=0;
heapsort(cal,1,n);
for(int a=1;a<n-1;a++){
calculate(cal,graph,n,a);
heapsort(cal,a,n);
}

struct list *path[n];
for(int i=1;i<n;i++){
        path[i]=NULL;
    }
sort_v(cal,1,n);
//creating path
for(int i=1;i<n;i++){
    int m=i;
    while(cal[m].prev!=-1){
        struct list *newnode=(struct list*)malloc(sizeof(struct list));
        newnode->data=cal[m].vid;
        newnode->dist=cal[m].dist;
        newnode->next=NULL;
        struct list *temp=path[i];
        if(temp==NULL){
            path[i]=newnode;
            temp=path[i];
        }
        else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            temp=temp->next;
        }
        m=cal[m].prev;
        if(m==n-1){
        struct list *newnode=(struct list*)malloc(sizeof(struct list));
        newnode->data=cal[m].vid;
        newnode->dist=cal[m].dist;
        newnode->next=NULL;
        temp->next=newnode;
        }
    }
}

for(int i=1;i<n-1;i++){
    struct list *temp=path[i];
    if(temp==NULL){
        printf("%d %s\n",i,"NO PATH");
    }
    else{
    printf("%d ",i);
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",path[i]->dist);
    }
}
    fclose(list);
    return 0;
}