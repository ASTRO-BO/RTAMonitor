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

#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>
#include "RTAMonitorI.h"

using namespace std;
using namespace CTA;

class RTAMonitorServer : public Ice::Application
{
public:

    virtual int run(int, char*[]);

private:

};

int main(int argc, char* argv[])
{
    RTAMonitorServer app;
    return app.main(argc, argv, "config.monitor");
}

int RTAMonitorServer::run(int argc, char* argv[])
{
	// parameters indexed per-apid
	std::map<int, std::vector<CTA::Parameter> > parameters;

	// log indexed per-apid
	std::map<int, std::vector<CTA::LogMessage> > logs;

	// Create an adapter for RTAMonitor
    Ice::ObjectAdapterPtr adapter = communicator()->createObjectAdapter("RTAMonitor");
    RTAMonitorPtr servant = new RTAMonitorI(parameters, logs);
    adapter->add(servant, communicator()->stringToIdentity("monitor"));
    adapter->activate();

    communicator()->waitForShutdown();

    return EXIT_SUCCESS;
}
