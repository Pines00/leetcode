

[原题链接](https://leetcode-cn.com/problems/set-matrix-zeroes/)

给定一个 `m x n` 的矩阵，如果一个元素为 **0** ，则将其所在行和列的所有元素都设为 **0** 。请使用 **[原地](http://baike.baidu.com/item/原地算法)** 算法**。**

第一种：定义两个数组用来做标志位；但是这样为o(m+n)

第二种：用数组本身来充当标志数组，这样内存开销为常数级。

第二种方法：

* 先遍历第一行与第一列，如果第一行与第一列有0，那么就将标志位设为1

* 然后遍历除去第一行与第一列其他元素，如果有元素为0，那么将对应的第一行与第一列置为0

* 从第二行和第二列遍历第二行和第二列之后的元素，如果为0，将整个行与列置0

* 最后查看第一行与第一列标志位，如果有0则置第一行与第一列为0

  举个例子
  $$
  a = \left[ \begin{matrix}  0  & 1 &2 &0\\  3 & 4 &0 &2 \\  1 & 3&1 &0 \end{matrix} \right]
  $$
  1.第一行与第一列有0，对应标志位flagi=1,flagj=1,表示的就是第一行中有个0，第二行中有个0。

  2.然后除去第一行与第一列中元素，也就是剩下 （4,0,2），（3,1,0），扫描整个数组，在

  `a[1][2]`处为0，则将`a[1][0]与a[0][2]`设为0。接下来其他也是按照这种做法

  3.再次遍历矩阵，如果第一行与第一列出现0，则将对应的行与列都，但注意的是得从第二行与第二列开始遍历，不然的话如果从第一行与第一列，那全为0.

  4.然后根据flag来判断是否将第一行或者第一列置0

```c++
第一种 就是创建两个数组，用来记录行或列中是否有0，若果有则将对应行或列值true在，最后将对应为true的行与列全置0.但是这种方法空间复杂度为o(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        vector<bool> raw(m,false);
        vector<bool> col(n,false);
        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    raw[i]=true;
                    col[j]=true;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(raw[i]){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(col[j]){
                for(int i=0;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
```

```c++
第二种参考别人的方法
1、先扫描第一行第一列，如果有0，则将各自的flag设置为true
2、然后扫描除去第一行第一列的整个数组，如果有0，则将对应的第一行和第一列的数字赋0
3、再次遍历除去第一行第一列的整个数组，如果对应的第一行和第一列的数字有一个为0，则将当前值赋0
4、最后根据第一行第一列的flag来更新第一行第一列
————————————————
版权声明：本文为CSDN博主「honeyRJ」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/baidu_37964071/article/details/80904310

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        int flagi=0,flagj=0;
        for(int i=0;i<m;i++){//设置标志位
            if(matrix[i][0]==0){
                flagj=1;
            }
        }
        for(int i=0;i<n;i++){//设置标志位
            if(matrix[0][i]==0){
                flagi=1;
            }
        }
        for(int i=1;i<m;i++){//从第二行第二列开始遍历，如果有0则将对应行的第一行与第一列对应位置元素置0
            for (int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){//然后下面两个循环主要判断从第二行与第二列开始判断元素是否为0，如果为0那么将对应行或列设为0，切记不能从第一行第一列开始，如果这样就错了
            if(matrix[i][0]==0){
                for(int j=1;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
         for(int j=1;j<n;j++){
            if(matrix[0][j]==0){
                for(int i=1;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }
        if(flagj){//最后判断一下，将行与列设为0
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
        if(flagi){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
    }
};

```

