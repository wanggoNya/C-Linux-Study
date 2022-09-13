CC = gcc
TARGET = main.out
OBJS = test5.o ./parson/parson.o
CFLAGS = -g -c  -Wall -Werror -Wextra  -Winline -Wsign-compare -Wunused-parameter -Wpointer-arith -Wshadow -Wstrict-prototypes -Wmissing-prototypes
all : main.out

$(TARGET) : $(OBJS)
		  $(CC) -o $@ $^
.c.o :
		$(CC) $(CFLAGS) -c -o $@ $<
clean :
		rm -f $(OBJS) $(TARGET)

