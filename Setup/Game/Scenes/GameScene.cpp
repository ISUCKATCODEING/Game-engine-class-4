#include "GameScene.h"

GameScene::GameScene() {
	model = nullptr;
	
	shape = nullptr;
	delete shape;
}

GameScene::~GameScene() {
	delete shape;
	shape = nullptr;
}

bool GameScene::OnCreate() {
	LogM::Info("INFO", "GameScene.cpp", __LINE__);

	CoreEngine::GetInstance()->SetCamera(new Camera());
	CoreEngine::GetInstance()->GetCamera()->SetPosition(glm::vec3(0.0f, 0.0f, 4.0f));
	CoreEngine::GetInstance()->GetCamera()->AddLight(new LightSource(glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(1.0f, 1.0f, 1.0f),  0.1f, 0.5f, 0.1f));
	
	

	
    model = new Model("Resources/Models/Dice.obj", "Resources/Materials/Dice.mtl", ShaderHandler::GetInstance()->GetShader("simpleShader"));
	//model->SetScale(glm::vec3(0.5f));
	shape = new GameObject(model);

	return true;
}

void GameScene::Update(const float deltaTime_) {
	//std::cout << deltaTime_ << std::endl;
	shape->Update(deltaTime_);
}

void GameScene::Render() {
	shape->Render(CoreEngine::GetInstance()->GetCamera());
}