# Section.2 fstream

## ofstream 写文档

```
#include<fstream>
ofstream temp(Filepath.txt);
temp<<………;
temp.close();
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

