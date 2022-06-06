# Section.5 ifstream 二进制文件读取及跳字节

场景：2022.3.17 其他软件无法正常显示.dat

```C++
std::ifstream ifs("filepath",ifsteam::binary);
if(!ifs){
    printf("ifs read error..\n");
    return -1
}
double value;
while(ifs.read((char*)value,sizeof(double)/*8*/)
{
    //如果value异常 （error只是一个假想的函数）
    if(error(value)){
        //ifs指针从当前位置（ios::cur）向前跳n-1的字节，
        ifs.seekg(1-sizeof(double),ios::cur);
        
        continue;
    }
}
```
`std::ifstream ifs("filepath",ifsteam::binary)`，用二进制方式读取文件。

`ifs.read(char_type* ,streamsize )`，每次读取`streamsize`长度的字节数，并存储到指定位置(`char_type*`)。

seekg:

`ifs.seekg(off_type,ios_base::seekDir)` ifs的当前指针移动到`seekDir`处并偏移`off_type`字节。

ios_base::seekDir:
>`ios::beg` 表示输入流的开始位置 \
`ios::cur` 表示输入流的当前位置 \
`ios::end` 表示输入流的结束位置