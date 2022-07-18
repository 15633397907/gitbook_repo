#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <io.h>
#include <stdlib.h> // _pgmptr
#include <stdio.h>


using  std::cout;
using  std::cin;
using std::endl;
using std::string;

using namespace std::filesystem;
using std::filesystem::directory_iterator;


static string root_path;
static string output_path;


//std::filesystem::path;

int main(int argv, char* argc[])
{
	//static string root_path;
	if (argv > 1) {
		root_path = argc[1];
	}
	if (_access_s(root_path.c_str(), 00) != 0) {
		char** tmp_pgmptr = new char*[1];
		tmp_pgmptr[0] = new char[256];
		_get_pgmptr(tmp_pgmptr);
		root_path = tmp_pgmptr[0];
		cout << "_pgmptr:" << root_path << endl;
	}
	std::filesystem::path fs_rootpath;
	if (!std::filesystem::is_directory(path(root_path)))
	{
		fs_rootpath = path(root_path).parent_path();
	}
	else {
		fs_rootpath = path(root_path);
	}
	root_path = fs_rootpath.string();
	cout << fs_rootpath << endl;
	cout << root_path << endl;


	output_path = root_path + "\\SUMMARY.md";
	if (argv > 2) {
		/// 不考虑意外情况 需要输入一个文件名, 带不带.md都可以
		output_path = root_path + "\\" + argc[2];
		if (std::filesystem::path(output_path).extension() != ".md") {
			output_path += ".md";
		}
	}

	
	if (!std::filesystem::is_directory(fs_rootpath)) {
		fs_rootpath = fs_rootpath.parent_path();
		if (!std::filesystem::is_directory(fs_rootpath)) {
			cout << "root path error" << endl;
			return -1;
		}
			
	}

	/* root_path 当前根目录  */ 


	// root.relative_path = .\   <- .\的格式github无法识别  需要/ 或 ./ 
	void statistic_files(string path, string parent_relative_path, std::vector<string>&output, int level);
	std::vector<string> str_tree;
	statistic_files(root_path, "", str_tree, 0);

	std::ofstream ofs(output_path);

	if(!ofs.is_open()){
		cout << "输出路径无法识别, 请检查:\n";
		cout << output_path << endl;
		return -2;
	}
	ofs << "# gitbook_content\n\n";
	for (int i = 0; i < str_tree.size(); i++) {
		ofs << str_tree[i];
	}
	ofs.close();
	system("pause");
}

void statistic_files(string path, string parent_relative_path, std::vector<string>&output, int level)
{
	

	for (auto& iter : directory_iterator(path))
	{
		if (std::filesystem::is_directory(iter.path()))
		{
			if (iter.path().filename().string() == ".vscode" || /*iter.path().string().find(".vscode") != string::npos || */
				iter.path().filename().string() == ".git"    || /*iter.path().string().find(".git") != string::npos ||*/
				iter.path().filename().string() == "_book"   || /*iter.path().string().find("._book") != string::npos ||*/
				iter.path().filename().string() == "node_modules" ||/*iter.path().string().find("node_modules") != string::npos ||*/
				iter.path().filename().string() == "pics" ||
				iter.path().filename().string() == "resourse")
				continue;
			std::string tmp="";
			for (int i = 0; i < level; i++)
				tmp += "  ";
			std::string filename = iter.path().filename().string();
			std::string relative_path = parent_relative_path + filename + "/";
			tmp += "* [" + filename + "](" + relative_path + ")\n";
			std::string relative_path_readmepath = relative_path + "README.md";
			
			//tmp += iter.path().string();
			cout << tmp;
			output.push_back(tmp);
			size_t vec_size_fst = output.size();
			statistic_files(iter.path().string(), relative_path, output, level + 1);
			if (!std::filesystem::exists(std::filesystem::path(relative_path_readmepath))) {
				std::ofstream ofs(relative_path_readmepath);
				ofs << "# " << filename <<"\n\n" ;
				for (size_t i = vec_size_fst; i < output.size(); i++) {
					ofs << output[i].substr((level+1) * 2, output[i].size() - (level+1) * 2);
				}
				ofs.close();
			}
		}
		else if (std::filesystem::is_regular_file(iter.path()))
		{
			if (iter.path().filename().string().find("README")!= string::npos ||
				iter.path().extension() != ".md") 
				continue;
			std::string tmp = "";
			for (int i = 0; i < level; i++)tmp += "  ";
			std::string filename = iter.path().filename().string();
			std::string relative_path = parent_relative_path + filename;
			std::string extension = iter.path().extension().string();
			tmp += "* [" + filename.substr(0,filename.size() - extension.size()) + "](" + relative_path + ")\n";
			//tmp += iter.path().string();
			cout << tmp;
			output.push_back(tmp);
		}
	}
}

// directory_iterator 遍历
// recursive_directory_iterator 迭代遍历
