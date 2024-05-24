/**
 * @copyright
 * Copyright (c) 2015 by LG Electronics Inc.
 * This program or software including the accompanying associated documentation
 * ("Software") is the proprietary software of LG Electronics Inc. and or its
 * licensors, and may only be used, duplicated, modified or distributed pursuant
 * to the terms and conditions of a separate written license agreement between you
 * and LG Electronics Inc. ("Authorized License"). Except as set forth in an
 * Authorized License, LG Electronics Inc. grants no license (express or implied),
 * rights to use, or waiver of any kind with respect to the Software, and LG
 * Electronics Inc. expressly reserves all rights in and to the Software and all
 * intellectual property therein. If you have no Authorized License, then you have
 * no rights to use the Software in any ways, and should immediately notify LG
 * Electronics Inc. and discontinue all use of the Software.
 *
 * @file
 * ConfigManagerProperty.h @n
 * Declaration of ConfigManagerProperty
 * @author
 *
 * @date
 * 2019.01.09
 */


#ifndef CONFIG_PROPERTY_H
#define CONFIG_PROPERTY_H

namespace configprop
{
static constexpr char* PROPERTY_NMCC = (char*)"cm.prop.nmcc";
static constexpr char* PROPERTY_NMNC = (char*)"cm.prop.nmnc";
static constexpr char* PROPERTY_SMCC = (char*)"cm.prop.smcc";
static constexpr char* PROPERTY_SMNC = (char*)"cm.prop.smnc";
static constexpr char* PROPERTY_DB_PATH = (char*)"cm.prop.db_path";
static constexpr char* PROPERTY_DB_SRC = (char*)"cm.prop.db_source";
} // namespace of configprop
#endif //CONFIG_PROPERTY_H
