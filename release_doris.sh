#!/usr/bin/env bash
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

####################################################################
# This script is used to build and package Doris


# build with avx2 
# clear all thirdparty builds, and rebuild all thirdparties and sources
rm -rf thirdparty/* && git reset --hard

export JAVA_HOME=/mnt/disk2/ygl/installs/jdk-11.0.13
export PATH=$JAVA_HOME/bin:$PATH
BUILD_META_TOOL=ON STRIP_DEBUG_INFO=ON sh build.sh --fe --be --broker --clean && rm -rf output/be/lib/debug_info && cp NOTICE.txt output/ && cp dist/LICENSE-dist.txt output/ && cp -r dist/licenses output/ && mv output avx-jdk11

export JAVA_HOME=/mnt/disk2/ygl/installs/jdk1.8.0_131
export PATH=$JAVA_HOME/bin:$PATH
BUILD_META_TOOL=ON STRIP_DEBUG_INFO=ON sh build.sh --fe --be --broker --clean && rm -rf output/be/lib/debug_info && cp NOTICE.txt output/ && cp dist/LICENSE-dist.txt output/ && cp -r dist/licenses output/ && mv output avx-jdk8

# build without avx2
# clear all thirdparty builds
rm -rf thirdparty/* && git reset --hard

export JAVA_HOME=/mnt/disk2/ygl/installs/jdk-11.0.13
export PATH=$JAVA_HOME/bin:$PATH
BUILD_META_TOOL=ON USE_AVX2=0 STRIP_DEBUG_INFO=ON sh build.sh --fe --be --broker --clean && rm -rf output/be/lib/debug_info && cp NOTICE.txt output/ && cp dist/LICENSE-dist.txt output/ && cp -r dist/licenses output/ && mv output noavx-jdk11

export JAVA_HOME=/mnt/disk2/ygl/installs/jdk1.8.0_131
export PATH=$JAVA_HOME/bin:$PATH
BUILD_META_TOOL=ON USE_AVX2=0 STRIP_DEBUG_INFO=ON sh build.sh --fe --be --broker --clean && rm -rf output/be/lib/debug_info && cp NOTICE.txt output/ && cp dist/LICENSE-dist.txt output/ && cp -r dist/licenses output/ && mv output noavx-jdk8
