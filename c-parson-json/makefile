CC = gcc
TARGET = main.out
OBJS = test3.o ./parson/parson.o

all : main.out

$(TARGET) : $(OBJS)
		  $(CC) -o $@ $^
.c.o :
		$(CC) -c -o $@ $<
clean :
		rm -f $(OBJS) $(TARGET)
