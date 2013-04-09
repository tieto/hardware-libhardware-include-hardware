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

#ifndef ANDROID_INCLUDE_BT_TEST_L2CAP_H
#define ANDROID_INCLUDE_BT_TEST_L2CAP_H

#include <stdbool.h>

__BEGIN_DECLS

typedef enum {
	BT_L2CAP_SUCCESS = 1,
	BT_L2CAP_FAIL = 2
} btl2cap_init_state_t;

/********from l2c_api.h***************/

typedef struct {
	uint8_t id;
	uint8_t stype;
	uint16_t max_sdu_size;
	uint32_t sdu_inter_time;
	uint32_t access_latency;
	uint32_t flush_timeout;
} thci_ext_flow_spec;

typedef struct {
	uint8_t mode;
	uint8_t tx_win_sz;
	uint8_t max_transmit;
	uint16_t rtrans_tout;
	uint16_t mon_tout;
	uint16_t mps;
} tl2cap_fcr_opts;

typedef struct {
	uint8_t qos_flags;
	uint8_t service_type;
	uint32_t token_rate;
	uint32_t token_bucket_size;
	uint32_t peak_bandwidth;
	uint32_t latency;
	uint32_t delay_variation;
} flow_spec;

typedef struct {
	uint16_t result;
	bool mtu_present;
	uint16_t mtu;
	bool qos_present;
	flow_spec qos;
	bool flush_to_present;
	uint16_t flush_to;
	bool fcr_present;
	tl2cap_fcr_opts fcr;
	bool fcs_present;
	uint8_t fcs;
	bool ext_flow_spec_present;
	thci_ext_flow_spec ext_flow_spec;
	uint16_t flags;
} tl2cap_cfg_info_t;

typedef struct {
	uint16_t event;
	uint16_t len;
	uint16_t offset;
	uint16_t layer_specific;
} bt_hdr_t;

/***************************************/

/*Callback types*/
typedef enum {
	/*
	 * val = bt_l2cap_conn_ind_t #0
	 */
	CONN_IND_CB,
	/*
	 * val = bt_l2cap_int_t #1
	 */
	CONN_CFM_CB,
	/*
	 * val = uint16_t #2
	 */
	CONN_PND_CB,
	/*
	 * val = bt_l2cap_cfg_t #3
	 */
	CONF_IND_CB,
	/*
	 * val = bt_l2cap_cfg_t #4
	 */
	CONF_CFM_CB,
	/*
	 * val = bt_l2cap_bool_cb_t #5
	 */
	DISC_IND_CB,
	/*
	 * val = bt_l2cap_int_t #6
	 */
	DISC_CFM_CB,
	/*
	 * val = bt_bdaddr_t* #7
	 */
	QOS_VIOL_IND_CB,
	/*
	 * val = bt_l2cap_data_t #8
	 */
	DATA_IND_CB,
	/*
	 * val = bt_l2cap_bool_cb_t #9
	 */
	CONG_STAT_CB,
	/*
	 * val = bt_l2cap_int_t #10
	 */
	TX_COMPLETE_CB,
	/*
	 * val = uint16_t #11
	 */
	ECHO_RSP
} bt_l2cap_callback_type_t;

typedef struct {
	uint16_t cid;
	bool result;
} bt_l2cap_bool_cb_t;

typedef struct {
	uint16_t cid;
	uint16_t result;
} bt_l2cap_int_t;

typedef struct {
	int cid;
	tl2cap_cfg_info_t *cfg;
} bt_l2cap_cfg_t;

typedef struct {
	uint16_t cid;
	bt_hdr_t *buf;
} bt_l2cap_data_t;

typedef struct {
	bt_bdaddr_t *addr;
	uint16_t cid;
	uint16_t psm;
	uint8_t id;
} bt_l2cap_conn_ind_t;

/*general type passed do handler*/
typedef struct {
	bt_l2cap_callback_type_t type;
	int len;
	void *val;
} bt_l2cap_callback_t;

/*handler in application using this interface. must be passed to register_psm*/
typedef void (*btl2cap_callback_function_t)(bt_l2cap_callback_t *callback_data);

/*handler for ping responses*/
typedef void (*echo_response)(uint16_t result);

typedef struct {
	uint16_t (*register_psm)(int psm, btl2cap_callback_function_t callback);
	void (*deregister_psm)(int psm);
	uint16_t (*allocate_psm)(void);
	uint16_t (*connect_req)(uint16_t psm, bt_bdaddr_t *addr);
	bool (*connect_rsp)(bt_bdaddr_t *addr, uint8_t id,
			uint16_t lcid, uint16_t result, uint16_t status);
	bool (*config_req)(uint16_t cid, tl2cap_cfg_info_t *config);
	bool (*config_rsp)(uint16_t cid, tl2cap_cfg_info_t *config);
	bool (*disconnect_req)(uint16_t cid);
	bool (*disconnect_rsp)(uint16_t cid);
	uint8_t (*write_data)(uint16_t cid, uint32_t length, uint8_t *buf);
	bool (*send_test_s_frame)(uint16_t cid, uint8_t sup_type, uint8_t back_track);
	bool (*ping)(uint8_t *addr, echo_response response);
} btl2cap_interface_t;

__END_DECLS

#endif /*ANDROID_INCLUDE_BT_TEST_L2CAP_H*/
