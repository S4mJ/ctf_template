FROM python:3-alpine

WORKDIR /usr/src/app/pwnone
EXPOSE 31337

CMD bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space' #Resets on restart unless you configure it in sysctl
CMD tcpserver -t 50 -RH10 0.0.0.0 31337 ./one
