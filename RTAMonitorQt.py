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

import sys
from PyQt4.QtGui import QApplication, QDialog
from Gui import Ui_Monitor

app = QApplication(sys.argv)
window = QDialog()
ui = Ui_Monitor()
ui.setupUi(window)

window.show()
sys.exit(app.exec_())
