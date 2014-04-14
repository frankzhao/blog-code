# Frank Zhao 2014
# http://frankzhao.net

# Turns on or off a GPIO pin
# Usage: ./gpio.sh [pin] [start | stop]

if [ "$1" != "2" ] && [ "$1" != "3" ] &&
	 [ "$1" != "4" ] && [ "$1" != "7" ] &&
	 [ "$1" != "8" ] && [ "$1" != "9" ] &&
	 [ "$1" != "10" ] && [ "$1" != "11" ] &&
	 [ "$1" != "14" ] && [ "$1" != "15" ] &&
	 [ "$1" != "17" ] && [ "$1" != "18" ] &&
	 [ "$1" != "22" ] && [ "$1" != "23" ] &&
	 [ "$1" != "24" ] && [ "$1" != "25" ] &&
	 [ "$1" != "27" ]; then

	echo "ERROR: GPIO does not exist."
	
elif [ "$2" = "start" ]; then
			echo "$1" > /sys/class/gpio/export
			echo "1" > /sys/class/gpio/gpio$1/value
			echo "Pin $1 started"
elif [ "$2" = "stop" ]; then
		 	echo "0" > /sys/class/gpio/gpio$1/value
			echo "$1" > /sys/class/gpio/unexport
			echo "Pin $1 stopped"
fi
