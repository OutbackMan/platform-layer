#include <linux/input.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include <unistd.h>

#include <string.h>

static const char *const event_value[3] = {
	"RELEASED",
	"PRESSED",
	"REPEATED"	
};

int main(int argc, char **argv)
{
	const char *keyboard = "/dev/input/event2";

	struct input_event event;

	int fd = open(keyboard, O_RDONLY);

	if (fd == -1) {
		fprintf(stderr, "Cannot open %s: %s.\n", keyboard, strerror(errno));

		return EXIT_FAILURE;
	}

	for (;;) {
		ssize_t n = read(fd, &event, sizeof event);

		if (n == -1) {
			if (errno == EINTR) {
				continue;
			} else {
				break;	
			}
		} else {
			if (n != sizeof event) {
				errno = EIO;
				break;
			}	
		}

		if (event.type == EV_KEY && event.value >= 0 && event.value <= 2) {
			printf("%s 0x%04x (%d)\n", event_value[event.value], (int)event.code, (int)event.code);
		}		
	}

	fflush(stdout);
	fprintf(stderr, "%s.\n", strerror(errno));

	return EXIT_FAILURE;
}
