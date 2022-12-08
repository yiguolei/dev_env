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
doris_version=1.1.3
export JAVA_HOME=/mnt/disk2/ygl/installs/jdk1.8.0_131
export PATH=$JAVA_HOME/bin:$PATH
rm -rf doris_release && mkdir -p doris_release &&

# build with avx2 
# clear all thirdparty builds, and rebuild all thirdparties and sources
rm -rf thirdparty/* && git reset --hard
rm -rf output/*
sh build.sh --clean &&
BUILD_META_TOOL=ON USE_AVX2=1 sh build.sh &&

mv output/fe doris_release/apache-doris-fe-$doris_version-bin &&
mv output/apache_hdfs_broker doris_release/apache-doris-fe-$doris_version-bin &&
mv output/audit_loader doris_release/apache-doris-fe-$doris_version-bin &&
mv output/be doris_release/apache-doris-be-$doris_version-bin-x86_64 &&

# build without avx2
# clear all thirdparty builds
rm -rf thirdparty/* && git reset --hard
rm -rf output
sh build.sh --clean &&
BUILD_META_TOOL=ON USE_AVX2=0 sh build.sh &&

mv output/be doris_release/apache-doris-be-$doris_version-bin-x86_64-noavx2 
