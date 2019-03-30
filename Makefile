CC=gcc
CFLAGS=-I.

VALIDATE = validateMain.c
CONVERTER = converterMain.c

VALIDATOREXE = validator
CONVERTEREXE = converter

DEPS = DeckFunctions.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

validator: $(VALIDATE)
	$(CC) -o $(VALIDATOREXE) $(VALIDATE)

converter: $(CONVERTER)
	$(CC) -o $(CONVERTEREXE) $(CONVERTER)

clean:
	rm -f *.o
