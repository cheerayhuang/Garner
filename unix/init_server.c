/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: init_server.c
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-03-2016 19:11:32
 * @version $Revision$
 *
 **************************************************************************/

#include <signal.h>
#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    pid_t pid1;

    assert((pid1 = fork()) >= 0);
    if (pid1 > 0) {
        fprintf(stderr, "this is parent process.\n");
        exit(0);
    }

    fprintf(stderr, "new sesiion id & session leader groupid = %d\n", setsid());
    umask(0);
    signal(SIGINT, SIG_IGN);
    signal(SIGCHLD, SIG_IGN);

    sleep(60);

    return 0;
}
