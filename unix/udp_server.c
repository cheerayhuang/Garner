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
#include <netinet/in.h>

int main() {

    int fd = socket(AF_INET, SOCK_DGRAM, 0);

    fprintf(stderr, "%d\n", fd);

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = 9999;

    /*
     * you can also bind it in order to make a name
     * for the socket.
     *
    struct sockaddr_in addr2;
    memset(&addr2, 0, sizeof(struct sockaddr_in));
    addr2.sin_family = AF_INET;
    addr2.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr2.sin_port = 9998;

    int r = bind(fd, (struct sockaddr*)&addr2, sizeof(struct sockaddr_in));

    printf("%d\n", r);
    */

    char msg[100];
    strcpy(msg, "hello!");
    sendto(fd, msg, strlen(msg)+1, 0, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));



    recv(fd, msg, 100, 0);
    fprintf(stderr, "%s\n", msg);

    close(fd);
    return 0;
}
