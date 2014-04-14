# Frank Zhao 2014
# http://frankzhao.net

# Cycles a GPIO pin on and off
# Usage: ./blink_gpio.sh [pin]

while true; do
  sudo ./gpio.sh $1 start
  sleep 1
  sudo ./gpio.sh $1 stop
  sleep 1
done
