/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: shm_recv.c
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-04-2016 13:34:07
 * @version $Revision$
 *
 **************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main() {

    int shmid = 1146892;
    //shmid = shmget(IPC_PRIVATE, 150, 0666 | IPC_CREAT);

    //printf("%d\n", shmid);

    char *p = shmat(shmid, 0, 0);

    char buf[20];

    memcpy(buf, p+100, 6);
    buf[6] = 0;

    fprintf(stderr, "%s\n", buf);

    shmdt(p);

    return 0;
}
