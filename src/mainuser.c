/*dll.c file:
            Autores: João Modesto, Luís Araújo  
            */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dll.h"

int main(){

    DoublyLinkedList dll;

    int select;
    bool alreadyInit=false;
    unsigned char data[ELEMENT_SIZE];
    unsigned char* data2;
    int remKey=0;
    int remkey=0;
    int i=0;
    char c;
    int count =0;
    char lixo;
    while(select!=7){
        printf("\nUser Menu (Press one Key):\n");
        printf("1-------Init\n");
        printf("2-------Insert\n");
        printf("3-------Remove\n");
        printf("4-------Find\n");
        printf("5-------FindNext\n");
        printf("6-------FindPrevious\n");
        printf("7-------End\n");


        scanf("%d",&select);

        if (select != 1 && alreadyInit==false){
            printf("You need to Init dll list first!!\n");
        }
        switch(select){
            case 1:
                MyDLLInit(&dll, MAX_ELEMENTS, ELEMENT_SIZE);
                printf("DLL Initialized\n");
                alreadyInit=true;
                break;
            case 2:
                printf("Insertion: ");
                //fgets((char*)data,ELEMENT_SIZE,stdin);
                i=0;
                lixo=getchar();
                while ((c = getchar()) != '\n' && i < ELEMENT_SIZE) {
                    data[i++] = c;
                }
                printf("\n");
                // ver dps se e preciso size_t len = strlen((char*)data);
                remkey ++;
                if(MyDLLInsert(&dll,remkey,data,ELEMENT_SIZE)==0){
                    printf("Inserted element with the Id %d ", remkey);
                    
                    for (int k = 0; k < ELEMENT_SIZE; k++) {
                        data[k] = ' ';
                    }
                }
                else{
                    printf("Element not inserted\n");
                    remkey--;
                }
                break;
            case 3:
                printf("Id of the element you want to remove: ");
                scanf("%d",&remKey);
                if(MyDLLRemove(&dll, remKey)==0){
                    printf("Element with the Id(%d) removed successfully\n",remKey);
                }
                else{
                    printf("Element not removed\n");
                }
                break;
            case 4:
                printf("Id of the element you want to find: ");
                scanf("%d",&remkey);
                data2 = MyDLLFind(&dll, remkey);
                if(data2!=NULL){
                    printf("Element Id %d : %s\n", remkey ,data2);
                    for (int k = 0; k < ELEMENT_SIZE; k++) {
                        data2[k] = ' ';
                    }
                }
                else{
                    printf("ERROR\n");
                }


                break;
            case 5:
                data2=MyDLLFindNext(&dll, remkey);
                if(data2==NULL){
                    printf("There is not a next element.\n");
                }
                else{
                    printf("The next element has the Id(%d): %s\n",remkey+1,data2);
                    for (int k = 0; k < ELEMENT_SIZE; k++) {
                            data2[k] = ' ';
                        }   
                        remkey++;
                    }
                break;
            case 6:
                data2=MyDLLFindPrevious(&dll, remkey);
                printf("The previous element has the Id(%d): %s\n",remkey-1,data2);
                for (int k = 0; k < ELEMENT_SIZE; k++) {
                        data2[k] = ' ';
                    }
                break;
            case 7:
            printf("\nGoodBye!\n");
                break;
            default:
                printf("Insert a valid value\n");
                break;
        }
      
    }
    return 0;  
}
