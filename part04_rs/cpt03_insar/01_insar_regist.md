# Section.2 主辅影像配准

## 相关系数法

相关系数法是图像配准的基本方法，常用于模板或模式的匹配(?)，是很多配准算法的基础。在某些匹配参数位置的情况下，相关函数法能够给出图像之间总体配准结果，从而为其他高精度的配准方法提供基准点。对于干涉SAR图像的配准，相关可以在复数域进行，也可以仅仅利用幅度信息进行配准。

**对于相干斑噪声比较严重的SAR图像，幅度相关要好于复数据相关。**

### 幅度互相关

$$
R(u',v')=\frac{\displaystyle\sum_i\sum_jM_1(i,j)M_2(i+u',j+v')}{\sqrt{\displaystyle\sum_i\sum_jM_1^2(i,j)}*\sqrt{\displaystyle\sum_i\sum_jM_2^2(i+u',j+v')}} 
$$

式中，$M_1(i,j)$ 和 $M_2(i,j)$分别是两景影像的幅度信息，$u'$和$v'$分别为距离向和方位向的偏移量，相关系数最大处$R(u',v')$的$u'$和$v'$值即为配准的结果。

### 复数相关

$$
R(u',v')=\displaystyle\sum_i\sum_jS_1(i,j)*S_2^*(i+u',j+v')
$$

式中，$S_1(i,j)$ 和 $S_2(i,j)$分别是两景影像的复数信息，$S_2^*(i,j)$为原影像的共轭矩阵，$u'$和$v'$分别为距离向和方位向的偏移量，相关系数最大处$R(u',v')$的$u'$和$v'$值即为配准的结果。

使用FFT加速计算过程

使用FFT变换将$S_1(i,j)$ 和 $S_2(i,j)$变换到频域，得到$S_1(m,n)$ 和 $S_2(m,n)，在频域中有：

$$
FFT(R)=S_1(m,n)*S_2^*(m,n)
$$

对上式进行二维逆FFT变换即为$S_1(i,j)$和$S_2(i,j)$的互相关函数，其最大值对应的位置为配准的偏移量。