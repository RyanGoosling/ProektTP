FROM ubuntu

ENV TZ=Europe/Moscow 
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone 
RUN apt-get update 
RUN apt install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y 
#RUN apt-get -y install gcc-snapshot g++-11
#RUN apt-get install -y qt-devel qt-create
 
WORKDIR /root/
RUN mkdir ProektTP
WORKDIR /root/ProektTP/
COPY *.cpp /root/ProektTP/
COPY *.h /root/ProektTP/
COPY *.pro /root/ProektTP/
COPY *.db /root/ProektTP/

RUN qmake echoServer.pro
RUN make 

ENTRYPOINT ["./echoServer"]