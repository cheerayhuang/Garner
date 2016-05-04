/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: http.c
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-04-2016 17:14:36
 * @version $Revision$
 *
 **************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
#include <string.h>
#include <errno.h>

int main() {

    int fd = socket(AF_UNIX, SOCK_STREAM, 0);

    fprintf(stderr, "%d\n", fd);

    struct sockaddr_un addr;
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, "./test");

    //int r = bind(fd, (struct sockaddr*)&addr, sizeof(struct sockaddr_un));
    int r = connect(fd, (struct sockaddr*)&addr, sizeof(struct sockaddr_un));

    fprintf(stderr, "%d\n", r);

    char msg[100];
    strcpy(msg, "hello!");

    //sleep(10);
    //fprintf(stderr, "ok");
    char addrbuf[256];
    socklen_t addrlen;
    int nsize = recvfrom(fd, msg, 100, 0, (struct sockaddr*)addrbuf, &addrlen);

    fprintf(stderr, "%s\n", msg);

    fprintf(stderr, "%u\n", addrlen);

    strcpy(msg, "world");
    send(fd, msg, strlen(msg)+1, 0);

    close(fd);
    return 0;
}
