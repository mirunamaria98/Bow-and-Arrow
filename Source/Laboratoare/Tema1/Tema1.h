#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>
#include "Generate_Objects.h"

class Tema1 : public SimpleScene
{
	public:
		Tema1();
		~Tema1();

		void Init() override;
		float limSup = 1000;

	private:

		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;

	protected:
		glm::mat3 modelMatrix;
		float translateX, translateY;
		float scaleX, scaleY;
		float angularStep;

		int Ran();
		float tx;
		float ty;

		float ty_sh;

		float tx_arrow = 30;
		float ty_arrow = 290;

		float tx_bow = 30;
		float ty_bow = 300;

		float tx_baloon = 100;
		float ty_baloon = 0;

		float tx_coada = tx_baloon - 50;
		float ty_coada = ty_baloon - 105;

		float tx_baloon_g = 255;
		float ty_baloon_g = 0;

		float tx_coada_g = tx_baloon_g - 50;
		float ty_coada_g = ty_baloon_g - 105;

		float tx_power_bar = tx_bow;
		float ty_power_bar;
		float tx_bar_tr = 170;

		float x_pos;
		float y_pos;
		float radius = 1.0f;
		float unghi_arrow;
		float unghi_aux;

		bool speed_grow = false;
		bool release;
		bool arrow_angle;
		bool power_button = false;

		int positions[11];
		int positions_y[11] = { 100,300,800,600,330,111,222,555,445,605 };
		int positions_g[11];
		int positions_g_y[11] = { 55,33,100,30,450,600,250 };
		int scale_bal_x[11] = { 4,4,4,4,4,4,4,4,4,4 };
		int scale_bal_y[11] = { 4,4,4,4,4,4,4,4,4,4 };
		int scale_bal_g_x[11] = { 4,4,4,4,4,4,4,4,4,4 };
		int scale_bal_g_y[11] = { 4,4,4,4,4,4,4,4,4,4 };
		int tx_power_bar_initial_pox = 40;
		int shuriken_rad = 120;
		int from_x_to_arrowhead = 45;
		int baloon_radius = 40;
		int iniatil_scale_baloon = 4;
		int hit_baloon_scale = 0;
		int tx_tail_dif = 50;
		int ty_tail_dif = 105;
		int shuriken_dimension = 30;
		int shuriken_translation = -30;
		int rad_shuriken = 40;
		float scale_balon_x = 4;
		float scale_balon_y = 4;
		float scale_tail_x = 10;
		float scale_tail_y = 10;
		bool lovit = false;
		int score;

		float speed1, speed2;
		int lives = 3;

};
