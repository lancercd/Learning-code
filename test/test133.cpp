
开关K5置为1，选择方波信号1HZ作为计数脉冲；K7置为0，使74LS193四位同步可逆计数器每一秒自动加1。
开关K6置为1，通过74LS126 4三态缓冲器使开关K1、K2、K3、K4输入数据有效，通过非门，2114~WE读写控制信号变为低电平，即写操作。通过K1~K4向2114中连续输入不同数据。然后再将K6置为0，即读操作，可观察到L1~L4以及七段显示器有序显示刚才连续输入的不同数据。
K5置为0，K6置为1，选择单脉冲作为计数脉冲，即点击一下P1，计数器加1，即可通过K1~K4输入一个数据。
K6置为0，K5置为1，可观察到L1~L4以及七段显示器与先前输入的数据相符合。
2、实验原理：
在此实验中，2114芯片的地址线只用了A0~A3四根，即只访问16个地址单元。74LS193计数器通过Q0~Q3向2114选择地址。
K5置为0，K6置为1，进行写操作，输入数据成功后，点击P1即计数器加1，访问下一个地址。
K5置为1，K6置为0，进行读操作，顺序读取2114中每一个地址的数据。
3、2114特点：
2114芯片为静态RAM，即可读可写存储器，采用NMOS工艺制成，容量为1K*4，即有10位地址线，4位输入/输出线，1个读写控制端，1个片选端。用触发器工作原理存储信息，因此即使信息读出后，它仍保持其原状态不需要再生。但电源掉电时原存信息丢失，所以它属于半性半导体存储器。
操作方法为：先选择地址，再输入要写入的数据，然后进行写操作；写完后再将数据读出来，以验证正确与否。











基本存储电路主要由R—S触发器构成，其两个稳态分别表示存储内容为“0”或为“1”，电源供电存入的数据才可以保存和读出，掉电源存储信息全部丢失所谓“易失性”。

区分不同的存储单元，每个单元规定一个地址号。

静态随机存取存储器使用某种触发器来储存每一位内存信息，存储单元使用的触发器是由引线将4-6个晶体管连接而成，但无须刷新，但由于构造比较复杂，静态随机存取存储器单元占据更多的芯片空间。

由于数据和地址 是由同一个数据开关给出的，因此数据和地址要分别给出，先关掉存储器的读写，数据开关给出地址00H，将地址00H打入AR中，再关掉地址寄存器，数据开关给出数据11H，打开输入三态门，然后使存储器处于写的状态，即将11H打入存储器；读出数据也要先给出地址，再进行读操作，地址00H的给出和前面一样，然后关闭IN的输出，使存储器处于读状态，此时数据总线上的数就是11H。
(2)存储器存储数据的原理：存储器中最小的存储单位就是一个双稳态半导体电路或者一个CMOS晶体管或者磁性材料的存储元，它可以存出一个二进制的代码。有若干个存储元组成一个存储单元，然后又许多存储单元组成一个存储器，就可以用来存放程序和数据了。
(3)由于存储器最终是要挂到CPU上，所以其有一个读写控制逻辑，使得CPU能控制MEN的读写，由于T3的参与，可以保证写脉宽与T3一致，T3由时序单元的TS3给出。IOM用来选择是对I/O设备还是对MEM进行读写操作，RD=1时为读，WR=1时为写。

2114特点：作速度快，只要电源不撤除，写入SRAM的信息就不会消失，不需要刷新电路，同时在读出时不破坏原来存放的信息，一经写入可多次读出，但集成度较低，功耗较大。
