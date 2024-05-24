#ifndef _XML_FILE_LIB_
#define _XML_FILE_LIB_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "Log.h"
#include "Error.h"
#include <utils/RefBase.h>
#include <services/ConfigurationManagerService/IConfigurationManagerServiceType.h>

#define TOTAL_DEPTH 7
#define PARSER_LOG 0
#define SAVE_XML_HDEADER 1

#define XML_HEADER_STRING "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n"

class XmlFileLib : public android::RefBase {
public:
    XmlFileLib();
    XmlFileLib(std::string xmlObjName);
    virtual ~XmlFileLib();
    void readXmlFile(std::string fileName);
    void saveXmlFile(std::string fileName);
    ConfigResult getXmlValueSingle(std::string dataName, std::string& dataValue);
    error_t setXmlValueSingle(std::string dataName, std::string dataValue);
    ConfigResponse getXmlValueSet(std::string dataName);
    error_t setXmlValueSet(std::string dataName, std::string dataValue);
    std::string makeNewDataName(std::string dataName, std::string dataKey);
    error_t addFromExternal(std::string dataName, std::string dataValue);

public :
    enum EFileStatus {
        E_FILE_OK,
        E_NO_FILE,
        E_FILE_BUSY,
        E_PARSE_ERROR,
        E_FILE_STATUS_MAX
    };

private :
    enum EcurrentReadState {
        XML_INIT,                 //should be followed by below
        XML_OPEN,                 //should be followed by below
        XML_OPEN_HEADER,          //should be followed by below
        XML_HEADER_NAME,          //start adding to temp name

        HEADER_IN_NAME_SPACE,     //add one depth if from above, remove temp name
        HEADER_IN_NAME_NAME,      //start adding to temp name
        HEADER_IN_NAME_EQUALS,    //should be followed by below
        HEADER_IN_NAME_OPEN,      //should be followed by below
        HEADER_IN_NAME_VALUE,     //start adding to temp value
        HEADER_IN_NAME_CLOSE,     //add one temporary depth, remove temp name and value

        XML_CLOSE_HEADER,         //should be followed by below
        XML_CLOSE,                //remove one depth

        XML_START_DATA_OPEN,      //should be follwed by below
        XML_START_DATA_NAME,      //start adding to temp name

        DATA_IN_NAME_SPACE,       //add one depth if from above, remove temp name
        DATA_IN_NAME_NAME,        //start adding to temp name
        DATA_IN_NAME_EQUALS,      //should be followed by below
        DATA_IN_NAME_OPEN,        //should be followed by below
        DATA_IN_NAME_VALUE,       //start adding to temp value
        DATA_IN_NAME_CLOSE,       //add one temporary depth, remove temp name and value

        XML_START_DATA_END,       //should be followed by XML_END_DATA_CLOSE

        XML_START_DATA_CLOSE,     //should be followed by below
        OUT_NAME_VALUE,           //start adding to temp value

        XML_END_DATA_OPEN,        //should be followed by below
        XML_END_DATA_NAME,        //start adding to temp name
        XML_END_DATA_CLOSE,       //add temp value, and remove one depth

        XML_ERROR,                //parsing error
        XML_NONE                  //none
    };

    enum EXMLKeyState {
        XML_KEY_STATE_START,
        XML_KEY_STATE_END,
        XML_KEY_STATE_NULL,
        XML_KEY_STATE_MAX
    };

#if PARSER_LOG == 1
    const char stateFlagText[XML_NONE][32] = {
        "XML_INIT",
        "XML_OPEN",
        "XML_OPEN_HEADER",
        "XML_HEADER_NAME",

        "HEADER_IN_NAME_SPACE",
        "HEADER_IN_NAME_NAME",
        "HEADER_IN_NAME_EQUALS",
        "HEADER_IN_NAME_OPEN",
        "HEADER_IN_NAME_VALUE",
        "HEADER_IN_NAME_CLOSE",

        "XML_CLOSE_HEADER",
        "XML_CLOSE",

        "XML_START_DATA_OPEN",
        "XML_START_DATA_NAME",

        "DATA_IN_NAME_SPACE",
        "DATA_IN_NAME_NAME",
        "DATA_IN_NAME_EQUALS",
        "DATA_IN_NAME_OPEN",
        "DATA_IN_NAME_VALUE",
        "DATA_IN_NAME_CLOSE",

        "XML_START_DATA_END",

        "XML_START_DATA_CLOSE",
        "OUT_NAME_VALUE",

        "XML_END_DATA_OPEN",
        "XML_END_DATA_NAME",
        "XML_END_DATA_CLOSE",

        "XML_ERROR"
    };
#endif //PARSER_LOG == 1

public:
    std::string getXmlFilePath();
    std::string getXmlFileName();
    EFileStatus getXmlFileStatus();
    bool isValueAvailable(std::string name);

private:
    bool checkNormalChar(char c);
    void printXmlValue(void);
    error_t addChild(std::string dataName, std::string dataChildKey);
    error_t addChildElement(std::string dataName, std::string dataChildKey, std::string dataChildValue);
    std::string makeXMLKeyString(std::string dataLoc, std::string dataName, EXMLKeyState XMLKeyState);
    std::string makeXMLKeyId(std::string dataName, EXMLKeyState XMLKeyState);

    std::unordered_map<std::string, std::string>* XmlData;
    std::unordered_map<std::string, std::string>* XmlAttr;
    std::map<std::string, std::vector<std::string>>* XmlChildList;
    std::string objName;
    std::string objPath;
    EFileStatus xmlFileStatus;
};


#endif // _XML_FILE_LIB_