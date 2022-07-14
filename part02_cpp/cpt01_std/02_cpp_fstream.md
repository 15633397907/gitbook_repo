# Section.2 fstream

## ofstream 写文档

```C++
#include<fstream>
ofstream temp(Filepath.txt);
temp<<………;
temp.close();
```

### 精度设置

```C++
std::ofstream(const char* filepath);
// 不适用科学计数法表示
ofs<<std::fixed 

// 有效数字位数
ofs.precision(int num);
// 当输出一行数字的精度不同时, 每次修改精度前单独设置一次

ofs<<num<<"\t";
ofs.precision(5);
ofs<<iter.incidence<<"\t";
ofs.precision(2);
ofs<<iter.row<<"\t"<<iter.col<<"\t";
ofs.precision(5);
ofs<<iter.point.x<<"\t"<<iter.point.y<<"\t"<<iter.point.z<<"\n";

// ...

ofs.close();

```

## ifstream 读文档

```c++
ifstream ifs;
ifs.open(txtsrc);
if (!ifs.is_open())
{
std::cout << "文件打开失败" << endl;
system("pasue");
exit(0);
}
 
string str;
string Separator = string(",");
while (getline(ifs, str))
{
    vector<string> strVec;
    SplitString(str, strVec, Separator);
    ComparisonData x0;
    x0.jRan_real = atoi(strVec[0].c_str());
    x0.iAzi_real = atoi(strVec[1].c_str());
    x0.jRan_sim = atoi(strVec[2].c_str());
    x0.iAzi_sim = atoi(strVec[3].c_str());
 
    PointsCompareData.push_back(x0);
}
```
