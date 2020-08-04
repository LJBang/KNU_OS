#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <stdio.h>
#include <string.h>

#define closesocket      close
#define PROTOPORT        5193        /* default protocol port number */

extern int               errno;
char   localhost[] = "localhost";    /* default host name            */

main(int argc, char *argv[])
{
   struct  hostent  *ptrh;   /* pointer to a host table entry       */
   struct  protoent *ptrp;   /* point to a protocol table entry     */
   struct  sockaddr_in sad;  /* structure to hold server's address  */
   int     sd;               /* socket descriptor                   */
   int     port;             /* protocol port number                */
   char    *host;            /* pointer to host name                */
   int     n;                /* number of characters read           */
   char    buf[1000];        /* buffer for data from the server     */
	int msglen;
	int trcvbyte=0,rcvbyte;
	char msgbuff[100];


   memset((char *)&sad,0,sizeof(sad));  /* clear sockaddr structure */
   sad.sin_family = AF_INET;            /* set family to Internet   */

   /* Check command-line argument for protocol port and extract     */
   /* port number if on is specified.  Otherwise, use the default   */
   /* port value biven by constant PROTOPORT                        */

   if (argc > 2) port = atoi(argv[2]);
   else port = PROTOPORT;
   
   if (port > 0) sad.sin_port = htons((u_short)port);
   else 
     { fprintf( stderr,"bad port number %s\n", argv[2]);
          exit(1);
     }
   
   if (argc > 1 ) host = argv[1];
   else host = localhost;
   
   ptrh = gethostbyname(host);
   if( ((char *)ptrh) == NULL)
     { fprintf( stderr, "invalid host:  %s\n", host);
       exit(1);
     }
   
   memcpy(&sad.sin_addr, ptrh->h_addr, ptrh->h_length);

   if ( ((int)(ptrp = getprotobyname("tcp"))) == 0)
     { fprintf( stderr, "cannot map \"tcp\" to protocol number\n");
       exit(1);
     }

   sd = socket(PF_INET, SOCK_STREAM, ptrp->p_proto);
   if (sd < 0)
     { fprintf( stderr, "socket creation failed\n");
       exit(1);
     }

   if (connect(sd, (struct sockaddr *)&sad, sizeof(sad)) < 0)
     { fprintf( stderr, "connect failed\n");
       exit(1);
     }
	scanf("%s",&buf);
	msglen = strlen(buf);
   	send(sd, buf, msglen, 0);
	printf("received: ");
	while(trcvbyte<msglen){
		rcvbyte=recv(sd,msgbuff,99,0);
		trcvbyte+=rcvbyte;
		msgbuff[rcvbyte]='\0';
		printf("%s",msgbuff);
	
	}
	printf("\n");
   closesocket(sd);
   exit(0);
}
