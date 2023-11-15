#pragma once
#include <set>
#include <string>

struct AudioDevice {
	int m_index;
	std::string m_name;
};

class InputAudio {
public:
	InputAudio();
	bool IsThereSound();
};