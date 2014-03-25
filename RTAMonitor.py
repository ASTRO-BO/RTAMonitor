#!/usr/bin/env python

############################################################################
#    begin                : Mar 25 2014
#    copyright            : (C) 2014 Andrea Zoli
#    email                : zoli@iasfbo.inaf.it
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

command = 0

class MonitorI(CTA.RTAMonitor):
    def __init__(self, ic):
        CTA.RTAMonitor.__init__(self)
        self.ic = ic

    def sendParameter(self, param, current=None):
        print("Received a Parameter")
        if param.type == 0:
            print "apid:", param.apid, "time:", param.timestamp, "rate:", param.value, "MB/s"

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

		# Activate RTAMonitor adapter
        ic = self.communicator()
        adapter = ic.createObjectAdapter("RTAMonitor")
        adapter.add(MonitorI(ic), ic.stringToIdentity("monitor"))
        adapter.activate()

        ic.waitForShutdown()
        return 0

if __name__ == "__main__":
    monitor = Monitor()
    sys.exit(monitor.main(sys.argv, "config.monitor"))
