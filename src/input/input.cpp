#include <glad.h>
#include <GLFW/glfw3.h>
#include "input.hpp"

GLFWwindow* Input::window;
std::vector<KeyState> Input::key_states = std::vector<KeyState>(key_count, KeyState::RELEASED);

bool Input::is_key_down(int key_code) {
	return key_states[key_code] == KeyState::PRESSED
		|| key_states[key_code] == KeyState::JUST_PRESSED;
}
bool Input::key_just_pressed(int key_code) {
	return key_states[key_code] == KeyState::JUST_PRESSED;
}
bool Input::is_key_up(int key_code) {
	return key_states[key_code] == KeyState::RELEASED
		|| key_states[key_code] == KeyState::JUST_RELEASED;
}
bool Input::key_just_released(int key_code) {
	return key_states[key_code] == KeyState::JUST_RELEASED;
}


void Input::poll_events() {
	for(int i = 0; i < key_count; ++i) {
		int state = glfwGetKey(window, i);
		if(state == GLFW_PRESS) {
			if(key_states[i] == KeyState::RELEASED) {
				key_states[i] = KeyState::JUST_PRESSED;
			}else {
				key_states[i] = KeyState::PRESSED;
			}
		}else {
			if(key_states[i] == KeyState::PRESSED) {
				key_states[i] = KeyState::JUST_RELEASED;
			}else {
				key_states[i] = KeyState::RELEASED;
			}
		}
	}
}