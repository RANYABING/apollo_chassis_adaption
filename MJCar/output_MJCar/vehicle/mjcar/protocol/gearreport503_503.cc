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

#include "modules/canbus/vehicle/MJCar/protocol/gearreport503_503.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace MJCar {

using ::apollo::drivers::canbus::Byte;

Gearreport503503::Gearreport503503() {}
const int32_t Gearreport503503::ID = 0x503;

void Gearreport503503::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_MJCar()->mutable_gearreport503_503()->set_gear_stateact(gear_stateact(bytes, length));
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 3, 'name': 'gear_stateact', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Gearreport503503::gear_stateact(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 3);

  int ret = x;
  return ret;
}
}  // namespace MJCar
}  // namespace canbus
}  // namespace apollo
