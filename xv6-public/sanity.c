//
//  main.c
//  sanity
//
//  Created by Simone Brown on 4/14/19.
//  Copyright © 2019 Simone Brown. All rights reserved.
//

#include <stdio.h>

int main(int argc, char * argv[]) {
    if(argc != 2){
        printf("error");
        exit();
    }
    
    int wtime, rtime, iotime, status, totr, totw, tott, avgr, avgw, avgt;
    int pid, i, j, k;
    int procs[20];
    int comptime = 4000000;
    
    for(i = 0; i<20; i++){
        procs[i] = fork();
        
        if(i <= 10){    // making some tasks take shorter than others
            comptime = 2000000;
        }
        for(j=0; j < comptime; j++){}   // time consuming task, doesn't do anything
        exit();
    }
    
    while((pid = wait_stat(&wtime, &rtime, &iotime, &status)) != -1){
        for(k = 0; k < 20; k++){
            if(status == procs[i]){
                printf(1, "Child process %d with pid %d:\n", k, procs[i])
                printf(1, "For child process %d, wait time: %d, running time: %d, overall turnaround time: %d", k, wtime, rtime, (iotime+wtime+rtime))
                break;
            }
        }
        totw += wtime;
        totr += rtime;
        tott += (wtime + rtime + iotime)
    }
    
    avgw = totw/20
    avgr = totr/20
    avgt = tott/20
    
    printf(1, "The average performance for 20 processes is as listed below./n");
    printf(1, "Average waiting time: %d, Average running time: %d, Average overall turnaround time: %d", avgw, avgr, avgt);
    exit();
}
