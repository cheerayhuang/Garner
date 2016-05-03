/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: wait1.c
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-03-2016 17:45:52
 * @version $Revision$
 *
 **************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t i, j;
    int status;

    if ((i = fork()) == 0) {
        fprintf(stderr, "child begin, pid = [%d], ppid = [%d] \n", getpid(), getppid());
        sleep(40);
        fprintf(stderr, "child end. ppid = [%d]\n", getppid());
        fprintf(stderr, "child end. pid = [%d]\n", getpid());
        exit(10);
    }

    j = wait(&status);
    fprintf(stderr, "child pid = [%d], exit pid [%d], status [%d] \n", i, j, status);
    //sleep(40);
    return 0;
}



