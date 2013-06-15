PROJ:=l2

OPTCFLAGS=-O
ADDCFLAGS+=-Wall -Wextra

P:=B

all: $(PROJ)

l2: l2.c.o
	$(LINK.o) $(ADDCFLAGS) $(OPTCFLAGS) $(OUTPUT_OPTION) $^

l2.c.o: l2.c
	$(COMPILE.c) $(ADDCFLAGS) $(OPTCFLAGS) $(OUTPUT_OPTION) $<

run: $(PROJ)
	time -p ./$(PROJ) <$(P)_sample.dat
