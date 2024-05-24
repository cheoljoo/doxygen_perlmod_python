
#ifndef _PPS_TIME_H_
#define _PPS_TIME_H_

#include <Typedef.h>

using namespace std;

class PPSTimeHandler
{
public:
    static PPSTimeHandler* getInstance();
    ~PPSTimeHandler();
    uint32_t getPPSTime();

private:
    PPSTimeHandler();

    bool init();
    bool isReady();

    bool mInit;
    uint32_t mPPSTime;
};

#endif //_PPS_TIME_H_

