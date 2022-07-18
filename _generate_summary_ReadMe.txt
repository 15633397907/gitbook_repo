可以选择直接打开，不输入参数的情况下，以exe的当前目录为根目录，默认输出SUMMARY.md，如果有原文件，会被覆盖。

如果输入参数：

第一个参数为设置根目录 root_path

第二个参数为设置输出文件名称，仅输入名称即可，不需要输入路径。会在根目录中生成该文件。


ver2

会在每一层自动生成一个README.txt（如果查找不到该文件的话会生成，如果可以查到则不会影响原README.txt文件）

每一个README.txt文档都会记录其文件夹内的所有md文件的路径。

该版本为了配合github，文件夹链接处去掉了../README.txt，例如[part02_cpp](part02_cpp/README.txt) --> [part02_cpp](part02_cpp/) ，符合github的格式。