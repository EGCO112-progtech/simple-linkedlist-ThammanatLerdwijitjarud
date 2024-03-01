//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b, *head ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    
    struct node d;
    b.next=&d;
    d.value=11;
    d.next=NULL;
    printf("%d\n", head->next->next->value);
    printf("\n");

    /*  Exercise I                                     
    1. Add 1 more at the end
    2. Add value(11)
    3. Make next become NULL
    */

    struct node e;
    e.next=&a;
    e.value=2;
    head=&e;
    printf("%d\n", head->value);
    printf("%d\n", head ->next->value );
    printf("%d\n", head->next->next->value);
    printf("%d\n", head->next->next->next->value);


/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    // Exercise III Use loop to print everything
        int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp = tmp->next;
          // What is missing???
        }
        
    printf("\n");
    
    // Exercise IV change to while loop!! (you can use NULL to help)
    tmp = head;
     
         while(tmp!=NULL){
            printf("%3d", tmp->value);
            tmp = tmp->next;
        }
        printf("\n");

    tmp = head;
    
    
    //  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
         typedef struct node* nodePtr;
         nodePtr temp;
         head = (nodePtr)malloc(sizeof(struct node));
         temp = head;

         for(int i=0;i<4;i++) {
            temp->value = tmp->value;
            if (i<3) {
                temp->next = (nodePtr)malloc(sizeof(struct node));
            }
            printf("%3d", temp->value);
            temp = temp->next;
            tmp = tmp->next;
         }

         printf("\n");
     
    temp = head;
    //   Exercise VI Free all node !!
         //use a loop to help
        //  while(head!=NULL) {
        //     head = head->next;
        //     free(temp);
        //     temp = head;
        //     printf("free ");
        //  }

         while(head) {
            tmp=head;
            head=head->next;
            printf("%3d", tmp->value);
            free(tmp);
         }
         printf("\n");
          
    
    
    return 0;
}
