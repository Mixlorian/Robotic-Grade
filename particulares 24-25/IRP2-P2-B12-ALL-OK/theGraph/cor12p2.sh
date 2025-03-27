for i in $(seq 10 15); do
	echo "ejecutando prueba " $i
	./t$i
	if [ $? = 0 ] 
	then
		echo "OK"
	else
		echo "NO OK"
	fi
	
done

for i in $(seq 17 18); do
	echo "ejecutando prueba " $i
	./t$i
	if [ $? = 0 ] 
	then
		echo "OK"
	else
		echo "NO OK"
	fi
	
done

