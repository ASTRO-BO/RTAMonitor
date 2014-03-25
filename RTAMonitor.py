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

class MonitorI(HasTraits, CTA.RTAMonitor):

    simDelay = Range(0.0, 2000.0)
    simRate = String("0 MB/s")
    receiverRate = String("0 MB/s")

    traits_view = View(Item(name='simDelay', style='simple'),
                       Item(name='simRate', style='readonly'),
                       Item(name='receiverRate', style='readonly'),
                       resizable=True,
                       title='RTA Sleep',
                       width=500, height=200)

    def __init__(self, ic):
        HasTraits.__init__(self)
        CTA.RTAMonitor.__init__(self)
        self.ic = ic
        self.command = 0

    def _simDelay_changed(self):
        if self.command != 0:
            self.command.setSimDelay(self.simDelay)

    def sendParameter(self, param, current=None):
#        print "apid:", param.apid, "type:", param.type, "time:", param.timestamp, "rate:", param.value, "MB/s"
        if param.type == 0:
            if param.apid == 200:
                self.simRate = str(param.value)+" MB/s"
            if param.apid == 201:
                self.receiverRate = str(param.value)+" MB/s"

    def sendLog(self, msg, current=None):
        print(msg.apid, msg.timestamp, msg.value)

    def registerApp(self, apid, current=None):
        if apid == 200:
            print "RTAEBSim registered."
            self.command = CTA.RTACommandPrx.checkedCast(self.ic.propertyToProxy('RTAEBSimCommand.Proxy')).ice_oneway()

class Monitor(Ice.Application):
    def run(self, args):
        if len(args) > 1:
            print(self.appName() + ": too many arguments")
            return 1

		# Activate RTAMonitor adapter
        ic = self.communicator()
        adapter = ic.createObjectAdapter("RTAMonitor")
        servant = MonitorI(ic)
        adapter.add(servant, ic.stringToIdentity("monitor"))
        adapter.activate()

        servant.configure_traits()
        return 0

if __name__ == "__main__":
    monitor = Monitor()
    sys.exit(monitor.main(sys.argv, "config.monitor"))
