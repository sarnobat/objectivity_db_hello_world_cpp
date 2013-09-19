OBJY_HOME       = /Applications/Objectivity/11.1
OBJY_LS         = `hostname`

OBJYBIN         = $(OBJY_HOME)/bin
OBJYINCLUDES    = $(OBJY_HOME)/include
OBJYLIB         = $(OBJY_HOME)/lib

# Compilier and link flags
OBJYFLAGS       = -L$(OBJYLIB) -loo.11.1 -lrpcsvc -ldl -pthread
CC              = g++ -m64 -g
LD              = g++ -m64
LDFLAGS         = $(OBJYFLAGS)

# Objectivity admin tools
OODDLX          = $(OBJYBIN)/ooddlx
CREATEFD        = $(OBJYBIN)/objy createfd
DELETEFD        = $(OBJYBIN)/objy deletefd
IMPORTPLACEMENT = $(OBJYBIN)/objy importplacement
EXPORTPLACEMENT = $(OBJYBIN)/objy exportplacement
