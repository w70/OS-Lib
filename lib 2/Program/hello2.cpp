#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"

int main(int argc,char*argv[]){
   
    if(argc==1){
        printf("hello\n");
        return 0;
    }
    if(argc==2){
        int time=atoi(argv[1]);
        sleep(time);
         printf("hello\n");
         return 0;
    }

}