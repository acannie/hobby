#include <iostream>
#include <cstring>
#include <cstdint>
#include <utf8.h>

int main() {
  const char* str1 = u8"明日天気にな〜れ";

  const char* it = str1;
  const char* end = str1 + strlen(str1);

  // 文字列の長さを取得
  int length = utf8::distance(it, end);
  std::cout << "長さ: " << length << std::endl;

  std::cout << std::hex;

  while (it < end) {
    // イテレータを1文字分すすめる
    std::uint32_t code = utf8::next(it, end);

    // 該当位置の文字コードを出力
    std::cout << code << std::endl;
  }

  return 0;
}