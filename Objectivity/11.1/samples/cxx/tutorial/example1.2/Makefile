include	../../include.mk

#Sample	specific settings
PROGRAM					=	main
OBJ_FILES				=	src/main.o \
								src/Session.o

#	Default	target
all: $(PROGRAM)

$(PROGRAM):	PROGRAM_OBJ
	$(CC)	-o $(PROGRAM)	$(LDFLAGS) $(OBJ_FILES)
	
PROGRAM_OBJ	:
	cd src ; make -e all

clean: 
	rm -f	$(PROGRAM) *.bak
	cd src ; make -e clean
	
