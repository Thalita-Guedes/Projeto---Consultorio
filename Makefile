CC		= gcc
CFLAGS	= -I. -Iinc -g
SRC		= $(wildcard src/*.c)
OBJDIR	= build/obj
BINDIR	= build
OBJ		= $(patsubst src/%.c, $(OBJDIR)/%.o, $(SRC))
TARGET	= $(BINDIR)/app

exec: $(TARGET)
	./build/app

all: $(TARGET)
	@echo "Finalizado com sucesso (aplicacao em build/app)"

$(TARGET): $(OBJ)
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(OBJDIR)/%.o: src/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BINDIR)

.PHONY: all clean exec