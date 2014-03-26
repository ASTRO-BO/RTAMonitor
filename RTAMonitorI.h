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

#ifndef _RTAMONITOR_I_H
#define _RTAMONITOR_I_H

#include "RTAMonitor.h"

class RTAMonitorI : public CTA::RTAMonitor
{
public:

	RTAMonitorI(std::map<int, std::vector<CTA::Parameter> >& parameters, 
                std::map<int, std::vector<CTA::LogMessage> >& logs)
		: _parameters(parameters), _logs(logs)
	{
	}
	virtual void sendParameter(const CTA::Parameter& param, const Ice::Current& cur);
	virtual void sendLog(const CTA::LogMessage& msg, const Ice::Current& cur);

	virtual void registerApp(int apid, const Ice::Current& cur);

private:

	std::map<int, std::vector<CTA::Parameter> >& _parameters;
	std::map<int, std::vector<CTA::LogMessage> >& _logs;

};

#endif
