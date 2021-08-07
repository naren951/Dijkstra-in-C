#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define MAXCHAR 1000
struct list {
    int data;
    int dist;
    struct list *next;
};    
struct node {
    int data;
    int weight;
    struct node *next;
};
struct heap{
    int vid;
    int dist;
    int prev;
};
void heapsort(struct heap *,int ,int );
void calculate(struct heap *,struct node **,int ,int );
void sort_v(struct heap *,int ,int );
void create_graph(char *,FILE *,struct node **);