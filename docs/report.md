### 算法详解
就是按照高度进行排序，能塞进去就塞进去，塞不进去就新开一层。
### 近似比分析
近似比为2
证明：假设测试案例符合以下特征：
   width  high
1  0.5     10
2   x      10
3  0.5     9
4   x      9
......
OPT>=全部塞满的高度
此时全部塞满的高度high 为S/width
近似算法的高度<=S/0.5width
此时近似算法的高度/OPT<=S/width/S/0.5width==2