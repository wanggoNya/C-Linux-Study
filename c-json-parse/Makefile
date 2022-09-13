OBJECTS = main.o

CC = gcc
CFLAGS = -g -O3 -c  -Wall -Werror -D_GNU_SOURCE -Wextra -Winline -Wsign-compare -Wunused-parameter -Wpointer-arith -Wshadow -Wstrict-prototypes -Wmissing-prototypes
INC = -I./
INC += -I/usr/local/include/json-c

LDFLAGS = -L/usr/local/lib64 -ljson-c

eval_objs = main.o

eval : $(eval_objs)
	$(CC) -o test $(eval_objs) $(LDFLAGS)

all:$(eval)

%.o:%.c
	$(CC) $(INC) $(CFLAGS) $<

clean :
	rm -rf $(OBJECTS) $(eval_objs) test core
