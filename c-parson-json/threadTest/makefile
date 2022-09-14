CC = gcc
TARGET = test8.out
OBJS = test8.o

all : test8.out

$(TARGET) : $(OBJS)
		  $(CC) -pthread -o $@ $^
.c.o :
		$(CC) -c -o $@ $<
clean :
		rm -f $(OBJS) $(TARGET)
