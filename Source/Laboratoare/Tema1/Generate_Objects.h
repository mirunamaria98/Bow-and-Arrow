#pragma once

#include <string>
#include <Core/GPU/Mesh.h>
#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include <Component/SimpleScene.h>
using namespace std;
class Generate_Objects
{
public:
	Generate_Objects();
	~Generate_Objects();

	Mesh* Generate_Power_Bar();
	Mesh* GAME_OVER();
	Mesh* Generate_arrow();
	Mesh* Generate_Baloon(glm::vec3(colour), string name);
	Mesh* Generate_balloon_tail(glm::vec3 color, string name);
	Mesh* Generate_Bow(glm::vec3 color);
	Mesh* Generate_Shuriken();
};