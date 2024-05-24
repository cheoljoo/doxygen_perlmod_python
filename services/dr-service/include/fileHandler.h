
#ifndef _FILE_HANDLER_H_
#define _FILE_HANDLER_H_

#include <Typedef.h>
#include <fstream>
#include <utils/RefBase.h>

using namespace std;
using namespace android;

const string NVRAM_PATH ="/var/lib/nvram";
const string HIPPO_ENABLE="/data/hippo_log_mode.cfg";
const string HIPPO_PATH = "/var/log/hippo.log";

class FileHandler : public RefBase
{
public:

    FileHandler(string fileName) : mFileName(fileName){}
    ~FileHandler(){}

    void setFileName(string& fileName){
        mFileName = fileName;
    }

    bool read(char* data,size_t size);
    bool write(const char* data,size_t size);
    bool append(const char* data,size_t input_size,size_t available_size);
    bool isAvailable(size_t input_size, size_t available_size);
    bool fileExist();

private:
    string mFileName;

};

#endif //_FILE_HANDLER_H_

