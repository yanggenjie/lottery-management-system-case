CFLAGS:=-Iinclude
CFLAGS+=-c
TARGET:=bin/Ticket
DEPEND:=obj/mainMenu.o
DEPEND+=obj/account.o
DEPEND+=obj/adminMenu.o
DEPEND+=obj/notaryMenu.o
DEPEND+=obj/userMenu.o
DEPEND+=obj/fileIO.o

$(TARGET):$(DEPEND)
	gcc -g $^ -o $@
obj/%.o:src/%.c
	gcc -g $(CFLAGS) $^ -o $@
.PHONY:clean
clean:
	rm -rf $(DEPEND)