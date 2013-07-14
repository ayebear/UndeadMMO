// See the file COPYRIGHT.txt for authors and copyright information.
// See the file LICENSE.txt for copying conditions.

#ifndef PACKET_H
#define PACKET_H

namespace Packet
{
    // This is sent with the login packet
    const int ProtocolVersion = 2;

    // This type is sent with every packet so the code that receives it can determine how to process it
    // Please refer to the documentation for more information about these types
    enum Type
    {
        // Client/server needs to receive these
        LoginStatus = 1, // Sent from the server to tell the client if the login was successful
        ChatMessage, // Includes private/public/server messages
        EntityUpdate,
        MapData, // All of the logical tiles for the map; is automatically sent from the server on successful login
        MultiPacket,

        PacketTypes, // For the client

        // Server only needs to receive these
        Input,
        LogIn,
        LogOut,
        CreateAccount,
        GetPlayerList,
        GetServerInfo,

        TotalPacketTypes // For the server
    };

    // Sub-types
    namespace Login
    {
        enum Type
        {
            Successful = 1,
            InvalidUsername,
            InvalidPassword,
            AccountBanned,
            AlreadyLoggedIn,
            ProtocolVersionMismatch,
            Timeout,
            ErrorConnecting,
            UnknownFailure
        };
    }
    namespace Chat
    {
        enum Type
        {
            Public = 1,
            Server,
            Private
        };
    }
}

#endif
