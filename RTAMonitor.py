#!/usr/bin/env python

############################################################################
#    begin                : Mar 25 2014
#    copyright            : (C) 2014 Andrea Zoli, Valentina Fioretti
#    email                : zoli@iasfbo.inaf.it, fioretti@iasfbo.inaf.it
############################################################################

############################################################################
#                                                                          #
#   This program is free software for non commercial purpose               #
#   and for public research institutes; you can redistribute it and/or     #
#   modify it under the terms of the GNU General Public License.           #
#   For commercial purpose see appropriate license terms                   #
#                                                                          #
############################################################################

import sys, traceback, time, Ice

Ice.loadSlice('RTAMonitor.ice')
Ice.loadSlice('RTACommand.ice')
Ice.updateModules()
import CTA

from traits.api \
    import HasTraits, Range, Float, String, on_trait_change, Property
from traitsui.api import View, Item

command = 0

class Gui(HasTraits):

    simDelay = Range(0.0, 2000.0)
    simRate = String("0 MB/s")

    traits_view = View(Item(name='simDelay', style='simple'),
                       Item(name='simRate', style='readonly'),
                       resizable=True,
                       title='RTA Sleep',
                       width=500, height=200)

    def __init__(self):
        HasTraits.__init__(self)

    def _simDelay_changed(self):
        print("c")


class MonitorI(CTA.RTAMonitor):
    def __init__(self, ic, gui):
        CTA.RTAMonitor.__init__(self)
        self.ic = ic
        self.gui = gui

    def sendParameter(self, param, current=None):
        print("Received a Parameter")
        if param.type == 0:
#            print "apid:", param.apid, "time:", param.timestamp, "rate:", param.value, "MB/s"
            if param.apid == 200:
                self.gui.simRate = str(param.value)+" MB/s"

    def sendLog(self, msg, current=None):
        print(msg.apid, msg.timestamp, msg.value)

    def registerApp(self, apid, current=None):
        if apid == 200:
            print "RTAEBSim registered."
            # Get a RTACommand proxy to RTAEBSim
            command = CTA.RTACommandPrx.checkedCast(self.ic.propertyToProxy('RTAEBSimCommand.Proxy')).ice_oneway()

class Monitor(Ice.Application):
    def run(self, args):
        if len(args) > 1:
            print(self.appName() + ": too many arguments")
            return 1

        gui = Gui()

		# Activate RTAMonitor adapter
        ic = self.communicator()
        adapter = ic.createObjectAdapter("RTAMonitor")
        adapter.add(MonitorI(ic, gui), ic.stringToIdentity("monitor"))
        adapter.activate()

        gui.configure_traits()
        return 0

if __name__ == "__main__":
    monitor = Monitor()
    sys.exit(monitor.main(sys.argv, "config.monitor"))
