NBR1=$(echo $FT_NBR1 | tr "[\'\"\?\!]" "[0234]"| sed 's/\\/1/g')
NBR2=$(echo $FT_NBR2 | tr "[mrdoc]" "[01234]")

NBR1=$(echo "ibase=5;$NBR1"|bc)
NBR2=$(echo "ibase=5;$NBR2"|bc)

result=$(echo "obase=13; $NBR1+$NBR2" | bc)
result=$(echo $result | tr "[0123456789ABC]" "[gtaio luSnemf]")
echo "$result"
