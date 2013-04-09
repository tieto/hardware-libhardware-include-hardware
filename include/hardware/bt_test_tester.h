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

#ifndef ANDROID_INCLUDE_BT_TEST_TESTER_H
#define ANDROID_INCLUDE_BT_TEST_TESTER_H

__BEGIN_DECLS

#define DUMP_TYPE_STOP    0
#define DUMP_TYPE_FILE    1
#define DUMP_TYPE_SOCKET  2

typedef struct _tester_test_interface_t {
    int  (*dump)(unsigned int type, char *name);
} tester_test_interface_t;

__END_DECLS

#endif /*ANDROID_INCLUDE_BT_TEST_TESTER_H*/
