/*cachenew.c*/
#include "cachenew.h"
//we are making this which tell us the program in open or not or we can when to close this program 
bool scontinuation;
void mainloop(int s){
   //now we have to accepting connection

   struct sockaddr_in cli;
   int32 len;
   int s2;
   char* ip;
   int16 port;
   accept(s,(struct sockaddr *)&cli,(unsigned int *)&len)<0;
   if(s2<0){
    sleep(1);
    return;}
    port =(int16)htons((int)cli.sin_port);
    ip= inet_ntoa(cli.sin_addr);
printf("connectiono form %s:%d\n",ip,port);
return ;
   

}
int initserver(int16 port){
    struct sockaddr_in sock;
    int s;
    sock.sin_family =AF_INET;
    //htons(port)-convert hte port from host byte order to network byte order
    sock.sin_port= htons(port);
    //inet_addr - convert ip addres string in host  to in_addr_t
    sock.sin_addr.s_addr=inet_addr(HOST);
    
    //create a socket type of tcp 
    s=socket(AF_INET,SOCK_STREAM,0);
    //check wheater the socket createtion is succes or not as if it fails return -1
    assert(s>0);
    
    //binding of upper two
    errno=0;
    //bind the socket to ip and port
    if(bind(s,(struct sockaddr *)&sock,sizeof(sock)))assert_perror(errno);
     
    //puts the socket in listening mode wiht backlog of 20 connections

    if(listen(s,20))assert_perror(errno);
  printf("Server listening on %s:%d\n",HOST,port);
  return s;
//scontinuation=false /*as if we not do so in main fucntion ,this function will runn in loop and if it aquire one port at one time so when loop goes to its next iteration it will fail*/
}
int main(int argc,char* argv[]){

     char *sport;
     int16 port;
     int s;
     if(argc<2){
        sport=PORT
     }
     else{sport=argv[1];}
     port=(int16)atoi(sport);
     s=initserver(port);
     scontinuation=true;
     while(scontinuation)mainloop(s);

     printf("Shutting down .... \n");
     close(s);
     return 0;

}