#!bin/shell

mv $* /mnt/home/Garbage/
if [ $1 == '-clear' ];
	then
		for i in $*+1
			do
				echo "$i"
			done
	fi
