CFLAGS:=-Iinclude
CFLAGS+=-c
TARGET:=bin/Ticket
DEPEND:=obj/main.o
DEPEND+=obj/account.o
DEPEND+=obj/adminMenu.o
DEPEND+=obj/notaryMenu.o
DEPEND+=obj/userMenu.o

$(TARGET):$(DEPEND)
	gcc -g $^ -o $@
obj/%.o:src/%.c
	gcc -g $(CFLAGS) $^ -o $@ 