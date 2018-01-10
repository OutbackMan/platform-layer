#include <stdint.h>
#include <stdbool.h>

#define MU_MAX_KEYS 256
#define MU_MAX_TEXT 256

struct MuInt2 {
	int value1;
	int value2;
};

struct MuFloat2 {
	float value1;
	float value2;
};

struct MuDigitalButton {
	bool down;
	bool pressed;
	bool released;
};

struct MuAnalogButton {
	float threshold;
	float value;
	bool down; // < threshold
	bool pressed;
	bool released;
};

struct MuAxis {
	float value;
	float threshold;
};

struct MuStick {
	struct MuAxis x;
	struct MuAxis y;
};

struct MuGamePad {
	struct MuDigitalButton a_button;
	struct MuDigitalButton b_button;
	struct MuDigitalButton x_button;
	struct MuDigitalButton y_button;
	struct MuAnalogButton left_trigger;
	struct MuAnalogButton right_trigger;
	struct MuDigitalButton left_bumper_button;
	struct MuDigitalButton right_bumper_button;
	struct MuDigitalButton up_button;
	struct MuDigitalButton down_button;
	struct MuDigitalButton left_button;
	struct MuDigitalButton right_button;
	struct MuStick left_thumbstick;
	struct MuStick right_thumbstick;
	struct MuDigitalButton left_thumb_button;
	struct MuDigitalButton right_thumb_button;
	struct MuDigitalButton select_button;
	struct MuDigitalButton start_button;
};

struct Mu {
	// Window
	char *name;
	struct MuInt2 position;
	struct MuInt2 size;

	// Keyboard
	struct MuDigitalButton keys[MU_MAX_KEYS];

	// Gamepad
	struct MuGamePad;

	// Text
	char *text; // 0 if no new text
	char text_buffer[MU_MAX_TEXT];

	// Time
	float delta_seconds;
	uint64_t delta_milliseconds;
	uint64_t delta_microseconds;
	uint64_t delta_nanoseconds;
	uint64_t samples; // how many samples to generate per frame

	// Sound
	uint32_t samples_per_second; // e.g. 44k
	int16_t *samples; // Points to start of sample_buffer after update
	int16_t sample_buffer[MU_MAX_SAMPLES];

	bool quit;

}

int main(int argc, char **argv)
{
	// before each frame pull all data into context struct
	return 0;
}
