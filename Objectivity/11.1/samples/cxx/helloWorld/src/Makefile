include	../../include.mk

INCLUDES	=	-I.	-I$(OBJYINCLUDES)	-I../ddlFiles	

PROGRAM_SRC		=	main.cpp \
							HelloObject.cpp
		 
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
all:	$(PROGRAM_OBJ)

clean:
	rm -f	*.bak	$(PROGRAM_OBJ) $(SCHEMA_OBJ) $(SCHEMA_H) $(SCHEMA_C) $(SCHEMA_REF)
