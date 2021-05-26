### Climbing Stairs

原题[leetcode70](https://leetcode-cn.com/problems/climbing-stairs/)

You are  climbing a  stair  case.  It  takes n steps  to  reach to the  top.
Each time  you can either  climb  1  or 2  steps.  In  how  many distinct  ways can you climb to the top

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的⽅法可 以爬到楼顶呢？注意：给定 n 是⼀个正整数

分解：假如现在爬的有5层楼

层数		方法

1			1				第一层只有一种方式，就是爬一个台阶

2			2				第二层可以1-1 or 2

3			3				第三层分为两种情况1.爬上第一层，不经过第二层然后经过两步上第三层2.爬上第										二层，然后经过一步上第三层

4			5				第四层 还是两种情况1.在第三层上经过一步直接上第四层，那么，上第三层有多少								种方法，这种情况就有多少种方法2.就是在第二层上，不经过第三层直接上第二								层，那么上第二层有多少种情况，上第四层就有多少种情况

5			8              	 上第三层有3种方法，上第四层有5种方法，那么上第五层就有8中



总的来说就是斐波那契数列，也是一个dp问题 递推式就是d[n]=d[n-1]+d[n-2]

```c++
//一个斐波那契数列问题，初始化d[0],d[1],从d[2]开始，d[2]=d[0]+d[1],最后返回d[n]就好
class Solution {
public:
    int climbStairs(int n) {
        int d[n+1];
        d[1]=1;
        d[0]=1;
        for(int i =2;i<n+1;i++){
            d[i] = d[i-1]+d[i-2];
        }
        return d[n];
    }
};
```

