# Section.06 ofstream输出精度设置

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
