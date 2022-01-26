# Section5.21 线性问题预留21-40

## 线性最小二乘

解决密集矩阵的线性最小二乘问题
 
 $Ax=b$

 Eigen文档中提供了三种方法，分别是SVD分解，QR分解和正规方程三种方式。其中，SVD分解通常是最准确但也是最慢的，正规方程最快但最不准确，QR介于两者之间。

 ### SVD分解 (SVD decomposition)

``` C++
#include <iostream>
#include <Eigen/Dense>
 
using namespace std;
using namespace Eigen;
 
int main()
{
   MatrixXf A = MatrixXf::Random(3, 2);
   cout << "Here is the matrix A:\n" << A << endl;
   VectorXf b = VectorXf::Random(3);
   cout << "Here is the right hand side b:\n" << b << endl;
   cout << "The least-squares solution is:\n"
        << A.bdcSvd(ComputeThinU | ComputeThinV).solve(b) << endl;
}

//output:
Here is the matrix A:
  0.68  0.597
-0.211  0.823
 0.566 -0.605
Here is the right hand side b:
 -0.33
 0.536
-0.444
The least-squares solution is:
-0.67
0.314
```

### QR分解 (QR decomposition)


### 正规方程 (normal equations)

$\kern{45 mu}  Ax=b\\  \implies A^TAx=A^Tb \\ \implies x=(A^TA)^{-1}A^Tb$