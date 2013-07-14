// See the file COPYRIGHT.txt for authors and copyright information.
// See the file LICENSE.txt for copying conditions.

#include <iostream>
#include <SFML/Network.hpp>
#include "network.h"
#include "packet.h"

using namespace std;

const unsigned short Network::defaultPort = 1337;

Network::Network() : udpThread(&Network::receiveUdp, this),
                     tcpThread(&Network::receiveTcp, this)
{
    udpSock.setBlocking(true);
    udpSock.bind(defaultPort);
    threadsRunning = false;
}

Network::~Network()
{
    cout << "Network class destructor called.\n";
    udpSock.setBlocking(false);
    udpSock.unbind();
    cout << "UDP Socket was unbound.\n";
    stopThreads();
}

void Network::launchThreads()
{
    if (!threadsRunning)
    {
        udpThread.launch();
        tcpThread.launch();
        threadsRunning = true;
    }
}

void Network::stopThreads()
{
    cout << "stopThreads(): Terminating threads now...\n";
    udpThread.terminate();
    tcpThread.terminate();
    threadsRunning = false;
}
