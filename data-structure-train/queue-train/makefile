CC = gcc
TARGET = main.out
OBJS = queue1.o 
CFLAGS = -g -c -Wall -Werror -Wextra  -Winline -Wsign-compare -Wunused-parameter -Wpointer-arith -Wshadow -Wstrict-prototypes -Wmissing-prototypes
all : main.out
LDFLAGS = -pthread

$(TARGET) : $(OBJS)
		  $(CC) $(LDFLAGS) -o $@ $^
.c.o :
		$(CC) $(CFLAGS) -c -o $@ $<
clean :
		rm -f $(OBJS) $(TARGET)


