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

class MonitorI(CTA.RTAMonitor):
    def sendParameter(self, param, current=None):
        print("Received a Parameter")
        if param.type == 0:
            print "apid:", param.apid, "time:", param.timestamp, "rate:", param.value, "MB/s"

    def sendLog(self, msg, current=None):
        print(msg.apid, msg.timestamp, msg.value)

class Monitor(Ice.Application):
    def run(self, args):
        if len(args) > 1:
            print(self.appName() + ": too many arguments")
            return 1

        adapter = self.communicator().createObjectAdapter("RTAMonitor")
        adapter.add(MonitorI(), self.communicator().stringToIdentity("monitor"))
        adapter.activate()
        self.communicator().waitForShutdown()
        return 0

if __name__ == "__main__":
    monitor = Monitor()
    sys.exit(monitor.main(sys.argv, "config.monitor"))
