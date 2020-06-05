# TowerDefenseGame
### 版本一
  
#### 设计思路：  
&emsp;&emsp;刚拿到这个题目的时候，说实话整个人都懵了。。。最开始是按照贪吃蛇的范例代码尝试着实现那些自带的
Qt中的类，但是很快就发现自己的游戏界面都还没弄好，于是又转向游戏基础界面的设计。然后完成基础界面的设计,
例如画出路径，其余部分的图片，终点房子的图片，这时我意识到还要给防御塔留有空间。所以接下来我设计了一个
防御塔坑类，然后在某些位置画出了防御塔坑的图片。到此为止，整个游戏的基础界面就算弄好了。然后想到的是插入
怪物，随便在网上（ddl在即）找了几张动物的图片，然后按照基础界面中已经设计好的路径给怪物设置移动路径，确
定其各项数据，然后就大致完成了。其次是防御塔本身的设计，这是最麻烦的。首先要在已经设计出的防御塔坑上画出
所选择的防御塔，那就需要来connect鼠标点击事件和这个防御塔坑，从而到达可以选择防御塔（图片也是随便选的）
的目的。选好之后就是画出防御塔，然后取消这个选择框，就完成了一个防御塔。然后再设计发出子弹、击中怪物和
防御塔的旋转。然后基本上我这个代码主体的设计就完成了。最后随便画了画UI界面，connect了点击开始，整个代码
就算是完成了。

#### 代码功能：  
&emsp;&emsp;该代码实现了建立防御塔，怪物移动，防御塔攻击，判断游戏结束等这些基础功能。

#### 现存缺陷：  
1.“家”在画出的过程中只画出一部分；  
2.有一种怪物在未到达“家”就判断为到达，而且生命值扣除；  
3.子弹由于是用的一次函数，故在飞行的时候可能会因为延迟而无法攻击到怪物；  
4.怪物移动感觉帧数有点低；  
5.游戏的怪物设计，防御塔设计数据不平衡，可能导致游戏体验差。而且没有新手指引，从而无法提供最佳的游戏体验；  
6.在购买防御塔时，由于时间原因，未能将所有的防御塔标上价格；  
7.由于时间原因，未能插入音频文件。  

#### 代码文件：  
&emsp;&emsp;在主页面上可以看到。共有MainWindow类（主体），DefeTowerParent类（防御塔的父类），BigTurret类（防
御塔子类），FireTurret类（防御塔子类），GreenTurret类（防御塔子类），LightTurret类（防御塔子类），
GlobalStruct类（全局类集合），Monster类（怪物类），SelectionBox类（选择框类），DefenseTowerPit类
（防御塔坑类），Startform类（Ui所在类），以及各自类（除了GlobalStruct类）的cpp文件。

#### 总结：  
&emsp;&emsp;虽然大致上还算可以运行出一个游戏（-_-）,但是距离目标还是远远不够的，可以期待接下来的更新中将bug完善，提升
玩家游戏体验，并且推出更多好玩的功能。  
