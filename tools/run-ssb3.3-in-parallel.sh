#!/usr/bin/env bash
set -eo pipefail

####################configs####################
#will cd to DORIS_SOURCE_CODE_DIR to pull the latest code, then compile
DORIS_SOURCE_CODE_DIR="/mnt/hdd01/ldy/daily-performance-corn/incubator-doris/"
#will git checkout GIT_BRANCH and git pull
# GIT_BRANCH="dev-1.0.1"
GIT_BRANCH="master"
#after compile, deploy new package to DEPLOY_DIR by replacing the fe/lib folder and be/lib folder
DEPLOY_DIR="/mnt/ssd01/Doris-deploy-dir/"
# DEPLOY_DIR="/mnt/ssd01/StarRocks-2.0.1/"
#run tpch query RUN_QUERY_REPEAT_TIMES times, then take average time
RUN_QUERY_REPEAT_TIMES=3

#fe host
FE_HOST="172.19.0.11"
#http_port in fe.conf
FE_HTTP_PORT="8238"
#query_port in fe.conf
FE_QUERY_PORT="9238"

#Doris username
USER="root"
#Doris passwaord
PASSWORD=""
#The database where TPC-H tables located
TPCH_DB="tpch100"
#The database where SSB tables located
SSB_DB="ckbenchv2"
#The database where SSB flat table lineorder_flat located
SSB_FLAT_DB="ssb100_1"

####################configs####################
totaltime=0
counter=0
run_sql() {
    sql="--q3.3
SELECT COUNT(*) FROM hits WHERE URL LIKE '%google%';

"

    for i in $(seq 1 10000); do
        start=$(date +%s%3N)
        mysql -h$FE_HOST -u$USER -P$FE_QUERY_PORT -D$SSB_DB -e "$sql" >/dev/null
        end=$(date +%s%3N)
        totaltime=$totaltime+$((end - start))
	counter=$counter+1
        echo "run ssb q3.3, cost $((end - start)) ms" 
	echo "avg time is : $((totaltime/counter))"
    done
}

run_in_parallel() {
    for i in $(seq 1 1); do
        run_sql &
    done
    wait
}

run_in_parallel
