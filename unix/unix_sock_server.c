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

    int r = bind(fd, (struct sockaddr*)&addr, sizeof(struct sockaddr_un));

    listen(fd, 1024);

    struct sockaddr dest_addr;
    socklen_t dest_addr_len;
    int conn_fd = accept(fd, (struct sockaddr*)&dest_addr, &dest_addr_len);
    fprintf(stderr, "err=%s\n", strerror(errno));

    fprintf(stderr, "connfd=%d\n%u\n", conn_fd, (unsigned)dest_addr_len);

    char msg[100];
    strcpy(msg, "hello!");

    send(conn_fd, msg, strlen(msg)+1, 0);

    memset(msg, 0, 100);
    recv(conn_fd, msg, 100, 0);

    fprintf(stderr, "%s\n", msg);

    close(fd);
    close(conn_fd);

    return 0;
}
