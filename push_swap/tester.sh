ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`
#./push_swap $ARG
./push_swap $ARG | ./checker_Mac $ARG
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l
ARG=`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`
#./push_swap $ARG
./push_swap $ARG | ./checker_Mac $ARG
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l
