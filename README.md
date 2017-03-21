Contiki SNMP Getting Started
==============================
0. install contiki  (http://anrg.usc.edu/contiki/index.php/Installation#Using_ContikiOS_from_Github_repository)
   ```
   wget https://github.com/contiki-os/contiki/archive/3.0.zip
   ```
   
   ```
   unzip 3.0.zip
   ```
   
   ```
   mv contiki-3.0 contiki
   ```
   
   ```
   sudo apt-get install build-essential binutils-msp430 gcc-msp430 msp430-libc msp430mcu mspdebug gcc-arm-none-eabi gdb-arm-none-eabi openjdk-8-jdk openjdk-8-jre ant libncurses5-dev radvd
   ```
   
   ```
   sudo apt-get install lib32ncurses5
   ```

1. Back up your old contiki-snmp project
    ```
    mv contiki-snmp contiki-snmp_bk
    ```
2. Download this project
    ```
    git clone https://github.com/ca7erina/contiki-snmp.git
    ```
3. Compile
    ```
    cd contiki-snmp
    ./compile.sh
    ```
4. Start radvd
    ```
    cd contiki-snmp
    ./startRadvd.sh
    ```
    
5. test
    ```
    snmpwalk -v 1 -c public udp6:[aaaa::206:98ff:fe00:232]:1610 1
    ```

