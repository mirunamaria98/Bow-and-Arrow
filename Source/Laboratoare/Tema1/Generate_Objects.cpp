#include "Generate_Objects.h"
Generate_Objects::Generate_Objects()
{
}
Generate_Objects ::~Generate_Objects() {

}

Mesh* Generate_Objects::Generate_Power_Bar() {

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(-10,3, 0), glm::vec3(1,0,0)),
		VertexFormat(glm::vec3(5, 3, 0), glm::vec3(1,0,0)),
		VertexFormat(glm::vec3(5, 2, 0), glm::vec3(1,0,0)),
		VertexFormat(glm::vec3(-10, 2, 0), glm::vec3(1,0,0)),

	};

	Mesh* power_bar = new Mesh("power_bar");
	std::vector<unsigned short> indices = { 0,1,3,
											1,2,3


	};

	
	power_bar->InitFromData(vertices, indices);
	return power_bar;
}

Mesh* Generate_Objects::GAME_OVER() {

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(2.5,7.5, 0), glm::vec3(1,0,0)),//0
		VertexFormat(glm::vec3(4, 7.5, 0), glm::vec3(1,0,0)),//1
		VertexFormat(glm::vec3(2.5, 6, 0), glm::vec3(1,0,0)),//2
		VertexFormat(glm::vec3(4, 6, 0), glm::vec3(1,0,0)),//3
		VertexFormat(glm::vec3(4, 5.5, 0), glm::vec3(1,0,0)),//4
		VertexFormat(glm::vec3(2.5, 5.5, 0), glm::vec3(1,0,0)),//5
		VertexFormat(glm::vec3(3, 6, 0), glm::vec3(1,0,0)),//6

		VertexFormat(glm::vec3(4.5,5.5, 0), glm::vec3(1,0,0)),//7
		VertexFormat(glm::vec3(5, 6, 0), glm::vec3(1,0,0)),//8
		VertexFormat(glm::vec3(5.25, 7.5, 0), glm::vec3(1,0,0)),//9
		VertexFormat(glm::vec3(5.5, 6, 0), glm::vec3(1,0,0)),//10
		VertexFormat(glm::vec3(6, 5.5, 0), glm::vec3(1,0,0)),//11
		VertexFormat(glm::vec3(6.5, 5.5, 0), glm::vec3(1,0,0)),//12
		VertexFormat(glm::vec3(6.5, 7.5, 0), glm::vec3(1,0,0)),//13
		VertexFormat(glm::vec3(7.25,6, 0), glm::vec3(1,0,0)),//14
		VertexFormat(glm::vec3(8, 7.5, 0), glm::vec3(1,0,0)),//15
		VertexFormat(glm::vec3(8, 5.5, 0), glm::vec3(1,0,0)),//16
		VertexFormat(glm::vec3(10, 5.5, 0), glm::vec3(1,0,0)),//17
		VertexFormat(glm::vec3(8.5, 5.5, 0), glm::vec3(1,0,0)),//18
		VertexFormat(glm::vec3(10, 6, 0), glm::vec3(1,0,0)),//19
		VertexFormat(glm::vec3(8.5, 6, 0), glm::vec3(1,0,0)),//20
		VertexFormat(glm::vec3(10,7.5, 0), glm::vec3(1,0,0)),//21
		VertexFormat(glm::vec3(8.5, 7.5, 0), glm::vec3(1,0,0)),//22
		VertexFormat(glm::vec3(4, 3, 0), glm::vec3(1,0,0)),//23
		VertexFormat(glm::vec3(2.5, 3, 0), glm::vec3(1,0,0)),//24
		VertexFormat(glm::vec3(4, 5, 0), glm::vec3(1,0,0)),//25
		VertexFormat(glm::vec3(2.5, 5, 0), glm::vec3(1,0,0)),//26
		VertexFormat(glm::vec3(6, 5, 0), glm::vec3(1,0,0)),//27
		VertexFormat(glm::vec3(5.25,3, 0), glm::vec3(1,0,0)),//28
		VertexFormat(glm::vec3(4.5, 5, 0), glm::vec3(1,0,0)),//29
		VertexFormat(glm::vec3(8, 3, 0), glm::vec3(1,0,0)),//30
		VertexFormat(glm::vec3(6.5, 3, 0), glm::vec3(1,0,0)),//31
		VertexFormat(glm::vec3(8, 4, 0), glm::vec3(1,0,0)),//32
		VertexFormat(glm::vec3(6.5, 4, 0), glm::vec3(1,0,0)),//33
		VertexFormat(glm::vec3(8, 5, 0), glm::vec3(1,0,0)),//34
		VertexFormat(glm::vec3(6.5,5, 0), glm::vec3(1,0,0)),//35
		VertexFormat(glm::vec3(10, 3, 0), glm::vec3(1,0,0)),//36
		VertexFormat(glm::vec3(8.5, 3, 0), glm::vec3(1,0,0)),//37
		VertexFormat(glm::vec3(10, 4, 0), glm::vec3(1,0,0)),//38
		VertexFormat(glm::vec3(8.5, 4, 0), glm::vec3(1,0,0)),//39
		VertexFormat(glm::vec3(10, 5, 0), glm::vec3(1,0,0)),//40
		VertexFormat(glm::vec3(8.5, 5, 0), glm::vec3(1,0,0)),//41


	};

	Mesh* game_over = new Mesh("GAME OVER");
	std::vector<unsigned short> indices = { 0,1,
											6,3,
											5,4,
											0,2,
											2,5,
											3,4,
											7,9,
		11,9,
		8,10,
		12,13,
		14,13,
		14,15,
		16,15,
		17,18,
		20,19,
		22,21,	
		18,22,
		24,23,
		26,25,
		24,26,
		23,25,
		28,29,
		28,27,
		31,30,
		33,32,
		35,34,
		31,35,
		39,38,
		41,40,
		39,36,
		37,41,
		38,40

											


	};

	game_over->SetDrawMode(GL_LINES);
	game_over->InitFromData(vertices, indices);
	return game_over;
}

Mesh* Generate_Objects::Generate_arrow() {
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(0,0.1, 0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(2.4, 0.1, 0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(2.4, 0, 0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(2.6, 0.15, 0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(2.4, 0.3, 0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(2.4, 0.2, 0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(0, 0.2, 0), glm::vec3(0,0,0))

	};

	Mesh* arrow = new Mesh("arrow");
	std::vector<unsigned short> indices = { 0,1,6,
											1,5,6,
											2,3,4


	};
	arrow->InitFromData(vertices, indices);
	return arrow;
}

Mesh* Generate_Objects::Generate_Baloon(glm::vec3(colour), string name) {

	std::vector<VertexFormat> vertices;
	std::vector<unsigned short> indices;

	float angle;
	int step;
	int index = 0;

	for (int i = 0; i <= 360; i += 4) {
		angle = i * 3.142 / 180;
		vertices.push_back(VertexFormat(glm::vec3(7 * cos(angle), 10 * sin(angle), 0), colour));
		indices.push_back(index++);
	}

	Mesh* balloon = new Mesh(name);
	balloon->SetDrawMode(GL_TRIANGLE_FAN);
	balloon->InitFromData(vertices, indices);
	return balloon;
}

Mesh* Generate_Objects::Generate_balloon_tail(glm::vec3 color, string name) {
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(4.2, 6,0), color),//0
		VertexFormat(glm::vec3(5.5,6,0),color),//1
		VertexFormat(glm::vec3(5, 7, 0), color),//2
		VertexFormat(glm::vec3(4.5, 6, 0), color),//3
		VertexFormat(glm::vec3(4.7, 6, 0), color),//4
		VertexFormat(glm::vec3(4.3, 5.5, 0), color),//5
		VertexFormat(glm::vec3(4.5, 5.5, 0), color),//6
		VertexFormat(glm::vec3(4.8, 5, 0), color),//7
		VertexFormat(glm::vec3(5, 5, 0), color),//8
		VertexFormat(glm::vec3(4.5, 4.5, 0), color),//9
		VertexFormat(glm::vec3(4.7, 4.5, 0), color),//10
		VertexFormat(glm::vec3(4.8, 4, 0), color),//11
		VertexFormat(glm::vec3(5, 4, 0), color)//12



	};

	Mesh* balloon_tail = new Mesh(name);
	std::vector<unsigned short> indices = { 0,1,2,
											5,4,3,
											5,6,4,
											7,6,5,
											7,8,6,
											9,8,7,
											9,10,8,
											11,10,9,
											11,12,10


	};
	balloon_tail->InitFromData(vertices, indices);
	return balloon_tail;
}

Mesh* Generate_Objects::Generate_Bow(glm::vec3 color) {

	std::vector<VertexFormat> vertices;
	std::vector<unsigned short> indices;
	float angle;
	int step;
	int index = 0;

	for (int i = -90; i <= 90; i += 4) {
		angle = i * 3.142 / 180;
		vertices.push_back(VertexFormat(glm::vec3(5 * cos(angle), 10 * sin(angle), 0), color));
		indices.push_back(index++);
	}

	Mesh* bow = new Mesh("bow");
	bow->SetDrawMode(GL_LINE_LOOP);
	bow->InitFromData(vertices, indices);
	return bow;
}

Mesh* Generate_Objects::Generate_Shuriken()
{

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(0,0,0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(1,0,0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(2, 0, 0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(0,1,0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(1,1,0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(2, 1, 0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(0,2,0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(1,2,0), glm::vec3(0,0,0)),
		VertexFormat(glm::vec3(2, 2, 0), glm::vec3(0,0,0)),
	};

	Mesh* triangle = new Mesh("triangle");
	std::vector<unsigned short> indices = { 0,4,3,
											1,2,4,
											4,7,6,
											4,5,8

	};

	triangle->InitFromData(vertices, indices);
	return triangle;
}
