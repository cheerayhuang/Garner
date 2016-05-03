/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: szomb.c
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-03-2016 18:46:25
 * @version $Revision$
 *
 **************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    pid_t pid1;

    if ((pid1 = fork()) == 0) {

        printf("child(%d)\n", getpid());
        if ((pid1 = fork()) == 0) {
            printf("grandson[%d]\n", getpid());
            sleep(20);
            exit(0);
        }
        exit(0);
    }

    waitpid(pid1, 0, 0);
    printf("parent(%d)\n", getpid());

    sleep(60);

    return 0;
}



