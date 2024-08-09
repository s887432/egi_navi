# egi_navi
## compile<br>
$ git clone https://github.com/s887432/egt_navi<br>
$ cd egt_navi<br>
$ cd build_cortex<br>
$ make<br>
## usage<br>
egt_navt UART_DEVICE 0/1<br>
where <br>
UART_DEVICE is tty console device which is located at /dev/tttySx<br>
0/1: means enable BLE or send through UART directly.<br>
0: thouygh BLE<br>
1: through UART directly<br>
example:<br>
&#35; egt_navi /dev/ttyS2<br><br>
Have fun!!!<br>
Patrick @ Taipei
