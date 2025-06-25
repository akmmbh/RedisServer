/*cachenew.c*/
#include "cachenew.h"
//we are making this which tell us the program in open or not or we can when to close this program 
bool scontinuation;
bool ccontinuation;
void zero(int8* buf,int16 size){
   int8 *p;
   int16 n;
   for(n=0,p=buf;n<size;n++,p++)*p=0;
   return;
}
void childloop(Client *cli){
   int8 buf[256];
   int8 *p,*f;
   int16 n;
   int8 cmd[256],folder[256],args[256];
   zero(buf,256);
   read(cli->s,buf,255);
   n=(int16)strlen((char *)buf);
   if(n>254){
      n=254;
   }
   //select /Users/job
   //create /Users/logins
   //insert /Users/job akffkafjafafaf 
    for(p=buf;(*p)&&(n--)&&(*p!=' ')&&(*p!='\r')&&(*p!='\n');p++)
    zero(cmd,256);zero(folder,256);zero(args,256); 
    if(!(*p)||(!n)){
      strncpy((char *)cmd,(char *)buf,255);
     goto done;
    }
    else if((*p  == ' ')|| (*p=='\n')||(*p =='\r')){
      *p =0;
      strncpy((char*)cmd,(char*)buf,255);
    }
    for(p++,f=p;(*p)&&(n--)&&(*p!=' ')&&(*p!='\r')&&(*p!='\n');p++)
   // zero(cmd,256);zero(folder,256);zero(args,256);
    if(!(*p)||(!n)){
      strncpy((char *)folder,(char *)f,255);
     goto done;
    }
    else if((*p  == ' ')|| (*p=='\n')||(*p =='\r')){
      *p =0;
      strncpy((char*)folder,(char*)f,255);
    }
    p++;
    if(*p){
      strncpy((char*)args,(char *)p,255);
      for(p=args;(*p)&&((*p)!='\n'&&(*p)!='\r');p++)
      *p=0;
    }
    done:
       dprintf(cli->s,"cmd:\t%s\n",cmd);
       dprintf(cli->s,"folder:\t%s\n",folder);
       dprintf(cli->s,"args:\t%s\n",cmd);
   return;
}
void mainloop(int s){
   //now we have to accepting connection

   struct sockaddr_in cli;
   int32 len;
   int s2;
   char* ip;
   int16 port;
   Client *client
   pid_t pid;
  s2= accept(s,(struct sockaddr *)&cli,(unsigned int *)&len)<0;
   if(s2<0){
    sleep(1);
    return;}
    port =(int16)htons((int)cli.sin_port);
    ip= inet_ntoa(cli.sin_addr);
printf("connectiono form %s:%d\n",ip,port);
client =(Client *)malloc(sizeof(struct s_client));
assert(client);
zero((int8 *)client,sizeof(struct s_client));
client->s=s2;
client->port=port;
strncpy(client->ip,ip,15);
pid=fork();
if(pid){
   free(client);
   return ;
}
else{
   dprintf(s2,"100 connected to cachenew server");
   ccontinuation=true;
   while(ccontinuation)childloop(client);
   close(s2);
   free(client);
}
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