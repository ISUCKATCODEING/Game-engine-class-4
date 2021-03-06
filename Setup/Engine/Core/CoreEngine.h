#ifndef COREENGINE_H
#define COREENGINE_H

#include "Window.h"
#include <memory>
#include "Timer.h"
#include "LogM.h"
#include "GameInterface.h"
#include "Scene.h"

#include "../Rendering/3D/GameObject.h"

#include "../Graphics/ShaderHandler.h"

#include "../Camera/Camera.h"

#include "../Graphics/TextureHandler.h"

class CoreEngine
{
public:
	CoreEngine(const CoreEngine&) = delete;
	CoreEngine(CoreEngine&&) = delete;
	CoreEngine& operator=(const CoreEngine&) = delete;
	CoreEngine& operator=(CoreEngine&&) = delete;

	static CoreEngine* GetInstance();


	bool OnCreate(std::string name_, int width_, int hieght_);
	void Run();
	void Exit();
	bool GetIsRunning() const;
	int GetCurrentScene() const;

	void SetGameInterface(GameInterface* gameInterface_);
	void SetCurrentScene(int sceneNum_);
	float GetScreenWidth() const;
	float GetScreenHight() const;
	Camera* GetCamera() const;

	
	
	void SetCamera(Camera* camera_);


private:
	CoreEngine();
	~CoreEngine();
	void Update(const float deltaTime_);
	void Render();
	void OnDestroy();

	static std::unique_ptr<CoreEngine> engineInstance;
	friend std::default_delete<CoreEngine>;

	Window* window;
	bool isRunning;
	Timer timer;
	unsigned int fps;
	GameInterface* gameInterface;

	int currentSceneNum;

	Camera* camera;
};
#endif

