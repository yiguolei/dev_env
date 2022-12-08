#!/usr/bin/env bash

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" &>/dev/null && pwd)"

export ENV_HOME="${ROOT}"

cd "${ENV_HOME}/installs"

cat jdk-11.0.13_linux-x64_bin.tar.gz.part* > jdk-11.0.13_linux-x64_bin.tar.gz
cat jdk-8u131-linux-x64.tar.gz.part* > jdk-8u131-linux-x64.tar.gz

tar -xzf jdk-11.0.13_linux-x64_bin.tar.gz
tar -xzf jdk-8u131-linux-x64.tar.gz
tar -xzf apache-maven-3.6.3-bin.tar.gz

rm -rf jdk-8u131-linux-x64.tar.gz
rm -rf jdk-11.0.13_linux-x64_bin.tar.gz
