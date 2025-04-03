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

