/*
출처: https://www.acmicpc.net/source/80559519
작성자: cksrb4309
코드 내용: FESTIO
*/
#include <cstdio>
#include <cstring>
#define SIZE     (1<<20)

char read_buf[SIZE], write_buf[SIZE];
int read_index = SIZE, write_index;

inline char read_char(){
  // 읽기 인덱스가 크기와 같다면 데이터를 모두 읽은 것이기 때문에 재읽기
  if (read_index == SIZE){ 
    fread(read_buf, sizeof(char), SIZE, stdin);
    read_index = 0; // 읽기 인덱스 초기화
  }
  // 버퍼 내용 한 단계 출력
  return read_buf[read_index++];
}

int read_int(){
  int ret = 0;
  char ch = 0;
  bool n = false;
  
  while ((ch = read_char()) > '9' || ch < '0');
  if (ch == '-'){
    n = true;
    ch = read_char();
  }
  while ('0' <= ch && ch <= '9'){
    // 하위 4비트만 추출하는 연산을 통해 (ch - '0') 값을 얻음
    ret = ret * 10 + (ch & 0xF);
    ch = read_char();
  }
  return n ? -ret : ret;
}

inline int get_size(int n)
{
    int ret = 1;
    n = n > 0 ? n : -n; 
    while (n >= 10) ret++, n /= 10; 
    return ret;
}

void write_int(int n, char delim)
{
    int siz = get_size(n);
    if (write_index + siz + 2 > SIZE) {    // '-' and delim
        fwrite(write_buf, sizeof(char), write_index, stdout);
        write_index = 0;
    }
    if (n < 0) {
        write_buf[write_index++] = '-';
        n = -n; 
    }   
    int temp = siz-1;
    while (temp >= 0) {
        write_buf[write_index + temp--] = n % 10 | '0';
        n /= 10;
    }
    write_index += siz;
    write_buf[write_index++] = delim;
}

struct Flusher {
    ~Flusher() {
        if (write_index) {
            fwrite(write_buf, sizeof(char), write_index, stdout);
            write_index = 0;
        }
    }
} flusher;

int main(int argc, char *argv[])
{
    int X, M = read_int();
    char op;
    int S = 0;
    while (M--) {
        read_char();        // first character
        op = read_char();   // second character
        switch (op) {
            case 'd': X = read_int(); S |= 1 << (X-1); break;
            case 'e': X = read_int(); S &= ~(1 << (X-1)); break;
            case 'h': X = read_int();
                      write_int((S & (1 << (X-1))) >> (X-1), '\n'); 
                      break;
            case 'o': X = read_int(); S ^= 1 << (X-1); break;
            case 'l': S = (1 << 20) - 1;
                      read_char(); read_char(); break;
            case 'm': S = 0; read_char();
                      read_char(); read_char(); read_char(); break;
        }
    }
    return 0;
}