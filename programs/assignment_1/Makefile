CC	=	gcc
CFLAGS	=	-I.
OBJS	=	sys_info.o

sys_info: ${OBJS}
	${CC} -o $@ $^ ${CFLAGS}

clean:
	rm -rf sys_info ${OBJS}