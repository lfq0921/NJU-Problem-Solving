## 题目描述
有一个偏僻的村庄，只有一条羊肠小道能够经行这个村庄。村庄里只有一户人家。他们虽然与世隔绝，倒也其乐融融。
在一个风雨交加的夜晚，一个可疑的过路人敲开了这户人家的门。好心的男主人刚把这位过路人引进门他便狂性大发，大开杀戮，把这一家人全部杀死。由于这个村庄太过偏僻，所以案发多日才由送信的邮差发现尸体，可惜此时再向警局报案已经太晚。冤死的一家人的亡灵便化作一个青面獠牙的厉鬼，对所有路过这个村庄的人实施疯狂的报复。
zyb是一个初阶捉鬼师，他得知了这个村庄的灵异事件便迫不及待地前来捉鬼，如果能捉到这只鬼，他就能变成进阶捉鬼师，否则，他将惨死于厉鬼刀下。
zyb首先在村庄中布下法阵，它由n个子阵法构成，并创建了n-1条法迹，**这些法迹保证任意的两个子阵法都可以通过法迹相连接**，从一个子阵法走到另一个子阵法需要耗费走过对应法迹所需要的法力值$p_i$( i $\in$ [1, n-1] )。**布阵要耗费的法力为从一个子阵法走到另一个子阵法所要耗费的法力的最大值**。虽然通过布阵捉住了鬼，但此时ybgg的法力已经恰好耗尽，如果没有外挂的帮忙他将无法净化厉鬼。这个时候他发现自己身上还剩下一个外挂——道符，使用这个道符，他将可以**打破阵法中的任意一条法迹，并任意选择两个子阵法构建一条新的法迹**，走过这条新法迹所需要的法力值为c。这个新阵法仍然要满足**任意两个子阵法都可以通过法迹相连接**。ybgg重新布下这个新法阵，如果布下此阵要耗费的法力比第一次布阵耗费的法力小，那么他在布阵后仍有净化厉鬼的能力，即捉鬼成功。否则，他将被厉鬼的恶灵反噬，魂飞魄散。为了安全，他将尽可能选择布下一个耗费法力最小的新法阵。
ybgg抽出道符，默念咒语，重新布阵，4s之后，一阵凄厉的惨叫声传出村庄
“啊————————”
## 输入格式
第一行一个正整数n,表示共布下n个子阵法（编号从1到n）。
接下来的n-1行描述最初的n-1条法迹的情况， 每一行三个正整数，u，v，p，其中u，v表示这条法迹所连接的两个子阵法的编号，p表示走过这条法迹要耗费的法力值。
接下来的一行一个正整数c，表示走过使用道符后构建的新法迹所需要的法力值。
// to add 数据范围
- 对于所有数据， 满足1 $\leq$ n $\leq$ 3000，1$\leq$ $p_i$，c $\leq$ $10^9$
## 输出格式
如果ybgg能够捉鬼成功，则输出两行
第一行，输出yes表示ybgg能够捉鬼成功；第二行输出使用道符后能够布下的新法阵中需要耗费的法力的最小值。
如果ybgg捉鬼失败，则只输出一行no,显示他已经遭遇不测。