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

from PyQt4.QtGui import QApplication, QDialog
from PyQt4 import QtCore
from Gui import Ui_Monitor

import sys, traceback, time, Ice

Ice.loadSlice('RTAMonitor.ice')
Ice.loadSlice('RTACommand.ice')
Ice.updateModules()
import CTA

class MonitorI(CTA.RTAMonitor, Ui_Monitor):
    simRate = 0.0
    receiverRate = 0.0

    def __init__(self, ic):
        CTA.RTAMonitor.__init__(self)
        self.ic = ic
        self.command = 0

    def sendParameter(self, param, current=None):
#        print "apid:", param.apid, "type:", param.type, "time:", param.timestamp, "rate:", param.value, "MB/s"
        if param.type == 0:
            if param.apid == 200:
                self.label_6.setText(str(int(param.value)))
            if param.apid == 201:
                self.label_9.setText(str(int(param.value)))

    def sendLog(self, msg, current=None):
        print(msg.apid, msg.timestamp, msg.value)

    def registerApp(self, apid, current=None):
        if apid == 200:
            print "RTAEBSim registered."
            self.command = CTA.RTACommandPrx.checkedCast(self.ic.propertyToProxy('RTAEBSimCommand.Proxy')).ice_oneway()

    def setupUi(self, Monitor):
        Ui_Monitor.setupUi(self, Monitor)
        QtCore.QObject.connect(self.horizontalSlider, QtCore.SIGNAL("valueChanged(int)"), self.updateLabel)
        QtCore.QObject.connect(self.lineEdit, QtCore.SIGNAL("textEdited(const QString&)"), self.updateSlider)

        self.horizontalSlider.setMinimum(0)
        self.horizontalSlider.setMaximum(3000)

    def updateSlider(self, val):
        self.horizontalSlider.setValue(int(val))
        if self.command != 0:
            self.command.setSimDelay(int(val))

    def updateLabel(self, val):
        self.lineEdit.setText(str(val))
        if self.command != 0:
            self.command.setSimDelay(val)

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

        app = QApplication(sys.argv)
        window = QDialog()
        servant.setupUi(window)

        window.show()
        sys.exit(app.exec_())

if __name__ == "__main__":
    monitor = Monitor()
    sys.exit(monitor.main(sys.argv, "config.monitor"))
