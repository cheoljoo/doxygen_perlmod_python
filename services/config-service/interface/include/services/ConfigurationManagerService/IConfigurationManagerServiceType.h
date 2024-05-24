#ifndef _ICONFIGURATION_MANAGER_SERVICE_TYPE_H_
#define _ICONFIGURATION_MANAGER_SERVICE_TYPE_H_

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <forward_list>
#include <cstdint>
#include <tuple>
#include <stdexcept>
#include <type_traits>

#include "json.hpp"

#define CONFIGURATION_SRV_NAME "service_layer.ConfigurationManagerService"



/**
 * @defgroup ConfigParam Parameters
 * @ingroup CONFIGMGR
 * @brief ConfigManager arguments and return value description.
 * @note Refer the "IConfigurationManagerServiceType.h"
 */

/**
 * To get value from ConfigManager, getData( ) would be called. \n
 * ConfigResponse is return structure of getData( ).
 * Before accessing the value, caller shall check the result first.
 * @ingroup CONFIGMGR
 */

/**
* @ingroup ConfigParam
*/
enum class DataFrom {
    /** Data from General purpose*/
    General = 0,
    /** Data from Vehicle Processor*/
    Coding  = 0,
    /** Data from Default Access Set */
    DefaultProvData = 1,
    Das = 1,
    /** Data from Provisioning*/
    ProvisionedData = 2,
    Provisioning = 2,
    /** Data from Default DB */
    ProvisioningData = 3,
    Default = 3,
    /** Data storage not defined */
    DataMax,

    /** JSON data */
    JSON
};

/**
* @ingroup ConfigParam
*/
enum class ConfigResult {
    /** Success */
    NoError,
    /** Data object(DB) is not exist */
    ObjectError,
    /** Data(item) is not exist */
    DataNotFound,
    /** ConfigManager is busy or not ready now. Try again.*/
    Busy,
    /** Unknown error*/
    ResultMax
};

/**
 * @ingroup ConfigParam
*/
struct dbStatus {
    /** General purpose result 1 */
    int32_t rst1;
    /** General purpose result 2 */
    int32_t rst2;
    /** General purpose result 3 */
    int32_t rst3;
    /** General purpose result string */
    std::map<std::string, std::string> data;
};

/**
 * @ingroup ConfigParam
*/
enum class Reload {
    /** Init (no condition)*/
    Init = 0,
    /** DiagJob-file injected */
    Diag,
    /** new Ota file injected */
    Ota,
    /** HMI interface triggered */
    Hmi,
    /** Diag Reset message received */
    Reset,
    /** RSU message received */
    Rsu,
    /** Max */
    ReasonMax
};

/**
 * @ingroup ConfigParam
*/
enum class Query {
    /** Response for Diagnostic message */
    Diag = 0,
    /** Response for Syntax check message */
    Syntax,
    /** Response for scheme check message */
    Scheme,
    /** Response for Meta data query message */
    Meta,
    /** Max */
    QueryMax,
};

/**
 * @ingroup ConfigParam
*/
enum class Mno {
    /** SIM id 1 */
    SIM1 = 0,
    /** SIM id 2 */
    SIM2,
    /** Network 1 */
    NW1,
    /** Network 2 */
    NW2,
    /** Max */
    MnoMax,
};



#ifndef DOXYGEN_SHOULD_SKIP_THIS
using attribute_type = std::vector<std::pair<std::string, std::string>>;

struct FILTER_TYPE {
    std::string type;
    std::vector<std::string> smcc;
    std::vector<std::string> smnc;
    std::vector<std::string> nmcc;
    std::vector<std::string> nmnc;
    std::vector<std::string> country;
    std::vector<std::string> hmilanguage;
};

struct ELEMENT_TYPE {
    std::string name;
    std::map<std::string, std::string> data;
};

struct FILTER_ELEMENT_TYPE {
    FILTER_TYPE filter;
    std::map<std::string, ELEMENT_TYPE> set_element;
};

#endif

struct ConfigDataSet {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    std::vector<std::pair<std::string, std::string>> setDataList;
#endif

    void addKey(std::string key) {
        std::string value = std::string();
        setDataList.push_back(std::pair<std::string,std::string>(key, value));
    }

    void addKeyToParent(std::string key, std::string parent) {
        std::string value = std::string();
        setDataList.push_back(std::pair<std::string,std::string>(getKeyWithParent(key, parent), value));
    }

    std::string getKeyWithParent(std::string key, std::string parent) {
        std::string returnKey(parent + ">" + key);
        return returnKey;
    }

    std::string getKeyWithID(std::string key, std::string ID) {
        std::string returnKey(key + "<" + ID);
        return returnKey;
    }

    void addKeyWithValue(std::string key, std::string value) {
        setDataList.push_back(std::pair<std::string,std::string>(key, value));
    }

    void addKeyWithValueToParent(std::string key, std::string value, std::string parent) {
        setDataList.push_back(std::pair<std::string,std::string>(getKeyWithParent(key, parent), value));
    }
};

struct ConfigResponse {
    ConfigResult result;
    std::string name;
    DataFrom sourceType;
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    std::map<std::string, std::string> data;
#endif
    nlohmann::json mJsonData;

    std::string getKeyWithID(std::string key, std::string ID) {
        std::string returnKey(key + "<" + ID);
        return returnKey;
    }

    std::string getStringFromDataFrom(DataFrom configSourceType) {
        std::string stringSource;
        if(DataFrom::General == configSourceType) {
            stringSource = "General";
        } else if(DataFrom::DefaultProvData == configSourceType) {
            stringSource = "DefaultProvData";
        } else if(DataFrom::ProvisionedData == configSourceType) {
            stringSource = "ProvisionedData";
        } else if(DataFrom::ProvisioningData == configSourceType) {
            stringSource = "ProvisioningData";
        }
        return stringSource;
    }

    /*
     * It returns attribute of app or value of General parameter.
     * @retval  std::string
     * @note refer getData( ) example
     */
    std::string read() {
        return data[""];
    }

    /*
     * It returns attribute or value  of items.
     * @param[in] item name
     * @retval  std::string
     * @note refer getData( ) example
     */

    std::string read(std::string&& n) {
        return data[n];
    }

    /*
     * It returns attribute or value  of items.
     * @param[in] item name
     * @retval  std::string
     * @note refer getData( ) example
     */

    std::string read(std::string&& n, std::string&& nn) {
        return data[n + ">" + nn];
    }

    /*
     * It returns value of items.
     * @param[in] item name
     * @retval  std::string
     * @note refer getData( ) example
     */
    std::string read(std::string&& n, std::string&& nn, std::string&& nnn) {
        return data[n + ">" + nn + ">" + nnn];
    }

    /*
     * It returns value of items.
     * @param[in] item name
     * @retval  std::string
     * @note refer getData( ) example
     */
    std::string read(std::string&& n, std::string&& nn, std::string&& nnn, std::string&& nnnn) {
        return data[n + ">" + nn + ">" + nnn + ">" + nnnn];
    }
};

typedef ConfigResponse ProvisioningResponse;


/**
 * \b config namespace contains structures and functions which was deliberately chosen to operate
 * upon JSON data.
 */
namespace config
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS

using std::enable_if;
using std::tuple;
using std::tuple_size;
using std::is_same;

#endif


using json = nlohmann::json;


/**
 * @brief The \b data_t class defines \e generic type for configuration data. Basically, it provides
 * some conversion functions so object of this type can be implicitly or explicitly convertible to a
 * library object (the one that is responsible for actual data handling). It's because wrapper interface
 * provides APIs to read/write library object (so users can manipulate data the way libraries support)
 * and just in case someone decides that multiple data formats support is a \b must for project, then
 * programmers only need to implement corresponding conversion functions, avoid modifying wrapper interface
 * that was intended to be generic in the first place.
 */
class data_t
{
public:
    operator json&()
    {
        return data;
    }

    operator const json&() const
    {
        return data;
    }

    json& to_json()
    {
        return data;
    }

    const json& to_json() const
    {
        return data;
    }

    /**
     * @note: Conversion functions for other types (if needed) can be defined below.
     */

private:
    json data;
};


#ifndef DOXYGEN_SHOULD_SKIP_THIS

struct json_functor
{
    template<typename T>
    T& operator()(T& t)
    {
        return t;
    }
};

template<size_t Index = 0, typename FuncT, typename... Tp>
inline typename enable_if<Index == sizeof...(Tp), void>::type
serialize(int, tuple<Tp...>&, FuncT, json::iterator) {}


template<size_t Index = 0, typename FuncT, typename... Tp>
inline typename enable_if<Index < sizeof...(Tp), void>::type
serialize(int index, tuple<Tp...> &t, FuncT f, json::iterator it)
{
    if (index == 0) f(std::get<Index>(t)) = it.value();

    serialize<Index + 1, FuncT, Tp...>(index-1, t, f, it);
}

#endif  // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @brief Convert JSON object to \b std::tuple
 * @param json_object A JSON object. It can be the result of a reading operation, provided by Config
 * Manager's \b read API.
 * @param data Of type \b std::tuple, the result of conversion from JSON library object to standard
 * programming language data type.
 * @note JSON standard defines object as "an unordered collection of zero or more name/value pairs".
 * The library <a href="https://github.com/nlohmann/json">nlohmann</a> default behavior does not
 * preserve the insertion order of object elements, it uses \b std::map to store JSON objects, and
 * thus stores object keys sorted alphabetically.
 * I suppose that if any chance you use this utility function, then by manually define a \b std::tuple
 * variable, it should not take you too long to type (i.e. just couple of fields), and you are also
 * aware of them in configuration file (their names), so you know their alphabetical order at first
 * glance. Therefore, please declare your \b std::tuple with template typenames with respect to the
 * order of name fields of that JSON object. I am sorry for this inconvenience.
 * <pre>
 * As an example, suppose we have a JSON object like this:
 * <em>
 * "object": {
 *      "ivalue": 1,
 *      "svalue": "foo",
 *      "bvalue": true
 * }
 * </em>
 * Then your \b std::tuple declaration should look like this:
 * <b>std::tuple<bool, int64_t, string> data</b>
 * before passing into conversion function. That is because after parsing, \e bvalue will come \b
 * before \e ivalue, which in turn will come \b before \e svalue.
 * </pre>
 */
template <typename... Ts>
void convert(json &json_object, tuple<Ts...> &data)
{
    if (tuple_size<tuple<Ts...>>::value != json_object.size())
        throw std::domain_error("Size mismatch");

    size_t i = 0;
    for (json::iterator it = json_object.begin(); it != json_object.end(); ++it)
    {
        serialize(i++, data, json_functor(), it);
    }
}


/**
 * @brief Check whether or not a type is supported by Config Manager's APIs.
 * @return \b true if type is supported, \b false otherwise.
 */
template <typename T>
inline constexpr bool is_type_supported()
{
    return is_same<T, data_t>::value                ||
           is_same<T, bool>::value                  ||
           is_same<T, int64_t>::value               ||
           is_same<T, double>::value                ||
           is_same<T, std::string>::value           ||
           is_same<T, std::vector<bool>>::value     ||
           is_same<T, std::vector<int64_t>>::value  ||
           is_same<T, std::vector<double>>::value   ||
           is_same<T, std::vector<std::string>>::value;
}


} // end of namespace config


#endif
