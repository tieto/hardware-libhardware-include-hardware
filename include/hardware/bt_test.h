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

#ifndef ANDROID_INCLUDE_BT_TEST_H
#define ANDROID_INCLUDE_BT_TEST_H

__BEGIN_DECLS

#include "bt_test_l2cap.h"
#include "bt_test_sdp.h"
#include "bt_test_rfcomm.h"
#include "bt_test_tester.h"


#define TEST_L2CAP   1
#define TEST_SDP     2
#define TEST_RFCOMM  3
#define TEST_TESTER  4

typedef struct {
	const void* (*get_test_interface)(int interface);
} test_interface_t;

__END_DECLS

#endif/* ANDROID_INCLUDE_BT_TEST_H*/
