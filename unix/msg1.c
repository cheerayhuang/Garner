/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: msg1.c
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-04-2016 12:03:34
 * @version $Revision$
 *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/errno.h>
#include <string.h>

extern int errno;

struct MsgBuf {
    long mtype;
    char msg[100];
};

int main() {
    struct MsgBuf buf;

    int msgid;

    if ((msgid = msgget(0x1234, 0666|IPC_CREAT)) < 0) {
        fprintf(stderr, "open msg %X failed.\n", 0x1234);
        return 1;
    }

    strcpy(buf.msg, "hello world!");
    buf.mtype = 100;

    msgsnd(msgid, &buf, strlen(buf.msg), 0);

    struct MsgBuf buf1;

    memset(&buf1, sizeof(buf1), 0);

    msgrcv(msgid, &buf1, sizeof(buf1.msg), 0, 0);

    fprintf(stderr, "%s\n", buf1.msg);

    return 0;
}
