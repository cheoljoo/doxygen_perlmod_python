#ifndef _CONFIG_MGR_DEFINE_
#define _CONFIG_MGR_DEFINE_

/* path for configuration files */
#define USE_ONE_FILE 1
#if USE_ONE_FILE == 1

#define CONFIGMGR_DIR_PATH "/data/config/"
#define CONFIGMGR_FILENAME "ConfigMgrData.xml"
#define CONFIGMGR_FULLPATH CONFIGMGR_DIR_PATH CONFIGMGR_FILENAME

#else //USE_ONE_FILE
#define GENERAL_DATA_DIR_PATH "/to/be/defined/"
#define DEFAULT_PROV_DIR_PATH "/to/be/defined/"
#define PROVISIONING_DIR_PATH "/to/be/defined/"

#define GENERAL_DATA_FILENAME "TBD.xml"
#define DEFAULT_PROV_FILENAME "TBD.xml"
#define PROVISIONING_FILENAME "TBD.xml"

#define GENERAL_DATA_FULLPATH GENERAL_DATA_DIR_PATH GENERAL_DATA_FILENAME
#define DEFAULT_PROV_FULLPATH DEFAULT_PROV_DIR_PATH DEFAULT_PROV_FILENAME
#define PROVISIONING_FULLPATH PROVISIONING_DIR_PATH PROVISIONING_FILENAME

#endif //USE_ONE_FILE

#define PRINT_ALL 0
#if PRINT_ALL == 0
#define CFG_LOG_I(fmt, args...) {}
#elif PRINT_ALL == 1
#define CFG_LOG_I(fmt, args...) {LOGI("%s " fmt, __FUNCTION__, ##args);}
#else
#define CFG_LOG_I(fmt, args...) {}
#endif

#endif //_CONFIG_MGR_DEFINE_
