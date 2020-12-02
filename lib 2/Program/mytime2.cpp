#include"sys/types.h"
#include<unistd.h>
#include"stdio.h"
#include<sys/time.h>  //gettimeofday
#include<sys/wait.h>  //wait
#include<ctime>       //localtime
int main(int argc,char*argv[]){
    pid_t pid;
   
     int year,month,day,hour,minute,second,millisecond;
   struct timeval startTime;
    struct timeval endTime;
    struct timezone zone;
    time_t startTime_t;
    time_t endTime_t;
    struct tm *startTime_tm;
    struct tm *endTime_tm;
   
    if((pid=fork())<0){
        printf("fork failed\n");
        return 0;
    }else if(pid==0){
        if(argc==1)
        execv(argv[1],argv);
        else{
            char *str = strcat(argv[1], " ");
          str = strcat(str, argv[2]);
           execv(str,argv);
        }

    }else{
        gettimeofday(&startTime,&zone);
        wait(0);   //等待子进程结束
        gettimeofday(&endTime, &zone);
        long long int during=(endTime.tv_sec-startTime.tv_sec)*1000000+endTime.tv_usec-startTime.tv_usec;
        millisecond=during%1000000;
        second=during/1000000;
        minute=second/60;
        second%=60;
        hour=minute/60;
        minute%=60;
        day=hour/24;
        hour%=24;
        month=day/30;
        day%=30;
        year=month/12;
        month%=12;
        if(second<0){
        minute--;
        second+=60;
        }
    if(minute<0){
        hour--;
        minute+=60;
    }
    if(hour<0){
        day--;
        hour+=24;
    }
    if(day<0){
        month--;
        day+=30;
    }
    if(month<0){
        year--;
        month+=12;
    }

    if(year>0) printf("%d 年 ",year);
    if(month>0) printf("%d 月 ",month);
   if(day>0) printf("%d 日 ",day);
   if(hour>0) printf("%d 小时 ",hour);
   if(minute>0) printf("%d 分钟 ",minute);
   if(second>0) printf("%d 秒 ",second);
   printf("\n");
    return 0;
    }

}