/***************************************************************************
    begin                : Mar 13 2014
    copyright            : (C) 2014 Andrea Zoli
    email                : zoli@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   and for public research institutes; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#include "RTAMonitorI.h"
#include <iostream>

using namespace CTA;

void RTAMonitorI::sendParameter(const Parameter& param, const Ice::Current& cur)
{
	_parameters[param.apid].push_back(param);
	std::cout << param.apid << " " << param.timestamp << " " << param.type << " " << param.value << std::endl;
}

void RTAMonitorI::sendLog(const LogMessage& msg, const Ice::Current& cur)
{
	_logs[msg.apid].push_back(msg);
	std::cout << msg.apid << " " << msg.timestamp << " " << msg.value << std::endl;
}
