# name of the program (Minix service)
PROG = proj

# source code files to be compiled
# all:
#    +$(MAKE) gui
#    +$(MAKE) libs
#    +$(MAKE) libs/game
#    +$(MAKE) libs/modules/gpu
#    +$(MAKE) libs/modules/keyboard
#    +$(MAKE) libs/modules/mouse
#    +$(MAKE) libs/modules/rtc
#    +$(MAKE) libs/modules/serial_port
#    +$(MAKE) libs/modules/timer

#    SRCS = main.c

SRCS = $(wildcard *.c)

# additional compilation flags
# "-Wall -Wextra -Werror -I . -std=c11 -Wno-unused-parameter" are already set
#CPPFLAGS += -DPROJ
#CFLAGS += -pedantic
CPPFLAGS += -pedantic -D __LCOM_OPTIMIZED__
#CPPFLAGS += -pedantic

# list of library dependencies (only LCF library)
DPADD += ${LIBLCF}
LDADD += -llcf

# include LCOM's makefile that does all the "heavy lifting"
.include <minix.lcom.mk>
