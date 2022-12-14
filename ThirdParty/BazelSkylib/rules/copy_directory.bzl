# Copyright 2022 The Bazel Authors. All rights reserved.
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

"""A rule that copies a directory to another place.

The rule uses a Bash command on Linux/macOS/non-Windows, and a cmd.exe command
on Windows (no Bash is required).
"""

load(
    "//rules/private:copy_directory_private.bzl",
    _copy_directory = "copy_directory",
    _copy_directory_action = "copy_directory_action",
)

copy_directory = _copy_directory
copy_directory_action = _copy_directory_action
