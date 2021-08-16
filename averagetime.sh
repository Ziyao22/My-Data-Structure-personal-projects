#!/bin/bash
#Ziyao Gao zg8rw 10/20/2020
#File name: averagetime.sh

echo enter the exponent for counter.cpp:
read e

quit="quit"
if [ $e == $quit ]
then
    exit
fi

for(( i = 1;i < 6;i++))
do
    echo Running iteration $i...	 
    RUNNING_TIME=`./a.out $e | tail -1`
    echo "time taken: $RUNNING_TIME ms"
    ((totalTime+=RUNNING_TIME))
done
averagetime=`expr "$totalTime" / 5`
echo "5 iterations took $totalTime ms"
echo "Average time was $averagetime ms"
