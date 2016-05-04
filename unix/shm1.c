/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: shm1.c
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-04-2016 13:26:48
 * @version $Revision$
 *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int shmid;
    char *p;

    shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);
    p = shmat(shmid, 0, 0);

    char buf[1024];

    strcpy(buf, "hello, world!");
    memcpy(p+100, buf, strlen(buf));

    shmdt(p);

    return 0;
}


