#include <stdio.h>   // printf
#include <fcntl.h>   // open
#include <unistd.h>  // close
#include "get_next_line_bonus.h"
// get_next_line 함수의 프로토타입 선언
// 실제 프로젝트에서는 헤더 파일(.h)에 이 선언과 BUFFER_SIZE 정의가 있어야 합니다.


// main 함수
int main(void)
{
	int		fd1, fd2, fd3;
	char	*line1, *line2, *line3;
	int		files_active = 0; // 동시에 처리할 파일의 수

	// 1. 테스트 파일들을 연다.
	fd1 = open("test1.txt", O_RDONLY);
	if (fd1 == -1)
	{
		perror("Error opening test1.txt");
		// fd1이 실패하면 fd2, fd3도 열지 않고 종료하거나,
		// 혹은 나머지 파일이라도 처리하도록 로직을 구성할 수 있습니다.
		// 여기서는 간단히 하나라도 실패하면 일부만 테스트합니다.
	} else {
		printf("test1.txt opened with fd: %d\n", fd1);
		files_active++;
	}

	fd2 = open("test2.txt", O_RDONLY);
	if (fd2 == -1)
	{
		perror("Error opening test2.txt");
	} else {
		printf("test2.txt opened with fd: %d\n", fd2);
		files_active++;
	}

	fd3 = open("test3.txt", O_RDONLY);
	if (fd3 == -1)
	{
		perror("Error opening test3.txt");
	} else {
		printf("test3.txt opened with fd: %d\n", fd3);
		files_active++;
	}

	if (files_active == 0) {
		printf("No files could be opened. Exiting.\n");
		return (1);
	}

	printf("\n--- Reading lines alternately from files ---\n");

	// 2. 모든 파일에서 EOF에 도달할 때까지 번갈아 가며 라인을 읽는다.
	// 각 파일의 상태를 추적하기 위해 포인터를 사용합니다.
	// NULL이 아니면 해당 fd에서 라인을 성공적으로 읽었음을 의미합니다.
	// 처음에는 어떤 값이든 상관없지만, 루프 진입을 위해 NULL이 아닌 값으로 설정합니다.
	line1 = (fd1 != -1) ? (char *)1 : NULL; // fd가 유효하면 활성 상태로 간주
	line2 = (fd2 != -1) ? (char *)1 : NULL;
	line3 = (fd3 != -1) ? (char *)1 : NULL;

	while (line1 || line2 || line3) // 어느 파일이든 읽을 내용이 남아있다면 계속
	{
		if (fd1 != -1 && line1) // fd1이 유효하고, 이전에 EOF가 아니었다면
		{
			line1 = get_next_line(fd1);
			if (line1)
			{
				printf("FD[%d]: %s\n", fd1, line1);
				free(line1); // GNL이 반환한 메모리 해제
			}
			else
			{
				printf("FD[%d]: EOF or Error\n", fd1);
				close(fd1); // 파일을 다 읽었거나 오류 발생 시 닫음
				fd1 = -1;   // 더 이상 이 fd를 사용하지 않도록 표시
			}
		}

		if (fd2 != -1 && line2) // fd2가 유효하고, 이전에 EOF가 아니었다면
		{
			line2 = get_next_line(fd2);
			if (line2)
			{
				printf("FD[%d]: %s\n", fd2, line2);
				free(line2);
			}
			else
			{
				printf("FD[%d]: EOF or Error\n", fd2);
				close(fd2);
				fd2 = -1;
			}
		}

		if (fd3 != -1 && line3) // fd3이 유효하고, 이전에 EOF가 아니었다면
		{
			line3 = get_next_line(fd3);
			if (line3)
			{
				printf("FD[%d]: %s\n", fd3, line3);
				free(line3);
			}
			else
			{
				printf("FD[%d]: EOF or Error\n", fd3);
				close(fd3);
				fd3 = -1;
			}
		}
		// 모든 파일 디스크립터가 -1이 되면 line1, line2, line3 모두 NULL이 되어 루프 종료
		if (fd1 == -1) line1 = NULL;
		if (fd2 == -1) line2 = NULL;
		if (fd3 == -1) line3 = NULL;
	}

	printf("\n--- All files processed ---\n");

	// 3. (선택적) 이미 루프 내에서 close 했지만, 안전을 위해 다시 한번 닫거나 확인
	// if (fd1 != -1) close(fd1);
	// if (fd2 != -1) close(fd2);
	// if (fd3 != -1) close(fd3);

	return (0);
}
