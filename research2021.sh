#!/bin/bash

#sudo pmap 3494
#cat /proc/3494/smaps
# top and ps
# ps aux | more
# grep

echo Enter PID:
read pid

i=0
> memory_outputs.txt # clear old ouputs
# grab 4 times a second for 200 seconds. 800 * 1/4 = 200
echo "ms since epoch, total memory" >> memory_outputs.txt
while [ $i -le 600 ]
do
	# print to output file
	total_mem=$(sudo pmap $pid | tail -n 1 | awk '/[0-9]K/{print $2}') # this will only grab the total memory of a process, no other information
	echo "$(date +%s%N | cut -b1-13), $total_mem" >> memory_outputs.txt # ms since epoch, memory
	sudo pmap $pid | tail -n 1
	((i++))
	sleep 0.25
done
