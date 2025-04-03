#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 拼音首字母对应表
struct PinyinMap {
	char pinyin;
	unsigned char gb2312Start[2];
};

// 根据题目给出的表格初始化映射表
PinyinMap pinyinMap[] = {
	{'A', {0xB0, 0xA1}}, {'B', {0xB0, 0xC5}}, {'C', {0xB2, 0xC1}},
	{'D', {0xB4, 0xEE}}, {'E', {0xB6, 0xEA}}, {'F', {0xB7, 0xA2}},
	{'G', {0xB8, 0xC1}}, {'H', {0xB9, 0xFE}}, {'J', {0xBB, 0xF7}},
	{'K', {0xBF, 0xA6}}, {'L', {0xC0, 0xAC}}, {'M', {0xC2, 0xE8}},
	{'N', {0xC4, 0xC3}}, {'O', {0xC5, 0xB6}}, {'P', {0xC5, 0xBE}},
	{'Q', {0xC6, 0xDA}}, {'R', {0xC8, 0xBB}}, {'S', {0xC8, 0xF6}},
	{'T', {0xCB, 0xFA}}, {'W', {0xCD, 0xDA}}, {'X', {0xCE, 0xF4}},
	{'Y', {0xD1, 0xB9}}, {'Z', {0xD4, 0xD1}}
};

// 函数用于将GB2312编码的汉字转换为拼音首字母
char getInitial(unsigned char high, unsigned char low) {
	for (int i = 0; i < 26; ++i) {
		if (high < pinyinMap[i].gb2312Start[0] ||
			(high == pinyinMap[i].gb2312Start[0] && low < pinyinMap[i].gb2312Start[1])) {
			return pinyinMap[i - 1].pinyin;
		}
	}
	return 'Z'; // 如果超出范围，默认返回'Z'
}

int main() {
	int n;
	cin >> n;
	cin.ignore(); // 忽略换行符
	
	vector<string> lines(n);
	for (int i = 0; i < n; ++i) {
		getline(cin, lines[i]);
	}
	
	for (const string& line : lines) {
		for (size_t j = 0; j < line.length(); j += 2) {
			// 取出GB2312编码的高字节和低字节
			unsigned char high = line[j];
			unsigned char low = line[j + 1];
			// 转换为拼音首字母并输出
			cout << getInitial(high, low);
		}
		cout << endl;
	}
	
	return 0;
}


/*

在上述程序中，使用了一个名为 PinyinMap 的结构体来作为数据结构，其作用与构成如下：

作用：
映射关系存储：PinyinMap 结构体用于存储拼音首字母与GB2312编码起始字节之间的映射关系。这种映射关系是程序能够根据汉字的GB2312编码快速找到其拼音首字母的关键。
快速查找：通过数组 pinyinMap 初始化的映射表，程序可以快速定位到任意汉字的拼音首字母所在的范围，从而实现高效的数据查询。
代码可读性与维护性：使用结构体使得代码更加清晰、易于理解，同时也方便后续的维护和扩展，比如添加新的拼音首字母映射关系。
构成：
PinyinMap 结构体包含以下成员：

char pinyin：存储拼音首字母。在程序中，这个字段用于存储从 ‘A’ 到 ‘Z’ 的拼音首字母。
unsigned char gb2312start[2]：存储GB2312编码的起始字节。在GB2312编码中，每个汉字由两个字节表示，这个字段存储了每个拼音首字母对应的汉字在GB2312编码中的起始位置。第一个元素是区号，第二个元素是位号。
数组 pinyinMap：
pinyinMap 是一个 PinyinMap 结构体的数组，它初始化了所有拼音首字母与GB2312编码起始字节的映射关系。
数组的每个元素都对应一个拼音首字母和其在GB2312编码中的起始位置。这些位置是根据题目中给出的表格初始化的。
总结：
PinyinMap 结构体和 pinyinMap 数组共同构成了程序中的核心数据结构，它们实现了拼音首字母与GB2312编码之间的快速映射，是程序能够根据输入的汉字输出其拼音首字母的基础。通过这种结构化的数据表示，程序不仅实现了功能需求，还保证了代码的清晰性和可维护性。
*/
