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
#include <arpa/inet.h>

int main() {

    int fd = socket(AF_INET, SOCK_DGRAM, 0);

    fprintf(stderr, "%d\n", fd);

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = 9999;

    int r = bind(fd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));
    fprintf(stderr, "%d\n", r);


    char msg[100];
    strcpy(msg, "hello!");

    char addrbuf[256];
    socklen_t addrlen;
    int nsize = recvfrom(fd, msg, 100, 0, (struct sockaddr*)addrbuf, &addrlen);

    fprintf(stderr, "%s\n", msg);

    struct sockaddr_in *dest_addr = (struct sockaddr_in *)&addrbuf;
    fprintf(stderr, "%u\n", dest_addr->sin_port);
    fprintf(stderr, "%s\n", inet_ntoa(dest_addr->sin_addr));

    sleep(5);
    strcpy(msg, "world");

    nsize = sendto(fd, msg, strlen(msg)+1, 0, (struct sockaddr*)&addrbuf, addrlen);
    fprintf(stderr, "%s\n", strerror(errno));
    fprintf(stderr, "%d\n", nsize);

    close(fd);
    return 0;
}
