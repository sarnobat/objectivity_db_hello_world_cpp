include ../../include.mk

INCLUDES		= -I. -I$(OBJYINCLUDES)

DATA_DIR		= ../data
PMD_DIR			= ../pmdFiles
PMD				= $(PMD_DIR)/default.pmd

OBJY_FDPATH = $(DATA_DIR)
FDNAME		= HelloWorld
BOOTFILE	= $(OBJY_FDPATH)/HelloWorld.boot

DDL			= HelloObject.ddl	
		 
######################################

.SUFFIXES: .ddl
.cpp.o:	 
	$(CC)	$(C_FLAGS) $(INCLUDES) $(DEFINES)	-c $*.cpp	-o $*.o	

.cxx.o:	 
	$(CC)	$(C_FLAGS) $(INCLUDES) $(DEFINES)	-c $*.cxx	-o $*.o	
	
.C.o:	 
	$(CC)	$(C_FLAGS) $(INCLUDES) $(DEFINES)	-c $*.C	-o $*.o	
	
.ddl.h:	
	$(OODDLX) -c++_suffix _ddl.cpp $(INCLUDES) $*.ddl $(BOOTFILE)

#######################################
PROGRAM_OBJ	=	$(PROGRAM_SRC:.cpp=.o)
SCHEMA_H		=	$(DDL:.ddl=.h)
SCHEMA_REF	=	$(DDL:.ddl=_ref.h)
SCHEMA_OBJ	=	$(SCHEMA_C:.cpp=.o)
SCHEMA_C		=	$(DDL:.ddl=_ddl.cpp)

#	Default	target
all:	$(BOOTFILE)	$(SCHEMA_H)	$(SCHEMA_OBJ) $(PMD)

# This target helps us work around a gnu make 3.81 bug - bug# 443
# see: http://savannah.gnu.org/bugs/?443
$(SCHEMA_C):
	touch $(SCHEMA_C)

$(BOOTFILE):
	$(CREATEFD) -fdname $(FDNAME) -fddirpath $(OBJY_FDPATH) -lockserverhost $(OBJY_LS)

$(PMD):
	$(EXPORTPLACEMENT) -outfile $(PMD) -bootfile $(BOOTFILE)

clean:
	rm -f	*.h	*_ddl.cpp	*.bak	*.o	
	rm -f $(PMD)
	oodeletefd -force	$(BOOTFILE)
