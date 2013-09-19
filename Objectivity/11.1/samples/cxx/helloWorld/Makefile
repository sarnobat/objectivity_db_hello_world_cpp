include	../include.mk

#echo DYLD_LIBRARY_PATH
#Sample	specific settings
PROGRAM					=	helloWorld
OBJ_FILES				=	src/main.o src/HelloObject.o ddlFiles/HelloObject_ddl.o


#	Default	target
all: $(PROGRAM)

$(PROGRAM):	PROGRAM_DDL	PROGRAM_OBJ
	$(CC)	-o $(PROGRAM) $(OBJ_FILES) $(LDFLAGS)
	
PROGRAM_DDL	:
	cd ddlFiles	;	make -e all

PROGRAM_OBJ	:
	cd src ; make -e all

clean: 
	rm -f	$(PROGRAM) *.bak
	cd ddlFiles ; make -e clean
	cd src ; make -e clean
	
