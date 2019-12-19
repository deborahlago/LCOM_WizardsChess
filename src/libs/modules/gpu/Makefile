# name of the program (Minix service)
PROG=proj

# source code files to be compiled
SRCS = videographic.c

# additional compilation flags
# "-Wall -Wextra -Werror -I . -std=c11 -Wno-unused-parameter" are already set
CPPFLAGS += -D PROJ
CFLAGS += -pedantic

# list of library dependencies (only LCF library)
DPADD += ${LIBLCF}
LDADD += -llcf

# include LCOM's makefile that does all the "heavy lifting"
.include <minix.lcom.mk>
