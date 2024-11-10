#pragma once

#include "UserController.h"

struct Application {
private:
	static Application* instance;

	UserController* userController;

	Application(UserController* userController);

public:
	static auto getInstance(UserController* userController) -> Application*;

	auto start() -> void;
};