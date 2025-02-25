CC = gcc
CFLAGS = -Iinclude -Wall -O3 -lncurses

TARGET = bin/game_of_life
SRCDIR = src
OBJDIR = ./obj
OBJS= $(OBJDIR)/menu.o $(OBJDIR)/game.o $(OBJDIR)/window.o $(OBJDIR)/game_mode.o


.PHONY: all clean run

run: clean $(TARGET)
	@./$(TARGET)

all: $(TARGET)

clean:
	@rm -rf $(OBJDIR) ./bin

$(TARGET): $(OBJS) main.c
	@mkdir -p bin
	@$(CC) -o $@ $^ $(CFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) -c -o $@ $< $(CFLAGS)