Contiki SNMP Getting Started
==============================
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


