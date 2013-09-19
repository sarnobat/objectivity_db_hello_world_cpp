include	../../../include.mk

INCLUDES	=	-I.	-I$(OBJYINCLUDES)	-I../ddlFiles	

DATA_DIR		= ../data

BOOTFILE		= $(DATA_DIR)/example1.2.boot
FDBFILE		= $(DATA_DIR)/example1.2.fdb
OBJY_FDID	= 2

PROGRAM_SRC		=	main.cpp \
						Session.cpp
		 
######################################

.SUFFIXES: .C	.cpp .cxx
.cpp.o:	 
	$(CC)	$(C_FLAGS) $(INCLUDES) $(DEFINES)	-c $*.cpp	-o $*.o	

.cxx.o:	 
	$(CC)	$(C_FLAGS) $(INCLUDES) $(DEFINES)	-c $*.cxx	-o $*.o	
	
.C.o:	 
	$(CC)	$(C_FLAGS) $(INCLUDES) $(DEFINES)	-c $*.C	-o $*.o	
	
#######################################
PROGRAM_OBJ		=	$(PROGRAM_SRC:.cpp=.o)
SCHEMA_H			=	$(DDL:.ddl=.h)
SCHEMA_REF		=	$(DDL:.ddl=_ref.h)
SCHEMA_OBJ		=	$(SCHEMA_C:.cpp=.o)
SCHEMA_C			=	$(DDL:.ddl=_ddl.cpp)

#	Default	target
all: $(BOOTFILE) $(PROGRAM_OBJ)

$(BOOTFILE):
	$(OONEWFD) -fdfilepath $(FDBFILE) -lockserverhost $(OBJY_LS) -fdnumber $(OBJY_FDID) $(BOOTFILE)

clean:
	oodeletefd -force $(BOOTFILE)
	rm -f	*.bak	$(PROGRAM_OBJ) $(SCHEMA_OBJ) $(SCHEMA_H) $(SCHEMA_C) $(SCHEMA_REF)
