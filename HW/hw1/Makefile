.SUFFIXES: .c .o
CC = gcc


arrOBJ = main.o arr.o
linkOBJ = main.o link.o
SRCS = $(arrOBJ:.o=.c) $(linkOBJ:.o=.c)

all: arr link

arr: $(arrOBJ)
	$(CC) -o arr $(arrOBJ)

link: $(linkOBJ)
	$(CC) -o link $(linkOBJ)
dep: 
	gccmakedep $(SRCS)
