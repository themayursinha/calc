CC = clang
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`
SRC = gui/gui.c src/calculator.c src/main.c
OBJ = $(SRC:.c=.o)
OUT = calculator_gui

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)

.PHONY: all clean
