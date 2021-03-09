                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         #include "Tema1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform2D.h"
#include <math.h>
#include "Generate_Objects.h"

using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}


void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);
	tx = window->GetResolution().x;
	ty = 300;

	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 50;
		Generate_Objects* object = new Generate_Objects();
	AddMeshToList(object->Generate_Baloon(glm::vec3(1, 0, 0), "balon rosu"));
	AddMeshToList(object->Generate_balloon_tail(glm::vec3(1, 0, 0), "coada rosie"));

	AddMeshToList(object->Generate_Baloon(glm::vec3(1, 1, 0), "balon galben"));
	AddMeshToList(object->Generate_balloon_tail(glm::vec3(1, 1, 0), "coada galbena"));
	AddMeshToList(object->Generate_Shuriken());

	AddMeshToList(object-> Generate_arrow());

	AddMeshToList(object->Generate_Bow(glm::vec3(0,0,0)));

	AddMeshToList(object->Generate_Power_Bar());
	AddMeshToList(object->GAME_OVER	());

	for (int i = 0; i < 10; i++) {
		positions[i] = (rand() % ((1100) - (600))) + (600);
	}
	for (int i = 0; i < 7; i++) {
		positions_g[i] = (rand() % ((1100) - (600))) + (600);
	}
	ty_sh = 300;
	score = 0;
	

}


void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}
bool variabila = true;

float unghi;
void Tema1::Update(float deltaTimeSeconds)
{

	if (lives > 0) {


		//animatie pentru sho
		modelMatrix = glm::mat3(1);

		tx -= deltaTimeSeconds * 200;
		modelMatrix *= Transform2D::Translate(tx, ty_sh);

		if (tx < 0) {
			tx = window->GetResolution().x + 300;
			ty_sh = rand() % 700 + 10;
			if (lovit == true) {
				lives -= 1;
				lovit = false;
				cout << "Lives left " << lives << endl;
			}
		}
		//rotatie
		unghi += 2 * deltaTimeSeconds;
		modelMatrix *= Transform2D::Rotate(unghi);
		modelMatrix *= Transform2D::Translate(shuriken_translation, shuriken_translation);

		modelMatrix *= Transform2D::Scale(shuriken_dimension, shuriken_dimension);
		RenderMesh2D(meshes["triangle"], shaders["VertexColor"], modelMatrix);

		float dx = tx_bow - tx;
		float dy = ty_bow - ty_sh;
		float dist = sqrt(dx * dx + dy * dy);
		if (dist < shuriken_rad && power_button == false) {
			lovit = true;
		}
		float dx_p = tx_arrow + from_x_to_arrowhead - tx;
		float dy_p = ty_arrow - ty_sh;
		float distance_p = sqrt(dx_p * dx_p + dy_p * dy_p);
		if (distance_p < rad_shuriken && power_button == true) {
			tx = tx = window->GetResolution().x + 300;
			ty_sh = rand() % 700 + 10;
			shuriken_dimension = 0;
			score += 10;
			cout << "Score " << score<<endl;
		}
		else {
			shuriken_dimension = 30;
		}

		//arrow

		if (speed_grow == true) {
			speed1 += 100;
		}
		if (release == true && power_button == true) {
			tx_arrow += deltaTimeSeconds * speed1 * cos(unghi_aux);
			ty_arrow += deltaTimeSeconds * speed1 * sin(unghi_aux);
			tx_power_bar += deltaTimeSeconds * 100;
		}
		if (tx_arrow >= window->GetResolution().x || ty_arrow >= window->GetResolution().y ||
			tx_arrow <= 0 || ty_arrow <= 0) {
			tx_arrow = tx_bow;
			ty_arrow = ty_bow - 10;
			tx_power_bar = tx_power_bar_initial_pox;
			release = false;
			power_button = false;
			speed1 = 0;
		}

		modelMatrix = glm::mat3(1);
		if (release == true) {
			modelMatrix *= Transform2D::Translate(tx_arrow , ty_arrow);
			modelMatrix *= Transform2D::Rotate(unghi_aux);
		}

		else {
			modelMatrix *= Transform2D::Translate(tx_arrow, ty_arrow);
			modelMatrix *= Transform2D::Rotate(unghi_arrow);
		}
		modelMatrix *= Transform2D::Scale(50, 50);
		RenderMesh2D(meshes["arrow"], shaders["VertexColor"], modelMatrix);

		//bow
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(tx_bow, ty_bow);
		modelMatrix *= Transform2D::Rotate(unghi_arrow);
		modelMatrix *= Transform2D::Scale(10, 10);
		RenderMesh2D(meshes["bow"], shaders["VertexColor"], modelMatrix);

		for (int i = 0; i < 10; i++) {
			if (positions_y[i] < window->GetResolution().y + 100) {
				positions_y[i] += 100 * deltaTimeSeconds;
			}
			else {
				positions_y[i] = (rand() % ((-30) - (-300))) + (-300);
				positions[i] = (rand() % ((1100) - (600))) + (600);
				scale_bal_x[i] = iniatil_scale_baloon;
				scale_bal_y[i] = iniatil_scale_baloon;
			}
			float dx = tx_arrow  + from_x_to_arrowhead - positions[i];
			float dy = ty_arrow - positions_y[i];
			float distance = sqrt(dx * dx + dy * dy);
			if (distance < baloon_radius) {
				scale_bal_x[i] = 0;
				scale_bal_y[i] = 0;
				score += 10;
				cout << "Score  " << score<< endl;
			}
		}
		for (int i = 0; i < 10; i++) {

			//balon rosu
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(positions[i], positions_y[i]);
			modelMatrix *= Transform2D::Scale(scale_bal_x[i], scale_bal_y[i]);
			RenderMesh2D(meshes["balon rosu"], shaders["VertexColor"], modelMatrix);
			//coada balon rosie
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate( positions[i] - tx_tail_dif, positions_y[i] - ty_tail_dif);
			modelMatrix *= Transform2D::Scale(scale_bal_x[i] * 10 / iniatil_scale_baloon, scale_bal_y[i] * 10 / iniatil_scale_baloon);
			RenderMesh2D(meshes["coada rosie"], shaders["VertexColor"], modelMatrix);
		}
		for (int i = 0; i < 7; i++) {
			if (positions_g_y[i] < window->GetResolution().y + 100) {
				positions_g_y[i] += 100 * deltaTimeSeconds;
			}
			else {
				positions_g_y[i] = (rand() % ((-30) - (-300))) + (-300);
				positions_g[i] = (rand() % ((1100) - (600))) + (600);
				scale_bal_g_x[i] = iniatil_scale_baloon;
				scale_bal_g_y[i] = iniatil_scale_baloon;
			}
			float dx = tx_arrow + from_x_to_arrowhead - positions_g[i];
			float dy = ty_arrow - positions_g_y[i];
			float distance = sqrt(dx * dx + dy * dy);
			if (distance < baloon_radius) {
				scale_bal_g_x[i] = hit_baloon_scale;
				scale_bal_g_y[i] = hit_baloon_scale;
				score -= 10;
				cout << "Score  " << score << endl;
			}
		}
		for (int i = 0; i < 7; i++) {
			//balon galben
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(positions_g[i], positions_g_y[i]);
			modelMatrix *= Transform2D::Scale(scale_bal_g_x[i], scale_bal_g_y[i]);
			RenderMesh2D(meshes["balon galben"], shaders["VertexColor"], modelMatrix);
			//coada balon galben
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(positions_g[i] - tx_tail_dif, positions_g_y[i] - ty_tail_dif);
			modelMatrix *= Transform2D::Scale(scale_bal_g_x[i] * 10 / iniatil_scale_baloon, scale_bal_g_y[i] * 10 / iniatil_scale_baloon);
			RenderMesh2D(meshes["coada galbena"], shaders["VertexColor"], modelMatrix);
		}

		//power bar
		modelMatrix = glm::mat3(1);
		if (window->MouseHold(0)) {
			tx_power_bar += deltaTimeSeconds * 10;
		}
		else {
			tx_power_bar = 40;
		}
		modelMatrix *= Transform2D::Scale(tx_power_bar, 10);
		RenderMesh2D(meshes["power_bar"], shaders["VertexColor"], modelMatrix);

	}
	else{
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Scale(90, 80);
	RenderMesh2D(meshes["GAME OVER"], shaders["VertexColor"], modelMatrix);
	}

}

void Tema1::FrameEnd()
{

}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
	if (window->KeyHold(GLFW_KEY_W)) {
		ty_arrow += deltaTime * 100;
		ty_bow += deltaTime * 100;
		
	}
	if (window->KeyHold(GLFW_KEY_S)) {
		ty_arrow -= deltaTime * 100;
		ty_bow -= deltaTime * 100;

	}
}

void Tema1::OnKeyPress(int key, int mods)
{
}

void Tema1::OnKeyRelease(int key, int mods)
{
}

float cateta_x;
float cateta_y;
void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	cateta_x = mouseX - tx_bow;
	cateta_y = window->GetResolution().y - mouseY - ty;

	if (atan(cateta_y / cateta_x) > -1 && atan(cateta_y / cateta_x) < 1) {
		unghi_arrow = atan(cateta_y / cateta_x);
	}
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{

	if (button == 1) {
		speed_grow = true;
		power_button = false;
		release = false;
		unghi_aux = unghi_arrow;
	}
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	if (button == 1) {
		power_button = true;
		release = true;
		speed_grow = false;
	}
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
                  