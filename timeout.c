/* test timeout */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fd_set rfds;
    struct timeval tv;
    int retval;

    // 파일 디스크립터 0(STDIN_FILENO)를 모니터링하도록 설정
    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);

    // 타임아웃 설정 (5초)
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    // select()를 사용하여 타임아웃까지 대기
    retval = select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select()");
        return EXIT_FAILURE;
    } else if (retval) {
        // 입력이 준비되었음
        printf("Data is available now.\n");
        // 여기에서 적절한 처리를 수행
    } else {
        // 타임아웃 발생
        printf("No data within five seconds.\n");
    }

    return EXIT_SUCCESS;
}
