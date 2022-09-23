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

#include "modules/canbus/vehicle/mjev/protocol/wheelspeedreport506_506.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace mjev {

using ::apollo::drivers::canbus::Byte;

Wheelspeedreport506506::Wheelspeedreport506506() {}
const int32_t Wheelspeedreport506506::ID = 0x506;

void Wheelspeedreport506506::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_mjev()->mutable_wheelspeedreport506_506()->set_wheelspeedrr(wheelspeedrr(bytes, length));
  chassis->mutable_mjev()->mutable_wheelspeedreport506_506()->set_wheelspeedrl(wheelspeedrl(bytes, length));
  chassis->mutable_mjev()->mutable_wheelspeedreport506_506()->set_wheelspeedfr(wheelspeedfr(bytes, length));
  chassis->mutable_mjev()->mutable_wheelspeedreport506_506()->set_wheelspeedfl(wheelspeedfl(bytes, length));
}

// config detail: {'bit': 48, 'description': 'WheelSpeedRR', 'is_signed_var': False, 'len': 16, 'name': 'wheelspeedrr', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|65.535]', 'physical_unit': 'm/s', 'precision': 0.001, 'type': 'double'}
double Wheelspeedreport506506::wheelspeedrr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.001000;
  return ret;
}

// config detail: {'bit': 32, 'description': 'WheelSpeedRL', 'is_signed_var': False, 'len': 16, 'name': 'wheelspeedrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|65.535]', 'physical_unit': 'm/s', 'precision': 0.001, 'type': 'double'}
double Wheelspeedreport506506::wheelspeedrl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.001000;
  return ret;
}

// config detail: {'bit': 16, 'description': 'WheelSpeedFR', 'is_signed_var': False, 'len': 16, 'name': 'wheelspeedfr', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|65.535]', 'physical_unit': 'm/s', 'precision': 0.001, 'type': 'double'}
double Wheelspeedreport506506::wheelspeedfr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 2);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.001000;
  return ret;
}

// config detail: {'bit': 0, 'description': 'WheelSpeedFL', 'is_signed_var': False, 'len': 16, 'name': 'wheelspeedfl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|65.535]', 'physical_unit': 'm/s', 'precision': 0.001, 'type': 'double'}
double Wheelspeedreport506506::wheelspeedfl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.001000;
  return ret;
}
}  // namespace mjev
}  // namespace canbus
}  // namespace apollo
