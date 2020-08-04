#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * socketthread(void * parm);       /* thread function prototype    */
void RSP(int k);
void prtmsg(int m);

pthread_mutex_t  mut;
pthread_cond_t tcon= PTHREAD_COND_INITIALIZER;
pthread_cond_t tcon2= PTHREAD_COND_INITIALIZER;
#define PROTOPORT         5193          /* default protocol port number */
#define QLEN              6             /* size of request queue        */

char inval[10][100];
char outval[10][100];
int t =  0,i=0, g[3]; 			/* counts client connections     */

main (int argc, char *argv[])
{
     struct   hostent   *ptrh;     /* pointer to a host table entry */
     struct   protoent  *ptrp;     /* pointer to a protocol table entry */
     struct   sockaddr_in sad;     /* structure to hold server's address */
     struct   sockaddr_in cad;     /* structure to hold client's address */
     int      sd, sd2;             /* socket descriptors */
     int      port;                /* protocol port number */
     int      alen;                /* length of address */
     pthread_t  tid;             /* variable to hold thread ID */

     pthread_mutex_init(&mut, NULL);

     memset((char  *)&sad,0,sizeof(sad)); /* clear sockaddr structure   */
     sad.sin_family = AF_INET;            /* set family to Internet     */
     sad.sin_addr.s_addr = INADDR_ANY;    /* set the local IP address */
 	if (argc > 1) {                        /* if argument specified     */
                     port = atoi (argv[1]); /* convert argument to binary*/
     } else {
                      port = PROTOPORT;     /* use default port number   */
     }
     if (port > 0)                          /* test for illegal value    */
                      sad.sin_port = htons((u_short)port);
     else {                                /* print error message and exit */
                      fprintf (stderr, "bad port number %s/n",argv[1]);
                      exit (1);
     }


     /* Map TCP transport protocol name to protocol number */

     if ( ((int)(ptrp = getprotobyname("tcp"))) == 0)  {
                     fprintf(stderr, "cannot map \"tcp\" to protocol number");
                     exit (1);
     }

     /* Create a socket */
     sd = socket (PF_INET, SOCK_STREAM, ptrp->p_proto);
     if (sd < 0) {
                       fprintf(stderr, "socket creation failed\n");
                       exit(1);
     }

     /* Bind a local address to the socket */
     if (bind(sd, (struct sockaddr *)&sad, sizeof (sad)) < 0) {
                        fprintf(stderr,"bind failed\n");
                        exit(1);
     }

     /* Specify a size of request queue */
     if (listen(sd, QLEN) < 0) {
                        fprintf(stderr,"listen failed\n");
                         exit(1);
     }

     alen = sizeof(cad);
 /* Main server loop - accept and handle requests */
     fprintf( stderr, "Server up and running.\n");
	pthread_mutex_lock(&mut);
	while(1){
        printf("SERVER: Waiting for contact ...\n");

        if((sd2=accept(sd, (struct sockaddr *)&cad, &alen)) < 0) {
	                      fprintf(stderr, "accept failed\n");
                              exit (1);
	}
	g[i]=sd2;
	pthread_create(&tid, NULL, socketthread, (void *) sd2);
	
	i++;
	if(i==2){
		pthread_mutex_unlock(&mut);
	}
	if(t==2){
		exit(0);
	}
	}
     close(sd);
}
void * socketthread(void * parm)
{
	int tsd, msiz;
   	char     buf[100];           
	char start[]="\nGame Start!(R,S,P중에서 하나만 고르시오(대문자)) \n";
 	tsd = (int) parm;	
	
    	printf(" user%d is connected\n",tsd);
	while(1){
		memset(inval[tsd],0,100);
		pthread_mutex_lock(&mut);
		send(tsd,start,strlen(start),0);
		msiz=recv(tsd,buf,sizeof(buf)-1,0);
                buf[msiz]='\0';
                if(strcmp(buf,"exit")==0){
                        printf("user %d quit.\n",tsd);
                        memset(buf,0,100);
                        pthread_exit(0);
                }
                else{
                        if(msiz==0){
                                printf("user%d quit.\n",tsd);
                                pthread_exit(0);
                        }
                        strcpy(inval[tsd],buf);
			printf("user%d: %s\n",tsd,inval[tsd]);
		}
		pthread_mutex_unlock(&mut);
		sleep(10);
		
		while((inval[g[1]][0]==0)||(inval[g[0]][0]==0)){
		
		pthread_mutex_lock(&mut);
		}

		RSP(tsd);
		
		send(tsd,outval[tsd],strlen(outval[tsd]),0);
		
		pthread_mutex_unlock(&mut);
		sleep(2);
		if(strcmp(outval[tsd],"You win")==0 || strcmp(outval[tsd],"You lose")==0){
			exit(0);
		}
		pthread_mutex_unlock(&mut);
		memset(inval[tsd],0,100);
	}
}    

void RSP(int k){
	
	char a,b;
	char buf[100];
	if(k==g[0]){
		a=inval[g[0]][0];
		b=inval[g[1]][0];
	}
	else{
		a=inval[g[1]][0];
		b=inval[g[0]][0];
	}
	if(a==b){
		strcpy(outval[k],"Again");
	}
	else if((a=='R' && b=='S')||(a=='S' && b=='P')||(a=='P'&&b=='R')){
		strcpy(outval[k],"You win");
		
	}
	else if((a=='S' && b=='R')||(a=='P' && b=='S')||(a=='R'&&b=='P')){
		strcpy(outval[k],"You lose");
		
	}
	else{
		strcpy(outval[k],"Error");
	}
}   

