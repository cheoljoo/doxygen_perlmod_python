/**
 * @attention Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved.
 *   This program or software including the accompanying associated documentation ("Software") is
 *   the proprietary software of LG Electronics Inc.  and or its licensors, and may only be used,
 *   duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement
 *   between you and LG Electronics Inc. ("Authorized License").
 *   Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use,
 *   or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in
 *   and to the Software and all intellectual property therein.
 *   If you have no Authorized License, then you have no rights to use the Software in any ways,
 *   and should immediately notify LG Electronics Inc. and discontinue all use of the Software.
 *  @defgroup DRMGR_APIS Dr API list
 *  @ingroup DRMGR
 *
 *  This is the Dr Manager Service. This class includes all native functions.
 *  - APIs ( native codes )
 *
 * @cond UML
 * Basic Process about API using binder
 * @startuml
 *     box "Application (Proxy)"
 *     participant App
 *     participant BpDrManagerService
 *     end box
 *     participant Binder
 *     box "Service (Native)"
 *     participant BnDrManagerService
 *     participant ServiceStub
 *     end box
 *
 *     App -> BpDrManagerService : API(arguments)
 *     BpDrManagerService -> Binder : DrData >> remote()->onTransact(OP_REGISTER_API, Parcel)
 *     Binder -> BnDrManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_API, Parcel >> arguments
 *     BnDrManagerService -> ServiceStub : API(arguments)
 *     activate ServiceStub
 *     BnDrManagerService <- ServiceStub : return E_OK
 *     deactivate ServiceStub
 *     Binder <- BnDrManagerService : reply->writeInt32
 *     BpDrManagerService <- Binder : reply.readInt32()
 *     App <- BpDrManagerService : return
 * @enduml
 * @endcond
 *
 */


#ifndef _SERVICELAYER_DRNOSTIC_MANAGER_SERVICE_H_
#define _SERVICELAYER_DRNOSTIC_MANAGER_SERVICE_H_

#include <map>
#include <list>

#include <Typedef.h>
#include <corebase/SystemService.h>

#include "drEngine.h"


#include "gnssIface.h"
#include "drIface.h"

#include <services/DrManagerService/IdrManagerReceiver.h>
#include <services/DrManagerService/IdrManagerService.h>

/**
 * @brief DrManagerService is class to serive APIs for application and another services.
 *
 * @cond UML
 * Basic Process about API using binder
 * @startuml
 *     box "Application (Proxy)"
 *     participant App
 *     participant BpDrManagerService
 *     end box
 *     participant Binder
 *     box "Service (Native)"
 *     participant BnDrManagerService
 *     participant ServiceStub
 *     end box
 *
 *     App -> BpDrManagerService : API(arguments)
 *     BpDrManagerService -> Binder : DrData >> remote()->onTransact(OP_REGISTER_API, Parcel)
 *     Binder -> BnDrManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_API, Parcel >> arguments
 *     BnDrManagerService -> ServiceStub : API(arguments)
 *     activate ServiceStub
 *     BnDrManagerService <- ServiceStub : return E_OK
 *     deactivate ServiceStub
 *     Binder <- BnDrManagerService : reply->writeInt32
 *     BpDrManagerService <- Binder : reply.readInt32()
 *     App <- BpDrManagerService : return
 * @enduml
 * @endcond
 */
class DrManagerService: public SystemService
{
public:
    DrManagerService();
    virtual ~DrManagerService();

    static const char* getServiceName() { return "service_layer.drManagerService"; }
    virtual uint8_t getModuleID() { return MODULE_LOCATION_MGR; }
    //virtual uint8_t getModuleID() { return DR_MGR; }

    virtual bool onInit();
    virtual void instantiate();
    virtual error_t onStart();
    virtual error_t onStop();
    virtual error_t dump(LogOutput&){ return E_OK; }

    error_t registerReceiver(uint32_t id,const sp<IDrManagerReceiver>& receiver);
    error_t unregisterReceiver(const sp<IDrManagerReceiver>& receiver);

    bool gnssInit(android::sp<IDrManagerReceiver>& locMgr);

    bool gnssStart();
    bool gnssStop();
    bool  gnssXTRAInit();
    bool gnssSetPositionMode(uint32_t mode,uint32_t recurrence,uint32_t min_interval, uint32_t preferred_accuracy, uint32_t preferred_time);
    bool gnssDeleteAidingData(int32_t mask);
    bool gnssInjectTime(int64_t time, int64_t timeReference, int32_t uncertainty);
    bool gnssInjectXtraData(const char* data, int length);
    int  gnssGetGpsStartMode();
    bool gnssSetGnssUsedSystem(int32_t param);
    bool gnssGetGnssUsedSystem(int32_t &status);
    bool gnssSetGnssCn0(int32_t param);
    bool gnssGetGnssCn0(int32_t &status);
    bool gnssCommand(int32_t cmdType, int32_t value, int32_t& resp_value);
    bool setHippoLogging(bool enable);
    void cmdTest_IdrManagerReceiver();

private:
    class ServiceStub: public BnDrManagerService {
    public:
        ServiceStub(DrManagerService& parent) : mParent(parent) {}
        virtual error_t registerReceiver(uint32_t id, const sp<IDrManagerReceiver>& receiver);
        virtual error_t unregisterReceiver(const sp<IDrManagerReceiver>& receiver);

        virtual bool gnssInit(android::sp<IDrManagerReceiver> locMgr);
        //virtual error_t gnssInit();
        virtual bool gnssStart();
        virtual bool gnssStop();
        virtual bool  gnssXTRAInit();
        virtual bool gnssSetPositionMode(uint32_t mode,uint32_t recurrence,uint32_t min_interval, uint32_t preferred_accuracy, uint32_t preferred_time);
        virtual bool gnssDeleteAidingData(int32_t mask);
        virtual bool gnssInjectTime(int64_t time, int64_t timeReference, int32_t uncertainty);
        virtual bool gnssInjectXtraData(const char* data, int length);
        virtual int  gnssGetGpsStartMode();
        virtual bool gnssSetGnssUsedSystem(int32_t param);
        virtual bool gnssGetGnssUsedSystem(int32_t &status);
        virtual bool gnssSetGnssCn0(int32_t param);
        virtual bool gnssGetGnssCn0(int32_t &status);
        virtual bool gnssCommand(int32_t cmdType, int32_t value, int32_t& resp_value);
        virtual bool setHippoLogging(bool enable);
        virtual void cmdTest_IdrManagerReceiver();

    private:
        DrManagerService& mParent;
    };

private:
    sp<DrEngine> mDrEngine;

};

#endif // _SERVICELAYER_DRNOSTIC_MANAGER_SERVICE_H_
