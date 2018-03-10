// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>

#include "azure_c_shared_utility/platform.h"

#include "provisioning_service_client.h"

int main()
{
    int result = 0;

    const char* connectionString = "[Connection String]";

    /* ---This function must be called before anything else so that sockets work--- */
    platform_init();

    /* ---Create a handle for accessing the Provisioning Service--- */
    PROVISIONING_SERVICE_CLIENT_HANDLE prov_sc = prov_sc_create_from_connection_string(connectionString);
    
    /* ---Optionally set connection options---*/
    prov_sc_set_trace(prov_sc, TRACING_STATUS_ON);

    PROVISIONING_QUERY_SPECIFICATION query_spec;
    query_spec.page_size = NULL;
    query_spec.query_string = "*";
    query_spec.version = PROVISIONING_QUERY_SPECIFICATION_VERSION_1;

    PROVISIONING_QUERY_RESPONSE* query_resp;

    char* cont_token = NULL;

    //int res = prov_sc_query_enrollment_group(prov_sc, &query_spec, &cont_token, &query_resp);
    int res = prov_sc_query_individual_enrollment(prov_sc, &query_spec, &cont_token, &query_resp);
    res = res;

    /* ---Destroy the provisioning service client handle--- */
    prov_sc_destroy(prov_sc);

    return result;
}
