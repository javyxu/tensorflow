# Copyright 2020 The TensorFlow Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Settings for not pre-defined ARC processors. 
# User need to specify ARC target with Tool Configuration File (*.tcf). 
# Path to this file must be passed through TCF_FILE variable.
# Otherwise, default em7d_voice_audio configuration is used 
ifeq ($(TARGET_ARCH), arc)

# Known target are specified with their own make configurations. 
ifeq ($(filter $(TARGET), arc_emsdp),)

ARC_TOOLCHAIN := mwdt

ifneq ($(TCF_FILE), )
  TARGET = $(basename $(notdir $(TCF_FILE)))
else
  $(warning TCF_FILE variable is not specified. Use default em7d_voice_audio configuration)
  TARGET = em7d_voice_audio
  TCF_FILE = em7d_voice_audio
endif

include $(MAKEFILE_DIR)/targets/arc/arc_common.inc

MAKE_PROJECT_FILES := $(filter-out README_MAKE.md, $(MAKE_PROJECT_FILES)) README_ARC.md

endif  # $(TARGET)
endif  # $(TARGET_ARCH)...

