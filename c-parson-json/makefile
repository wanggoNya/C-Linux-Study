CC = gcc
TARGET = main.out
OBJS = signal_parson.o ./parson/parson.o 
CFLAGS = -g -c -lpthread -pthread -Wall -Werror -Wextra  -Winline -Wsign-compare -Wunused-parameter -Wpointer-arith -Wshadow -Wstrict-prototypes -Wmissing-prototypes
all : main.out

$(TARGET) : $(OBJS)
		  $(CC) -pthread -o $@ $^
.c.o :
		$(CC) $(CFLAGS) -c -o $@ $<
clean :
		rm -f $(OBJS) $(TARGET)


