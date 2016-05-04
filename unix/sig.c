/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: sig.c
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-03-2016 20:44:45
 * @version $Revision$
 *
 **************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void ChildFunc(int sig) {
    fprintf(stderr, "Get sig\n");
    exit(6);
}

int main() {
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) exit(-1);

    if (pid == 0) {
        //signal(SIGTERM, ChildFunc);
        sleep(30);
        exit(0);
    }

    fprintf(stderr, "parent [%d] fork child pid = [%d]\n", getpid(), pid);
    sleep(1); // wait child set signal handler function.
    kill(pid, SIGTERM);
    wait(&status);
    fprintf(stderr, "Kill child pid = [%d], exit[%x]\n", pid, status);

    return 0;
}

