CNT=500
LIMIT=5500
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`./push_swap $ARG | wc -l`
while [ $NUM -lt $LIMIT ]
do
echo $NUM
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`./push_swap $ARG | wc -l`
done
