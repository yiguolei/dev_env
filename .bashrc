# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=
export YGL_HOME=/mnt/disk2/ygl/
# User specific aliases and functions
export JAVA_HOME=$YGL_HOME/dev_env/installs/jdk1.8.0_131
export MVN_HOME=$YGL_HOME/dev_env/installs/apache-maven-3.6.3
export PATH=$YGL_HOME/dev_env/tools/FlameGraph-master/:$YGL_HOME/dev_env/installs/ldbtools/bin:$JAVA_HOME/bin:$MVN_HOME/bin:$PATH

alias hh="cd $YGL_HOME/code/github/apache-doris"
