#ifndef _DB_BASE_VARIANT_
#define _DB_BASE_VARIANT_

/* List of Data to use Default data */
#define ListStringMaxLength 32
#define DefaultProvisioningPrioritySize 1

char DefaultProvisioningPriorityList[DefaultProvisioningPrioritySize][ListStringMaxLength] = {
    "none"
};

#include <string>
#include <vector>


std::vector<std::string> xmlParsePath = {};
std::vector<std::string> xmlParsePathWithSignature = {"signed"};
std::vector<std::string> xmlParseDataPath = {"set", "data"};
std::vector<std::string> xmlParseDataPathWithSignature = {"signed", "set", "data"};

#endif //_DB_BASE_VARIANT_
