# **********************************************************************
#
# Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
#
# This copy of Ice is licensed to you under the terms described in the
# ICE_LICENSE file included in this distribution.
#
# **********************************************************************

# Prefix for each installed program. Only ABSOLUTE PATH
prefix=/usr/local
exec_prefix=$(prefix)
# The directory to install the binary files in.
bindir=$(exec_prefix)/bin
# The directory to install the libraries in.
libdir=$(exec_prefix)/lib
# The directory to install the include files in.
includedir=$(exec_prefix)/include
# The directory to install the local configuration file.
datadir=$(exec_prefix)/share

top_srcdir	= .

CLIENT		=
SERVER		= RTAMonitorServer

TARGETS		= $(SERVER)

OBJS		= RTAMonitor.o

COBJS		=

SOBJS		= RTAMonitorI.o RTAMonitorServer.o

SRCS		= $(OBJS:.o=.cpp) \
		  $(COBJS:.o=.cpp) \
		  $(SOBJS:.o=.cpp)

SLICE_SRCS	= RTAMonitor.ice

include $(top_srcdir)/config/Make.rules

CPPFLAGS	:= -I. $(CPPFLAGS)

$(CLIENT): $(OBJS) $(COBJS)
	rm -f $@
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(COBJS) $(LIBS)

$(SERVER): $(OBJS) $(SOBJS)
	rm -f $@
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(SOBJS) $(LIBS)

install:
	test -d $(bindir) || mkdir -p $(bindir)
	cp -pf RTAMonitor.py $(bindir)
	cp -pf RTAMonitorQt.py $(bindir)
	cp -pf Gui.py $(bindir)
	cp -pf RTAMonitorServer $(bindir)
	test -d $(datadir)/monitor || mkdir -p $(datadir)/monitor
	cp -pf config.monitor $(datadir)/monitor
	cp -pf RTAMonitor.ice $(datadir)/monitor
	cp -pf RTACommand.ice $(datadir)/monitor

include .depend
