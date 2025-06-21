/*cachenew.h  */
#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<errno.h>

#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>


#define PORT     12000
#define HOST     "127.0.0.1"

typedef unsigned int int32;
typedef unsigned short int int16;
typedef unsigned char int8;


void mainloop(void);
int main(int,char**);