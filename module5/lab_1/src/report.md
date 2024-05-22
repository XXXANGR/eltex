# Установка заголовков Linux
apt-get install build-essential linux-headers-$(uname -r)  
- Версии заголовок ядер  

![](images/6.png)   
## Cоздайте следующий модуль hello.c  
- Введите лицензию, автора и описание того что делает модуль  

![](images/1.png)   

## Cоздайте Makefile  

![](images/7.png)   

## Введите команду insmod hello.ko  
- `insmod` вставит новый модуль в ядро  
- Ввести команду `dmesg | tail -1` для просмотра системного журнала  
- Чтобы проверить список 
![](images/2.png)  

## Введите команду modinfo hello.ko чтобы просмотреть информацию о параметрах модуля  

![](images/3.png) 

## Введите команду lsmod hello.ko | grep "hello" чтобы посмотреть что модуль находится в системе  

![](images/5.png) 
