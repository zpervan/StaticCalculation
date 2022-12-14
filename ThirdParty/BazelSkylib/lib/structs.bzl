# Copyright 2017 The Bazel Authors. All rights reserved.
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

"""Skylib module containing functions that operate on structs."""

def _to_dict(s):
    """Converts a `struct` to a `dict`.

    Args:
      s: A `struct`.

    Returns:
      A `dict` whose keys and values are the same as the fields in `s`. The
      transformation is only applied to the struct's fields and not to any
      nested values.
    """

    # to_json()/to_proto() are disabled by --incompatible_struct_has_no_methods
    # and will be removed entirely in a future Bazel release.
    return {
        key: getattr(s, key)
        for key in dir(s)
        if key != "to_json" and key != "to_proto"
    }

structs = struct(
    to_dict = _to_dict,
)
