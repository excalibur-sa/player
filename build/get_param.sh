#!/bin/bash

#TODO: auto add the configure settings
get_param_function(){
	config_setting=""
	cfg_para_index=5
	cur_count=1

	#echo "The amount of the parameters is $# !"
	#echo "cfg_para_index: $cfg_para_index"
	#echo ""
	for arg in "$@"
	do
 		#echo "The value of the $cur_count parameter is $arg !"
  		if [ $cur_count -ge $cfg_para_index ];then
 			config_setting="${config_setting} $arg"
    	fi
 		let ++cur_count
	done

	#echo ""
	echo "config_setting: $config_setting"
}

get_param_function 1a 2b 3c 4d  5--diable-static 6--enable-share
