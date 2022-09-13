CC = gcc
TARGET = memcpy_base64.out
OBJS = memcpy_base64.o

all : memcpy_base64.out

$(TARGET) : $(OBJS)
		  $(CC) -o $@ $^
.c.o :
		$(CC) -c -o $@ $<
clean :
		rm -f $(OBJS) $(TARGET)
