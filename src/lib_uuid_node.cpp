#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sole.hpp"

#include "lib_uuid_node.hpp"

#include <thread>
#include <string>
#include <mutex>

uuid_msgs::UniqueID libuuid::create_uuid()
{
    uuid_msgs::UniqueID out;

    sole::uuid u = sole::uuid0();

    for( int i = 0; i < 8; i++ )
    {
        out.uuid[i] = u.ab >> (i*8);
    }

    for( int i = 0; i < 8; i++ )
    {
        out.uuid[i+8] = u.cd >> (i*8);
    }

    return out;
}
