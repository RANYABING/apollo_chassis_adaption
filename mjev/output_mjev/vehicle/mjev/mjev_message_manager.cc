/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus/vehicle/mjev/mjev_message_manager.h"

#include "modules/canbus/vehicle/mjev/protocol/brakecommand101_101.h"
#include "modules/canbus/vehicle/mjev/protocol/gearcommand103_103.h"
#include "modules/canbus/vehicle/mjev/protocol/steeringcommand102_102.h"
#include "modules/canbus/vehicle/mjev/protocol/throttlecommand100_100.h"

#include "modules/canbus/vehicle/mjev/protocol/brakereport501_501.h"
#include "modules/canbus/vehicle/mjev/protocol/gearreport503_503.h"
#include "modules/canbus/vehicle/mjev/protocol/steeringreport502_502.h"
#include "modules/canbus/vehicle/mjev/protocol/throttlereport500_500.h"
#include "modules/canbus/vehicle/mjev/protocol/vcureport505_505.h"
#include "modules/canbus/vehicle/mjev/protocol/wheelspeedreport506_506.h"

namespace apollo {
namespace canbus {
namespace mjev {

MjevMessageManager::MjevMessageManager() {
  // Control Messages
  AddSendProtocolData<Brakecommand101101, true>();
  AddSendProtocolData<Gearcommand103103, true>();
  AddSendProtocolData<Steeringcommand102102, true>();
  AddSendProtocolData<Throttlecommand100100, true>();

  // Report Messages
  AddRecvProtocolData<Brakereport501501, true>();
  AddRecvProtocolData<Gearreport503503, true>();
  AddRecvProtocolData<Steeringreport502502, true>();
  AddRecvProtocolData<Throttlereport500500, true>();
  AddRecvProtocolData<Vcureport505505, true>();
  AddRecvProtocolData<Wheelspeedreport506506, true>();
}

MjevMessageManager::~MjevMessageManager() {}

}  // namespace mjev
}  // namespace canbus
}  // namespace apollo
