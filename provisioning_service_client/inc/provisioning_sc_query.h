// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef PROVISIONING_SC_QUERY_H
#define PROVISIONING_SC_QUERY_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "azure_c_shared_utility/umock_c_prod.h"
#include "azure_c_shared_utility/macro_utils.h"
#include "provisioning_sc_models.h"
#include "parson.h"

#define PROVISIONING_QUERY_SPECIFICATION_VERSION_1 (int)1
    
#define PROVISIONING_QUERY_TYPE_VALUES \
    QUERY_INVALID, \
    QUERY_INDIVIDUAL_ENROLLMENT, \
    QUERY_ENROLLMENT_GROUP, \
    QUERY_DEVICE_REGISTRATION_STATE

DEFINE_ENUM(PROVISIONING_QUERY_TYPE, PROVISIONING_QUERY_TYPE_VALUES);

typedef struct PROVISIONING_QUERY_SPECIFICATION_TAG
{
    int version;
    char* query_string;
    size_t* page_size;
} PROVISIONING_QUERY_SPECIFICATION;

typedef struct PROVISIONING_QUERY_RESPONSE_TAG
{
    union {
        INDIVIDUAL_ENROLLMENT_HANDLE* ie;
        ENROLLMENT_GROUP_HANDLE* eg;
        DEVICE_REGISTRATION_STATE_HANDLE* drs;
    } response_arr;
    size_t repsonse_arr_size;
    PROVISIONING_QUERY_TYPE response_arr_type;
} PROVISIONING_QUERY_RESPONSE;

/*---INTERNAL USAGE ONLY---*/
MOCKABLE_FUNCTION(, PROVISIONING_QUERY_TYPE, queryType_stringToEnum, const char*, string);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PROVISIONING_SC_QUERY_H */
