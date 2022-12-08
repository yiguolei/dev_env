# split file
# split -b 500m log.txt newfile

# merge file
cat jdk-11.0.13_linux-x64_bin.tar.gz.part* > jdk-11.0.13_linux-x64_bin.tar.gz
cat jdk-8u131-linux-x64.tar.gz.part* > jdk-8u131-linux-x64.tar.gz
