SRC := lua-htmlentity.c
OBJ := $(SRC:.c=.o)
SO_NAME := htmlentity.so

LUA_INC=/usr/local/include
LUA_LIB=/root/project/skyent_src/3rd/lua
CFLAGS := -Wall -O3 -flto -g -fPIC -MMD -I$(LUA_INC)

.PHONY = all clean

all : $(SO_NAME)

${OBJ} : %.o : %.c
	$(CC) $(CFLAGS)  -c $<

${SO_NAME} : ${OBJ}
	$(CC) $(CFLAGS) -L$(LUA_LIB) $^ -shared -o $@

clean:
	rm -f *.o *.so a.out *.d
