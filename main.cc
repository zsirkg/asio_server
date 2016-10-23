#include "server.h"

int main()
{
    Server echo_server(1025);
    echo_server.Start();

    return 0;
}
