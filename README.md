# egi_navi
## compile<br>
$ git clone https://github.com/s887432/egt_navi<br>
$ cd egt_navi<br>
$ mkdir build<br>
$ cd build<br>
$ cmake .. -DARCH=arm9<br>
where arm9 is built for sam9x60, sam9x75<br>
cortex is built for SAMA5, SAMA7 series<br>
$ make<br>
<br>
The output will be placed at project folder.<br>
If built for ARM9, the output folder will be arm9_bin<br>
If built for CORTEX, the output folder will be cortex_bin<br>
<br>
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
