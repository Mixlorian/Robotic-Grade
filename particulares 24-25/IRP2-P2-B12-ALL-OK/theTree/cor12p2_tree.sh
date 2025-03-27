limite=9
for i in $(seq 1 $limite); do
	echo "ejecutando prueba " $i
	./t$i
	if [ $? = 0 ] 
	then
		echo "OK"
	else
		echo "NO OK"
	fi	
done

i=16
echo "ejecutando prueba " $i
./t$i
if [ $? = 0 ] 
then
	echo "OK"
else
	echo "NO OK"
fi


i=19
echo "ejecutando prueba " $i
./t$i
if [ $? = 0 ] 
then
	echo "OK"
else
	echo "NO OK"
fi



