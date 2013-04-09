/*
 * Copyright 2013 Tieto Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_INCLUDE_BT_TEST_SDP_H
#define ANDROID_INCLUDE_BT_TEST_SDP_H

__BEGIN_DECLS

struct sdp_test_record_attribute {
    unsigned int id;
    unsigned int type;
    unsigned int size;
    unsigned int value_offset;
};

struct sdp_test_record {
    unsigned int attributes_num;
    unsigned int attribute_offset;
};

struct sdp_test_records {
    unsigned int           size;
    unsigned int           records_num;
    struct sdp_test_record record[0];
};

union btt_msg_cmd_sdp_print_remote_records_data {
    uint32_t record_handle;
    uint16_t uuid;
};

typedef struct _sdp_test_interface_t {
    uint32_t  (*get_number_of_records)();
    uint32_t  (*get_max_number_of_records)();
    uint32_t  (*create_record)();
    uint32_t  (*delete_record)(unsigned int handle);
    uint8_t  *(*get_records)();
    uint8_t  *(*get_remote_records)(uint8_t bd_addr[6], uint8_t type, union btt_msg_cmd_sdp_print_remote_records_data data);
    int32_t   (*add_rfcomm_record)(const char* name, const uint8_t *uuid, int scn);
    uint32_t  (*add_attribute)(uint32_t handle, uint16_t attribute_id,
            uint8_t attribute_type, uint32_t attribute_length,
            uint8_t *attribute_value);
    uint32_t  (*delete_attribute)(uint32_t handle, uint16_t attribute_id);
    uint8_t   (*trace_level)(uint8_t level);
    uint32_t  (*connect)(uint8_t bd_addr[6]);
    uint32_t  (*disconnect)(uint32_t handle);
    uint32_t  (*send)(uint32_t handle, uint32_t length, uint8_t *data);
} sdp_test_interface_t;

__END_DECLS

#endif /*ANDROID_INCLUDE_BT_TEST_SDP_H*/
